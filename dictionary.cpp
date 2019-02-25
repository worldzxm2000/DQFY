#include"dictionary.h"

Dictionary::Dictionary()
{
	//观察要素
	//负离子浓度
	map.insert("asa", "NegatIonDens");
	//5分钟气温
	map.insert("aaa5","AT_AT1");
	//5分钟相对湿度
	map.insert("ada5","AH_RH1");
	//主板温度 
	map.insert("ua","MotherTempValue");
	//主板电压
	map.insert("ub","MainClctrVltgVal");
	//设备自检状态
	map.insert("z","AutoCheckSts1");
	//气温传感器状态
	map.insert("y_aaa","AirTmprtSensorSts1");
	//湿度传感器状态
	map.insert("y_ada","AirHmdSensorSts1");
	//外接电源交流电
	map.insert("xa","ExtPwrSts1");
	//主板电压状态
	map.insert("xb","MainClctrVltgSts");
	//主板温度状态
	map.insert("wa","MotherTemp");
}

QString Dictionary::Find(QString key)
{
	QMap<QString, QString>::const_iterator mi = map.find(key);
	if (mi != map.end())
		return map[key];
	return NULL;
}