#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "line.h"
#include "circle.h"
#include "shape.h"

#include <QPaintEvent>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QApplication>




MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    view = new QGraphicsView(scene , this);
    setCentralWidget(view);




}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_actionLine_triggered()          // not trigger event
{
    int x = 50;
    int y = 100;
    int a = 200;
    int b = 200;
    line* p = new line(x , y , a , b , ui->centralWidget);

    update();
    p->show();
    raise();
}


void MainWindow::on_actionL_ine_triggered()
{
    int x = 50;
    int y = 100;
    int a = 200;
    int b = 200;
    line* p = new line(x , y , a , b , NULL);

    p->update();
    p->show();
    p->raise();
    scene->addWidget(p, Qt::Widget);
}
void MainWindow::on_actionR_ectangle_triggered()
{
    char val;
    val = 'r';
    shape *r = new shape(NULL);
    r->getShape(val);
    r->update();
    r->show();
    r->raise();
    scene->addWidget(r, Qt::Widget);

}

void MainWindow::on_actionC_ircle_2_triggered()
{
    int x = 50;
    int y = 50;
    circle* c = new circle(NULL , x , y);
//    setCentralWidget(c);

    c->update();
    c->show();
    c->raise();
    scene->addWidget(c, Qt::Widget);
}

void MainWindow::on_actionA_rc_triggered()
{
    char val;
    val = 'a';
    shape *a = new shape(NULL);
    a->getShape(val);
    a->update();
    a->show();
    a->raise();
    scene->addWidget(a, Qt::Widget);
}

void MainWindow::on_action_Text_triggered()
{
    char val;
    val = 't';
    shape *t = new shape(NULL);
    t->getShape(val);
    t->update();
    t->show();
    t->raise();
    scene->addWidget(t, Qt::Widget);
}

void MainWindow::on_action_Path_triggered()
{
    char val;
    val = 'p';
    shape *p = new shape(NULL);
    p->getShape(val);
    p->update();
    p->show();
    p->raise();
    scene->addWidget(p, Qt::Widget);
}

void MainWindow::on_actionPo_lygon_triggered()
{
    char val;
    val = 'o';
    shape *o = new shape(NULL);
    o->getShape(val);
    o->update();
    o->show();
    o->raise();
    scene->addWidget(o, Qt::Widget);
}



void MainWindow::on_actionEx_it_triggered()
{
    QApplication::quit();
}
