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
	//�߳���������
	extern int systemTime,Date;
	while(!stopped){
		State_trans();
		sleep(1);//ÿ������һ��
		emit newTime(systemTime);
		if(systemTime==0){
			Date++;
			ofstream outfile("Log.txt",ios::app);
			if(!outfile){
				exit(1);
			}
			outfile<<"ģ�����ڣ���"<<Date <<"��"<<endl;
			emit newDate(Date);
		}
	}
}
void transThread::start()		//�߳̿�ʼ����
{
	stopped=false;
	QThread ::start();
}
void transThread::stop()		//�߳�ֹͣ
{
     stopped = true;
}
void Traverser::SetCurFlight()
{
	//���õ�ǰ����
	if(!plan_flight.empty())
		current_f=&plan_flight.front();
	else
		current_f=NULL;
}
void Traverser::ChangeCurFlight()
{
	//�ı䵱ǰ����
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
	//��ǰû�мƻ���������
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
	StatePrint(T);		//��ӡ״̬
	p:systemTime++;
	systemTime%=24;
}


