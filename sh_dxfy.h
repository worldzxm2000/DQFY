﻿#ifndef SH_DXFY_H
#define SH_DXFY_H

#define SH_DXFY_HHARED_EXPORT __declspec(dllexport)
#ifdef SH_DXFY_HHARED_EXPORT
#else
#define SH_DXFY_HHARED_EXPORT __declspec(dllimport)
#endif

#include<Windows.h>
#include<QJsonObject>
#include<QWidget>
#include"ControlUI.h"
#include<QPushButton>
#define HEADER "BG"
#define TAIL "ED"
#define SH_DXFY "8"
QString Convert2Time(QString strTime);
QString ConvertToC(QString str);
//获取业务号
EXTERN_C SH_DXFY_HHARED_EXPORT int GetServiceTypeID();
//获取业务名称
EXTERN_C SH_DXFY_HHARED_EXPORT QString GetServiceTypeName();
//获取端口号
EXTERN_C SH_DXFY_HHARED_EXPORT int GetPort();
//获取版本号
EXTERN_C SH_DXFY_HHARED_EXPORT QString GetVersionNo();
//解析数据
EXTERN_C SH_DXFY_HHARED_EXPORT LRESULT Char2Json(QString &buff, QJsonObject &json);
//调试窗体
EXTERN_C SH_DXFY_HHARED_EXPORT void GetControlWidget(QString StationID, uint Socket, QWidget *parent);
//矫正时钟
EXTERN_C SH_DXFY_HHARED_EXPORT void SetTime(QString StationID, uint Socket);
//显示返回值
EXTERN_C SH_DXFY_HHARED_EXPORT void  SetValueToControlWidget(QStringList list);
//发送命令
EXTERN_C SH_DXFY_HHARED_EXPORT void SetCommand(uint Socket, int CommandType, QString Params1, QString Params2, QString StationID);
ControlUI *control_ui;//终端窗体
bool isActive;//判断终端窗体是否开启
#endif // SH_DXFY_H
