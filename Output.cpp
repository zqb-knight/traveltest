#include"Variable.h"
#include"Output.h"
#include<iostream>

string toVehicle(VehicleType vehicle)
{
	//��ͨ��ʽ���ַ���
	switch(vehicle)
	{
		case TRAIN: return"��";
		case PLANE: return"�ɻ�";
		case CAR:   return"����"; 
		default:    return"";
	}
}
void usrPrint(Traverser &T)
{
	//�û���¼��Ϣ�ļ����
	struct tm *local;
    time_t t; 
    t=time(NULL);
    local=localtime(&t);
	ofstream outfile("Log.txt",ios::app);
	if(!outfile){
		cout<<"���ļ�����"<<endl;
		exit(1);
	}
	outfile<<local->tm_year+1900<<"��"<<local->tm_mon+1<<"��"<<local->tm_mday<<"�� ";
	outfile<<local->tm_hour<<":"<<local->tm_min<<":"<<local->tm_sec<<" �ͻ���½   ";
	outfile<<"�û�����"<<"   "<<T.GetName()<<endl;
	outfile.close();
	return;
}
void RequirePrint(Traverser &T)
{
	//�ͻ������ļ����
	ofstream outfile("Log.txt",ios::app);
	if(!outfile){
		cout<<"���ļ�����"<<endl;
		exit(1);
	}
	outfile<<"���: "<<T.GetLocation()<<"  �յ�: "<<T.GetDestination()<<endl;
	
}

void ArrivePrint(Traverser &T)			
{
	//������Ϣ�ļ����
	ofstream outfile("Log.txt",ios::app);
	if(!outfile){
		cout<<"���ļ�����"<<endl;
		exit(1);
	}
	extern int systemTime;
	outfile<<"��ǰʱ��:"<<systemTime<<"�ͻ��ִ�Ŀ�ĵ�: "<<T.GetLocation()<<endl;
}

void Flight_Out(Flight *f)
{
	//����ƻ�·�߱�׼���
	cout<<f->tag_transfer;
	cout<<setiosflags(ios::left)<<setw(8)<<f->start_point<<"-";
	cout<<setiosflags(ios::left)<<setw(8)<<f->arrive_point<<":";
	cout<<toVehicle(f->vehicletype)<<" "<<f->flight_name<<"  ";
	cout<<setiosflags(ios::left)<<setw(5)<<f->time_start;
	cout<<setiosflags(ios::left)<<setw(5)<<f->time_arrive;
	cout<<setiosflags(ios::left)<<setw(4)<<f->costtime;
	cout<<setiosflags(ios::left)<<setw(6)<<f->expense<<endl;
}
void FlightPrint(Flight*f)
{
	//����ƻ�·���ļ����
	extern int systemTime;
	ofstream outfile("Log.txt",ios::app);
	if(!outfile){
		cout<<"���ļ�����"<<endl;
		exit(1);
	}
	cout<<"��ǰʱ��:"<<systemTime<<"��ִ�мƻ�:";
	Flight_Out(f);
	outfile<<"��ǰʱ��:"<<systemTime<<"��ִ�мƻ�:";
	outfile<<f->tag_transfer;
	outfile<<setiosflags(ios::left)<<setw(8)<<f->start_point<<"-";
	outfile<<setiosflags(ios::left)<<setw(8)<<f->arrive_point<<":";
	outfile<<toVehicle(f->vehicletype)<<" "<<f->flight_name<<"  ";
	outfile<<setiosflags(ios::left)<<setw(5)<<f->time_start;
	outfile<<setiosflags(ios::left)<<setw(5)<<f->time_arrive;
	outfile<<setiosflags(ios::left)<<setw(4)<<f->costtime;
	outfile<<setiosflags(ios::left)<<setw(6)<<f->expense<<endl;
	outfile.close();
}
void Traverser::AllFlightPrint( )
{
	int num;
	Flight *f;
	ofstream outfile("Log.txt",ios::app);
	if(!outfile){
		cout<<"���ļ�����"<<endl;
		exit(1);
	}
	f=GetPlanFlight(num);
	if(num){
		outfile<<" ���    -�յ�     ��ʽ ���� ���� ���� ��ʱ ����"<<endl;
		for(int i=0;i<num;i++){
			outfile<<f[i].tag_transfer;
			outfile<<setiosflags(ios::left)<<setw(8)<<f[i].start_point<<"-";
			outfile<<setiosflags(ios::left)<<setw(8)<<f[i].arrive_point<<":";
			outfile<<toVehicle(f[i].vehicletype)<<" "<<f[i].flight_name<<"  ";
			outfile<<setiosflags(ios::left)<<setw(5)<<f[i].time_start;
			outfile<<setiosflags(ios::left)<<setw(5)<<f[i].time_arrive;
			outfile<<setiosflags(ios::left)<<setw(4)<<f[i].costtime;
			outfile<<setiosflags(ios::left)<<setw(6)<<f[i].expense<<endl;
			Flight_Out(&f[i]);
		}
	}
	else{
		outfile<<"��Ҫ����;�����У����޷���������·"<<endl;
	}
	outfile.close();
}
void StatePrint(Traverser &T)
{
	//״̬���
	extern int systemTime;
	Flight *f=T.current_f;
	ofstream outfile("Log.txt",ios::app);
	if(!outfile){
		cout<<"���ļ�����"<<endl;
		exit(1);
	}
	cout<<"��ǰʱ��:"<<systemTime;
	outfile<<"��ǰʱ��:"<<systemTime;
	if(T.GetState()==STATIC){
		cout<<"���ڵ�:"<<T.GetLocation()<<endl;
		outfile<<"���ڵ�:"<<T.GetLocation()<<endl;
	}
	else{
		cout<<"��;��:";
		cout<<f->start_point<<"->"<<f->arrive_point<<toVehicle(f->vehicletype)<<f->flight_name<<endl;
		outfile<<f->start_point<<"->"<<f->arrive_point<<" "<<toVehicle(f->vehicletype)<<" "<<f->flight_name<<" "<<T.movetime-1<<endl;
	}
	outfile.close();
}

