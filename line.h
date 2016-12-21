#ifndef LINE_H
#define LINE_H

#include <QObject>
#include <QWidget>
#include <QPaintEvent>
#include <QMouseEvent>
#include <QPoint>
#include <QtGui>
#include <QtCore>
#include <QRubberBand>


class line : public QWidget
{
    Q_OBJECT
    QRubberBand *r;

    QPoint delta;                               // 1st point for the line
    QPoint hitDeltaxR;                           // hit box for line in delta in the x position
    QPoint hitDeltaXL;

    QPoint hitDeltaYT;                           // hit box for delta point on the y position
    QPoint hitDeltaYB;

    QPoint epsilon;                             // second point for the line
    QPoint hitEpXR;                              // hit box for line in epsilon in the x position
    QPoint hitEpXL;

    QPoint hitEpYT;                              // hit box for epsilon point on the y position
    QPoint hitEpYB;

    QPoint midpoint;
    QPoint mpXL;                                // hit box for midpoint in x directions used for moving in this case
    QPoint mpXR;
    QPoint mpYT;                                // hit box for midpoint in y directions used for moving in this case
    QPoint mpYB;
    QPoint location;                            // variable used when line is pressed(mouse click event)
    bool moving;


protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);


public:
    explicit line(QWidget *parent = 0);
    line(int a, int b, int c, int d, QWidget *p);
    void paintEvent(QPaintEvent *);

signals:

public slots:
};

#endif // LINE_H
