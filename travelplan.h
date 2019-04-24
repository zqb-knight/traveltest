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
	void SetEnabled(bool);			//���ɼƻ���ť�Ƿ���Ч
	void SetName(QString);			//�û�����ʾ
	void SetChoose();				//���õ�ǰ�ƻ�����
	void SetChangeChoose(int);		//��Ҫ���ĵļƻ�����
	void GetChange_infor(QString,QString,QString);	//��ȡ���ļƻ���Ϣ������
	void IsGenerate(bool);			//��ǰ�����Ƿ�������ɼƻ�
	void success(bool);				//�ƻ��Ƿ�ɹ�����
	void changesucceed(bool);		//���ļƻ���Ϣ����
	void newTime(int);				//���ø�������
	void newDate(int);				//���ø���ʱ��
	void newState(QString);			//���ø���״̬
	void FlightPrint(QString[],int,QString);	//�ƻ��������
	void setcity(int,QString);		//����ѡ��
	void routedisplay(QString);		//����·�����
	void paint(int,int,int);		//���ݳ��кͽ�ͨ��ʽ����·��
	void move(Flight *,int);		//ÿ���Ӷ���
	void still();					//���еȴ���ִ�Ŀ�ĵ�ͼƬ��ʾ����
	void arrive();					//�����������Ի���
signals:
	void generate(QString,QString,QString,int,QString);	//���ɼƻ���Ϣ
	void changeplan(QString,QString,int,QString);		//���ļƻ���Ϣ
	void exeutive();									//ִ��ϵ�ź�
	void wait();										//��ͣ�ź�
public slots:
	void on_strategyButton_click();		//����ѡ��Ի���
	void on_planButton_click();			//���ɼƻ�
	void on_changeButton_click();		//���ļƻ��Ի���
	void on_exeButton_click();			//ִ�мƻ�
	void on_quitButton_click();			//�˳�
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
