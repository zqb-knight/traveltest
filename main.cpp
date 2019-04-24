#include"Variable.h"
#include"State_trans.h"

#include "travelplan.h"
#include <QtWidgets/QApplication>
#include <Qtimer>
#include <QMovie>
#include <QSound>
#include "dialog.h"

void work();
void initial();

int systemTime,Date=1; 
ALGraph M;
Traverser T;


int main(int argc, char *argv[])
{
	
	M.Initial();
	QApplication a(argc, argv);

	QIcon icon;
    icon.addFile(QStringLiteral(":/picture/plane.png"), QSize(), QIcon::Normal, QIcon::Off);
	a.setWindowIcon(icon);

	QTimer *timer=new QTimer;
	QLabel begin;

	transThread transthread;
	TravelPlan  *win;
	logdialog *d;

	win = new TravelPlan ;
	d=new logdialog;

	//开机动画
	QMovie *movie = new QMovie("Image/begin.gif");
	begin.setMovie(movie);
	movie->start();
	begin.show();

	QSound *player1=new QSound("Music/My Soul.wav");
	QSound *player2=new QSound("Music/Butter-Fly.wav");
	player1->play ();
	player2->setLoops(QSound::Infinite); 
	QObject ::connect(timer, SIGNAL(timeout()), movie, SLOT(stop()) );
	QObject ::connect(timer, SIGNAL(timeout()), &begin, SLOT(close()) );
	QObject ::connect(timer, SIGNAL(timeout()), d, SLOT(show()) );
	QObject ::connect(timer, SIGNAL(timeout()), timer,SLOT(stop()));
    timer->start(4000);// 4秒单触发定时器

	//用户登陆信息传递
	QObject ::connect(d,&logdialog::newname,win,&TravelPlan::show);
	QObject ::connect(d,&logdialog::newname,win,&TravelPlan::SetName);
	QObject ::connect(d,&logdialog::newname,&T,&Traverser::setName);
	QObject ::connect(d,&logdialog::newname,player1,&QSound::stop );
	QObject ::connect(d,SIGNAL(newname(QString)),player2,SLOT(play()) );
	//生成计划和更改计划传递
	QObject ::connect(&T,&Traverser::success,&T,&Traverser::initial);
	QObject ::connect(win,&TravelPlan::generate ,&T,&Traverser::GetQString);
	QObject ::connect(win,&TravelPlan::changeplan,&T,&Traverser::Change_Strategy);
	QObject ::connect(&T,&Traverser::isGenerate,win,&TravelPlan::IsGenerate);
	QObject ::connect(&T,&Traverser::success,win,&TravelPlan::success);
	QObject ::connect(&T,&Traverser::changesucceed,win,&TravelPlan::changesucceed);

	//执行计划之间信息传递
	QObject ::connect(win,&TravelPlan::exeutive,&transthread,&transThread::start);	
	QObject ::connect(win,&TravelPlan::wait,&transthread,&transThread::stop);
	QObject ::connect(&transthread,&transThread::newTime,win,&TravelPlan::newTime);
	QObject ::connect(&transthread,&transThread::newDate,win,&TravelPlan::newDate);
	QObject ::connect(&T,&Traverser::curstate,win,&TravelPlan::newState);
	QObject ::connect(&T,&Traverser::PrintFlight,win,&TravelPlan::FlightPrint);
	QObject ::connect(&T,&Traverser::route,win,&TravelPlan::paint);
	
	QObject ::connect(&T,&Traverser::move,win,&TravelPlan::move);
	QObject ::connect(&T,&Traverser::still,win,&TravelPlan::still);
	QObject ::connect(&T,&Traverser::arrive,win,&TravelPlan::arrive);

	return a.exec();

}

