#include "travelplan.h"
#include <QMessageBox>
#include <QPushButton>
#include <QRadioButton>
#include <QLabel>
#include <QLineEdit>
#include <QGridLayout>
#include <QDateTimeEdit>
#include <QGraphicsScene>
#include <QMovie>
#include <QPropertyAnimation>
#include "dialog.h"

#include "Variable.h"
#include <time.h>


float posx[MAX_VERTEX_NUM];		//绘制路线时所用城市横坐标
float posy[MAX_VERTEX_NUM];		//绘制路线时所用城市纵坐标
float pos_x[MAX_VERTEX_NUM];	//移动动画时所用城市横坐标
float pos_y[MAX_VERTEX_NUM];	//移动动画时所用城市纵坐标

TravelPlan::TravelPlan(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	
	//按钮初始化和快捷键设置
	ui.strategyButton->setShortcut (tr("ctrl+S"));
	ui.planButton ->setEnabled (false);
	ui.planButton ->setShortcut(tr("ctrl+return"));
	ui.changehButton->setEnabled (false);
	ui.changehButton->setShortcut(tr("alt+S"));
	ui.exeButton->setEnabled (false);
	ui.exeButton->setShortcut(tr("alt+return"));
	ui.quitButton->setShortcut(tr("ESC"));

	//输出框隐藏
	ui.textFlight->setVisible(false);
	ui.statelabel->setVisible(false);
	ui.textstate->setVisible(false);

	//当前时间设置
	extern int systemTime;
	struct tm *local;
    time_t t; 
    t=time(NULL);
    local=localtime(&t);
	systemTime=local->tm_hour;
	QDate qdate=QDate::currentDate();
	ui.textDate->setText(qdate.toString("yyyy/MM/dd"));
	ui.textdate->setText(("date 1"));
	ui.texttime->setText(QString::number(systemTime)+=":00");
	
	//动画图标
	vehicle=new QLabel(this);
	vehicle->resize(40,50);
	vehicle->setStyleSheet("background:transparent");
	vehicle->setWindowTitle(QStringLiteral("模拟旅行"));
	scene=new QGraphicsScene;
	scene->setSceneRect(QRectF(0, 0, 780, 560));
	ui.graphicsView->setScene(scene);

	//城市坐标根据城市按钮获取
	QPoint p[MAX_VERTEX_NUM];
	p[0]=ui.bjButton->pos();
	p[1]=ui.shhButton->pos();
	p[2]=ui.dlButton->pos();
	p[3]=ui.zhzhButton->pos();
	p[4]=ui.qdButton->pos();
	p[5]=ui.whButton->pos();
	p[6]=ui.chshButton->pos();
	p[7]=ui.shzhButton->pos();
	p[8]=ui.tbButton->pos();
	p[9]=ui.kmButton->pos();
	p[10]=ui.chqButton->pos();
	p[11]=ui.chdButton->pos();
	p[12]=ui.lsButton->pos();
	p[13]=ui.xaButton->pos();
	p[14]=ui.wlmqButton->pos();
	p[15]=ui.lzhButton->pos();
	p[16]=ui.hhhtButton->pos();
	for(int i=0;i<MAX_VERTEX_NUM;i++){
		pos_x[i]=p[i].x()-8;
		pos_y[i]=p[i].y();
		posx[i]=p[i].x();
		posy[i]=p[i].y()+10;
	}
}

TravelPlan::~TravelPlan()
{

}


void TravelPlan::SetName(QString newname)
{
	//用户名显示
	ui.textusr->setText(newname);
}
void TravelPlan::SetEnabled(bool is)
{
	//生成计划按钮是否有效
	ui.planButton->setEnabled (is);
}

void TravelPlan::SetChangeChoose(int n)
{
	//需要更改的计划策略
	changechoose=n;
}
void TravelPlan::SetChoose()
{
	//设置当前计划策略
	choose=changechoose;
	if(choose==1){
		ui.textstrategy->setText(QString::fromLocal8Bit("费用优先"));
	}
	else if(choose==2){
		ui.textstrategy->setText(QString::fromLocal8Bit("时间优先"));
	}
	else{
		ui.textstrategy->setText(QString::fromLocal8Bit("限时费用优先"));
	}
}
void TravelPlan::GetChange_infor(QString qstr2,QString qstr,QString qs)
{
	//获取更改计划信息并发送
	city_2=qstr2;
	city_=qstr;
	limittime_=qs;
	emit changeplan(city_2,city_,changechoose,limittime_);
}
void TravelPlan ::IsGenerate(bool flag)
{
	//当前输入是否符合生成计划
	if(flag){
		scene->clear();
		QMessageBox::information(NULL,QStringLiteral("旅游模拟"),QStringLiteral("生成计划中"));
	}
	else{
		QMessageBox::information(NULL,QStringLiteral("旅游模拟"),QStringLiteral("生成计划失败，输入不符合要求"));
	}
	SetEnabled(false);	//不更改策略不能继续生成计划
}
void TravelPlan::success(bool flag)
{
	//计划是否成功生成
	if(flag){
		vehicle->setVisible(false);
		QMessageBox::information(NULL,QStringLiteral("旅游模拟"),QStringLiteral("生成计划成功"));
		ui.textFlight->setVisible(true);	//输出框显示
		ui.statelabel->setVisible(true);
		ui.textstate->setVisible(true);		
		SetChoose();
		ui.exeButton->setEnabled(true);		//执行计划按钮生效
	}
	else{
		QMessageBox::information(NULL,QStringLiteral("旅游模拟"),QStringLiteral("无符合要求路线"));
	}
}

void TravelPlan::changesucceed(bool flag)
{
	if(flag){
		QMessageBox::information(NULL,QStringLiteral("旅游模拟"),QStringLiteral("生成计划成功"));
		//更改计划信息设置
		city2=city_2;
		city=city_;
		limittime=limittime_;
		ui.lineEdit_2 ->setText(city2);
		ui.lineEdit_3 ->setText(city);
		ui.lineEdit_4 ->setText(limittime);
		ui.textFlight->setVisible(true);
		ui.statelabel->setVisible(true);
		ui.textstate->setVisible(true);
		SetChoose();
		ui.exeButton->setEnabled(true);
	}
	else{
		QMessageBox::information(NULL,QStringLiteral("旅游模拟"),QStringLiteral("无符合要求路线"));
	}
}
void TravelPlan::on_strategyButton_click()
{
	//策略选择对话框
	strategydialog *strategy=new strategydialog;
	strategy->show ();
	connect(strategy,&strategydialog::choose  ,this,&TravelPlan::SetChangeChoose );
	connect(strategy,&strategydialog::ischosen,this,&TravelPlan::SetEnabled );
	connect(strategy,&strategydialog::ischosen,this,&TravelPlan::SetChoose);
}
void TravelPlan::on_planButton_click()
{
	//生成计划
	city1=ui.lineEdit->text ();
	city2=ui.lineEdit_2 ->text ();
	city=ui.lineEdit_3 ->text ();
	limittime=ui.lineEdit_4 ->text ();
	emit wait();	//暂停时间运行
	emit generate(city1,city2,city,choose,limittime);	//发送生成计划所需信息
}
void TravelPlan::on_changeButton_click()
{
	//更改计划对话框
	changedialog *change = new changedialog(NULL,city2);
	change ->show();
	ui.textFlight->setVisible(false);
	emit wait();
	connect(change,&changedialog::changechoose,this,&TravelPlan::SetChangeChoose );
	connect(change,&changedialog::change_infor,this,&TravelPlan::GetChange_infor );
}
void TravelPlan::on_exeButton_click()
{
	extern Traverser T;
	extern ALGraph M ;
	int city;
	//动画图标显示
	vehicle->setStyleSheet("border-image:url(:/picture/conan.png);background:transparent");
	if(T.GetState()==STATIC){
		city=M.LocateVex(T.GetLocation());
	}
	else{
		city=M.LocateVex(T.GetCurDestination());
	}
	QPropertyAnimation *anim=new QPropertyAnimation(vehicle, "pos");
	anim->setDuration(5);
	anim->setStartValue(QPoint(pos_x[city],pos_y[city]));
	anim->setEndValue(QPoint(pos_x[city],pos_y[city]));
	anim->start();
	vehicle->show();

	emit exeutive();//发送执行信号
	ui.exeButton->setEnabled(false);		//执行计划中执行按钮不再有效
	ui.strategyButton->setEnabled(false);	//执行计划中策略选择按钮不再有效
	ui.changehButton->setEnabled(true);		//执行计划中更改计划按钮有效

	
}
void TravelPlan::on_quitButton_click()
{
	//退出
	emit wait();
	this->close();
}

void TravelPlan::setcity(int ch,QString cityname)
{
	QString qstr;
	//城市选项
	switch (ch)
	{
	case 1:	  
		ui.lineEdit->setText(cityname);
		break;
	case 2:
		ui.lineEdit_2->setText(cityname);
		break;
	case 3:
		qstr=ui.lineEdit_3->text();
		qstr+=" ";
		qstr+=cityname;
		ui.lineEdit_3->setText(qstr);
		break;
	case 4:	  
		routedisplay(cityname);
		break;
	default : break;
	}
}

void TravelPlan::newDate(int date)
{
	//设置更新日期
	QString s="date";
	s=s+QString::number(date);
	ui.textdate->setText(s);

}
void TravelPlan::newTime(int time)
{
	//设置更新时间
	ui.texttime->setText(QString::number(time).append(":00"));
}
void TravelPlan::newState(QString state)
{
	//设置更新状态
	ui.textstate->setText(state);
}
void TravelPlan::FlightPrint(QString flight[],int n,QString qstr)
{
	//计划航班输出
	ui.textFlight->setText(QStringLiteral(" 起点-> 终点 方式 车次 出发 到达 用时 费用\n")); 
	for(int i=0;i<n;i++){
		ui.textFlight->append(flight[i]);
	}
	ui.textFlight->append(qstr);
}
void TravelPlan::routedisplay(QString qstr)
{
	//城市路线输出
	QTextEdit *showtext=new QTextEdit();
	extern ALGraph M;
	int i,type;
	ArcNode *p;
	Flight *f;
	string str,s;
	QString Qstr,Qs;
	string cityname=string((const char *)qstr.toLocal8Bit());
	i=M.LocateVex(cityname);
	p=M.adjList[i].firstarc;
	while(p){
		str=M.adjList[i].vexdata;
		str+="-->";
		str+=M.adjList[p->adjvex].vexdata;
		str+=":";
		str+=string((const char*)QString::number(p->distance).toLocal8Bit());
		str+="(里程/千米)";
		Qstr=QString(QString::fromLocal8Bit(str.c_str()));
		showtext->append(Qstr);
		type=0;
		while(type<3){
			if(p->vehicle.tag[type]){ 
				f=p->vehicle.flight[type];
				while(f){
					str=f->flight_name; str+=" ";
					str+=toVehicle(f->vehicletype);  str+=" ";
					str+="出发时刻:";
					s=string((const char*)QString::number(f->time_start).toLocal8Bit());
					str+=s; str+="   ";
					if(s.length()<2)
						str+=" ";
					str+=" 到达时刻: ";
					s=string((const char*)QString::number(f->time_arrive).toLocal8Bit());
					str+=s; str+="   ";
					if(s.length()<2)
						str+=" ";
					str+="费用:";
					s=string((const char*)QString::number(f->expense).toLocal8Bit());
					str+=s; str+="  ";
					if(s.length()<2)
						str+=" ";
					str+=" 用时:";
					s=string((const char*)QString::number(f->costtime).toLocal8Bit());
					str+=s; 
		
					Qstr=QString(QString::fromLocal8Bit(str.c_str ()));
					showtext->append(Qstr);
					f=f->next_flight ;
			
				}
			}
			type++;
		}
		p=p->nextarc; 
		showtext->append("\n");
	}
	showtext->resize(400,300);
	Qs=qstr+QString::fromLocal8Bit("路线");
	showtext->setWindowTitle (Qs);
	showtext->show();
}

void TravelPlan::paint(int city1,int city2,int type)
{
	//根据城市和交通方式绘制路线
	QPen pen;
	pen.setWidth(3);
	if(type==TRAIN){
		pen.setColor(Qt::green);
	}
	else if(type==PLANE){
		pen.setColor(Qt::blue);
	}
	else{
		pen.setColor(Qt::red);
	}
	scene->addLine(posx[city1],posy[city1],posx[city2],posy[city2],pen);
}
void TravelPlan::move(Flight *f,int movetime)
{
	//每秒钟动画
	extern ALGraph M;
	int city1,city2,time;
	int x1,y1,x2,y2;

	city1=M.LocateVex(f->start_point);
	city2=M.LocateVex(f->arrive_point);
	VehicleType type=f->vehicletype;
	time=f->costtime;

	if(type==TRAIN){
		vehicle->setStyleSheet("border-image:url(:/picture/train.png);background:transparent");
	}
	else if(type==PLANE){
		vehicle->setStyleSheet("border-image:url(:/picture/plane.png);background:transparent");
	}
	else{
		vehicle->setStyleSheet("border-image:url(:/picture/car.png);background:transparent");
	}
	x1=pos_x[city1]+(pos_x[city2]-pos_x[city1])/time*movetime;
	x2=pos_x[city1]+(pos_x[city2]-pos_x[city1])/time*(movetime+1);
	y1=pos_y[city1]+(pos_y[city2]-pos_y[city1])/time*movetime;
	y2=pos_y[city1]+(pos_y[city2]-pos_y[city1])/time*(movetime+1);
	QPropertyAnimation *anim=new QPropertyAnimation(vehicle, "pos");
	anim->setDuration(1000);
	anim->setStartValue(QPoint(x1,y1));
	anim->setEndValue(QPoint(x2,y2));
	anim->start();
	vehicle->show();
	
}
void TravelPlan::arrive()
{
	//到达城市输出对话框
	ui.strategyButton->setEnabled(true);
	vehicle->setStyleSheet("border-image:url(:/picture/conan.png);background:transparent");
	extern int systemTime;
	QString qstr=QString::number((systemTime+24)%25);
	qstr=qstr+QStringLiteral("点抵达目的地");
	QMessageBox::information(NULL,QStringLiteral("旅游模拟"),qstr);
}
void TravelPlan::still()
{
	//城市等待或抵达目的地图片显示人物
	vehicle->setStyleSheet("border-image:url(:/picture/conan.png);background:transparent");
}
void TravelPlan::on_bjButton_click()
{
	citydialog *city=new citydialog(NULL,ui.bjButton->text());
	city->show();
	connect(city,&citydialog::setcity,this,&TravelPlan::setcity);
}
void TravelPlan::on_shhButton_click()
{
	citydialog *city=new citydialog(NULL,ui.shhButton->text());
	city->show();
	connect(city,&citydialog::setcity,this,&TravelPlan::setcity);
}
void TravelPlan::on_dlButton_click()
{
	citydialog *city=new citydialog(NULL,ui.dlButton->text());
	city->show();
	connect(city,&citydialog::setcity,this,&TravelPlan::setcity);	
}
void TravelPlan::on_zhzhButton_click()
	{
	citydialog *city=new citydialog(NULL,ui.zhzhButton->text());
	city->show();
	connect(city,&citydialog::setcity,this,&TravelPlan::setcity);	
}
void TravelPlan::on_qdButton_click()
{
	citydialog *city=new citydialog(NULL,ui.qdButton->text());
	city->show();
	connect(city,&citydialog::setcity,this,&TravelPlan::setcity);	
}
void TravelPlan::on_whButton_click()
{
	citydialog *city=new citydialog(NULL,ui.whButton->text());
	city->show();
	connect(city,&citydialog::setcity,this,&TravelPlan::setcity);	
}
void TravelPlan::on_chshButton_click()
{
	citydialog *city=new citydialog(NULL,ui.chshButton->text());
	city->show();
	connect(city,&citydialog::setcity,this,&TravelPlan::setcity);	
}
void TravelPlan::on_shzhButton_click()
{
	citydialog *city=new citydialog(NULL,ui.shzhButton->text());
	city->show();
	connect(city,&citydialog::setcity,this,&TravelPlan::setcity);	
}
void TravelPlan::on_tbButton_click()
{
	citydialog *city=new citydialog(NULL,ui.tbButton->text());
	city->show();
	connect(city,&citydialog::setcity,this,&TravelPlan::setcity);	
}
void TravelPlan::on_kmButton_click()
{
	citydialog *city=new citydialog(NULL,ui.kmButton->text());
	city->show();
	connect(city,&citydialog::setcity,this,&TravelPlan::setcity);	
}
void TravelPlan::on_chqButton_click()
{
	citydialog *city=new citydialog(NULL,ui.chqButton->text());
	city->show();
	connect(city,&citydialog::setcity,this,&TravelPlan::setcity);	
}
void TravelPlan::on_chdButton_click()
{
	citydialog *city=new citydialog(NULL,ui.chdButton->text());
	city->show();
	connect(city,&citydialog::setcity,this,&TravelPlan::setcity);	
}
void TravelPlan::on_lsButton_click()
{
	citydialog *city=new citydialog(NULL,ui.lsButton->text());
	city->show();
	connect(city,&citydialog::setcity,this,&TravelPlan::setcity);	
}
void TravelPlan::on_xaButton_click()
{
	citydialog *city=new citydialog(NULL,ui.xaButton->text());
	city->show();
	connect(city,&citydialog::setcity,this,&TravelPlan::setcity);	
}
void TravelPlan::on_wlmqButton_click()
{
	citydialog *city=new citydialog(NULL,ui.wlmqButton->text());
	city->show();
	connect(city,&citydialog::setcity,this,&TravelPlan::setcity);	
}
void TravelPlan::on_hhhtButton_click()
{
	citydialog *city=new citydialog(NULL,ui.hhhtButton->text());
	city->show();
	connect(city,&citydialog::setcity,this,&TravelPlan::setcity);	
}
void TravelPlan::on_lzhButton_click()
{
	citydialog *city=new citydialog(NULL,ui.lzhButton->text());
	city->show();
	connect(city,&citydialog::setcity,this,&TravelPlan::setcity);	
}