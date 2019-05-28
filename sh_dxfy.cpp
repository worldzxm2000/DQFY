#include<WinSock2.h>
#include "sh_dxfy.h"
#include"dictionary.h"
#include<QObject>
#include<QDateTime>
#include<QFile>
#include<QTextStream>
#include <QCoreApplication>
#include<QDir>
#include<QApplication>
//获取端口号
int GetPort()
{
    return 23002;
}

//获取业务号
int GetServiceTypeID()
{
    return 8;
}

//获取版本号
QString GetVersionNo()
{
    return "1.0";
}

//获取业务名称
QString GetServiceTypeName()
{
    QString name = QString::fromLocal8Bit("湿地大气负离子业务");
    return name;
}

//矫正时钟
void SetTime(QString StationID, uint Socket)
{
	QDateTime nowtime = QDateTime::currentDateTime();
	QString datetime = nowtime.toString("yyyy-MM-dd,hh:mm:ss");
	//设置时钟
	QString Comm = "DATETIME," + datetime + "\r\n";
	QByteArray ba = Comm.toLatin1();
	LPCSTR ch = ba.data();
	int len = Comm.length();
	::send(Socket, ch, len, 0);
}

//调试窗体
void  GetControlWidget(QString StationID, uint Socket, QWidget* parent)
{
	if (isActive)
	{
		return;
	}
	control_ui = new ControlUI();
	isActive = true;
	control_ui->Socket = Socket;
	control_ui->isActive= &isActive ;
	control_ui->show();
}

//返回值反馈
void SetValueToControlWidget(QStringList list)
{
	if (control_ui == nullptr)
		return;
	if (isActive)
		control_ui->setValue(list);
}

//终端命令
void SetCommand(uint Socket, int CommandType, QString Params1, QString Params2, QString StationID)
{
	//设备终端命令
	QString Comm;
	int len = Comm.length();
	switch (CommandType)
	{
	case 1201:
		//读取ID
		Comm = "ID\r\n";
		break;
	case 1202:
		//设置ID
		Comm = "ID," + Params1 + "\r\n";
		break;
	case 1203:
		//读取时钟
		Comm = "DATETIME\r\n";
		break;
	case 1204:
	{
		//设置时钟
		QDateTime nowtime = QDateTime::currentDateTime();
		QString datetime = nowtime.toString("yyyy-MM-dd,hh:mm:ss");
		Comm = Comm = "DATETIME," + datetime + "\r\n";
	}
	break;
	case 1205:
		//设备自检
		Comm = "AUTOCHECK\r\n";
		break;
	case 1206:
		//读取实时数据
		Comm = "READDATA\r\n";
		break;
	case 1207:
		//补抄数据
		Comm = "DOWN," + Params1 + "," + Params2 + "\r\n";
		break;
	case 1208:
		//读取台站号
		Comm = "QZ\r\n";
		break;
	case 1209:
		//设置台站号
		Comm = "QZ," + Params1 + "\r\n";
		break;
	default:
		break;
	}
	QByteArray ba = Comm.toLatin1();
	LPCSTR ch = ba.data();
	::send(Socket, ch, len, 0);
}

//解析数据
LRESULT Char2Json(QString &buff, QJsonObject &json)
{
    int Count = 0;//数据个数
    int Current_P = buff.length();//当前数据指

    //遍历查找数据
    for (int i = 0; i < buff.length() - 2; i++)
    {
        if (buff[i].toUpper() == 'B' && buff[i + 1].toUpper() == 'G'&&buff[i + 2] == ',')
        {
            Current_P = i;//指针指向帧头
            for (int j = i + 2; j < buff.length() - 2; j++)
            {
                if (buff[j] == ','&&buff[j + 1].toUpper() == 'E'&&buff[j + 2].toUpper() == 'D')
                {
                    Current_P = j + 3;//指针移动到帧尾下一个字符
                    Count += 1;//数据个数
                    Dictionary dic;
                    QString strBuff = buff.mid(i, j - i + 3);
                    QStringList strlist = strBuff.split(",");
                    QJsonObject SubJson;
					//数据类型 观测数据
                    SubJson.insert("DataType", 1);
                    //区站号
                    SubJson.insert("StationID", strlist.at(1));
                    //12大气负氧离子
                    SubJson.insert("ServiceTypeID",SH_DXFY);
					//数据存储类型
					SubJson.insert("DataSourceID", 12);
                    //纬度
                   SubJson.insert("Latitude", ConvertToC(strlist.at(2)));
                    //经度
                    SubJson.insert("Longitude", ConvertToC(strlist.at(3)));
                    //高度
                     SubJson.insert("Altitude",strlist.at(4).toInt());
                     //设备ID
                     SubJson.insert("DeviceID",strlist.at(7));
                    //时间
                    QString time = Convert2Time(strlist.at(8));
                    SubJson.insert("ObserveTime", time);
        
                    int CountOfFeature = ((QString)strlist.at(10)).toInt();
                    SubJson.insert("CountOfFeature", CountOfFeature);
                    int CountOfFacilitiesStatus = ((QString)strlist.at(11)).toInt();
                    SubJson.insert("CountOfFacilitiesStatus", CountOfFacilitiesStatus);
                    //判断数据完整性
                    if (strlist.count() < CountOfFeature * 2 + CountOfFacilitiesStatus * 2 + 12)
                    {
                        i = j + 2;//当前循环
                        continue;
                    }
                    //观察要素
                    QString strFeatureName;
        
                    for (int i = 12; i < CountOfFeature * 2 + 12; i += 2)
                    {
                        QString key = dic.Find(QString(strlist.at(i)).toLower());
                        if (key != NULL)
                        {
							int value = strlist.at(i + 1).toInt();
							if (key == "AT_AT1" || key == "MainClctrVltgVal")
							{
								float fvalue;
								fvalue = (float)value / 10.00;
								SubJson.insert(key,fvalue);
							}else
							{
								SubJson.insert(key, value);
							}
                            //质量控制码
                            if (i == 12)
                            {
                                strFeatureName = key;
                            }
                            else
                            {
                                strFeatureName += ",";
                                strFeatureName += key;
                            }
                        }
                    }
                    SubJson.insert("StatusBitName", strFeatureName);
                    //状态位
                    SubJson.insert("StatusBit", strlist.at(CountOfFeature * 2 + 12));

                    //设备状态
                    for (int i = CountOfFeature * 2 + 13; i < CountOfFeature * 2 + CountOfFacilitiesStatus * 2 + 13; i += 2)
                    {
                        QString key = dic.Find(QString(strlist.at(i)).toLower());
                        if (key != NULL)
                            SubJson.insert(key, strlist.at(i + 1));
                    }
                    //数据备份
                    QDateTime current_date_time = QDateTime::currentDateTime();
                    QString current_date = current_date_time.toString("yyyy.MM.dd hh:mm:ss");
                    QString current_day = current_date_time.toString("yyyy-MM-dd");
                    QString fileName = QCoreApplication::applicationDirPath() + "\\SH\\DXFY\\" + strlist.at(1) + "\\" + current_day;
                    QDir dir(fileName);
                    if (!dir.exists())
                        dir.mkpath(fileName);//创建多级目录
                    fileName += "\\data.txt";
                    QFile file(fileName);
                    if (!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append))
                    {}
                    QTextStream in(&file);
                    in << current_date << "\r\n" << strBuff << "\r\n";
                    file.close();
                    json.insert(QString::number(Count), SubJson);
                    i = j + 2;//当前循环
                    break;
                }
            }
        }
        else if (buff[i] == '<')
        {
            Current_P = i;//指针指向帧头
            for (int j = i + 1; j < buff.length(); j++)
            {
                if (buff[j] == '>')
                {
                    Current_P = j + 1;//指针移动到帧尾
                    Count += 1;//数据个数
                    QString subStr = buff.mid(i + 1, j - i - 1);
                    QStringList strlist = subStr.split(" ");
                    QJsonObject SubJson;
                    i = j;
                    switch (strlist.count())
                    {
                        //单个返回值
                    case 1:
                    {
						SubJson.insert("DataType", 2);//数据类型 2操作数据
                        SubJson.insert("ValueCount", 1);
                        SubJson.insert("RecvValue1", strlist.at(0));
                        json.insert(QString::number(Count), SubJson);
                        break;
                    }
                    //双返回值
                    case 2:
                    {
						SubJson.insert("DataType", 2);//数据类型 2操作数据
                        SubJson.insert("ValueCount", 2);
                        SubJson.insert("RecvValue1", strlist.at(0));
                        SubJson.insert("RecvValue2", strlist.at(1));
                        json.insert(QString::number(Count), SubJson);
                        break;
                    }
					case 3://心跳
					{
						SubJson.insert("DataType", 3);//数据类型3 心跳
						SubJson.insert("ServiceTypeID", strlist.at(0));
						SubJson.insert("StationID", strlist.at(1));
						SubJson.insert("DeviceID", strlist.at(2));
						json.insert(QString::number(Count), SubJson);
					}
                    //无效数据
                    default:
                        break;
                    }
                    break;
                }
            }
        }
    }
    json.insert("DataLength", Count);//JSON数据个数
    if (Current_P >= buff.length())//判断当前指针位置
    {
        buff.clear();
    }//清除内存
    else
    {
        buff.remove(0, Current_P);
    }//将剩余字节存入缓存
    return 1;
}

QString Convert2Time(QString strTime)
{
    QString tmp;
    tmp = strTime.mid(0, 4) + "-" + strTime.mid(4, 2) + "-" + strTime.mid(6, 2) + " " + strTime.mid(8, 2) + ":" + strTime.mid(10, 2) + ":" + strTime.mid(12, 2);
    return tmp;
}

QString ConvertToC(QString str)
{
	int degree, minute, second;
	float dms;
	second = str.mid(str.length() - 2, 2).toInt();
	minute = str.mid(str.length() - 4, 2).toInt();
	degree = str.mid(0, str.length() - 4).toInt();
	dms = (float)degree + (float)second / 3600.0 + (float)minute / 60;
	return QString::number(dms);
}