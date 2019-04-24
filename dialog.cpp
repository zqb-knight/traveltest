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
	QLabel *login=new QLabel;				//登陆对话框上的动画显示
	login->resize (250,60);
	QMovie *movie = new QMovie("Image/back.gif");
	movie->setScaledSize(login->size());
	login->setMovie(movie);
	movie->start();

	QLabel *usrLabel;						//用户登录信息模块
	QLabel *pwdLabel;
	usrLabel = new QLabel(QStringLiteral("用户名：")); 
	pwdLabel = new QLabel(QStringLiteral("密 码：")); 
	usrLineEdit = new QLineEdit; 
	pwdLineEdit = new QLineEdit; 
	pwdLineEdit->setEchoMode(QLineEdit::Password); 

	QGridLayout *usrLayout = new QGridLayout;
	usrLayout ->addWidget (login,0,0,1,4);
	usrLayout ->addWidget (usrLabel,1,0,1,1 );
	usrLayout ->addWidget (usrLineEdit ,1,1,1,3);
	usrLayout ->addWidget (pwdLabel ,2,0,1,1);
	usrLayout ->addWidget (pwdLineEdit ,2,1,1,3);
	
	QPushButton *okBtn = new QPushButton(QStringLiteral("确定")); 
	QPushButton *cancelBtn = new QPushButton(QStringLiteral("取消")); 

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

	

	connect(okBtn,SIGNAL(clicked()),this,SLOT(accept()));		//确认操作
	connect(cancelBtn,SIGNAL(clicked()),this,SLOT(reject()));	//取消操作
 
	setWindowTitle(QStringLiteral("旅游模拟登录")); 
	resize(300,200); 
} 
void logdialog::accept() 
{ 
	if (!usrLineEdit->text().isEmpty ()&& !pwdLineEdit->text().isEmpty ()) { 
		//登陆成功
		QString usrname=usrLineEdit->text();
		QDialog::accept(); 
		emit newname(usrname);
	 } 
	 else{ 
		//登陆失败
		QMessageBox::warning(this,QStringLiteral("警告"),QStringLiteral("用户名或密码错误"),QMessageBox::Yes); 
		usrLineEdit->clear (); 
	 } 
} 

logdialog::~logdialog() 
{ 
} 

strategydialog::strategydialog (QWidget *parent)
	:QDialog(parent) 
{
	button1=new QRadioButton (QStringLiteral("费用优先"));
	button2=new QRadioButton (QStringLiteral("时间优先"));
	button3=new QRadioButton (QStringLiteral("限时费用优先"));
	QHBoxLayout *layout=new QHBoxLayout;
	layout->addWidget (button1);
	layout->addWidget (button2);
	layout->addWidget (button3);
	QPushButton *okBtn = new QPushButton(QStringLiteral("确定")); 
	QPushButton *cancelBtn = new QPushButton(QStringLiteral("取消")); 
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

	setWindowTitle (QStringLiteral("策略选择"));
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
	QLabel *city2=new QLabel (QStringLiteral("目的城市"));
	QLabel *city =new QLabel (QStringLiteral("途经城市"));
	QLabel *limit=new QLabel (QStringLiteral("限定时间"));
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

	QRadioButton *button1=new QRadioButton (QStringLiteral("费用优先"));
	QRadioButton *button2=new QRadioButton (QStringLiteral("时间优先"));
	QRadioButton *button3=new QRadioButton (QStringLiteral("限时费用优先"));
	QHBoxLayout *layout=new QHBoxLayout;
	layout->addWidget (button1);
	layout->addWidget (button2);
	layout->addWidget (button3);
	QPushButton *okBtn = new QPushButton(QStringLiteral("确定")); 
	QPushButton *cancelBtn = new QPushButton(QStringLiteral("取消")); 
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

	setWindowTitle (QStringLiteral("计划更改"));
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
	QRadioButton *button1=new QRadioButton (QStringLiteral("作为起点城市"));
	QRadioButton *button2=new QRadioButton (QStringLiteral("作为终点城市"));
	QRadioButton *button3=new QRadioButton (QStringLiteral("作为途经城市"));
	QRadioButton *button4=new QRadioButton (QStringLiteral("查询该城市路线"));
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
	QPushButton *okBtn = new QPushButton(QStringLiteral("确定")); 
	QPushButton *cancelBtn = new QPushButton(QStringLiteral("取消")); 
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
	QString qstr=QString::fromLocal8Bit("城市选项-")+namestr;
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