#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsColorizeEffect>
#include <QLabel>
#include <QBrush>
#include <QTimer>
#include <QGraphicsItem>
#include <QPen>
#include <QGraphicsSceneEvent>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QLabel label;
    QGraphicsScene *scene;
    QGraphicsLineItem *Node1 = NULL;
    QGraphicsLineItem *Node2 = NULL;
    QGraphicsLineItem *Node3 = NULL;

    QTimer* timer;
    QTimer* testtimer;
    QPen * beacon;
    bool toggle = true;
    bool tmp = true;
    bool tmp2 = true;
    QPen pointyellow;
    QPen pointblue;
    QPen pointpurple;
    QGraphicsLineItem * testnode;
  //  virtual void mouseMoveEvent(QMouseEvent *hover);

    bool eventFilter(QObject *, QEvent*);
      QGraphicsLineItem *l[400];

public slots:
    void rotateup();
    void rotatedown();
    void zoomIn();
    void zoomOut();
    void beaconn();
    void activationtoggle();
    void activationtester();
    void nodehop();
    void sendinfotrain();
    void sendinfotrack();

signals:

};

#endif // MAINWINDOW_H
