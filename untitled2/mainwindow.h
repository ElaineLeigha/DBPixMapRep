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
#include <QComboBox>
#include <QVector>
#include <QSqlDatabase>

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
    QBoxLayout* mainLayout;

    //
    QLabel label;
    QGraphicsScene *scene;
    QGraphicsLineItem *Node1 = NULL;
    QGraphicsLineItem *Node2 = NULL;
    QGraphicsLineItem *Node3 = NULL;
    QMessageBox* dbErr;
    QMessageBox* workingdialog;
    QDialog* setVersion;
    QGraphicsLineItem* lines[100000] = {NULL};

    QLabel* choiceLabel;
    QComboBox* StandaloneORInteroperability;
    QPushButton* select;
    QVBoxLayout* dbSelectLayout;

    QPen pointyellow;
    QPen pointblue;
    QPen pointpurple;

    bool eventFilter(QObject *, QEvent*);

    //SQL Members
    QGraphicsLineItem *l[400];

    QVector<QString> DS;
    QGraphicsItemGroup * DSections[128];

    struct XY{
      QString dsname;
      int x;
      int y;
      QString SDirection;
    } point[50000];
    QPen redPen;
    QPen bluePen;
    QPen greenPen;
    QPen blackPen;
    QPoint midpoint[128];

    QString choice;
    QTimer* powertimer;
    QSqlDatabase t4adb, team4db;



public slots:
    void zoomIn();
    void zoomOut();
    void sendinfotrainDUM();
    void sendinfotrackDUM();
//    void sendinfotrain();
    void sendinfotrack();
    void sendinfoRoutes();
    void createDummyDatabase();
    void setmenubar();
    void RxTxDatabases();

    void setDBdialog();
    void selectdb();

    void turnoffsection();
    void turnonsection();
    void deactivate(QString section, bool power);
    void sendinfotrain(QSqlDatabase t4adb);


    void loadDataTable();
    void loadDataTable2();
    void loadDataTable3();
    void loadDataTable4();
    void loadDataTable5();
    void setLegendsandLogos();
    void starttimer();

signals:

};

#endif // MAINWINDOW_H
