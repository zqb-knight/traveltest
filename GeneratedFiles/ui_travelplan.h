/********************************************************************************
** Form generated from reading UI file 'travelplan.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRAVELPLAN_H
#define UI_TRAVELPLAN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TravelPlanClass
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QPushButton *strategyButton;
    QPushButton *planButton;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *lineEdit_4;
    QLabel *label_6;
    QLabel *label_7;
    QPushButton *quitButton;
    QPushButton *changehButton;
    QLabel *label_8;
    QLabel *statelabel;
    QPushButton *exeButton;
    QLabel *label_9;
    QPushButton *bjButton;
    QPushButton *shhButton;
    QPushButton *tbButton;
    QPushButton *dlButton;
    QPushButton *zhzhButton;
    QPushButton *qdButton;
    QPushButton *whButton;
    QPushButton *chshButton;
    QPushButton *kmButton;
    QPushButton *shzhButton;
    QPushButton *chqButton;
    QPushButton *chdButton;
    QPushButton *xaButton;
    QPushButton *lsButton;
    QPushButton *lzhButton;
    QPushButton *wlmqButton;
    QPushButton *hhhtButton;
    QTextBrowser *textFlight;
    QTextBrowser *textstate;
    QTextBrowser *textDate;
    QTextBrowser *textusr;
    QTextBrowser *texttime;
    QTextBrowser *textdate;
    QTextBrowser *textstrategy;
    QGraphicsView *graphicsView;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *TravelPlanClass)
    {
        if (TravelPlanClass->objectName().isEmpty())
            TravelPlanClass->setObjectName(QStringLiteral("TravelPlanClass"));
        TravelPlanClass->resize(780, 600);
        QFont font;
        font.setFamily(QStringLiteral("DFKai-SB"));
        font.setPointSize(9);
        font.setBold(false);
        font.setItalic(true);
        font.setWeight(50);
        TravelPlanClass->setFont(font);
        QIcon icon;
        icon.addFile(QStringLiteral(":/picture/plane.png"), QSize(), QIcon::Normal, QIcon::Off);
        TravelPlanClass->setWindowIcon(icon);
        TravelPlanClass->setStyleSheet(QStringLiteral("background:white;"));
        centralWidget = new QWidget(TravelPlanClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setStyleSheet(QStringLiteral(""));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 10, 35, 20));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setItalic(false);
        font1.setWeight(75);
        label->setFont(font1);
        label->setStyleSheet(QLatin1String("background:transparent;\n"
"color: rgb(255, 255, 255);\n"
""));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(130, 10, 35, 20));
        label_2->setFont(font1);
        label_2->setStyleSheet(QLatin1String("background:transparent;\n"
"color: rgb(255, 255, 255);\n"
""));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 40, 65, 20));
        label_3->setFont(font1);
        label_3->setStyleSheet(QLatin1String("background:transparent;\n"
"color: rgb(255, 255, 255);\n"
""));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(60, 10, 65, 20));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\344\273\277\345\256\213"));
        font2.setPointSize(10);
        font2.setBold(true);
        font2.setItalic(false);
        font2.setWeight(75);
        lineEdit->setFont(font2);
        lineEdit->setStyleSheet(QLatin1String("border:flat;\n"
"color: rgb(0, 0, 255);\n"
""));
        lineEdit_2 = new QLineEdit(centralWidget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(170, 10, 65, 20));
        lineEdit_2->setFont(font2);
        lineEdit_2->setStyleSheet(QLatin1String("border:flat;\n"
"color: rgb(0, 0, 255);\n"
""));
        lineEdit_3 = new QLineEdit(centralWidget);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(90, 40, 145, 20));
        lineEdit_3->setFont(font2);
        lineEdit_3->setStyleSheet(QLatin1String("border:flat;\n"
"color: rgb(0, 0, 255);\n"
""));
        strategyButton = new QPushButton(centralWidget);
        strategyButton->setObjectName(QStringLiteral("strategyButton"));
        strategyButton->setGeometry(QRect(290, 40, 60, 20));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font3.setBold(true);
        font3.setItalic(false);
        font3.setWeight(75);
        strategyButton->setFont(font3);
        strategyButton->setStyleSheet(QLatin1String("background-color: rgb(170, 255, 0);\n"
"color: rgb(255, 255, 255);\n"
"\n"
""));
        planButton = new QPushButton(centralWidget);
        planButton->setObjectName(QStringLiteral("planButton"));
        planButton->setGeometry(QRect(380, 40, 60, 20));
        planButton->setFont(font3);
        planButton->setCursor(QCursor(Qt::ArrowCursor));
        planButton->setStyleSheet(QLatin1String("background-color: rgb(170, 255, 0);\n"
"color: rgb(255, 255, 255);"));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(640, 10, 35, 20));
        label_4->setFont(font1);
        label_4->setStyleSheet(QLatin1String("background:transparent;\n"
"color: rgb(255, 255, 255);\n"
""));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(245, 10, 35, 20));
        label_5->setFont(font1);
        label_5->setStyleSheet(QLatin1String("background:transparent;\n"
"color: rgb(255, 255, 255);\n"
""));
        lineEdit_4 = new QLineEdit(centralWidget);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(280, 10, 65, 20));
        lineEdit_4->setFont(font2);
        lineEdit_4->setStyleSheet(QLatin1String("border:flat;\n"
"color: rgb(0, 0, 255);\n"
""));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(645, 480, 35, 30));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\344\273\277\345\256\213"));
        font4.setPointSize(11);
        font4.setBold(true);
        font4.setItalic(false);
        font4.setWeight(75);
        label_6->setFont(font4);
        label_6->setStyleSheet(QLatin1String("background:transparent;\n"
"border-image: url(:/picture/time.png);\n"
""));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(640, 40, 35, 22));
        label_7->setFont(font1);
        label_7->setStyleSheet(QLatin1String("background:transparent;\n"
"color: rgb(255, 255, 255);\n"
""));
        quitButton = new QPushButton(centralWidget);
        quitButton->setObjectName(QStringLiteral("quitButton"));
        quitButton->setGeometry(QRect(750, 70, 25, 25));
        QFont font5;
        font5.setFamily(QString::fromUtf8("\344\273\277\345\256\213"));
        font5.setItalic(false);
        quitButton->setFont(font5);
        quitButton->setStyleSheet(QLatin1String("background:transparent;\n"
"border-image: url(:/picture/quit.png);"));
        changehButton = new QPushButton(centralWidget);
        changehButton->setObjectName(QStringLiteral("changehButton"));
        changehButton->setGeometry(QRect(550, 40, 60, 20));
        changehButton->setFont(font3);
        changehButton->setStyleSheet(QLatin1String("background-color: rgb(170, 255, 0);\n"
"color: rgb(255, 255, 255);"));
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(380, 10, 65, 22));
        label_8->setFont(font1);
        label_8->setStyleSheet(QLatin1String("background:transparent;\n"
"color: rgb(255, 255, 255);\n"
""));
        statelabel = new QLabel(centralWidget);
        statelabel->setObjectName(QStringLiteral("statelabel"));
        statelabel->setGeometry(QRect(0, 420, 65, 20));
        statelabel->setFont(font1);
        statelabel->setStyleSheet(QLatin1String("background:transparent;\n"
"color: rgb(255, 255, 255);\n"
""));
        exeButton = new QPushButton(centralWidget);
        exeButton->setObjectName(QStringLiteral("exeButton"));
        exeButton->setGeometry(QRect(470, 40, 60, 20));
        exeButton->setFont(font3);
        exeButton->setStyleSheet(QLatin1String("background-color: rgb(170, 255, 0);\n"
"color: rgb(255, 255, 255);"));
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(645, 520, 35, 30));
        label_9->setFont(font4);
        label_9->setStyleSheet(QLatin1String("background:transparent;\n"
"border-image: url(:/picture/date.png);\n"
""));
        bjButton = new QPushButton(centralWidget);
        bjButton->setObjectName(QStringLiteral("bjButton"));
        bjButton->setGeometry(QRect(577, 197, 35, 20));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(0, 0, 0, 0));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(255, 127, 127, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(255, 63, 63, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(127, 0, 0, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(170, 0, 0, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush6(QColor(255, 255, 255, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush2);
        QBrush brush7(QColor(255, 255, 220, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush7);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush7);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        QBrush brush8(QColor(255, 0, 0, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush8);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush7);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        bjButton->setPalette(palette);
        bjButton->setFont(font2);
        bjButton->setStyleSheet(QLatin1String("background:transparent;\n"
"color: rgb(0, 0, 0);"));
        bjButton->setCheckable(false);
        bjButton->setDefault(true);
        bjButton->setFlat(true);
        shhButton = new QPushButton(centralWidget);
        shhButton->setObjectName(QStringLiteral("shhButton"));
        shhButton->setGeometry(QRect(687, 296, 35, 20));
        shhButton->setFont(font2);
        shhButton->setStyleSheet(QLatin1String("background:transparent;\n"
""));
        shhButton->setCheckable(false);
        shhButton->setDefault(true);
        shhButton->setFlat(true);
        tbButton = new QPushButton(centralWidget);
        tbButton->setObjectName(QStringLiteral("tbButton"));
        tbButton->setGeometry(QRect(726, 385, 35, 20));
        tbButton->setFont(font2);
        tbButton->setStyleSheet(QLatin1String("background:transparent;\n"
""));
        tbButton->setCheckable(false);
        tbButton->setDefault(true);
        tbButton->setFlat(true);
        dlButton = new QPushButton(centralWidget);
        dlButton->setObjectName(QStringLiteral("dlButton"));
        dlButton->setGeometry(QRect(655, 196, 35, 20));
        dlButton->setFont(font2);
        dlButton->setStyleSheet(QLatin1String("background:transparent;\n"
""));
        dlButton->setCheckable(false);
        dlButton->setDefault(true);
        dlButton->setFlat(true);
        zhzhButton = new QPushButton(centralWidget);
        zhzhButton->setObjectName(QStringLiteral("zhzhButton"));
        zhzhButton->setGeometry(QRect(553, 265, 35, 20));
        zhzhButton->setFont(font2);
        zhzhButton->setStyleSheet(QLatin1String("background:transparent;\n"
""));
        zhzhButton->setCheckable(false);
        zhzhButton->setDefault(true);
        zhzhButton->setFlat(true);
        qdButton = new QPushButton(centralWidget);
        qdButton->setObjectName(QStringLiteral("qdButton"));
        qdButton->setGeometry(QRect(645, 235, 31, 20));
        qdButton->setFont(font2);
        qdButton->setStyleSheet(QLatin1String("background:transparent;\n"
""));
        qdButton->setCheckable(false);
        qdButton->setDefault(true);
        qdButton->setFlat(true);
        whButton = new QPushButton(centralWidget);
        whButton->setObjectName(QStringLiteral("whButton"));
        whButton->setGeometry(QRect(575, 317, 35, 20));
        whButton->setFont(font2);
        whButton->setStyleSheet(QLatin1String("background:transparent;\n"
""));
        whButton->setCheckable(false);
        whButton->setDefault(true);
        whButton->setFlat(true);
        chshButton = new QPushButton(centralWidget);
        chshButton->setObjectName(QStringLiteral("chshButton"));
        chshButton->setGeometry(QRect(562, 353, 35, 20));
        chshButton->setFont(font2);
        chshButton->setStyleSheet(QLatin1String("background:transparent;\n"
""));
        chshButton->setCheckable(false);
        chshButton->setDefault(true);
        chshButton->setFlat(true);
        kmButton = new QPushButton(centralWidget);
        kmButton->setObjectName(QStringLiteral("kmButton"));
        kmButton->setGeometry(QRect(381, 405, 35, 20));
        kmButton->setFont(font2);
        kmButton->setStyleSheet(QLatin1String("background:transparent;\n"
""));
        kmButton->setCheckable(false);
        kmButton->setDefault(true);
        kmButton->setFlat(true);
        shzhButton = new QPushButton(centralWidget);
        shzhButton->setObjectName(QStringLiteral("shzhButton"));
        shzhButton->setGeometry(QRect(603, 437, 35, 20));
        shzhButton->setFont(font2);
        shzhButton->setStyleSheet(QLatin1String("background:transparent;\n"
""));
        shzhButton->setCheckable(false);
        shzhButton->setDefault(true);
        shzhButton->setFlat(true);
        chqButton = new QPushButton(centralWidget);
        chqButton->setObjectName(QStringLiteral("chqButton"));
        chqButton->setGeometry(QRect(449, 338, 35, 20));
        chqButton->setFont(font2);
        chqButton->setStyleSheet(QLatin1String("background:transparent;\n"
""));
        chqButton->setCheckable(false);
        chqButton->setDefault(true);
        chqButton->setFlat(true);
        chdButton = new QPushButton(centralWidget);
        chdButton->setObjectName(QStringLiteral("chdButton"));
        chdButton->setGeometry(QRect(408, 324, 35, 20));
        chdButton->setFont(font2);
        chdButton->setStyleSheet(QLatin1String("background:transparent;\n"
"\n"
""));
        chdButton->setCheckable(false);
        chdButton->setDefault(true);
        chdButton->setFlat(true);
        xaButton = new QPushButton(centralWidget);
        xaButton->setObjectName(QStringLiteral("xaButton"));
        xaButton->setGeometry(QRect(484, 276, 35, 20));
        xaButton->setFont(font2);
        xaButton->setStyleSheet(QLatin1String("background:transparent;\n"
""));
        xaButton->setCheckable(false);
        xaButton->setDefault(true);
        xaButton->setFlat(true);
        lsButton = new QPushButton(centralWidget);
        lsButton->setObjectName(QStringLiteral("lsButton"));
        lsButton->setGeometry(QRect(195, 330, 35, 20));
        lsButton->setFont(font2);
        lsButton->setStyleSheet(QLatin1String("background:transparent;\n"
"\n"
""));
        lsButton->setCheckable(false);
        lsButton->setDefault(true);
        lsButton->setFlat(true);
        lzhButton = new QPushButton(centralWidget);
        lzhButton->setObjectName(QStringLiteral("lzhButton"));
        lzhButton->setGeometry(QRect(407, 256, 35, 20));
        lzhButton->setFont(font2);
        lzhButton->setStyleSheet(QLatin1String("background:transparent;\n"
""));
        lzhButton->setCheckable(false);
        lzhButton->setDefault(true);
        lzhButton->setFlat(true);
        wlmqButton = new QPushButton(centralWidget);
        wlmqButton->setObjectName(QStringLiteral("wlmqButton"));
        wlmqButton->setGeometry(QRect(208, 159, 60, 25));
        wlmqButton->setFont(font2);
        wlmqButton->setStyleSheet(QLatin1String("background:transparent;\n"
"\n"
"\n"
"\n"
""));
        wlmqButton->setCheckable(false);
        wlmqButton->setDefault(true);
        wlmqButton->setFlat(true);
        hhhtButton = new QPushButton(centralWidget);
        hhhtButton->setObjectName(QStringLiteral("hhhtButton"));
        hhhtButton->setGeometry(QRect(513, 198, 55, 20));
        hhhtButton->setFont(font2);
        hhhtButton->setStyleSheet(QLatin1String("background:transparent;\n"
""));
        hhhtButton->setCheckable(false);
        hhhtButton->setDefault(true);
        hhhtButton->setFlat(true);
        textFlight = new QTextBrowser(centralWidget);
        textFlight->setObjectName(QStringLiteral("textFlight"));
        textFlight->setGeometry(QRect(0, 455, 280, 120));
        QFont font6;
        font6.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font6.setBold(true);
        font6.setWeight(75);
        textFlight->setFont(font6);
        textFlight->setStyleSheet(QLatin1String("background:transparent;\n"
"color: rgb(0, 85, 255);\n"
"border-color: rgb(85, 255, 255);\n"
""));
        textstate = new QTextBrowser(centralWidget);
        textstate->setObjectName(QStringLiteral("textstate"));
        textstate->setGeometry(QRect(80, 415, 201, 30));
        textstate->setFont(font6);
        textstate->setStyleSheet(QLatin1String("background:transparent;\n"
"color: rgb(0, 0, 255);\n"
"border-color: rgb(85, 255, 255);"));
        textDate = new QTextBrowser(centralWidget);
        textDate->setObjectName(QStringLiteral("textDate"));
        textDate->setGeometry(QRect(685, 40, 90, 20));
        QFont font7;
        font7.setFamily(QStringLiteral("Arial"));
        font7.setBold(false);
        font7.setItalic(false);
        font7.setWeight(50);
        textDate->setFont(font7);
        textDate->setStyleSheet(QLatin1String("background:transparent;\n"
"color: rgb(255, 255, 255);\n"
"border:flat;"));
        textusr = new QTextBrowser(centralWidget);
        textusr->setObjectName(QStringLiteral("textusr"));
        textusr->setGeometry(QRect(685, 10, 90, 20));
        textusr->setFont(font7);
        textusr->setStyleSheet(QLatin1String("background:transparent;\n"
"color: rgb(255, 255, 255);\n"
"border:flat;"));
        texttime = new QTextBrowser(centralWidget);
        texttime->setObjectName(QStringLiteral("texttime"));
        texttime->setGeometry(QRect(700, 485, 75, 20));
        QFont font8;
        font8.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font8.setPointSize(11);
        font8.setBold(true);
        font8.setItalic(false);
        font8.setWeight(75);
        texttime->setFont(font8);
        texttime->setStyleSheet(QLatin1String("background:transparent;\n"
"border:flat;\n"
"color: rgb(0, 0, 255);"));
        textdate = new QTextBrowser(centralWidget);
        textdate->setObjectName(QStringLiteral("textdate"));
        textdate->setGeometry(QRect(690, 525, 85, 20));
        textdate->setFont(font8);
        textdate->setStyleSheet(QLatin1String("background:transparent;\n"
"color: rgb(0, 0, 255);\n"
"border:flat;"));
        textstrategy = new QTextBrowser(centralWidget);
        textstrategy->setObjectName(QStringLiteral("textstrategy"));
        textstrategy->setGeometry(QRect(470, 10, 120, 20));
        textstrategy->setFont(font2);
        textstrategy->setStyleSheet(QLatin1String("background:transparent;\n"
"color: rgb(0, 0, 255);\n"
"border:flat;"));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(0, 0, 780, 560));
        QFont font9;
        font9.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font9.setPointSize(12);
        font9.setBold(true);
        font9.setWeight(75);
        graphicsView->setFont(font9);
        graphicsView->setStyleSheet(QLatin1String("border-image: url(:/picture/map.jpg);\n"
"background:transparent;\n"
"margin-bottom:0px;"));
        TravelPlanClass->setCentralWidget(centralWidget);
        graphicsView->raise();
        strategyButton->raise();
        label->raise();
        label_2->raise();
        label_3->raise();
        lineEdit->raise();
        lineEdit_2->raise();
        lineEdit_3->raise();
        planButton->raise();
        label_4->raise();
        label_5->raise();
        lineEdit_4->raise();
        label_6->raise();
        label_7->raise();
        quitButton->raise();
        changehButton->raise();
        label_8->raise();
        statelabel->raise();
        exeButton->raise();
        label_9->raise();
        bjButton->raise();
        shhButton->raise();
        tbButton->raise();
        dlButton->raise();
        zhzhButton->raise();
        qdButton->raise();
        whButton->raise();
        chshButton->raise();
        kmButton->raise();
        shzhButton->raise();
        chqButton->raise();
        chdButton->raise();
        xaButton->raise();
        lsButton->raise();
        lzhButton->raise();
        wlmqButton->raise();
        hhhtButton->raise();
        textFlight->raise();
        textstate->raise();
        textDate->raise();
        textusr->raise();
        texttime->raise();
        textdate->raise();
        textstrategy->raise();
        menuBar = new QMenuBar(TravelPlanClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 780, 23));
        TravelPlanClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(TravelPlanClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        TravelPlanClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(TravelPlanClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        TravelPlanClass->setStatusBar(statusBar);

        retranslateUi(TravelPlanClass);
        QObject::connect(hhhtButton, SIGNAL(clicked()), TravelPlanClass, SLOT(on_hhhtButton_click()));
        QObject::connect(strategyButton, SIGNAL(clicked()), TravelPlanClass, SLOT(on_strategyButton_click()));
        QObject::connect(planButton, SIGNAL(clicked()), TravelPlanClass, SLOT(on_planButton_click()));
        QObject::connect(exeButton, SIGNAL(clicked()), TravelPlanClass, SLOT(on_exeButton_click()));
        QObject::connect(changehButton, SIGNAL(clicked()), TravelPlanClass, SLOT(on_changeButton_click()));
        QObject::connect(quitButton, SIGNAL(clicked()), TravelPlanClass, SLOT(on_quitButton_click()));
        QObject::connect(wlmqButton, SIGNAL(clicked()), TravelPlanClass, SLOT(on_wlmqButton_click()));
        QObject::connect(lsButton, SIGNAL(clicked()), TravelPlanClass, SLOT(on_lsButton_click()));
        QObject::connect(lzhButton, SIGNAL(clicked()), TravelPlanClass, SLOT(on_lzhButton_click()));
        QObject::connect(chqButton, SIGNAL(clicked()), TravelPlanClass, SLOT(on_chqButton_click()));
        QObject::connect(chdButton, SIGNAL(clicked()), TravelPlanClass, SLOT(on_chdButton_click()));
        QObject::connect(kmButton, SIGNAL(clicked()), TravelPlanClass, SLOT(on_kmButton_click()));
        QObject::connect(shzhButton, SIGNAL(clicked()), TravelPlanClass, SLOT(on_shzhButton_click()));
        QObject::connect(chshButton, SIGNAL(clicked()), TravelPlanClass, SLOT(on_chshButton_click()));
        QObject::connect(whButton, SIGNAL(clicked()), TravelPlanClass, SLOT(on_whButton_click()));
        QObject::connect(zhzhButton, SIGNAL(clicked()), TravelPlanClass, SLOT(on_zhzhButton_click()));
        QObject::connect(xaButton, SIGNAL(clicked()), TravelPlanClass, SLOT(on_xaButton_click()));
        QObject::connect(bjButton, SIGNAL(clicked()), TravelPlanClass, SLOT(on_bjButton_click()));
        QObject::connect(qdButton, SIGNAL(clicked()), TravelPlanClass, SLOT(on_qdButton_click()));
        QObject::connect(tbButton, SIGNAL(clicked()), TravelPlanClass, SLOT(on_tbButton_click()));
        QObject::connect(shhButton, SIGNAL(clicked()), TravelPlanClass, SLOT(on_shhButton_click()));
        QObject::connect(dlButton, SIGNAL(clicked()), TravelPlanClass, SLOT(on_dlButton_click()));

        QMetaObject::connectSlotsByName(TravelPlanClass);
    } // setupUi

    void retranslateUi(QMainWindow *TravelPlanClass)
    {
        TravelPlanClass->setWindowTitle(QApplication::translate("TravelPlanClass", "\346\250\241\346\213\237\346\227\205\350\241\214", 0));
        label->setText(QApplication::translate("TravelPlanClass", "\350\265\267\347\202\271", 0));
        label_2->setText(QApplication::translate("TravelPlanClass", "\347\273\210\347\202\271", 0));
        label_3->setText(QApplication::translate("TravelPlanClass", "\351\200\224\347\273\217\345\237\216\345\270\202", 0));
#ifndef QT_NO_TOOLTIP
        lineEdit_3->setToolTip(QApplication::translate("TravelPlanClass", "<html><head/><body><p>\345\237\216\345\270\202\344\271\213\351\227\264\347\251\272\346\240\274\345\210\206\345\274\200</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        strategyButton->setToolTip(QApplication::translate("TravelPlanClass", "<html><head/><body><p><br/></p></body></html>", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        strategyButton->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        strategyButton->setText(QApplication::translate("TravelPlanClass", "\347\255\226\347\225\245\351\200\211\346\213\251", 0));
#ifndef QT_NO_TOOLTIP
        planButton->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        planButton->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        planButton->setText(QApplication::translate("TravelPlanClass", "\347\224\237\346\210\220\350\256\241\345\210\222", 0));
        label_4->setText(QApplication::translate("TravelPlanClass", "\347\224\250\346\210\267", 0));
        label_5->setText(QApplication::translate("TravelPlanClass", "\351\231\220\346\227\266", 0));
        label_6->setText(QString());
        label_7->setText(QApplication::translate("TravelPlanClass", "\346\227\245\346\234\237", 0));
        quitButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        changehButton->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        changehButton->setText(QApplication::translate("TravelPlanClass", "\346\233\264\346\224\271\350\256\241\345\210\222", 0));
        label_8->setText(QApplication::translate("TravelPlanClass", "\345\275\223\345\211\215\347\255\226\347\225\245", 0));
        statelabel->setText(QApplication::translate("TravelPlanClass", "\345\275\223\345\211\215\347\212\266\346\200\201", 0));
#ifndef QT_NO_TOOLTIP
        exeButton->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        exeButton->setText(QApplication::translate("TravelPlanClass", "\346\211\247\350\241\214\350\256\241\345\210\222", 0));
        label_9->setText(QString());
        bjButton->setText(QApplication::translate("TravelPlanClass", "\345\214\227\344\272\254", 0));
        shhButton->setText(QApplication::translate("TravelPlanClass", "\344\270\212\346\265\267", 0));
        tbButton->setText(QApplication::translate("TravelPlanClass", "\345\217\260\345\214\227", 0));
        dlButton->setText(QApplication::translate("TravelPlanClass", "\345\244\247\350\277\236", 0));
        zhzhButton->setText(QApplication::translate("TravelPlanClass", "\351\203\221\345\267\236", 0));
        qdButton->setText(QApplication::translate("TravelPlanClass", "\351\235\222\345\262\233", 0));
        whButton->setText(QApplication::translate("TravelPlanClass", "\346\255\246\346\261\211", 0));
        chshButton->setText(QApplication::translate("TravelPlanClass", "\351\225\277\346\262\231", 0));
        kmButton->setText(QApplication::translate("TravelPlanClass", "\346\230\206\346\230\216", 0));
        shzhButton->setText(QApplication::translate("TravelPlanClass", "\346\267\261\345\234\263", 0));
        chqButton->setText(QApplication::translate("TravelPlanClass", "\351\207\215\345\272\206", 0));
        chdButton->setText(QApplication::translate("TravelPlanClass", "\346\210\220\351\203\275", 0));
        xaButton->setText(QApplication::translate("TravelPlanClass", "\350\245\277\345\256\211", 0));
        lsButton->setText(QApplication::translate("TravelPlanClass", "\346\213\211\350\220\250", 0));
        lzhButton->setText(QApplication::translate("TravelPlanClass", "\345\205\260\345\267\236", 0));
        wlmqButton->setText(QApplication::translate("TravelPlanClass", "\344\271\214\351\262\201\346\234\250\351\275\220", 0));
        hhhtButton->setText(QApplication::translate("TravelPlanClass", "\345\221\274\345\222\214\346\265\251\347\211\271", 0));
    } // retranslateUi

};

namespace Ui {
    class TravelPlanClass: public Ui_TravelPlanClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRAVELPLAN_H
