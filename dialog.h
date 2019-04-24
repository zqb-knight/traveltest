#ifndef DIALOG__H
#define DIALOG__H

#include<QDialog>

class QPushButton;
class QRadioButton;
class QLineEdit;
class QLabel;
class QTextEdit; 


class logdialog : public QDialog			//��½�Ի���
{
	Q_OBJECT
public:
	logdialog(QWidget *parent=0);
	~logdialog(); 
public slots:
	void accept();						//���ȷ�ϰ�ť
signals:
	void newname(QString name);			//���û�������������
private:
    QLineEdit * usrLineEdit;			//�û�������
	QLineEdit * pwdLineEdit;			//����������
};

class strategydialog : public QDialog	//����ѡ��Ի���
{
	Q_OBJECT
public:
	strategydialog(QWidget *parent=0);
	~strategydialog();
public slots:
	void accept();
	void setchoose1();				//ѡ�����1��������
	void setchoose2();				//ѡ�����2ʱ������
	void setchoose3();				//ѡ�����3��ʱ��������
signals:
	void ischosen(bool);
	void choose(int);
	
public:
	QRadioButton *button1;
	QRadioButton *button2;
	QRadioButton *button3;
};
class changedialog : public QDialog		//�ı�ƻ��Ի���
{
	Q_OBJECT 
public:
	changedialog(QWidget *parent,QString qstr);
	~changedialog();
public slots:
	void accept();
	void setchangechoose1();		//�ı�Ϊ����1
	void setchangechoose2();		//�ı�Ϊ����2
	void setchangechoose3();		//�ı�Ϊ����3
signals:
	void changechoose(int);			//ѡ���Ĳ���
	void change_infor(QString,QString,QString);	//�ı�ƻ����й���Ϣ
public:
	QLineEdit *city2Edit;			//�ı�ƻ����յ�
	QLineEdit *limitEdit;			//�ı�ƻ����޶�ʱ��
	QLineEdit *cityEdit;			//�ı�ƻ���;������
	bool pushed;					//�Ƿ���������ѡ��
};
class citydialog : public QDialog	//���жԻ���
{
	Q_OBJECT 
public:
	citydialog(QWidget *parent,QString name);
	~citydialog();
public:
	int choose;		//���в���ѡ��
	QString name;	//��������
signals:
	void setcity(int,QString);	//����ĳ��в���
public slots:
	void setchoose1();			//ѡ��1��Ϊ���
	void setchoose2();			//ѡ��2��Ϊ�յ�
	void setchoose3();			//ѡ��3��Ϊ;������
	void setchoose4();			//ѡ��4����ó���·��
	void accept();

};
#endif;