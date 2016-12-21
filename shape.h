#ifndef SHAPE_H
#define SHAPE_H

#include <QObject>
#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include <QtGui>
#include <QtCore>
#include <QPen>
#include <QApplication>
#include <QtMath>
#include <QSize>
#include <QRubberBand>


class shape : public QWidget
{
    Q_OBJECT
    enum Shape {rect , arc , path , text , polygon};
    Shape s;
    QPoint p;                                 // points on the rect
    // create hit box around p
    QPoint pXL;
    QPoint pXR;
    QPoint pYT;
    QPoint pYB;

    QPoint p1;                               // points on the rect
    // create hit box around p1
    QPoint p1XL;
    QPoint p1XR;
    QPoint p1YT;
    QPoint p1YB;

    QPoint p2;                              // points on the rect
    // create hit box around p2
    QPoint p2XL;
    QPoint p2XR;
    QPoint p2YT;
    QPoint p2YB;

    QPoint p3;                              // points on the rect
    // create hit box around p3
    QPoint p3XL;
    QPoint p3XR;
    QPoint p3YT;
    QPoint p3YB;

    QPoint startPos;                        // mouseclick
    QRect rect1;
    QRectF r;
    char v;
    bool moving;
    QPoint zeta;
    QPoint eta;

protected:

    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

public:
    explicit shape(QWidget *parent = 0);
    void paintEvent(QPaintEvent *event);
    void setShape(Shape forma);                                 // referenced from
                                                               // http://doc.qt.io/qt-5/qtwidgets-painting-basicdrawing-example.html
    void getShape(char p);


signals:

public slots:


};

#endif // SHAPE_H
