#include "ControlUI.h"
#include<QMessageBox>
ControlUI::ControlUI(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	setWindowFlags(Qt::WindowCloseButtonHint | Qt::FramelessWindowHint);
	ui.CloseBtn->setToolTipName(QString::fromLocal8Bit("关闭"));
	ui.MinBtn->setToolTipName(QString::fromLocal8Bit("最小化"));
	connect(ui.MinBtn, SIGNAL(clicked()), this, SLOT(slot_minWindow()));
	connect(ui.CloseBtn, SIGNAL(clicked()), this, SLOT(close()));
}

ControlUI::~ControlUI()
{
	
}

void ControlUI::closeEvent(QCloseEvent *event)
{
	QWidget::close();
	*isActive = false;
	delete this;
}

void ControlUI::slot_minWindow()
{
	this->showMinimized();
}

void ControlUI::mousePressEvent(QMouseEvent *event)
{
	if (event->button() == Qt::LeftButton) {
		m_Drag = true;
		m_DragPosition = event->globalPos() - this->pos();
		event->accept();
	}
}

void ControlUI::mouseMoveEvent(QMouseEvent *event)
{
	if (m_Drag && (event->buttons() && Qt::LeftButton)) {
		move(event->globalPos() - m_DragPosition);
		event->accept();
	}
}

void ControlUI::mouseReleaseEvent(QMouseEvent *event)
{
	m_Drag = false;
}

void ControlUI::on_RIDBtn_clicked()
{
	cmmIndex = 1201;
	//读取ID
	QString Comm = "ID\r\n";
	QByteArray ba = Comm.toLatin1();
	LPCSTR ch = ba.data();
	int len = Comm.length();
	::send(Socket, ch, len, 0);
}

void ControlUI::on_WIDBtn_clicked()
{
	cmmIndex = 1202;
	//设置ID
	QString Comm = "ID," + ui.DevicelineEdit->text().trimmed() + "\r\n";
	QByteArray ba = Comm.toLatin1();
	LPCSTR ch = ba.data();
	int len = Comm.length();
	::send(Socket, ch, len, 0);
}

void ControlUI::on_RQZBtn_clicked()
{
	cmmIndex = 1208;
	//读取区站号
	QString Comm = "QZ\r\n";
	QByteArray ba = Comm.toLatin1();
	LPCSTR ch = ba.data();
	int len = Comm.length();
	::send(Socket, ch, len, 0);
}

void ControlUI::on_WQZBtn_clicked()
{
	cmmIndex = 1209;
	//设置区站号
	QString Comm = "QZ," + ui.QZlineEdit->text().trimmed() + "\r\n";
	QByteArray ba = Comm.toLatin1();
	LPCSTR ch = ba.data();
	int len = Comm.length();
	::send(Socket, ch, len, 0);
}

void ControlUI::on_RTimeBtn_clicked()
{
	cmmIndex = 1203;
	//读取时钟
	QString Comm = "DATETIME\r\n";
	QByteArray ba = Comm.toLatin1();
	LPCSTR ch = ba.data();
	int len = Comm.length();
	::send(Socket, ch, len, 0);
}

void ControlUI::on_WTimeBtn_clicked()
{
	cmmIndex = 1204;
	//设置时钟
	QString Time;
	Time =ui.RdateTimeEdit->dateTime().toString("yyyy-MM-dd,HH:mm:ss");
	QString Comm = "DATETIME," + Time + "\r\n";
	QByteArray ba = Comm.toLatin1();
	LPCSTR ch = ba.data();
	int len = Comm.length();
	::send(Socket, ch, len, 0);
}

void ControlUI::on_RDBtn_clicked()
{
	cmmIndex = 1206;
	//读取实时数据
	QString Comm = "READDATA\r\n";
	QByteArray ba = Comm.toLatin1();
	LPCSTR ch = ba.data();
	int len = Comm.length();
	::send(Socket, ch, len, 0);
}

void ControlUI::on_DownBtn_clicked()
{
	cmmIndex = 1207;
	//补抄数据
	QString Time_B, Time_E;
	Time_B = ui.BdateTimeEdit->dateTime().toString("yyyy-MM-dd,HH:mm:ss");
	Time_E = ui.EdateTimeEdit->dateTime().toString("yyyy-MM-dd,HH:mm:ss");
	QString Comm = "DOWN," + Time_B + "," + Time_E + "\r\n";
	QByteArray ba = Comm.toLatin1();
	LPCSTR ch = ba.data();
	int len = Comm.length();
	::send(Socket, ch, len, 0);
}

void ControlUI::on_AutoCheckBtn_clicked()
{
	cmmIndex = 1205;
	//设备自检
	QString Comm = "AUTOCHECK\r\n";
	QByteArray ba = Comm.toLatin1();
	LPCSTR ch = ba.data();
	int len = Comm.length();
	::send(Socket, ch, len, 0);
}

//设备返回值
void ControlUI::setValue(QStringList list)
{
	switch (cmmIndex)
	{
	case 1201://设备号
	{
		if (list.count() < 1)
			break;
		ui.DevicelineEdit->setText(list.at(0));
		break;
	}
	case 1208://台站号
	{
		if (list.count() < 1)
			break;
		ui.QZlineEdit->setText(list.at(0));
		break;
	}
	case 1203://设备时间
	{
		if (list.count() < 1)
			break;
		QDateTime time = QDateTime::fromString(list.at(0), "yyyy-MM-dd,hh:mm:ss");
		ui.RdateTimeEdit->setDateTime(time);
		break;
	}
	default:
	{
		if (list.count() < 1)
			break;
		QString r = list.at(0);
		if (r.toUpper().compare("T")==0)
		{
			QMessageBox::about(this, QString::fromLocal8Bit("设备状态"), QString::fromLocal8Bit("操作成功！"));
		}
		else 
		{
			QMessageBox::about(this, QString::fromLocal8Bit("设备状态"), QString::fromLocal8Bit("操作失败！"));
		}
	}
		break;
	}
}

