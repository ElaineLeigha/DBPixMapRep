#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPalette>
#include <QColor>
#include <QBrush>
#include <QLabel>
#include <QPen>
#include <qmath.h>
#include <qglobal.h>
#include <QTime>
#include <stdio.h>
#include <QGraphicsSceneHoverEvent>
#include <QEvent>
#include <QMouseEvent>
#include <QtSql>
//#include <qr
//#include <QColor
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
  //  ui->graphicsView->setScene(scene);
    QPen  path1(Qt::black);
    pointblue.setWidth(100);
    pointblue.setColor("blue");
    pointyellow.setColor("yellow");
    pointyellow.setWidth(100);
    pointpurple.setColor("purple");
    pointpurple.setWidth(100);

    //QPen  beacon(Qt::blue);
    beacon = new QPen(Qt::blue);
    beacon->setWidth(20);
    path1.setWidth(6);
//    QPixmap pix("C://Users/Elaine/Downloads/CoordExtrap.jpg");
//    scene->addPixmap(pix);

    testnode = Node1;
    QBrush  paint;
    paint.setColor(Qt::blue);
    QPen clear(Qt::green);
    clear.setWidth(6);
    scene->setBackgroundBrush(paint);
    ui->graphicsView->setStyleSheet("background-color: white;");
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setMouseTracking(true);

    timer = new QTimer(this);
    timer->setInterval(5000);
    timer->start();

    testtimer = new QTimer(this);
    testtimer->setInterval(1000);

    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(rotateup()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(rotatedown()));
    connect(ui->Zoom, SIGNAL(clicked()),this, SLOT(zoomIn()));
    connect(ui->OutButton,SIGNAL(clicked()),this,SLOT(zoomOut()));
   // connect(timer,SIGNAL(timeout()),this,SLOT(beaconn()));
   // connect(ui->pushButton_3,SIGNAL(clicked()),SLOT(activationtoggle()));
   // connect(testtimer,SIGNAL(timeout()),this,SLOT(nodehop()));

    setMouseTracking(true);
    scene->installEventFilter(this);


  //*****************************************************************************
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("team3a.db");
     if(!db.open())
     {
         qDebug() << db.lastError();
         qDebug() << "Error: unable to connect due to above error";
     }
     QSqlQuery q;
     q.exec("Drop table dummytrain");//prevent duplicate tables
     q.exec("CREATE TABLE dummytrain (node INTEGER, xpos INTEGER, ypos INTEGER)");
     q.exec("INSERT INTO dummytrain VALUES( 0,163,850)");
     q.exec("INSERT INTO dummytrain VALUES( 1,163,1028)");
     q.exec("INSERT INTO dummytrain VALUES( 2,310,1175)");
     q.exec("INSERT INTO dummytrain VALUES( 3,488,1175)");
     q.exec("INSERT INTO dummytrain VALUES( 4,635,1028)");
     q.exec("INSERT INTO dummytrain VALUES( 5,635,850)");
     q.exec("INSERT INTO dummytrain VALUES( 6,400,610)");

     q.exec("Drop table loco");
     q.exec("CREATE TABLE loco (node INTEGER, train INTEGER)");
     q.exec("INSERT INTO loco VALUES( 0,0)");
     q.exec("INSERT INTO loco VALUES( 1,1)");
     q.exec("INSERT INTO loco VALUES( 2,0)");
     q.exec("INSERT INTO loco VALUES( 3,2)");
     q.exec("INSERT INTO loco VALUES( 4,0)");
     q.exec("INSERT INTO loco VALUES( 5,3)");
     q.exec("INSERT INTO loco VALUES( 6,0)");


     q.exec("Drop table track");
     q.exec("CREATE TABLE track (line INTEGER, x1 INTEGER, y1 INTEGER, x2 INTEGER, y2 INTEGER)");
     q.exec("INSERT INTO track VALUES(1,15,225,195,45)");
     q.exec("INSERT INTO track VALUES(2,195,45,503,45)");
     q.exec("INSERT INTO track VALUES(3,503,45,608,78)");
     q.exec("INSERT INTO track VALUES(4,608,78,932,78)");
     q.exec("INSERT INTO track VALUES(5,932,78,2312,78)");
     q.exec("INSERT INTO track VALUES(6,2312,78,2585,78)");
     q.exec("INSERT INTO track VALUES(7,2585,78,2697,45)");
     q.exec("INSERT INTO track VALUES(8,2697,45,3007,45)");
     q.exec("INSERT INTO track VALUES(9,3007,45,3184,225)");
     q.exec("INSERT INTO track VALUES(10,3184,225,3184,1175)");
     q.exec("INSERT INTO track VALUES(11,3184,1175,2978,1382)");
     q.exec("INSERT INTO track VALUES(12,2978,1382,2505,1382)");
     q.exec("INSERT INTO track VALUES(13,2505,1382,2325,1204)");
     q.exec("INSERT INTO track VALUES(14,2325,1204,2325,950)");
     q.exec("INSERT INTO track VALUES(15,2325,950,2325,704)");
     q.exec("INSERT INTO track VALUES(16,2325,704,2235,610)");
     q.exec("INSERT INTO track VALUES(17,2235,610,2030,610)");
     q.exec("INSERT INTO track VALUES(18,2030,610,1927,641)");
     q.exec("INSERT INTO track VALUES(19,1927,641,1274,641)");
     q.exec("INSERT INTO track VALUES(20,1274,641,1167,610)");
     q.exec("INSERT INTO track VALUES(21,1167,610,964,610)");
     q.exec("INSERT INTO track VALUES(22,964,610,875,700)");
     q.exec("INSERT INTO track VALUES(23,875,700,875,950)");
     q.exec("INSERT INTO track VALUES(24,875,950,875,1195)");
     q.exec("INSERT INTO track VALUES(25,875,1195,697,1382)");
     q.exec("INSERT INTO track VALUES(26,697,1382, 221,1382)");
     q.exec("INSERT INTO track VALUES(27,221,1382,15,1175)");
     q.exec("INSERT INTO track VALUES(28,15,1175,15,225)");
     q.exec("INSERT INTO track VALUES(29,75,257,252,78)");
     q.exec("INSERT INTO track VALUES(30,252,78,600,78)");
     q.exec("INSERT INTO track VALUES(31, 75,952,105,1085)");
     q.exec("INSERT INTO track VALUES(32, 105,1085,310,1292)");
     q.exec("INSERT INTO track VALUES(33, 310,1292,635,1292)");

     q.exec("INSERT INTO track VALUES(35, 75,1145,252,1325)");
     q.exec("INSERT INTO track VALUES(41, 815,580,845,610)");
     q.exec("INSERT INTO track VALUES(42, 845,610,740,507)");
     q.exec("INSERT INTO track VALUES(43, 740,507,635,405)");
     q.exec("INSERT INTO track VALUES(44, 635,405,635,315)");
     q.exec("INSERT INTO track VALUES(45, 635,315,458,137)");
     q.exec("INSERT INTO track VALUES(46, 458,137,280,137)");
     q.exec("INSERT INTO track VALUES(47, 280,137,133,288)");
     q.exec("INSERT INTO track VALUES(48, 133,288,133,345)");
     q.exec("INSERT INTO track VALUES(49, 133,345,400,610)");
     q.exec("INSERT INTO track VALUES(50, 400,610,635,850)");
     q.exec("INSERT INTO track VALUES(51, 635,850,635,1028)");
     q.exec("INSERT INTO track VALUES(52, 635,1028,488,1175)");
     q.exec("INSERT INTO track VALUES(53, 488,1175,310,1175)");
     q.exec("INSERT INTO track VALUES(54, 310,1175,163,1028)");
     q.exec("INSERT INTO track VALUES(55, 163,1028,163,850)");
     q.exec("INSERT INTO track VALUES(56, 163,850,392,611)");
     q.exec("INSERT INTO track VALUES(62, 1198,228,2013,228)");
     q.exec("INSERT INTO track VALUES(64, 1303,258,1893,258)");
     q.exec("INSERT INTO track VALUES(66, 1423,288,2268,288)");
     q.exec("INSERT INTO track VALUES(67, 1573,318,2285,318)");
     q.exec("INSERT INTO track VALUES(68, 1543,318,1573,318)");
     q.exec("INSERT INTO track VALUES(69, 1573,318,1663,348)");
     q.exec("INSERT INTO track VALUES(70, 1663,348,2312,348)");
     q.exec("INSERT INTO track VALUES(71, 1663,348,1693,378)");
     q.exec("INSERT INTO track VALUES(72, 815,288,964,138)");
     q.exec("INSERT INTO track VALUES(73, 964,138,1142,138)");
     q.exec("INSERT INTO track VALUES(74, 1142,138,2117,138)");
     q.exec("INSERT INTO track VALUES(75, 2117,138,2237,138)");
     q.exec("INSERT INTO track VALUES(76, 2237,138,2387,288)");
     q.exec("INSERT INTO track VALUES(77, 2387,288,2387,498)");
//     q.exec("INSERT INTO track VALUES(78, 2387,498,1723,423)");
//     q.exec("INSERT INTO track VALUES(79, 1723,423,1723,348)");
     q.exec("INSERT INTO track VALUES(84, 2567,408,2567,318)");
     q.exec("INSERT INTO track VALUES(85, 2567,318,2747,138)");
     q.exec("INSERT INTO track VALUES(86, 2747,138,2927,138)");
     q.exec("INSERT INTO track VALUES(87, 2927,138,3077,288)");
     q.exec("INSERT INTO track VALUES(88, 3077,288,3077,348)");
     q.exec("INSERT INTO track VALUES(89, 3077,348,2807,618)");
     q.exec("INSERT INTO track VALUES(90, 2807,618,2567,858)");
     q.exec("INSERT INTO track VALUES(91, 2567,858,2567,1038)");
     q.exec("INSERT INTO track VALUES(92, 2567,1038,2717,1188)");
     q.exec("INSERT INTO track VALUES(93, 2717,1188,2899,1188)");
     q.exec("INSERT INTO track VALUES(94, 2899,1188,3047,1038)");
     q.exec("INSERT INTO track VALUES(95, 3047,1038,3049,858)");
     q.exec("INSERT INTO track VALUES(96, 3049,858,2687,498)");
//     q.exec("INSERT INTO track VALUES(97, 2687,498,2387,723)");
     q.exec("INSERT INTO track VALUES(98, 2387,723,2387,1188)");
     q.exec("INSERT INTO track VALUES(99, 2387,1188,2537,1338)");
     q.exec("INSERT INTO track VALUES(100, 2537,1338,2957,1338)");
     q.exec("INSERT INTO track VALUES(101, 2957,1338,3137,1158)");
     q.exec("INSERT INTO track VALUES(102, 3137,1158,3137,978)");
     q.exec("INSERT INTO track VALUES(103, 3137,978,3107,1098)");
     q.exec("INSERT INTO track VALUES(104, 3107,1098,2899,1308)");
     q.exec("INSERT INTO track VALUES(105, 2899,1308,2567,1308)");
//     q.exec("INSERT INTO track VALUES(106, 2367,1308,3137,258)");
     q.exec("INSERT INTO track VALUES(107, 3137,258,2947,75)");
//     q.exec("INSERT INTO track VALUES(108, 2947,75,2357,618)");
     q.exec("INSERT INTO track VALUES(110, 2089,464,1912,464)");
     q.exec("INSERT INTO track VALUES(111, 1912,464,1230,464)");
     q.exec("INSERT INTO track VALUES(112, 1230,464,1110,464)");
     q.exec("INSERT INTO track VALUES(113, 1230,464,1334,492)");
     q.exec("INSERT INTO track VALUES(114, 1334,492,1807,492)");
//     q.exec("INSERT INTO track VALUES(115, 1912,462,1570,550)");
//     q.exec("INSERT INTO track VALUES(116, 1570,550,1082,550)");
//     q.exec("INSERT INTO track VALUES(117, 1670,520,1120,520)");
//     q.exec("INSERT INTO track VALUES(118, 1110,424,1082,555)");
//     q.exec("INSERT INTO track VALUES(119, 1082,555,518,492)");


     connect(ui->sendButtonTrain, SIGNAL(clicked()), this, SLOT(sendinfotrain()));
     connect(ui->sendButtonTrack, SIGNAL(clicked()), this, SLOT(sendinfotrack()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::rotateup()
{
    ui->graphicsView->rotate(10);
    //ui->graphicsView->centerOn(); pass in section number for live feed
}

void MainWindow::rotatedown()
{
    ui->graphicsView->rotate(-10);
}

void MainWindow::zoomIn()
{
    ui->graphicsView->scale(1.1,1.1);
}
void MainWindow::zoomOut()
{
    ui->graphicsView->scale(.8,.8);
}

void MainWindow::beaconn()
{
    //this->sendinfo();
}

void MainWindow::activationtoggle()
{
    testnode->hide();
    scene->update();
    timer->stop();
    testtimer->stop();
    QPen testpen;
    testpen.setColor("brown");
    testpen.setWidth(23);
    //testnode = Node1;
    testnode->show();
    testnode->setPen(testpen);
    if (toggle == true)
    {
       toggle = false;
       //testtimer->start();
       activationtester();
    }
    else
    {
        toggle = true;
    }
}

void MainWindow::activationtester()
{
    QString myarray[] = {"Node2","Node3","Node4","Node5","Node6","Node7","Node8"};
    QString ran;
    int random = qrand() % 8;
   // ran = rand(myarray);
    std::map<QString,QGraphicsLineItem*> map;
    map["Node2"]= Node2;
    map["Node3"]= Node3;
//    map["Node4"]= Node4;
//    map["Node5"]= Node5;
//    map["Node6"]= Node6;
//    map["Node7"]= Node7;
//    map["Node8"]= Node8;

    testnode = map[myarray[random]];
    QPen bluepen(Qt::blue);
    bluepen.setWidth(23);
    testnode->setPen(bluepen);
    testtimer->start();
    nodehop();
}

void MainWindow::nodehop()
{
    if (tmp2 == true)
    {
    testnode->hide();
    testnode->setPen(*beacon);
    //Node1->setPen(QPen temp(Qt::blue));
    tmp2 = false;
    scene->update();
    }
    else
    {
        testnode->show();
        scene->update();
        tmp2 = true;
    }
}

bool MainWindow::eventFilter(QObject* s,QEvent* h)
{
    scene->update();
    int xval;
    int yval;
    if (s == ui->graphicsView->scene())
   {
        if (h->type() == QEvent::GraphicsSceneMouseMove)
        {
           QGraphicsSceneMouseEvent* move = static_cast<QGraphicsSceneMouseEvent*>(h);
           xval = move->scenePos().toPoint().x();
           yval = move->scenePos().toPoint().y();
           ui->pushButton_4->setText("XCoor: "+QString::number(xval));
           ui->pushButton_5->setText("YCoor: "+QString::number(yval));
           return false;
        }
    }
    //return (s,h);
    return false;
}

//*********************************************************************

void MainWindow::sendinfotrain()
{
    QSqlQuery q;

    if(ui->lineEdit->text() == NULL)
    {
        QString defaultcommand = "select train,xpos,ypos from dummytrain natural join loco where train<>0";
        q.exec(defaultcommand);
        qDebug() << "default select: " << defaultcommand << endl;
    }
    else
    {
        q.prepare(ui->lineEdit->text());
        q.exec(ui->lineEdit->text());
        qDebug() << ui->lineEdit->text();
    }
    int i = 0;
    const int numTrains = 5;
    int train[numTrains] = {0};//max number of trains, init to zeros, can retain 0 or train number
    int xpos[numTrains] = {0};
    int ypos[numTrains] = {0};
    while(q.next())
    {

        train[i] = q.value(0).toInt();
        xpos[i] = q.value(1).toInt();
        ypos[i] = q.value(2).toInt();
        qDebug() << q.value(0).toInt() << q.value(1).toInt() << q.value(2).toInt();
        i++;
    }
    qDebug() << endl;
    for(int j = 0; j<numTrains; j++)
    {
        if(train[j] != 0)
        {
            if(train[j] == 1)
            {
                if(Node1)
                {
                    Node1->setVisible(false);
                }
                Node1 = scene->addLine(xpos[j],ypos[j],xpos[j],ypos[j],pointblue);
                continue;
            }
            else if(train[j] == 2)
            {
                if(Node2)
                {
                    Node2->setVisible(false);
                }
                Node2 = scene->addLine(xpos[j],ypos[j],xpos[j],ypos[j],pointyellow);
                continue;
            }
            else if(train[j] == 3)
            {
                if(Node3)
                {
                    Node3->hide();
                }
                Node3 = scene->addLine(xpos[j],ypos[j],xpos[j],ypos[j],pointpurple);
            }
        }
    }
    scene->update();
    ui->lineEdit->clear();
}

void MainWindow::sendinfotrack()
{
    QSqlQuery q;
       QPen  path1(Qt::black);
       path1.setWidth(6);

    if(ui->lineEdit->text() == NULL)
    {
        QString defaultcommand = "select * from track";
        q.exec(defaultcommand);
        qDebug() << "default select: " << defaultcommand << endl;
    }
    else
    {
        q.prepare(ui->lineEdit->text());
        q.exec(ui->lineEdit->text());
        qDebug() << ui->lineEdit->text();
    }
    int i = 0;;
    while(q.next())
    {
        l[q.value(0).toInt()] = scene->addLine(q.value(1).toInt(),q.value(2).toInt(),q.value(3).toInt(),q.value(4).toInt(),path1) ;
        qDebug() << q.value(0).toInt() << q.value(1).toInt() << q.value(2).toInt() << q.value(3).toInt() << q.value(4).toInt();
        i++;
    }
    qDebug() << endl;
    scene->update();
    ui->lineEdit->clear();
}
