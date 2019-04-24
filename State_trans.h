#ifndef MYTHREAD_H
#define MYTHREAD_H
#include <QThread>

void State_trans();		//״̬ת��

class transThread : public QThread		//״̬ת���߳�
{
	Q_OBJECT
public:
    explicit transThread(QObject *parent = 0);
    void run();
	void stop();
	void start();
signals:
	void newTime(int);
	void newDate(int);
private:
	bool stopped;
};

#endif // MYTHREAD_H


