#include"Variable.h"
#include"Output.h"
#include<iostream>
#include<fstream>
#include <sstream>
#include<iomanip>
#include<QString>

ALGraph::ALGraph()		//ͼ�Ĺ��캯�� 
{
	numvex=0;
	for(int i=0;i<MAX_VERTEX_NUM;i++)
		adjList[i].firstarc=NULL; 
}
int ALGraph::LocateVex(VertexType &v)	//�õ����д������� 
{
	for(int i=0;i<numvex;i++){
		if(v==adjList[i].vexdata)
			return i;
	}
	return -1;
}
VertexType ALGraph::GetVex(int v)	//�õ��������� 
{
	if(!(v<numvex&&v>=0)){
		cout<<"�����ڸö���";
		exit(1); 
	}
	else
		return adjList[v].vexdata;
}

void ALGraph::Initial()		//ͼ�ĳ�ʼ�� 
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
		cout<<"���ļ�����."<<endl;
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
		cout<<"���ļ�����."<<endl;
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
			if(vehicletype=="��"){
				vehicle=TRAIN;
			}
			else if(vehicletype=="�ɻ�"){
				vehicle=PLANE;
			}
			else if(vehicletype=="����"){
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
		    flag=false;				//��־�Ƿ�����б߽����޸� 
			while(p){
				if(p->adjvex==city2){
					flag=true;				//�����б߽����޸� 
					if(vehicletype=="��"){
						vehicle=TRAIN;
					}
					else if(vehicletype=="�ɻ�"){
						vehicle=PLANE;
					}
					else if(vehicletype=="����"){
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
				if(vehicletype=="��"){
					vehicle=TRAIN;
				}
				else if(vehicletype=="�ɻ�"){
					vehicle=PLANE;
				}
				else if(vehicletype=="����"){
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
void ALGraph::CityDisplay()	//ͼ�ĳ���·����Ϣ���
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
	
void ALGraph::Display()	//ͼ����ʾ
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
			cout<<p->distance<<"(���)"<<endl;
			outfile <<adjList[i].vexdata;
			outfile <<"-->"<<adjList[p->adjvex].vexdata<<":";
			outfile <<p->distance<<"(���)"<<endl;
			type=0;
			while(type<3){
				if(p->vehicle.tag[type]){ 
					f=p->vehicle.flight[type];
					while(f){
						cout<<f->flight_name<<" "<<toVehicle(f->vehicletype)<<" ";
						cout<<"����ʱ��:"<<setw(2)<<f->time_start<<" ����ʱ��: "<<setw(2)<<f->time_arrive<<" ";
						cout<<"����:"<<setw(4)<<f->expense<<" ��ʱ:"<<setw(2)<<f->costtime<<endl;
						outfile <<f->flight_name<<" "<<toVehicle(f->vehicletype)<<" ";
						outfile <<"����ʱ��:"<<setw(2)<<f->time_start<<" ����ʱ��: "<<setw(2)<<f->time_arrive<<" ";
						outfile <<"����:"<<setw(4)<<f->expense<<" ��ʱ:"<<setw(2)<<f->costtime<<endl;

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
	//�ӽ����ϵõ���Ϣת��
	location =string((const char *)city1.toLocal8Bit());
	destination =string((const char *)city2.toLocal8Bit());
	string str=string((const char *)city.toLocal8Bit());
	string s=string((const char *)limittime.toLocal8Bit());
	GeneratePlan (str,choose,s);
}
void Traverser ::GeneratePlan (string str,int choose,string s )
{
	//������Ϣ���ɼƻ�
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
	//�ı�ƻ�
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
QString toQString1(string str )	//�ַ���תΪQString
{
	string s="���ڵأ� ";
	s+=str;
	return QString(QString::fromLocal8Bit(s.c_str ()));
	
}
QString toQstring2(Flight *f)	//�ַ���תΪQString
{
	string s="��;�У�";
	string str;
	s+=f->start_point; s+=" ";
	s+=f->arrive_point;s+=" ";
	s+=toVehicle(f->vehicletype);s+=" ";
	s+=f->flight_name;
	return QString(QString::fromLocal8Bit(s.c_str ()));
}
void Traverser::initial()		//�ÿͳ�ʼ��
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
void Traverser::setName(QString qstr)	  //¼���ÿ����� 
{	
	string s=string((const char *)qstr.toLocal8Bit().constData());
	name=s;
	usrPrint(*this);
} 
string Traverser::GetName()      //�õ��ÿ����� 
{ 		return name;} 
string Traverser::GetID()	    //�õ��ÿ�ID 
{	return ID;	}
State Traverser::GetState()	   //�õ��ÿ�״̬ 
{	return state;	}
string Traverser::GetLocation()   //�õ��ÿ����ڵ�
{  return location;}
string Traverser::GetDestination()	//�õ��ÿ�����Ŀ�ĵ� 
{  return destination;	}
string Traverser::GetCurDestination() //�õ��ÿ͵�ǰĿ�ĵ� 
{	return curdestination; }
void Traverser::SetLocation(string city)	//�����״����ڵ� 
{	location=city;	}
void Traverser::SetState()			//�����״�״̬ 
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
void Flight_Assign(Flight &f,Flight*fp)		//���ำֵ 
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

