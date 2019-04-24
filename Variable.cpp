#include"Variable.h"
#include"Output.h"
#include<iostream>
#include<fstream>
#include <sstream>
#include<iomanip>
#include<QString>

ALGraph::ALGraph()		//图的构造函数 
{
	numvex=0;
	for(int i=0;i<MAX_VERTEX_NUM;i++)
		adjList[i].firstarc=NULL; 
}
int ALGraph::LocateVex(VertexType &v)	//得到城市代表的序号 
{
	for(int i=0;i<numvex;i++){
		if(v==adjList[i].vexdata)
			return i;
	}
	return -1;
}
VertexType ALGraph::GetVex(int v)	//得到城市名称 
{
	if(!(v<numvex&&v>=0)){
		cout<<"不存在该顶点";
		exit(1); 
	}
	else
		return adjList[v].vexdata;
}

void ALGraph::Initial()		//图的初始化 
{
	numvex=0;
	numarc=0;
	string cityname,space,cityA,cityB;
	string vehicletype,flight;
	int city1,city2,starttime,arrivetime,costtime,expense;
	float distance;
	bool flag;
	ArcNode *p,*s;
	Flight *f;
	VehicleType vehicle;
	ifstream infile1("city.txt",ios::in);
	if(!(infile1)){
		cout<<"打开文件错误."<<endl;
		exit(1);
	}
	infile1>>cityname;
	adjList[numvex].vexdata=cityname;
	numvex++;
	while(!infile1.eof()){
		infile1>>cityname;
		adjList[numvex].vexdata=cityname;
		numvex++;
	}
	infile1.close();
	ifstream infile;
	infile.open("TimeTable.txt",ios::in);
	if(!(infile)){
		cout<<"打开文件错误."<<endl;
		exit(1);
	}
	getline(infile,space);
	while(!infile.eof()){
		numarc++;
		infile>>cityA>>space>>cityB;
		infile>>vehicletype>>flight;
		infile>>starttime>>arrivetime>>costtime>>expense>>distance;
		Flight *newflight=new Flight;
		newflight->flight_name=flight;
		newflight->tag_transfer=' ';
		newflight->costtime=costtime;
		newflight->expense=expense;
		newflight->start_point=cityA;
		newflight->arrive_point=cityB;
		newflight->time_start=starttime;
		newflight->time_arrive=arrivetime;
		newflight->next_flight=NULL;
		city1=LocateVex(cityA);
		city2=LocateVex(cityB);
		if(adjList[city1].firstarc==NULL){
			ArcNode *q=new ArcNode;
			q->adjvex=city2;
			q->distance=distance;
			q->vehicle.tag[TRAIN]=q->vehicle.tag[PLANE]=q->vehicle.tag[CAR]=false;
			if(vehicletype=="火车"){
				vehicle=TRAIN;
			}
			else if(vehicletype=="飞机"){
				vehicle=PLANE;
			}
			else if(vehicletype=="汽车"){
				vehicle=CAR;
			} 
			q->vehicle.tag[vehicle]=true;
			newflight->vehicletype=vehicle;
			q->vehicle.flight[vehicle]= newflight;
			q->nextarc=NULL; 
			adjList[city1].firstarc=q;
		}
		else{
			p=adjList[city1].firstarc;
		    flag=false;				//标志是否对已有边进行修改 
			while(p){
				if(p->adjvex==city2){
					flag=true;				//对已有边进行修改 
					if(vehicletype=="火车"){
						vehicle=TRAIN;
					}
					else if(vehicletype=="飞机"){
						vehicle=PLANE;
					}
					else if(vehicletype=="汽车"){
						vehicle=CAR;
					} 
					if(p->vehicle.tag[vehicle]==false){
						p->vehicle.tag[vehicle]=true;
						newflight->vehicletype=vehicle;
						p->vehicle.flight[vehicle]=newflight;
					}
					else{
						newflight->vehicletype=vehicle;
						f=p->vehicle.flight[vehicle];
						while(f->next_flight){
							f=f->next_flight;
						}
						f->next_flight=newflight;
					}
					break;
				}
				s=p; 
				p=p->nextarc;
			}
			if(flag==false){
				ArcNode *q=new ArcNode;
				q->adjvex=city2;
				q->distance=distance;
				q->vehicle.tag[TRAIN]=q->vehicle.tag[PLANE]=q->vehicle.tag[CAR]=false;
				if(vehicletype=="火车"){
					vehicle=TRAIN;
				}
				else if(vehicletype=="飞机"){
					vehicle=PLANE;
				}
				else if(vehicletype=="汽车"){
					vehicle=CAR;
				} 
				q->vehicle.tag[vehicle]=true;
				newflight->vehicletype=vehicle;
				q->vehicle.flight[vehicle]= newflight;
				q->nextarc=NULL; 
				s->nextarc=q;
			}
		}
	}
	infile.close();
	Display();
}
void ALGraph::CityDisplay()	//图的城市路线信息输出
{
	string cityname;
	for(int i=0;i<numvex;i++){
		cityname=adjList[i].vexdata;
		cout<<setw(10)<<cityname;
		if((i+1)%5==0)
			cout<<endl;
	}
	cout<<endl;
}
	
void ALGraph::Display()	//图的显示
{
	ArcNode *p;
	Flight *f;
	int type,num=0;
	ofstream outfile("CityRoute.txt",ios::out);
	outfile<<"********************************************************"<<endl;
	for(int i=0;i<numvex;i++){
		p=adjList[i].firstarc;
		while(p){
			cout<<adjList[i].vexdata;
			cout<<"-->"<<adjList[p->adjvex].vexdata<<":";
			cout<<p->distance<<"(里程)"<<endl;
			outfile <<adjList[i].vexdata;
			outfile <<"-->"<<adjList[p->adjvex].vexdata<<":";
			outfile <<p->distance<<"(里程)"<<endl;
			type=0;
			while(type<3){
				if(p->vehicle.tag[type]){ 
					f=p->vehicle.flight[type];
					while(f){
						cout<<f->flight_name<<" "<<toVehicle(f->vehicletype)<<" ";
						cout<<"出发时刻:"<<setw(2)<<f->time_start<<" 到达时刻: "<<setw(2)<<f->time_arrive<<" ";
						cout<<"费用:"<<setw(4)<<f->expense<<" 用时:"<<setw(2)<<f->costtime<<endl;
						outfile <<f->flight_name<<" "<<toVehicle(f->vehicletype)<<" ";
						outfile <<"出发时刻:"<<setw(2)<<f->time_start<<" 到达时刻: "<<setw(2)<<f->time_arrive<<" ";
						outfile <<"费用:"<<setw(4)<<f->expense<<" 用时:"<<setw(2)<<f->costtime<<endl;

						f=f->next_flight ;
						num++;
					}
				}
				type++;
			}
			p=p->nextarc;
			cout<<endl;
			outfile<<endl;
		}
		cout<<"********************************************************"<<endl;
		outfile<<"********************************************************"<<endl;
	}
	cout<<num<<endl;
	outfile<<num<<endl;
	outfile.close();
}
void Traverser::GetQString(QString city1,QString city2,QString city,int choose,QString limittime)
{
	//从界面上得到信息转化
	location =string((const char *)city1.toLocal8Bit());
	destination =string((const char *)city2.toLocal8Bit());
	string str=string((const char *)city.toLocal8Bit());
	string s=string((const char *)limittime.toLocal8Bit());
	GeneratePlan (str,choose,s);
}
void Traverser ::GeneratePlan (string str,int choose,string s )
{
	//根据信息生成计划
	extern ALGraph M;
	extern int systemTime; 
	string city[10];
	bool flag=true;
	stringstream ss(str);
	int i=0,num,limittime;
	while(ss>>city[i]){
		i++;
	}
	num=i;
	if(flag){
		if(M.LocateVex (location )==-1)
			flag=false;
	}
	if(flag){
		if(M.LocateVex (destination  )==-1)
			flag=false;
	}
	for(i=0;i<num;i++){
		if(M.LocateVex (city[i])==-1){
			flag=false;
			break;
		}
	}
	if(choose==3){
		if(s.empty())
			flag=false;
		limittime=atoi(s.c_str());
		if(limittime<=0||limittime>INF)
			flag=false;
	}
	emit isGenerate (flag);
	RequirePrint(*this);
	if(flag){
		PopFlight();
		switch(choose)
		{
		case 1: 
			flag=Strategy_cost(M,systemTime,location,destination,num,city); 
			break; 
		case 2:
			flag=Strategy_time(M,systemTime,location,destination,num,city);
			break; 
		case 3: 
			flag=Strategy_cost_time (M,systemTime,limittime,location,destination,num,city); 
			break; 
		default: break;
		}
		emit success(flag);
	}
}
void Traverser::Change_Strategy(QString city2,QString city_,int choose,QString limit)
{
	//改变计划
	extern ALGraph M;
	extern int systemTime; 
	string city[10];
	string str2=string((const char *)city2.toLocal8Bit());
	string str=string((const char *)city_.toLocal8Bit());
	string s=string((const char *)limit.toLocal8Bit());
	stringstream ss(str);
	int i=0,num,limittime;
	bool flag=true;
	while(ss>>city[i]){
		i++;
	}
	num=i;
	if(flag){
		if(M.LocateVex (str2 )==-1)
			flag=false;
	}
	for(i=0;i<num;i++){
		if(M.LocateVex (city[i])==-1){
			flag=false;
			break;
		}
	}
	if(choose==3&&!s.empty ()){
		limittime=atoi(s.c_str());
		if(limittime<=0||limittime>INF)
			flag=false;
	}
	emit isGenerate (flag);
	string city_1,city_2;
	Flight f;
	int time;
	State state;
	if(flag)
		if(current_f)
			Flight_Assign(f,current_f);
		state=GetState();
		if(state==STATIC){
			time=systemTime;
			city_1=GetLocation();
		}
		else{
			time=f.time_arrive;
			city_1=f.arrive_point;
		}
		city_2=str2;
		PopFlight();
		if(state==MOVE){
			PushFlight(&f); 
		} 
		switch(choose)
		{
			case 1: 
				flag=Strategy_cost(M,time,city_1,city_2,num,city); 
				break; 
			case 2:
				flag=Strategy_time(M,time,city_1,city_2,num,city); 
				break; 
			case 3:  
				flag=Strategy_cost_time (M,systemTime,limittime,city_1,city_2,num,city);  
				break; 
			default: break;
		}
		emit changesucceed(flag);
		if(flag)
			SetCurFlight();
}
QString toQString1(string str )	//字符串转为QString
{
	string s="所在地： ";
	s+=str;
	return QString(QString::fromLocal8Bit(s.c_str ()));
	
}
QString toQstring2(Flight *f)	//字符串转为QString
{
	string s="旅途中：";
	string str;
	s+=f->start_point; s+=" ";
	s+=f->arrive_point;s+=" ";
	s+=toVehicle(f->vehicletype);s+=" ";
	s+=f->flight_name;
	return QString(QString::fromLocal8Bit(s.c_str ()));
}
void Traverser::initial()		//旅客初始化
{
	SetState(); 
	SetCurFlight();
}
void Traverser::Allocate(int IDnum)
{
	string str,space;
	stringstream ss;
	ss<<IDnum;
	ss>>str;
	int len=str.length();
	space=string(5-len,'0');
	str=space+str;
	ID=str;
}
void Traverser::setName(QString qstr)	  //录入旅客姓名 
{	
	string s=string((const char *)qstr.toLocal8Bit().constData());
	name=s;
	usrPrint(*this);
} 
string Traverser::GetName()      //得到旅客姓名 
{ 		return name;} 
string Traverser::GetID()	    //得到旅客ID 
{	return ID;	}
State Traverser::GetState()	   //得到旅客状态 
{	return state;	}
string Traverser::GetLocation()   //得到旅客所在地
{  return location;}
string Traverser::GetDestination()	//得到旅客最终目的地 
{  return destination;	}
string Traverser::GetCurDestination() //得到旅客当前目的地 
{	return curdestination; }
void Traverser::SetLocation(string city)	//设置首次所在地 
{	location=city;	}
void Traverser::SetState()			//设置首次状态 
{	
	state=STATIC;  
	movetime=0;
	emit curstate(toQString1(location));
}
void Traverser::PopFlight()
{
	while(!plan_flight.empty()){
		plan_flight.pop();
	}
}
void Traverser::PushFlight(Flight *f)
{
	Flight flight;
	Flight_Assign(flight,f);
	plan_flight.push(flight); 
}
void Traverser::ChangeState()
{
	if(state==STATIC){ 
		curdestination=current_f->arrive_point;
		emit curstate(toQstring2(current_f));
		state=MOVE;
		
	}
	else{
		location=current_f->arrive_point;
		emit still();
		emit curstate(toQString1(location));
		state=STATIC;
		movetime=0;
		
	} 
} 
void Flight_Assign(Flight &f,Flight*fp)		//航班赋值 
{
	f.vehicletype=fp->vehicletype;
	f.flight_name=fp->flight_name;
	f.tag_transfer=fp->tag_transfer;
	f.start_point=fp->start_point;
	f.arrive_point=fp->arrive_point;
	f.time_start=fp->time_start;
	f.time_arrive=fp->time_arrive;
	f.costtime=fp->costtime;
	f.expense=fp->expense;
	f.next_flight=NULL;
}

Flight* Traverser::GetPlanFlight(int &n)
{
	int i;
	n=plan_flight.size();
	Flight *f=new Flight[n];
	for(i=0;i<n;i++){
		f[i]=plan_flight.front();
		plan_flight.pop();
	}
	for(i=0;i<n;i++){
		plan_flight.push(f[i]); 
	}
	return f;
} 

