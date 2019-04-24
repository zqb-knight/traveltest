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


enum State{STATIC,MOVE};      //ö���ÿ�״̬ 
enum Eventtype{STATE_INQUIRE,PLAN_INQUIRE }; //ö���¼�����
enum VehicleType{TRAIN,PLANE,CAR};	//��ͨ�������� 

typedef string VertexType;		//���ж����� 
typedef struct Flight{			//���೵����Ϣ 
	string flight_name;
	char tag_transfer;		//�Ƿ�����תվ 
	VehicleType vehicletype;
	int costtime,expense; 		//��ֱ����м���ʱ��Ʊ�� 
	string start_point,arrive_point; 
	int time_start,time_arrive;
	struct Flight *next_flight;
}Flight;
typedef struct Vehicle{			//��ͨ������Ϣ 
	bool tag[3];		//�������𳵡��ɻ����ڱ�־ 
	Flight *flight[3];	//����ֱ�����֮��ĳ�����Ϣ 
}Vehicle; 
typedef struct ArcNode{			//������֮�����Ϣ 
	int adjvex;
	Vehicle vehicle;			//������֮�佻ͨ��Ϣ 
	float distance;				//������ֱ����� 
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
		string name; 			//�ÿ�����
		string ID; 				//�ÿʹ��� 
		string location,destination,curdestination;	//�ÿ����ڵ�,����Ŀ�ĵأ���ǰĿ�ĵ� 
		State state;		//�ÿ�״̬ 
		queue<Flight> plan_flight; //�ÿͼƻ��� 
	public:
		Flight* current_f;
		int movetime;
signals:
		void isGenerate(bool);	//�Ƿ����ɳɹ�
		void success(bool);		//�Ƿ��мƻ�·��
		void changesucceed(bool);	//�Ƿ���ļƻ��ɹ�
		void curstate(QString);		//��ǰ״̬�ź�
		void clear();				//���·��
		void PrintFlight(QString[],int,QString);	//����ƻ��ź�
		void route(int,int,int);		//����·���ź�
		void move(Flight*,int);			//�ƶ��ź�
		void still();					//�ڳ��о�ֹ�ź�
		void arrive();					//�ִ�Ŀ�ĵ��ź�
	public:
		void initial();			//�ͻ���Ϣ��ʼ��
		void GetQString(QString,QString,QString,int,QString);	//������ɼƻ�������Ϣ
		void GeneratePlan(string,int,string);					//���ɼƻ�
		void Change_Strategy(QString,QString,int,QString);		//���ļƻ�
		void setName(QString); 	  //¼���ÿ����� 
		string GetName();       //�õ��ÿ����� 
		string GetID();	    //�õ��ÿ�ID 
		void Allocate(int IDnum);	//�����ID 
		State GetState();	   //�õ��ÿ�״̬ 
		string GetLocation();  //�õ��ÿ����ڵ�
		string GetDestination();	//�õ��ÿ�����Ŀ�ĵ� 
		string GetCurDestination(); //�õ��ÿ͵�ǰĿ�ĵ� 
		void SetLocation(string city);	//�����״����ڵ� 
		void SetState();			//�����״�״̬ 
		void SetCurFlight();	//�����״��ÿͼƻ� 
		void PushFlight(Flight *f);   //����ÿͼƻ� 
		void ChangeState();	   //�ı��ÿ�״̬ 
		void ChangeCurFlight();	//�ı��ÿ͵�ǰ�ƻ�
		Flight* GetPlanFlight(int &n);	//�õ��ÿ�ȫ�̼ƻ��� 
		void AllFlightPrint();			//���ļ����ȫ���ƻ���
		void PopFlight();			//�����ÿͼƻ���ǰ���ԭ�мƻ� 
		bool Strategy_cost(ALGraph &G,int time,VertexType &city1,VertexType &city2,int n,VertexType city[]);		//��С���ò��� 
		bool Strategy_time(ALGraph &G,int time,VertexType &city1,VertexType &city2,int n,VertexType city[]);		//���ʱ����� 
		bool Strategy_cost_time(ALGraph &G,int time,int limit_time,VertexType &city1,VertexType &city2,int n,VertexType city[]);//��ʱ�������ٲ��� 
};
class ALGraph{
	friend class Traverser;		//��Ԫ�� 
	private:
		
		int numvex;				//������� 
		int numarc;
		Flight* min_cost(ArcNode*p,int time,int &cost); 	 //�õ�����ֱ����м����ٷ��õķ�ʽ
		Flight* min_time(ArcNode*p,int time,int &cost_time); //�õ�����ֱ��������絽����߷�ʽ
		
	public:
		ALGraph();			//ͼ�Ĺ��캯�� 
		AdjList adjList;		//�ڽӱ� 
		void Initial();		//ͼ�ĳ�ʼ�� 
		void Display();		//ͼ����ʾ
		void CityDisplay(); //������ʾ
		int LocateVex(VertexType &v);	//�õ����ж������ 
		VertexType GetVex(int v);		//�õ������� 
		int JudgeVia(int v[],int n,Flight flight[MAX_VERTEX_NUM-1],int flight_num);
		int Path_min_cost(int v1,int v2,int time,queue<Flight> &plan_flight);	//��������֮�����ٻ��Ѳ��Ե�·��		
		int Path_min_time(int v1,int v2,int time,queue<Flight> &plan_flight);	//��������֮������ʱ����Ե�·��
		int Path_mintime(int v1,int v2,int time);								//��������֮������ʱ��
		void Path_cost_time(int v1,int v2,int v[],int n,int time,int spend_time,int cost,int num2,Flight flight[][MAX_VERTEX_NUM-1],bool arrived[]);
};

void Flight_Assign(Flight &f,Flight *fp);		//���ำֵ 

string toVehicle(VehicleType v);		//��ͨ��������ת�����ַ���

#endif
