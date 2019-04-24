#include"Variable.h"
#include"Output.h"
#include<iostream>
#include<stack>
#include<sstream>

Flight* ALGraph::min_cost(ArcNode*p,int time,int &cost)
{
	//得到两个直达城市间最少费用的方式
	int mincost=INF;
	int mincosttime,costtime;
	int type=0;
	Flight *f,*min_f;
	while(type<3){ 
		if(p->vehicle.tag[type]){
			f=p->vehicle.flight[type];
			//找出该交通方式最早出发的班次
			while(f){
				if(f->expense<mincost){
					mincost=cost=f->expense;
					min_f=f;
					if(min_f->time_start-time<0){
						mincosttime=min_f->time_start+24-time+min_f->costtime;
					}
					else{
						mincosttime=min_f->time_start-time+min_f->costtime;
					}
				}
				else if(f->expense==mincost){
					if(f->time_start-time<0){
						costtime=f->time_start+24-time+f->costtime;
					}
					else{
						costtime=f->time_start-time+f->costtime;
					}
					if(costtime<mincosttime){
						mincosttime=costtime; 
						min_f=f;
					}
					 
				}
				f=f->next_flight;
			} 
		}
		type++;
	} 
	return min_f;
}
int ALGraph::Path_min_cost(int v1,int v2,int systemTime,queue<Flight> &plan_flight)
{
	//两个城市之间最少花费策略的路线	
	bool visited[MAX_VERTEX_NUM];
	int pre[MAX_VERTEX_NUM];
	int Dis[MAX_VERTEX_NUM];
	Flight flight[MAX_VERTEX_NUM],*min_f;
	ArcNode *p;
	int currentcost,time;
	int min,n=numvex;
	int i,j;
	int w;
	if(v1==v2)
		return 0; 
	time=systemTime;
	for(i=0;i<n;i++){
		visited[i]=false;
		Dis[i]=INF;
		pre[i]=v1;
	}
	p=adjList[v1].firstarc;
	while(p){
		min_f=min_cost(p,time,currentcost);
		Dis[p->adjvex]=currentcost;
		Flight_Assign(flight[p->adjvex],min_f);
		p=p->nextarc;
	}
	visited[v1]=true;
	Dis[v1]=0;
	for(i=1;i<n;i++){
		min=INF;
		//找余下城市中权值最少的城市
		for(j=0;j<n;j++){
			if(!visited[j]&&Dis[j]<min){
				w=j;min=Dis[j];
			}
		}
		visited[w]=true;	//标记改城市已访问
		p=adjList[w].firstarc;
		while(p){
			//将该城市作为中转点更改余下城市权值
			if(!visited[p->adjvex]){
				time=flight[w].time_arrive;
				min_f=min_cost(p,time,currentcost);
				if(min+currentcost<Dis[p->adjvex]){
					Dis[p->adjvex]=currentcost+min;
					Flight_Assign(flight[p->adjvex],min_f);	//记录到达该城市的航班
					pre[p->adjvex]=w;			//记录该城市的上一个城市
				}
			}
			p=p->nextarc;
		}
	}
	//用栈逆序输出路线
	stack<int>s;
	int prev;
	int u2=v2;
	while(u2!=v1){
		s.push(u2);
		u2=pre[u2]; 
	}
	s.push(u2);
	prev=s.top();
	s.pop();
	if(!s.empty()){
		flight[s.top()].tag_transfer='@';
	}
	while(!s.empty()){
		prev=s.top();
		plan_flight.push(flight[prev]);
		s.pop();
	}
	return Dis[v2];
}
 

Flight* ALGraph::min_time(ArcNode*p,int time,int &cost_time)
{
	//得到两个直达城市最早到达后者方式
	int mintime=INF,costtime;
	int type=0;
	Flight *f,*min_f;
	while(type<3){ 
		if(p->vehicle.tag[type]){
			f=p->vehicle.flight[type];
			while(f){ 
				if(f->time_start-time<0){
					costtime=f->time_start+24-time+f->costtime;
				}
				else{
					costtime=f->time_start-time+f->costtime;
				}
				if(costtime<mintime){
					cost_time=mintime=costtime;
					min_f=f;
				}
				else if((costtime==mintime)&&(f->expense<min_f->expense)){
					min_f=f;
				} 
				f=f->next_flight;
			} 
		}
		type++;
	}
	return min_f;
}
int ALGraph::Path_min_time(int v1,int v2,int systemTime,queue<Flight> &plan_flight)
{
	//两个城市之间最少时间策略的路线
	bool visited[MAX_VERTEX_NUM];
	int pre[MAX_VERTEX_NUM];
	int Dis[MAX_VERTEX_NUM];
	Flight flight[MAX_VERTEX_NUM],*min_f;
	ArcNode *p;
	int currentcost,time;
	int min,n=numvex;
	int i,j;
	int w;
	if(v1==v2)
		return 0; 
	time=systemTime;
	for(i=0;i<n;i++){
		visited[i]=false;
		Dis[i]=INF;
		pre[i]=v1;
	}
	p=adjList[v1].firstarc;
	while(p){
		min_f=min_time(p,time,currentcost);
		Dis[p->adjvex]=currentcost;
		Flight_Assign(flight[p->adjvex],min_f);
		p=p->nextarc;
	} 
	visited[v1]=true;
	Dis[v1]=0;
	for(i=1;i<n;i++){
		min=INF;
		for(j=0;j<n;j++){
			if(!visited[j]&&Dis[j]<min){
				w=j;min=Dis[j];
			}
		}
		visited[w]=true;
		p=adjList[w].firstarc;
		while(p){
			if(!visited[p->adjvex]){
				time=flight[w].time_arrive;
				min_f=min_time(p,time,currentcost);
				if(min+currentcost<Dis[p->adjvex]){
					Dis[p->adjvex]=currentcost+min;
					Flight_Assign(flight[p->adjvex],min_f);
					pre[p->adjvex]=w;
				}
			}
			p=p->nextarc;
		}
	}
	stack<int>s;
	int prev;
	int u2=v2;
	while(u2!=v1){
		s.push(u2);
		u2=pre[u2]; 
	}
	s.push(u2);
	prev=s.top();
	s.pop();
	if(!s.empty()){
		flight[s.top()].tag_transfer='@';
	}
	while(!s.empty()){
		prev=s.top();
		plan_flight.push(flight[prev]);
		s.pop();
	}
	return Dis[v2];
}
void toQString(Flight flight[],int n,QString qstr[])
{
	//将航班计划信息转成QString
	stringstream ss;
	string *str=new string[n];
	string s;
	for(int i=0;i<n;i++){
		str[i]=flight[i].tag_transfer;
		str[i]+=flight[i].start_point;
		if(flight[i].start_point.length()<5)
			str[i]+=" ";
		str[i]+="->";
		if(flight[i].arrive_point.length()<5)
			str[i]+="";
		str[i]+=flight[i].arrive_point; 
		str[i]+=":";
		str[i]+=toVehicle(flight[i].vehicletype); str[i]+="";
		str[i]+=flight[i].flight_name; str[i]+="  ";
		ss.str("");
		ss<<flight[i].time_start;
		s=ss.str(); str[i]+=s; str[i]+="   ";
		if(s.length()<2)
			str[i]+=" ";
		ss.str("");
		ss<<flight[i].time_arrive;
		s=ss.str(); str[i]+=s; str[i]+="   ";
		if(s.length()<2)
			str[i]+=" ";
		ss.str("");
		ss<<flight[i].costtime; 
		s=ss.str(); str[i]+=s; str[i]+="  ";
		if(s.length()<2)
			str[i]+=" ";
		ss.str("");
		ss<<flight[i].expense;
		s=ss.str(); str[i]+=s; 
		
		qstr[i]=QString(QString::fromLocal8Bit(str[i].c_str ()));
	}
}
 
bool Traverser::Strategy_cost(ALGraph &G,int time,VertexType &city1,VertexType &city2,int n,VertexType city[]) 
{
	//最小费用策略 
	int i;
	int *v;
	int cur_time=time;
	Flight fl;
	destination=city2;
	int expense;
	v=new int[n+2];
	v[0]=G.LocateVex(city1);
	v[n+1]=G.LocateVex(city2);
	for(i=1;i<n+1;i++){
		v[i]=G.LocateVex(city[i-1]);
	}
	expense=G.Path_min_cost(v[0],v[1],time,plan_flight);
	//在必经城市间分段调用最少费用策略
	for(i=1;i<n+1;i++){
		fl=plan_flight.back();
		time=fl.time_arrive;
		expense+=G.Path_min_cost(v[i],v[i+1],time,plan_flight);
	}
	AllFlightPrint();		//旅客计划文件和标准输出
	int n;
	int spendtime=0;
	int city_start,city_arrive;
	Flight *flight=GetPlanFlight(n);
	for(i=0;i<n;i++){
		if(flight[i].time_start-cur_time<0){
			spendtime+=flight[i].time_start+24-cur_time+flight[i].costtime;
			cur_time=flight[i].time_arrive;
		}
		else{
			spendtime+=flight[i].time_start-cur_time+flight[i].costtime;
			cur_time=flight[i].time_arrive;
		}
		city_start=G.LocateVex(flight[i].start_point);
		city_arrive=G.LocateVex(flight[i].arrive_point);
		emit route(city_start,city_arrive,flight[i].vehicletype);	//发送路线绘制信息
	}
	ofstream outfile("Log.txt",ios::app);
	if(!outfile){
		cout<<"打开文件错误"<<endl;
		exit(1);
	}
	outfile<<"总费用："<<expense<<"   总用时："<<spendtime<<endl<<endl;
	cout<<"总费用："<<expense<<"   总用时："<<spendtime<<endl<<endl;
	outfile.close();
	QString *qstr=new QString[n];
	toQString(flight,n,qstr);
	stringstream ss;
	string str="总花费:",s;
	ss.str("");
	ss<<expense;
	s=ss.str();
	str+=s;
	str+="    总用时:";
	ss.str("");
	ss<<spendtime;
	s=ss.str();
	str+=s;
	QString qstr1=QString(QString::fromLocal8Bit(str.c_str ()));
	emit PrintFlight(qstr,n,qstr1);			//发送航班计划打印信息
	delete []v;
	return true;
}
bool Traverser::Strategy_time(ALGraph &G,int time,VertexType &city1,VertexType &city2,int n,VertexType city[])
{
	//最短时间策略 
	int i;
	int *v;
	Flight fl;
	destination=city2;
	int spendtime; 
	v=new int[n+2];
	v[0]=G.LocateVex(city1);
	v[n+1]=G.LocateVex(city2);
	for(i=1;i<n+1;i++){
		v[i]=G.LocateVex(city[i-1]);
	}
	spendtime=G.Path_min_time (v[0],v[1],time,plan_flight);
	//在必经城市间分段调用最少时间策略
	for(i=1;i<n+1;i++){
		fl=plan_flight.back();
		time=fl.time_arrive;
		spendtime+=G.Path_min_time(v[i],v[i+1],time,plan_flight);
	}
	AllFlightPrint();
	int n;
	int city_start,city_arrive;
	int expense=0;
	Flight *flight=GetPlanFlight(n);
	for(i=0;i<n;i++){
		expense+=flight[i].expense;
		city_start=G.LocateVex(flight[i].start_point);
		city_arrive=G.LocateVex(flight[i].arrive_point);
		emit route(city_start,city_arrive,flight[i].vehicletype);	//发送路线绘制信息
	}
	ofstream outfile("Log.txt",ios::app);
	if(!outfile){
		cout<<"打开文件错误"<<endl;
		exit(1);
	}
	outfile<<"总时间："<<spendtime<<"   总花费："<<expense<<endl<<endl;
	cout<<"总时间："<<spendtime<<"   总花费："<<expense<<endl<<endl;
	outfile.close();
	QString *qstr=new QString[n];
	toQString(flight,n,qstr);		
	stringstream ss;
	string str="总用时:",s;
	ss.str("");
	ss<<spendtime;
	s=ss.str();
	str+=s;
	str+="    总花费:";
	ss.str("");
	ss<<expense;
	s=ss.str();
	str+=s;
	QString qstr1=QString(QString::fromLocal8Bit(str.c_str ()));
	emit PrintFlight(qstr,n,qstr1);				//发送航班计划打印信息
	delete []v;
	return true;
}
int ALGraph::Path_mintime(int v1,int v2,int systemTime)
{
	//两个城市之间最少时间
	bool visited[MAX_VERTEX_NUM];
	int pre[MAX_VERTEX_NUM];
	int Dis[MAX_VERTEX_NUM];
	Flight flight[MAX_VERTEX_NUM],*min_f;
	ArcNode *p;
	int currentcost,time;
	int min,n=numvex;
	int i,j;
	int w;
	if(v1==v2)
		return 0; 
	time=systemTime;
	for(i=0;i<n;i++){
		visited[i]=false;
		Dis[i]=INF;
	}
	p=adjList[v1].firstarc;
	while(p){
		min_f=min_time(p,time,currentcost);
		Dis[p->adjvex]=currentcost;
		Flight_Assign(flight[p->adjvex],min_f);
		p=p->nextarc;
	} 
	visited[v1]=true;
	Dis[v1]=0;
	for(i=1;i<n;i++){
		min=INF;
		for(j=0;j<n;j++){
			if(!visited[j]&&Dis[j]<min){
				w=j;min=Dis[j];
			}
		}
		visited[w]=true;
		p=adjList[w].firstarc;
		while(p){
			if(!visited[p->adjvex]){
				time=flight[w].time_arrive;
				min_f=min_time(p,time,currentcost);
				if(min+currentcost<Dis[p->adjvex]){
					Dis[p->adjvex]=currentcost+min;
					Flight_Assign(flight[p->adjvex],min_f);
				}
			}
			p=p->nextarc;
		}
	}
	return Dis[v2];
}
int limit_time,spend,mincost,num_flight;
int num1;

void ALGraph::Path_cost_time(int v1,int v2,int v[],int n,int time,int spend_time,int cost,int num2,Flight flight[][MAX_VERTEX_NUM-1],bool arrived[])
{
	//剪枝递归
	if(spend_time>limit_time)	//所用时间超过限制时间返回
		return; 
	if(cost>mincost)			//已用金钱大于当前最优计划总花费返回
		return;
	if(v1==v2){
		//抵达目的地
		//判断当前计划是否经过需途径城市
		if(JudgeVia(&v[1],n,flight[num1],num2)){
			//若经过所途径城市且费用小于当前最优计划或费油相等但用时短改变最优计划
			if((cost<mincost)||(cost==mincost&&spend_time<spend)){
				spend=spend_time;
				mincost=cost;
				num_flight=num2;
				
				if(num1==1){
					//将当前计划赋值给最优计划flight[0];
					for(int i=0;i<num2;i++)
						Flight_Assign(flight[num1-1][i],&flight[num1][i]);
				}
				else{
					//若是第一个符合条件的计划,将计划赋值给缓存计划flight[1];
					num1=1;
					for(int i=0;i<num2;i++)
						Flight_Assign(flight[num1][i],&flight[num1-1][i]);
				}
			}
		}
		return;
	}
	int mintime=Path_mintime(v1,v2,time);
	if((spend_time+mintime)>limit_time)	//若当前已用时间加上该城市到终点最少用时大于限制时间返回
		return;
	ArcNode*p;
	Flight *f,*min_f;
	p=adjList[v1].firstarc;
	int costtime,mincosttime;
	while(p){
		//遍历所有与该城市邻近的最早出发的航班
		for(int i=0;i<3;i++){
			if(arrived[p->adjvex])	//若下一个城市已经经过则跳出循环
				break;
			if(p->vehicle.tag[i]){
				f=p->vehicle.flight[i];
				mincosttime=INF;
				//找出该交通方式最早出发的班次
				while(f){
					if(f->time_start-time<0){
						costtime=f->time_start+24-time+f->costtime;
					}
					else{
						costtime=f->time_start-time+f->costtime;
					}
					if(costtime<mincosttime){
						mincosttime=costtime;   
						min_f=f;
					}
					f=f->next_flight;
				}
				Flight_Assign(flight[num1][num2],min_f);
				arrived[p->adjvex]=true;	//将当前城市下一个城市设为已经过
				//深度遍历下一个城市
				Path_cost_time(p->adjvex,v2,v,n,(time+mincosttime)%24,(mincosttime+spend_time),(cost+min_f->expense),num2+1,flight,arrived);
				arrived[p->adjvex]=false;	//将当前城市的下一个城市设为未经过
			} 
		}		
		p=p->nextarc;
	}
}
int ALGraph::JudgeVia(int v[],int n,Flight flight[MAX_VERTEX_NUM-1],int flight_num)
{
	//判断计划是否经过所有必经城市
	int i,city;
	int arrived[MAX_VERTEX_NUM];
	
	for(i=0;i<n;i++){
		city=v[i];
		arrived[city]=0;
	}
	for(i=0;i<flight_num;i++){
		city=LocateVex(flight[i].start_point);
		if(!arrived[city]){
			arrived[city]=1;
			flight[i].tag_transfer='@';		//标志着中转城市
		}
	}
	for(i=0;i<n;i++){
		if(!arrived[v[i]])	//若必经城市没有经过则返回
			return 0;
	}
	return 1;
} 

bool Traverser::Strategy_cost_time(ALGraph &G,int time,int limittime,VertexType &city1,VertexType &city2,int n,VertexType city[])
{
	//限时费用最少策略 
	int i,j;
	int num2=0;
	int spend_time=0,cost=0;
	int *v;
	bool flag;
	Flight flight[2][MAX_VERTEX_NUM-1];
	bool arrived[MAX_VERTEX_NUM];
	for(i=0;i<MAX_VERTEX_NUM;i++)
		arrived[i]=false; 
	limit_time=limittime;
	num1=0;
	mincost=INF;
	destination=city2;
	v=new int[n+2];
	v[0]=G.LocateVex(city1);
	v[n+1]=G.LocateVex(city2);
	for(i=1;i<n+1;i++){
		v[i]=G.LocateVex(city[i-1]);
	}
	arrived[v[0]]=true; 
	G.Path_cost_time(v[0],v[n+1],v,n,time,spend_time,cost,num2,flight,arrived);
	if(num1==0){
		cout<<"无符合条件线路"<<endl;
		ofstream outfile("Log.txt",ios::app);
		outfile<<city1<<"->"<<city2<<"在限定时间（"<<limit_time<<"）内无符合条件线路"<<endl;
		outfile.close();
		flag = false;
	}
	else{
		int min=0;
		flight[min][0].tag_transfer='@';
		for(i=0;i<num_flight;i++){
			plan_flight.push(flight[min][i]);
		}
		AllFlightPrint();
		ofstream outfile("Log.txt",ios::app);
		if(!outfile){
			cout<<"打开文件错误"<<endl;
			exit(1);
		}
		outfile<<"总用时："<<spend<<" 总费用："<<mincost<<endl<<endl;
		cout<<"总用时："<<spend<<" 总费用："<<mincost<<endl<<endl;
		outfile.close();
		int n;
		int city_start,city_arrive;
		Flight *flight=GetPlanFlight(n);
		emit clear();
		for(i=0;i<n;i++){
			city_start=G.LocateVex(flight[i].start_point);
			city_arrive=G.LocateVex(flight[i].arrive_point);
			emit route(city_start,city_arrive,flight[i].vehicletype);
		}
		QString *qstr=new QString[n];
		toQString(flight,n,qstr);
		stringstream ss;
		string str="总用时:",s;
		ss.str("");
		ss<<spend;
		s=ss.str();
		str+=s;
		str+="    总花费:";
		ss.str("");
		ss<<mincost;
		s=ss.str();
		str+=s;
		QString qstr1=QString(QString::fromLocal8Bit(str.c_str ()));
		emit PrintFlight(qstr,n,qstr1);
		flag = true;
	} 
	delete []v;
	return flag;
} 



