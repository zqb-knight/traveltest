#include"Variable.h"
#include "State_trans.h"
#include"Output.h"
#include<time.h>


transThread::transThread(QObject *parent) :
    QThread(parent)
{
    stopped = false;
}
void transThread::run()
{
	//线程运行重载
	extern int systemTime,Date;
	while(!stopped){
		State_trans();
		sleep(1);//每秒运行一次
		emit newTime(systemTime);
		if(systemTime==0){
			Date++;
			ofstream outfile("Log.txt",ios::app);
			if(!outfile){
				exit(1);
			}
			outfile<<"模拟日期：第"<<Date <<"天"<<endl;
			emit newDate(Date);
		}
	}
}
void transThread::start()		//线程开始运行
{
	stopped=false;
	QThread ::start();
}
void transThread::stop()		//线程停止
{
     stopped = true;
}
void Traverser::SetCurFlight()
{
	//设置当前航班
	if(!plan_flight.empty())
		current_f=&plan_flight.front();
	else
		current_f=NULL;
}
void Traverser::ChangeCurFlight()
{
	//改变当前航班
	Flight *f;
	extern int systemTime;
	f=&plan_flight.front();
	
	FlightPrint(f);
	f=NULL;
	plan_flight.pop();
	if(!plan_flight.empty()){
		f=&plan_flight.front();
	}
	current_f=f;
 }
bool between(int a,int b,int c)
{
	if((a<=b&&b<c)||(c<a&&b<c)||(c<a&&a<=b))
		return true;
	else
		return false;
}
void State_trans()
{
	extern int systemTime;
	extern Traverser T;
	int arrivetime,starttime;
	//当前没有计划跳出函数
	if(!T.current_f)
		goto p;
	arrivetime=T.current_f->time_arrive;
	starttime=T.current_f->time_start;
	if(systemTime==arrivetime&&T.movetime>=T.current_f->costtime){
		T.ChangeState();
		T.ChangeCurFlight();
		if(!T.current_f){
			StatePrint(T);
			ArrivePrint(T);
			emit T.arrive();
			goto  p;
		}
		arrivetime=T.current_f->time_arrive;
		starttime=T.current_f->time_start;
	}
	if(systemTime==starttime&&T.movetime==0){
		T.ChangeState();
	}
	if(T.GetState()==MOVE){
		emit T.move(T.current_f,T.movetime);
		T.movetime++;
	}
	StatePrint(T);		//打印状态
	p:systemTime++;
	systemTime%=24;
}


