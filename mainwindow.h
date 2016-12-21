#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
     QGraphicsScene *scene;
     QGraphicsView *view;
protected:

public:
    explicit MainWindow(QWidget *parent = 0);

    ~MainWindow();

private slots:

    void on_actionLine_triggered();

    void on_actionL_ine_triggered();

    void on_actionR_ectangle_triggered();

    void on_actionC_ircle_2_triggered();

    void on_actionA_rc_triggered();

    void on_action_Text_triggered();

    void on_action_Path_triggered();

    void on_actionPo_lygon_triggered();

    void on_actionEx_it_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
