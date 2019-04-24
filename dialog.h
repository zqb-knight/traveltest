#ifndef DIALOG__H
#define DIALOG__H

#include<QDialog>

class QPushButton;
class QRadioButton;
class QLineEdit;
class QLabel;
class QTextEdit; 


class logdialog : public QDialog			//登陆对话框
{
	Q_OBJECT
public:
	logdialog(QWidget *parent=0);
	~logdialog(); 
public slots:
	void accept();						//点击确认按钮
signals:
	void newname(QString name);			//将用户名传给主窗口
private:
    QLineEdit * usrLineEdit;			//用户输入栏
	QLineEdit * pwdLineEdit;			//密码输入栏
};

class strategydialog : public QDialog	//策略选择对话框
{
	Q_OBJECT
public:
	strategydialog(QWidget *parent=0);
	~strategydialog();
public slots:
	void accept();
	void setchoose1();				//选择策略1费用优先
	void setchoose2();				//选择策略2时间优先
	void setchoose3();				//选择策略3限时费用优先
signals:
	void ischosen(bool);
	void choose(int);
	
public:
	QRadioButton *button1;
	QRadioButton *button2;
	QRadioButton *button3;
};
class changedialog : public QDialog		//改变计划对话框
{
	Q_OBJECT 
public:
	changedialog(QWidget *parent,QString qstr);
	~changedialog();
public slots:
	void accept();
	void setchangechoose1();		//改变为策略1
	void setchangechoose2();		//改变为策略2
	void setchangechoose3();		//改变为策略3
signals:
	void changechoose(int);			//选择后的策略
	void change_infor(QString,QString,QString);	//改变计划的有关信息
public:
	QLineEdit *city2Edit;			//改变计划的终点
	QLineEdit *limitEdit;			//改变计划的限定时间
	QLineEdit *cityEdit;			//改变计划的途径城市
	bool pushed;					//是否点击过策略选项
};
class citydialog : public QDialog	//城市对话框
{
	Q_OBJECT 
public:
	citydialog(QWidget *parent,QString name);
	~citydialog();
public:
	int choose;		//城市操作选项
	QString name;	//城市名称
signals:
	void setcity(int,QString);	//点击的城市操作
public slots:
	void setchoose1();			//选项1作为起点
	void setchoose2();			//选项2作为终点
	void setchoose3();			//选项3作为途经城市
	void setchoose4();			//选项4输出该城市路线
	void accept();

};
#endif;