#include"Variable.h"
#include"Output.h"
#include<iostream>

string toVehicle(VehicleType vehicle)
{
	//交通方式的字符串
	switch(vehicle)
	{
		case TRAIN: return"火车";
		case PLANE: return"飞机";
		case CAR:   return"汽车"; 
		default:    return"";
	}
}
void usrPrint(Traverser &T)
{
	//用户登录信息文件输出
	struct tm *local;
    time_t t; 
    t=time(NULL);
    local=localtime(&t);
	ofstream outfile("Log.txt",ios::app);
	if(!outfile){
		cout<<"打开文件错误"<<endl;
		exit(1);
	}
	outfile<<local->tm_year+1900<<"年"<<local->tm_mon+1<<"月"<<local->tm_mday<<"日 ";
	outfile<<local->tm_hour<<":"<<local->tm_min<<":"<<local->tm_sec<<" 客户登陆   ";
	outfile<<"用户名："<<"   "<<T.GetName()<<endl;
	outfile.close();
	return;
}
void RequirePrint(Traverser &T)
{
	//客户需求文件输出
	ofstream outfile("Log.txt",ios::app);
	if(!outfile){
		cout<<"打开文件错误"<<endl;
		exit(1);
	}
	outfile<<"起点: "<<T.GetLocation()<<"  终点: "<<T.GetDestination()<<endl;
	
}

void ArrivePrint(Traverser &T)			
{
	//到达信息文件输出
	ofstream outfile("Log.txt",ios::app);
	if(!outfile){
		cout<<"打开文件错误"<<endl;
		exit(1);
	}
	extern int systemTime;
	outfile<<"当前时间:"<<systemTime<<"客户抵达目的地: "<<T.GetLocation()<<endl;
}

void Flight_Out(Flight *f)
{
	//航班计划路线标准输出
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
	//航班计划路线文件输出
	extern int systemTime;
	ofstream outfile("Log.txt",ios::app);
	if(!outfile){
		cout<<"打开文件错误"<<endl;
		exit(1);
	}
	cout<<"当前时间:"<<systemTime<<"已执行计划:";
	Flight_Out(f);
	outfile<<"当前时间:"<<systemTime<<"已执行计划:";
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
		cout<<"打开文件错误"<<endl;
		exit(1);
	}
	f=GetPlanFlight(num);
	if(num){
		outfile<<" 起点    -终点     方式 车次 出发 到达 用时 费用"<<endl;
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
		outfile<<"若要经过途径城市，则无符合条件线路"<<endl;
	}
	outfile.close();
}
void StatePrint(Traverser &T)
{
	//状态输出
	extern int systemTime;
	Flight *f=T.current_f;
	ofstream outfile("Log.txt",ios::app);
	if(!outfile){
		cout<<"打开文件错误"<<endl;
		exit(1);
	}
	cout<<"当前时间:"<<systemTime;
	outfile<<"当前时间:"<<systemTime;
	if(T.GetState()==STATIC){
		cout<<"所在地:"<<T.GetLocation()<<endl;
		outfile<<"所在地:"<<T.GetLocation()<<endl;
	}
	else{
		cout<<"旅途中:";
		cout<<f->start_point<<"->"<<f->arrive_point<<toVehicle(f->vehicletype)<<f->flight_name<<endl;
		outfile<<f->start_point<<"->"<<f->arrive_point<<" "<<toVehicle(f->vehicletype)<<" "<<f->flight_name<<" "<<T.movetime-1<<endl;
	}
	outfile.close();
}

