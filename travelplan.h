#ifndef TRAVELPLAN_H
#define TRAVELPLAN_H

#include <QtWidgets/QMainWindow>
#include "ui_travelplan.h"

class Flight;

class TravelPlan : public QMainWindow
{
	Q_OBJECT
public:
	TravelPlan(QWidget *parent = 0);
	~TravelPlan();
	QGraphicsScene *scene;
	QLabel *vehicle;
	QString city1,city2,city,limittime;
	QString city_2,city_,limittime_;
	int choose,changechoose;
	
public:
	void SetEnabled(bool);			//生成计划按钮是否有效
	void SetName(QString);			//用户名显示
	void SetChoose();				//设置当前计划策略
	void SetChangeChoose(int);		//需要更改的计划策略
	void GetChange_infor(QString,QString,QString);	//获取更改计划信息并发送
	void IsGenerate(bool);			//当前输入是否符合生成计划
	void success(bool);				//计划是否成功生成
	void changesucceed(bool);		//更改计划信息设置
	void newTime(int);				//设置更新日期
	void newDate(int);				//设置更新时间
	void newState(QString);			//设置更新状态
	void FlightPrint(QString[],int,QString);	//计划航班输出
	void setcity(int,QString);		//城市选项
	void routedisplay(QString);		//城市路线输出
	void paint(int,int,int);		//根据城市和交通方式绘制路线
	void move(Flight *,int);		//每秒钟动画
	void still();					//城市等待或抵达目的地图片显示人物
	void arrive();					//到达城市输出对话框
signals:
	void generate(QString,QString,QString,int,QString);	//生成计划信息
	void changeplan(QString,QString,int,QString);		//更改计划信息
	void exeutive();									//执行系信号
	void wait();										//暂停信号
public slots:
	void on_strategyButton_click();		//策略选择对话框
	void on_planButton_click();			//生成计划
	void on_changeButton_click();		//更改计划对话框
	void on_exeButton_click();			//执行计划
	void on_quitButton_click();			//退出
public slots:
	void on_bjButton_click();
	void on_shhButton_click();
	void on_dlButton_click();
	void on_zhzhButton_click();
	void on_qdButton_click();
	void on_whButton_click();
	void on_chshButton_click();
	void on_shzhButton_click();
	void on_tbButton_click();
	void on_kmButton_click();
	void on_chqButton_click();
	void on_chdButton_click();
	void on_lsButton_click();
	void on_xaButton_click();
	void on_wlmqButton_click();
	void on_hhhtButton_click();
	void on_lzhButton_click();
private:
	Ui::TravelPlanClass ui;
};

#endif // TRAVELPLAN_H
