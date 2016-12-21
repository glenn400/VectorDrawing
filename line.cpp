#include "line.h"


#include <QPainter>
#include <QMouseEvent>
#include <QtGui>
#include <QtCore>
#include <QPen>
#include <QApplication>
#include <QtMath>
#include <QSize>
#include <QRubberBand>



void line::mousePressEvent(QMouseEvent *event)
{

    if (Qt::LeftButton == event->button())
    {
        QPoint zero(0,0);
        location = event->pos();
    }
    mouseMoveEvent(event);
}
//****************************************************************************
void line::mouseMoveEvent(QMouseEvent *event)
{


        QPoint offset(1,1);
        if (location.x() >= hitDeltaXL.x() && location.x() <= hitDeltaxR.x() && location.y() >= hitDeltaYT.y() && location.y() <= hitDeltaYB.y() )
        {
              // rotate about that point
             // or stretch
            int distance = (event->pos() - location).manhattanLength();
            if (distance >= 4 )
            {
                delta = event->pos();
/*                hitDeltaXL.setX(delta.x() - 6);
                hitDeltaxR.setX(delta.x() + 6);
                hitDeltaYT.setY(delta.y() - 6);
                hitDeltaYB.setY(delta.y() + 6);
*/
                moving = true;
                update();
                mouseReleaseEvent(event);
                return;
            }

        }
        else if (location.x() >= hitEpXL.x() && location.x() <= hitEpXR.x() && location.y() >= hitEpYT.y() && location.y() <= hitEpYB.y() )
        {
            // rotate about that point
            // or stretch
            int distance = (event->pos() - location).manhattanLength();
            if (distance >= 4 )
            {
                epsilon = event->pos();
                moving = true;
                update();
                mouseReleaseEvent(event);
                return;
            }

        }
        else if( this)
        {

            // move(drag) line where user wants
            int distance = (event->pos() - location).manhattanLength();
            if (distance >= 4)
                    move( mapToParent(event->pos() ));
                    moving = true;
                    update();
                    raise();
                    mouseReleaseEvent(event);
                    return;
        }
        else
            moving = false;
            return;


}
//***********************************************************************************
void line::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        // update this paramenters

        hitDeltaXL.setX(delta.x() - 6);
        hitDeltaXL.setY(delta.y());
        hitDeltaxR.setX(delta.x() + 6);
        hitDeltaXL.setY(delta.y());
        hitDeltaYT.setY(delta.y() - 6);
        hitDeltaYT.setX(delta.x());
        hitDeltaYB.setY(delta.y() + 6);
        hitDeltaYB.setX(delta.x());

        hitEpXL.setX(epsilon.x() - 6);
        hitEpXR.setX(epsilon.x() + 6);
        hitEpYT.setY(epsilon.y() - 6);
        hitEpYB.setY(epsilon.y() + 6);

        mpXL.setX(midpoint.x() - 6);
        mpXR.setX(midpoint.x() + 6);
        mpYT.setY(midpoint.y() - 6);
        mpYB.setY(midpoint.y() + 6);

        if ( event->pos().x() >= hitDeltaXL.x() && event->pos().x() <= hitDeltaxR.x() && event->pos().y() >= hitDeltaYT.y() && event->pos().y() <= hitDeltaYB.y() )
        {
            delta = event->pos();
            midpoint = delta + epsilon / 2;
            hitDeltaXL.setX(delta.x() - 6);
            hitDeltaxR.setX(delta.x() + 6);
            hitDeltaYT.setY(delta.y() - 6);
            hitDeltaYB.setY(delta.y() + 6);

            moving = false;

            // new position
            location = event->pos();
            return;

        }
        else if ( event->pos().x() >= hitEpXL.x() && event->pos().x() <= hitEpXR.x() && event->pos().y() >= hitEpYT.y() && event->pos().y() <= hitEpYB.y())
        {
            epsilon = event->pos();
            midpoint = delta + epsilon / 2;
            hitEpXL.setX(delta.x() - 6);
            hitEpXR.setX(delta.x() + 6);
            hitEpYT.setY(delta.y() - 6);
            hitEpYB.setY(delta.y() + 6);

            moving = false;
            location = event->pos();
            return;

        }
        else
            midpoint = event->pos();
            hitEpXL.setX(delta.x() - 6);
            hitEpXR.setX(delta.x() + 6);
            hitEpYT.setY(delta.y() - 6);
            hitEpYB.setY(delta.y() + 6);

            moving = false;


    }
}
//*************************************************************************************
line::line(QWidget *parent) : QWidget(parent)
{

}
//**************************************************************************************
line::line(int a, int b, int c, int d, QWidget *p) : QWidget(p) , moving(false) , location(0,0) , r(NULL)
{
    delta.setX(a);                   // get point one
    delta.setY(b);
    epsilon.setX(c);                // get point two
    epsilon.setY(d);

    // make 6x6 hit box around point
    hitDeltaxR.setX(a+6);
    hitDeltaxR.setY(b);
    hitDeltaXL.setX(a-6);
    hitDeltaXL.setY(b);
    hitDeltaYT.setY(b-6);
    hitDeltaYT.setX(a);
    hitDeltaYB.setY(b+6);
    hitDeltaYB.setX(a);

    hitEpXL.setX(c-6);
    hitEpXL.setY(d);
    hitEpXR.setX(c+6);
    hitEpXR.setX(d);
    hitEpYT.setY(d-6);
    hitEpYT.setX(c);
    hitEpYB.setY(d+6);
    hitEpYB.setX(c);


    int x = (a + c) / 2;            // get midpoint
    int y = (b + d) / 2;

    midpoint.setX(x);
    midpoint.setY(y);               // will be using points to represent line

    mpXL.setX(x - 6);
    mpXL.setY(y);
    mpXR.setX(x + 6);
    mpXR.setX(y);
    mpYT.setY(y - 6);
    mpYT.setX(x);
    mpYB.setY(y + 6);
    mpYB.setX(x);

    setAttribute(Qt::WA_NoSystemBackground);


}
//***************************************************************************************
void line::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setBackgroundMode(Qt::TransparentMode );
    painter.setRenderHint(QPainter::Antialiasing);
    QPen blackPen(Qt::black);
    painter.setPen(blackPen);
    painter.drawLine(delta,epsilon);
    QPen dotPen(Qt::black);
    dotPen.setWidth(3);
    painter.setPen(dotPen);                                         // draw end points
    painter.drawPoint(delta);
    painter.drawPoint(epsilon);


}
