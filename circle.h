#ifndef CIRCLE_H
#define CIRCLE_H

#include <QObject>
#include <QWidget>

class circle : public QWidget
{
    Q_OBJECT
    int alpha;          // points for circle (rectangle
    int beta;
    QPoint gamma;           // alpha and beta
    QPoint startPos;

    bool moving;           // is object moving

    QPoint hitAlphaXL;
    QPoint hitAlphaXR;
    QPoint hitAlphaYT;
    QPoint hitAlphaYB;

    QPoint hitbBetaXL;
    QPoint hitBetaXR;
    QPoint hitBetaYT;
    QPoint hitBetaYB;

    QPoint center;

    QPoint hitCXL;
    QPoint hitCXR;
    QPoint hitCYT;
    QPoint hitCYB;

public:
    explicit circle(QWidget *parent = 0);
    circle(QWidget *parent , int x, int y );
    void paintEvent(QPaintEvent *);
protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
signals:

public slots:
};

#endif // CIRCLE_H
