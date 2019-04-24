#include"dialog.h"
#include"travelplan.h"
#include <QLineEdit> 
#include <QTextEdit>
#include <QBoxLayout>  
#include <QPushButton>
#include <QRadioButton>
#include <QLabel>
#include <QMessageBox>
#include <QMovie>


logdialog::logdialog(QWidget *parent)  
	:QDialog(parent) 
{
	QLabel *login=new QLabel;				//��½�Ի����ϵĶ�����ʾ
	login->resize (250,60);
	QMovie *movie = new QMovie("Image/back.gif");
	movie->setScaledSize(login->size());
	login->setMovie(movie);
	movie->start();

	QLabel *usrLabel;						//�û���¼��Ϣģ��
	QLabel *pwdLabel;
	usrLabel = new QLabel(QStringLiteral("�û�����")); 
	pwdLabel = new QLabel(QStringLiteral("�� �룺")); 
	usrLineEdit = new QLineEdit; 
	pwdLineEdit = new QLineEdit; 
	pwdLineEdit->setEchoMode(QLineEdit::Password); 

	QGridLayout *usrLayout = new QGridLayout;
	usrLayout ->addWidget (login,0,0,1,4);
	usrLayout ->addWidget (usrLabel,1,0,1,1 );
	usrLayout ->addWidget (usrLineEdit ,1,1,1,3);
	usrLayout ->addWidget (pwdLabel ,2,0,1,1);
	usrLayout ->addWidget (pwdLineEdit ,2,1,1,3);
	
	QPushButton *okBtn = new QPushButton(QStringLiteral("ȷ��")); 
	QPushButton *cancelBtn = new QPushButton(QStringLiteral("ȡ��")); 

	QHBoxLayout *btnLayout = new QHBoxLayout ;
	btnLayout ->setSpacing (50);
	btnLayout ->addWidget (okBtn );
	btnLayout ->addWidget (cancelBtn );

	QVBoxLayout *mainLayout = new QVBoxLayout ;
	mainLayout ->setMargin(30);
	mainLayout ->addLayout (usrLayout );
	mainLayout ->addStretch (40);
	mainLayout ->addLayout (btnLayout );
	setLayout (mainLayout );

	

	connect(okBtn,SIGNAL(clicked()),this,SLOT(accept()));		//ȷ�ϲ���
	connect(cancelBtn,SIGNAL(clicked()),this,SLOT(reject()));	//ȡ������
 
	setWindowTitle(QStringLiteral("����ģ���¼")); 
	resize(300,200); 
} 
void logdialog::accept() 
{ 
	if (!usrLineEdit->text().isEmpty ()&& !pwdLineEdit->text().isEmpty ()) { 
		//��½�ɹ�
		QString usrname=usrLineEdit->text();
		QDialog::accept(); 
		emit newname(usrname);
	 } 
	 else{ 
		//��½ʧ��
		QMessageBox::warning(this,QStringLiteral("����"),QStringLiteral("�û������������"),QMessageBox::Yes); 
		usrLineEdit->clear (); 
	 } 
} 

logdialog::~logdialog() 
{ 
} 

strategydialog::strategydialog (QWidget *parent)
	:QDialog(parent) 
{
	button1=new QRadioButton (QStringLiteral("��������"));
	button2=new QRadioButton (QStringLiteral("ʱ������"));
	button3=new QRadioButton (QStringLiteral("��ʱ��������"));
	QHBoxLayout *layout=new QHBoxLayout;
	layout->addWidget (button1);
	layout->addWidget (button2);
	layout->addWidget (button3);
	QPushButton *okBtn = new QPushButton(QStringLiteral("ȷ��")); 
	QPushButton *cancelBtn = new QPushButton(QStringLiteral("ȡ��")); 
	QHBoxLayout *btnLayout = new QHBoxLayout ;
	btnLayout ->setSpacing (30);
	btnLayout ->addWidget (okBtn );
	btnLayout ->addWidget (cancelBtn );

	QVBoxLayout *mainLayout = new QVBoxLayout ;
	mainLayout ->setMargin(30);
	mainLayout ->addLayout (layout);
	mainLayout ->addStretch (30);
	mainLayout ->addLayout (btnLayout );
	
	setLayout (mainLayout );

	connect(okBtn,SIGNAL(clicked()),this,SLOT(accept())); 
	connect(cancelBtn,SIGNAL(clicked()),this,SLOT(reject())); 
	connect(button1,SIGNAL(clicked()),this,SLOT(setchoose1()));
	connect(button2,SIGNAL(clicked()),this,SLOT(setchoose2()));
	connect(button3,SIGNAL(clicked()),this,SLOT(setchoose3()));

	setWindowTitle (QStringLiteral("����ѡ��"));
	resize(200,120); 
}
void strategydialog ::accept ()
{
	QDialog::accept();
	emit ischosen(true);
}
void strategydialog::setchoose1()
{
	emit choose(1);
}
void strategydialog::setchoose2()
{
	emit choose(2);
}
void strategydialog::setchoose3()
{
	emit choose(3);
}

strategydialog::~strategydialog()
{
}
changedialog::changedialog (QWidget *parent,QString qstr)
	:QDialog(parent) 
{
	QLabel *city2=new QLabel (QStringLiteral("Ŀ�ĳ���"));
	QLabel *city =new QLabel (QStringLiteral(";������"));
	QLabel *limit=new QLabel (QStringLiteral("�޶�ʱ��"));
	city2Edit=new QLineEdit;
	limitEdit=new QLineEdit;
	cityEdit = new QLineEdit;
	city2Edit->setText (qstr);

	QGridLayout *planLayout = new QGridLayout;
	planLayout ->addWidget (city2,0,0,1,1 );
	planLayout ->addWidget (city2Edit ,0,1,1,3);
	planLayout ->addWidget (limit ,1,0,1,1);
	planLayout ->addWidget (limitEdit ,1,1,1,3);
	planLayout ->addWidget (city,3,0,1,1);
	planLayout ->addWidget (cityEdit,3,1,1,3);

	QRadioButton *button1=new QRadioButton (QStringLiteral("��������"));
	QRadioButton *button2=new QRadioButton (QStringLiteral("ʱ������"));
	QRadioButton *button3=new QRadioButton (QStringLiteral("��ʱ��������"));
	QHBoxLayout *layout=new QHBoxLayout;
	layout->addWidget (button1);
	layout->addWidget (button2);
	layout->addWidget (button3);
	QPushButton *okBtn = new QPushButton(QStringLiteral("ȷ��")); 
	QPushButton *cancelBtn = new QPushButton(QStringLiteral("ȡ��")); 
	QHBoxLayout *btnLayout = new QHBoxLayout ;
	btnLayout ->setSpacing (30);
	btnLayout ->addWidget (okBtn );
	btnLayout ->addWidget (cancelBtn );

	QVBoxLayout *mainLayout = new QVBoxLayout ;
	mainLayout ->setMargin(30);
	mainLayout ->addLayout (planLayout );
	mainLayout ->addStretch (60);
	mainLayout ->addLayout (layout);
	mainLayout ->addStretch (40);
	mainLayout ->addLayout (btnLayout );
	
	setLayout (mainLayout );

	connect(okBtn,SIGNAL(clicked()),this,SLOT(accept())); 
	connect(cancelBtn,SIGNAL(clicked()),this,SLOT(reject())); 
	connect(button1,SIGNAL(clicked()),this,SLOT(setchangechoose1()));
	connect(button2,SIGNAL(clicked()),this,SLOT(setchangechoose2()));
	connect(button3,SIGNAL(clicked()),this,SLOT(setchangechoose3()));

	setWindowTitle (QStringLiteral("�ƻ�����"));
	pushed=false;
}
void changedialog ::accept ()
{
	if(pushed){
		QString city_2=city2Edit->text();
		QString city_=cityEdit->text();
		QString limit_=limitEdit->text();
		emit change_infor(city_2,city_,limit_);
	}
	QDialog::accept();
}
void changedialog::setchangechoose1()
{
	pushed=true;
	emit changechoose(1);
}
void changedialog::setchangechoose2()
{
	pushed=true;
	emit changechoose(2);
}
void changedialog::setchangechoose3()
{
	pushed=true;
	emit changechoose(3);
}
changedialog::~changedialog()
{
}

citydialog::citydialog(QWidget *parent,QString namestr)
	:QDialog(parent)
{
	QRadioButton *button1=new QRadioButton (QStringLiteral("��Ϊ������"));
	QRadioButton *button2=new QRadioButton (QStringLiteral("��Ϊ�յ����"));
	QRadioButton *button3=new QRadioButton (QStringLiteral("��Ϊ;������"));
	QRadioButton *button4=new QRadioButton (QStringLiteral("��ѯ�ó���·��"));
	QVBoxLayout *layout=new QVBoxLayout;
	layout->setMargin (20);
	layout->addWidget (button1);
	layout->addSpacing(5);
	layout->addWidget (button2);
	layout->addSpacing(5);
	layout->addWidget (button3);
	layout->addSpacing(5);
	layout->addWidget (button4);
	layout->addSpacing(5);
	QPushButton *okBtn = new QPushButton(QStringLiteral("ȷ��")); 
	QPushButton *cancelBtn = new QPushButton(QStringLiteral("ȡ��")); 
	QHBoxLayout *btnLayout = new QHBoxLayout ;
	btnLayout ->setSpacing (20);
	btnLayout ->addWidget (okBtn );
	btnLayout ->addWidget (cancelBtn );

	QVBoxLayout *mainLayout = new QVBoxLayout ;
	mainLayout ->setMargin(30);
	mainLayout ->addLayout (layout);
	mainLayout ->addSpacing(20);
	mainLayout ->addLayout (btnLayout );
	
	setLayout (mainLayout );

	connect(okBtn,SIGNAL(clicked()),this,SLOT(accept())); 
	connect(cancelBtn,SIGNAL(clicked()),this,SLOT(reject())); 
	connect(button1,SIGNAL(clicked()),this,SLOT(setchoose1()));
	connect(button2,SIGNAL(clicked()),this,SLOT(setchoose2()));
	connect(button3,SIGNAL(clicked()),this,SLOT(setchoose3()));
	connect(button4,SIGNAL(clicked()),this,SLOT(setchoose4()));
	QString qstr=QString::fromLocal8Bit("����ѡ��-")+namestr;
	resize(300,100);
	setWindowTitle (qstr);
	choose =0;
	name=namestr;
}
void citydialog::setchoose1()
{
	choose=1;
}
void citydialog::setchoose2()
{
	choose=2;
}
void citydialog::setchoose3()
{
	choose=3;
}
void citydialog::setchoose4()
{
	choose=4;
}
void citydialog ::accept ()
{
	if(choose){
		emit setcity(choose,name);
	}
	QDialog::accept();
}
citydialog::~citydialog ()
{
}