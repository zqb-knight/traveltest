#ifndef Variable_H
#define Variable_H

#include <QtWidgets/QMainWindow>

#include<string>
#include<queue>


using namespace std;

#define INF 65535
#define MAX_VERTEX_NUM 20
#define MAX_SEG 15

class QString;


enum State{STATIC,MOVE};      //枚举旅客状态 
enum Eventtype{STATE_INQUIRE,PLAN_INQUIRE }; //枚举事件类型
enum VehicleType{TRAIN,PLANE,CAR};	//交通工具类型 

typedef string VertexType;		//城市顶点名 
typedef struct Flight{			//航班车次信息 
	string flight_name;
	char tag_transfer;		//是否是中转站 
	VehicleType vehicletype;
	int costtime,expense; 		//两直达城市间用时，票价 
	string start_point,arrive_point; 
	int time_start,time_arrive;
	struct Flight *next_flight;
}Flight;
typedef struct Vehicle{			//交通工具信息 
	bool tag[3];		//汽车、火车、飞机存在标志 
	Flight *flight[3];	//两个直达城市之间的车次信息 
}Vehicle; 
typedef struct ArcNode{			//两顶点之间边信息 
	int adjvex;
	Vehicle vehicle;			//两城市之间交通信息 
	float distance;				//两城市直达距离 
    struct ArcNode *nextarc;	
}ArcNode;
typedef struct{
	VertexType vexdata;			
	ArcNode * firstarc;
}VexNode,AdjList[MAX_VERTEX_NUM];

class ALGraph;
class Traverser	: public QObject 
{
	Q_OBJECT 
	private:
		string name; 			//旅客姓名
		string ID; 				//旅客代码 
		string location,destination,curdestination;	//旅客所在地,最终目的地，当前目的地 
		State state;		//旅客状态 
		queue<Flight> plan_flight; //旅客计划表 
	public:
		Flight* current_f;
		int movetime;
signals:
		void isGenerate(bool);	//是否生成成功
		void success(bool);		//是否有计划路线
		void changesucceed(bool);	//是否更改计划成功
		void curstate(QString);		//当前状态信号
		void clear();				//清空路线
		void PrintFlight(QString[],int,QString);	//航班计划信号
		void route(int,int,int);		//城市路线信号
		void move(Flight*,int);			//移动信号
		void still();					//在城市静止信号
		void arrive();					//抵达目的地信号
	public:
		void initial();			//客户信息初始化
		void GetQString(QString,QString,QString,int,QString);	//获得生成计划所需信息
		void GeneratePlan(string,int,string);					//生成计划
		void Change_Strategy(QString,QString,int,QString);		//更改计划
		void setName(QString); 	  //录入旅客姓名 
		string GetName();       //得到旅客姓名 
		string GetID();	    //得到旅客ID 
		void Allocate(int IDnum);	//分配客ID 
		State GetState();	   //得到旅客状态 
		string GetLocation();  //得到旅客所在地
		string GetDestination();	//得到旅客最终目的地 
		string GetCurDestination(); //得到旅客当前目的地 
		void SetLocation(string city);	//设置首次所在地 
		void SetState();			//设置首次状态 
		void SetCurFlight();	//设置首次旅客计划 
		void PushFlight(Flight *f);   //添加旅客计划 
		void ChangeState();	   //改变旅客状态 
		void ChangeCurFlight();	//改变旅客当前计划
		Flight* GetPlanFlight(int &n);	//得到旅客全程计划表 
		void AllFlightPrint();			//向文件输出全部计划表
		void PopFlight();			//更改旅客计划表前清除原有计划 
		bool Strategy_cost(ALGraph &G,int time,VertexType &city1,VertexType &city2,int n,VertexType city[]);		//最小费用策略 
		bool Strategy_time(ALGraph &G,int time,VertexType &city1,VertexType &city2,int n,VertexType city[]);		//最短时间策略 
		bool Strategy_cost_time(ALGraph &G,int time,int limit_time,VertexType &city1,VertexType &city2,int n,VertexType city[]);//限时费用最少策略 
};
class ALGraph{
	friend class Traverser;		//友元类 
	private:
		
		int numvex;				//顶点个数 
		int numarc;
		Flight* min_cost(ArcNode*p,int time,int &cost); 	 //得到两个直达城市间最少费用的方式
		Flight* min_time(ArcNode*p,int time,int &cost_time); //得到两个直达城市最早到达后者方式
		
	public:
		ALGraph();			//图的构造函数 
		AdjList adjList;		//邻接表 
		void Initial();		//图的初始化 
		void Display();		//图的显示
		void CityDisplay(); //城市显示
		int LocateVex(VertexType &v);	//得到城市顶点序号 
		VertexType GetVex(int v);		//得到城市名 
		int JudgeVia(int v[],int n,Flight flight[MAX_VERTEX_NUM-1],int flight_num);
		int Path_min_cost(int v1,int v2,int time,queue<Flight> &plan_flight);	//两个城市之间最少花费策略的路线		
		int Path_min_time(int v1,int v2,int time,queue<Flight> &plan_flight);	//两个城市之间最少时间策略的路线
		int Path_mintime(int v1,int v2,int time);								//两个城市之间最少时间
		void Path_cost_time(int v1,int v2,int v[],int n,int time,int spend_time,int cost,int num2,Flight flight[][MAX_VERTEX_NUM-1],bool arrived[]);
};

void Flight_Assign(Flight &f,Flight *fp);		//航班赋值 

string toVehicle(VehicleType v);		//交通工具类型转换成字符串

#endif
