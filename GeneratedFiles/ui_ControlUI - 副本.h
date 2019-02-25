/********************************************************************************
** Form generated from reading UI file 'ControlUI.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTROLUI_H
#define UI_CONTROLUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>
#include "MyButton.h"
QT_BEGIN_NAMESPACE

class Ui_ControlUI
{
public:
    QGroupBox *groupBox_main;
    QLabel *TitleLabel_Name;
    QLabel *TiltleLabel;
    QGroupBox *groupBox;
    QGroupBox *groupBox_ID;
    QPushButton *RIDBtn;
    QPushButton *WIDBtn;
    QLineEdit *DevicelineEdit;
    QGroupBox *groupBox_down;
    QDateTimeEdit *BdateTimeEdit;
    QDateTimeEdit *EdateTimeEdit;
    QPushButton *DownBtn;
    QGroupBox *groupBox_RD;
    QPushButton *RDBtn;
    QGroupBox *groupBox_QZ;
    QPushButton *RQZBtn;
    QPushButton *WQZBtn;
    QLineEdit *QZlineEdit;
    QGroupBox *groupBox_time;
    QDateTimeEdit *RdateTimeEdit;
    QPushButton *RTimeBtn;
    QPushButton *WTimeBtn;
    QGroupBox *groupBox_AC;
    QPushButton *AutoCheckBtn;
    QGroupBox *groupBox_2;
    QScrollArea *ScrollArea_MinBtn;
    QWidget *ScrollAreaWidgetContents_MinBtn;
    MyButton *MinBtn;
    QScrollArea *ScrollArea_CloseBtn;
    QWidget *ScrollAreaWidgetContents_CloseBtn;
    MyButton *CloseBtn;

    void setupUi(QWidget *ControlUI)
    {
        if (ControlUI->objectName().isEmpty())
            ControlUI->setObjectName(QStringLiteral("ControlUI"));
        ControlUI->resize(412, 390);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        ControlUI->setFont(font);
        QIcon icon;
        icon.addFile(QStringLiteral("../Image/png/Weather.ico"), QSize(), QIcon::Normal, QIcon::Off);
        ControlUI->setWindowIcon(icon);
        ControlUI->setStyleSheet(QStringLiteral("background:rgb(77,77, 77);color:white"));
        groupBox_main = new QGroupBox(ControlUI);
        groupBox_main->setObjectName(QStringLiteral("groupBox_main"));
        groupBox_main->setGeometry(QRect(10, 10, 391, 371));
        groupBox_main->setFont(font);
        TitleLabel_Name = new QLabel(groupBox_main);
        TitleLabel_Name->setObjectName(QStringLiteral("TitleLabel_Name"));
        TitleLabel_Name->setGeometry(QRect(45, 15, 91, 25));
        TitleLabel_Name->setFont(font);
        TiltleLabel = new QLabel(groupBox_main);
        TiltleLabel->setObjectName(QStringLiteral("TiltleLabel"));
        TiltleLabel->setGeometry(QRect(10, 15, 32, 32));
        TiltleLabel->setFont(font);
        TiltleLabel->setPixmap(QPixmap(QString::fromUtf8("../Image/png/control.png")));
        groupBox = new QGroupBox(groupBox_main);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 50, 371, 311));
        groupBox->setFont(font);
        groupBox_ID = new QGroupBox(groupBox);
        groupBox_ID->setObjectName(QStringLiteral("groupBox_ID"));
        groupBox_ID->setGeometry(QRect(10, 10, 171, 91));
        groupBox_ID->setFont(font);
        RIDBtn = new QPushButton(groupBox_ID);
        RIDBtn->setObjectName(QStringLiteral("RIDBtn"));
        RIDBtn->setGeometry(QRect(10, 50, 75, 23));
        RIDBtn->setFont(font);
        WIDBtn = new QPushButton(groupBox_ID);
        WIDBtn->setObjectName(QStringLiteral("WIDBtn"));
        WIDBtn->setGeometry(QRect(90, 50, 75, 23));
        WIDBtn->setFont(font);
        DevicelineEdit = new QLineEdit(groupBox_ID);
        DevicelineEdit->setObjectName(QStringLiteral("DevicelineEdit"));
        DevicelineEdit->setGeometry(QRect(10, 20, 151, 20));
        DevicelineEdit->setFont(font);
        groupBox_down = new QGroupBox(groupBox);
        groupBox_down->setObjectName(QStringLiteral("groupBox_down"));
        groupBox_down->setGeometry(QRect(10, 210, 251, 81));
        groupBox_down->setFont(font);
        BdateTimeEdit = new QDateTimeEdit(groupBox_down);
        BdateTimeEdit->setObjectName(QStringLiteral("BdateTimeEdit"));
        BdateTimeEdit->setGeometry(QRect(10, 20, 151, 22));
        BdateTimeEdit->setFont(font);
        BdateTimeEdit->setDateTime(QDateTime(QDate(2018, 9, 1), QTime(0, 0, 0)));
        EdateTimeEdit = new QDateTimeEdit(groupBox_down);
        EdateTimeEdit->setObjectName(QStringLiteral("EdateTimeEdit"));
        EdateTimeEdit->setGeometry(QRect(10, 50, 151, 22));
        EdateTimeEdit->setFont(font);
        EdateTimeEdit->setDateTime(QDateTime(QDate(2018, 9, 1), QTime(0, 0, 0)));
        DownBtn = new QPushButton(groupBox_down);
        DownBtn->setObjectName(QStringLiteral("DownBtn"));
        DownBtn->setGeometry(QRect(170, 20, 75, 23));
        DownBtn->setFont(font);
        groupBox_RD = new QGroupBox(groupBox);
        groupBox_RD->setObjectName(QStringLiteral("groupBox_RD"));
        groupBox_RD->setGeometry(QRect(260, 110, 91, 91));
        groupBox_RD->setFont(font);
        RDBtn = new QPushButton(groupBox_RD);
        RDBtn->setObjectName(QStringLiteral("RDBtn"));
        RDBtn->setGeometry(QRect(10, 40, 75, 23));
        RDBtn->setFont(font);
        groupBox_QZ = new QGroupBox(groupBox);
        groupBox_QZ->setObjectName(QStringLiteral("groupBox_QZ"));
        groupBox_QZ->setGeometry(QRect(190, 10, 171, 91));
        groupBox_QZ->setFont(font);
        RQZBtn = new QPushButton(groupBox_QZ);
        RQZBtn->setObjectName(QStringLiteral("RQZBtn"));
        RQZBtn->setGeometry(QRect(10, 50, 75, 23));
        RQZBtn->setFont(font);
        WQZBtn = new QPushButton(groupBox_QZ);
        WQZBtn->setObjectName(QStringLiteral("WQZBtn"));
        WQZBtn->setGeometry(QRect(90, 50, 75, 23));
        WQZBtn->setFont(font);
        QZlineEdit = new QLineEdit(groupBox_QZ);
        QZlineEdit->setObjectName(QStringLiteral("QZlineEdit"));
        QZlineEdit->setGeometry(QRect(10, 20, 151, 20));
        QZlineEdit->setFont(font);
        groupBox_time = new QGroupBox(groupBox);
        groupBox_time->setObjectName(QStringLiteral("groupBox_time"));
        groupBox_time->setGeometry(QRect(10, 110, 171, 91));
        groupBox_time->setFont(font);
        RdateTimeEdit = new QDateTimeEdit(groupBox_time);
        RdateTimeEdit->setObjectName(QStringLiteral("RdateTimeEdit"));
        RdateTimeEdit->setGeometry(QRect(10, 20, 151, 22));
        RdateTimeEdit->setFont(font);
        RdateTimeEdit->setDateTime(QDateTime(QDate(2018, 9, 1), QTime(0, 0, 0)));
        RTimeBtn = new QPushButton(groupBox_time);
        RTimeBtn->setObjectName(QStringLiteral("RTimeBtn"));
        RTimeBtn->setGeometry(QRect(10, 50, 75, 23));
        RTimeBtn->setFont(font);
        WTimeBtn = new QPushButton(groupBox_time);
        WTimeBtn->setObjectName(QStringLiteral("WTimeBtn"));
        WTimeBtn->setGeometry(QRect(90, 50, 75, 23));
        WTimeBtn->setFont(font);
        groupBox_AC = new QGroupBox(groupBox);
        groupBox_AC->setObjectName(QStringLiteral("groupBox_AC"));
        groupBox_AC->setGeometry(QRect(270, 210, 91, 81));
        groupBox_AC->setFont(font);
        AutoCheckBtn = new QPushButton(groupBox_AC);
        AutoCheckBtn->setObjectName(QStringLiteral("AutoCheckBtn"));
        AutoCheckBtn->setGeometry(QRect(10, 40, 75, 23));
        AutoCheckBtn->setFont(font);
        groupBox_2 = new QGroupBox(groupBox_main);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(335, 15, 46, 26));
        groupBox_2->setFont(font);
        ScrollArea_MinBtn = new QScrollArea(groupBox_2);
        ScrollArea_MinBtn->setObjectName(QStringLiteral("ScrollArea_MinBtn"));
        ScrollArea_MinBtn->setGeometry(QRect(2, 3, 20, 20));
        ScrollArea_MinBtn->setFont(font);
        ScrollArea_MinBtn->setWidgetResizable(true);
        ScrollAreaWidgetContents_MinBtn = new QWidget();
        ScrollAreaWidgetContents_MinBtn->setObjectName(QStringLiteral("ScrollAreaWidgetContents_MinBtn"));
        ScrollAreaWidgetContents_MinBtn->setGeometry(QRect(0, 0, 18, 18));
		MinBtn = new MyButton("../Image/png/Mini.png", 1, ScrollAreaWidgetContents_MinBtn);
        MinBtn->setObjectName(QStringLiteral("MinBtn"));
        MinBtn->setGeometry(QRect(1, 1, 18, 18));
        MinBtn->setFont(font);
        ScrollArea_MinBtn->setWidget(ScrollAreaWidgetContents_MinBtn);
        ScrollArea_CloseBtn = new QScrollArea(groupBox_2);
        ScrollArea_CloseBtn->setObjectName(QStringLiteral("ScrollArea_CloseBtn"));
        ScrollArea_CloseBtn->setGeometry(QRect(24, 3, 20, 20));
        ScrollArea_CloseBtn->setFont(font);
        ScrollArea_CloseBtn->setWidgetResizable(true);
        ScrollAreaWidgetContents_CloseBtn = new QWidget();
        ScrollAreaWidgetContents_CloseBtn->setObjectName(QStringLiteral("ScrollAreaWidgetContents_CloseBtn"));
        ScrollAreaWidgetContents_CloseBtn->setGeometry(QRect(0, 0, 18, 18));
		CloseBtn = new MyButton("../Image/png/close.png", 1, ScrollAreaWidgetContents_CloseBtn);
        CloseBtn->setObjectName(QStringLiteral("CloseBtn"));
        CloseBtn->setGeometry(QRect(1, 1, 18, 18));
        CloseBtn->setFont(font);
        ScrollArea_CloseBtn->setWidget(ScrollAreaWidgetContents_CloseBtn);
        QWidget::setTabOrder(DevicelineEdit, RIDBtn);
        QWidget::setTabOrder(RIDBtn, WIDBtn);
        QWidget::setTabOrder(WIDBtn, QZlineEdit);
        QWidget::setTabOrder(QZlineEdit, RQZBtn);
        QWidget::setTabOrder(RQZBtn, WQZBtn);
        QWidget::setTabOrder(WQZBtn, RdateTimeEdit);
        QWidget::setTabOrder(RdateTimeEdit, RTimeBtn);
        QWidget::setTabOrder(RTimeBtn, WTimeBtn);
        QWidget::setTabOrder(WTimeBtn, RDBtn);
        QWidget::setTabOrder(RDBtn, BdateTimeEdit);
        QWidget::setTabOrder(BdateTimeEdit, EdateTimeEdit);
        QWidget::setTabOrder(EdateTimeEdit, DownBtn);
        QWidget::setTabOrder(DownBtn, AutoCheckBtn);
        QWidget::setTabOrder(AutoCheckBtn, MinBtn);
        QWidget::setTabOrder(MinBtn, CloseBtn);
        QWidget::setTabOrder(CloseBtn, ScrollArea_MinBtn);
        QWidget::setTabOrder(ScrollArea_MinBtn, ScrollArea_CloseBtn);

        retranslateUi(ControlUI);

        QMetaObject::connectSlotsByName(ControlUI);
    } // setupUi

    void retranslateUi(QWidget *ControlUI)
    {
        ControlUI->setWindowTitle(QApplication::translate("ControlUI", "\345\244\247\346\260\224\350\264\237\346\260\247\347\246\273\345\255\220\344\273\252\350\256\276\345\244\207\346\216\247\345\210\266", nullptr));
        groupBox_main->setTitle(QString());
        TitleLabel_Name->setText(QApplication::translate("ControlUI", "\345\244\247\346\260\224\350\264\237\346\260\247\347\246\273\345\255\220\344\273\252", nullptr));
        TiltleLabel->setText(QString());
        groupBox->setTitle(QString());
        groupBox_ID->setTitle(QApplication::translate("ControlUI", "\350\256\276\345\244\207\345\217\267", nullptr));
        RIDBtn->setText(QApplication::translate("ControlUI", "\350\257\273\345\217\226\350\256\276\345\244\207\345\217\267", nullptr));
        WIDBtn->setText(QApplication::translate("ControlUI", "\350\256\276\347\275\256\350\256\276\345\244\207\345\217\267", nullptr));
        groupBox_down->setTitle(QApplication::translate("ControlUI", "\346\225\260\346\215\256\350\241\245\346\212\204", nullptr));
        DownBtn->setText(QApplication::translate("ControlUI", "\350\241\245\346\212\204\346\225\260\346\215\256", nullptr));
        groupBox_RD->setTitle(QApplication::translate("ControlUI", "\345\256\236\346\227\266\346\225\260\346\215\256", nullptr));
        RDBtn->setText(QApplication::translate("ControlUI", "\351\207\207\351\233\206", nullptr));
        groupBox_QZ->setTitle(QApplication::translate("ControlUI", "\345\217\260\347\253\231\345\217\267", nullptr));
        RQZBtn->setText(QApplication::translate("ControlUI", "\350\257\273\345\217\226\345\217\260\347\253\231\345\217\267", nullptr));
        WQZBtn->setText(QApplication::translate("ControlUI", "\350\256\276\347\275\256\345\217\260\347\253\231\345\217\267", nullptr));
        groupBox_time->setTitle(QApplication::translate("ControlUI", "\350\256\276\345\244\207\346\227\266\351\227\264", nullptr));
        RTimeBtn->setText(QApplication::translate("ControlUI", "\350\257\273\345\217\226\346\227\266\351\222\237", nullptr));
        WTimeBtn->setText(QApplication::translate("ControlUI", "\350\256\276\347\275\256\346\227\266\351\222\237", nullptr));
        groupBox_AC->setTitle(QApplication::translate("ControlUI", "\350\256\276\345\244\207\350\207\252\346\243\200", nullptr));
        AutoCheckBtn->setText(QApplication::translate("ControlUI", "\345\220\257\345\212\250", nullptr));
        groupBox_2->setTitle(QString());
        MinBtn->setText(QApplication::translate("ControlUI", "PushButton", nullptr));
        CloseBtn->setText(QApplication::translate("ControlUI", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ControlUI: public Ui_ControlUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTROLUI_H
