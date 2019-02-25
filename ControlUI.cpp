#include "ControlUI.h"
#include<QMessageBox>
ControlUI::ControlUI(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	setWindowFlags(Qt::WindowCloseButtonHint | Qt::FramelessWindowHint);
	ui.CloseBtn->setToolTipName(QString::fromLocal8Bit("�ر�"));
	ui.MinBtn->setToolTipName(QString::fromLocal8Bit("��С��"));
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
	//��ȡID
	QString Comm = "ID\r\n";
	QByteArray ba = Comm.toLatin1();
	LPCSTR ch = ba.data();
	int len = Comm.length();
	::send(Socket, ch, len, 0);
}

void ControlUI::on_WIDBtn_clicked()
{
	cmmIndex = 1202;
	//����ID
	QString Comm = "ID," + ui.DevicelineEdit->text().trimmed() + "\r\n";
	QByteArray ba = Comm.toLatin1();
	LPCSTR ch = ba.data();
	int len = Comm.length();
	::send(Socket, ch, len, 0);
}

void ControlUI::on_RQZBtn_clicked()
{
	cmmIndex = 1208;
	//��ȡ��վ��
	QString Comm = "QZ\r\n";
	QByteArray ba = Comm.toLatin1();
	LPCSTR ch = ba.data();
	int len = Comm.length();
	::send(Socket, ch, len, 0);
}

void ControlUI::on_WQZBtn_clicked()
{
	cmmIndex = 1209;
	//������վ��
	QString Comm = "QZ," + ui.QZlineEdit->text().trimmed() + "\r\n";
	QByteArray ba = Comm.toLatin1();
	LPCSTR ch = ba.data();
	int len = Comm.length();
	::send(Socket, ch, len, 0);
}

void ControlUI::on_RTimeBtn_clicked()
{
	cmmIndex = 1203;
	//��ȡʱ��
	QString Comm = "DATETIME\r\n";
	QByteArray ba = Comm.toLatin1();
	LPCSTR ch = ba.data();
	int len = Comm.length();
	::send(Socket, ch, len, 0);
}

void ControlUI::on_WTimeBtn_clicked()
{
	cmmIndex = 1204;
	//����ʱ��
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
	//��ȡʵʱ����
	QString Comm = "READDATA\r\n";
	QByteArray ba = Comm.toLatin1();
	LPCSTR ch = ba.data();
	int len = Comm.length();
	::send(Socket, ch, len, 0);
}

void ControlUI::on_DownBtn_clicked()
{
	cmmIndex = 1207;
	//��������
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
	//�豸�Լ�
	QString Comm = "AUTOCHECK\r\n";
	QByteArray ba = Comm.toLatin1();
	LPCSTR ch = ba.data();
	int len = Comm.length();
	::send(Socket, ch, len, 0);
}

//�豸����ֵ
void ControlUI::setValue(QStringList list)
{
	switch (cmmIndex)
	{
	case 1201://�豸��
	{
		if (list.count() < 1)
			break;
		ui.DevicelineEdit->setText(list.at(0));
		break;
	}
	case 1208://̨վ��
	{
		if (list.count() < 1)
			break;
		ui.QZlineEdit->setText(list.at(0));
		break;
	}
	case 1203://�豸ʱ��
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
			QMessageBox::about(this, QString::fromLocal8Bit("�豸״̬"), QString::fromLocal8Bit("�����ɹ���"));
		}
		else 
		{
			QMessageBox::about(this, QString::fromLocal8Bit("�豸״̬"), QString::fromLocal8Bit("����ʧ�ܣ�"));
		}
	}
		break;
	}
}

