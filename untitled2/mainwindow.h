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
#include <QMessageBox>
#include <QBoxLayout>
#include <QLineEdit>
#include <QSql>
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

    //Set up the mainwindow program
    QLabel* statusLabel;
    QMenu* filemenu;
    QMenu* optionsmenu;
    QAction* quit;
    QAction* dbselect;

    //Objects necessary for warning dialog
    QVBoxLayout* errLayout;
    QLineEdit* newName;
    QPushButton* submit;
    QLabel* errLabel;

    //
    QLabel label;
    QGraphicsScene *scene;
    QGraphicsLineItem *Node1 = NULL;
    QGraphicsLineItem *Node2 = NULL;
    QGraphicsLineItem *Node3 = NULL;
    QMessageBox* dbErr;
    QDialog* newdb;
    QLineF lines[1000];

    QTimer* timer;
    QTimer* testtimer;
    QPen * beacon;

    QPen pointyellow;
    QPen pointblue;
    QPen pointpurple;
    QGraphicsLineItem * testnode;

    bool eventFilter(QObject *, QEvent*);

    //SQL Members
      QGraphicsLineItem *l[400];
      QString DS[128] = {NULL};
      struct XY{
          QString dsname;
          int x;
          int y;
      } drawLines[500];





public slots:
    void rotateup();
    void rotatedown();
    void zoomIn();
    void zoomOut();
    void sendinfotrainDUM();
    void sendinfotrackDUM();
//    void sendinfotrain();
    void sendinfotrack();
    void sendinfoRoutes();
    void createDummyDatabase();
    void setdatabars();
    void RxTxDatabases();
    void setDB();

signals:

};

#endif // MAINWINDOW_H
