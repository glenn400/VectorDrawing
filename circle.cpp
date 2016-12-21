#include "circle.h"
#include <QPainter>
#include <QMouseEvent>
#include <QtGui>
#include <QtCore>
#include <QPen>
#include <QApplication>
#include <QtMath>
#include <QSize>
#include <QRubberBand>


circle::circle(QWidget *parent) : QWidget(parent)
{

}

circle::circle(QWidget *parent, int x, int y) : QWidget(parent), startPos(0,0)
{

    alpha = x;
    beta = y;
    gamma.setX(x);
    gamma.setY(y);
    center.setX(100);
    center.setY(100);

    hitAlphaXL.setX(alpha );
    hitAlphaXL.setY(beta);
    hitAlphaXR.setX(alpha + 6);
    hitAlphaXR.setY(beta);

    hitBetaYT.setX(alpha);
    hitBetaYT.setY(beta - 6);
    hitBetaYB.setX(alpha);
    hitBetaYB.setY(beta +6 );

    hitCXL.setX(100 - 6);
    hitCXL.setY(100);
    hitCXR.setX(100 + 6);
    hitCXR.setY(100);
    hitCYT.setY(100 - 6);
    hitCYT.setX(100);
    hitCYB.setY(100 + 6);
    hitCYB.setX(100);

 //   setBackgroundRole(QPalette::Base);
 //   setAutoFillBackground(true);
    setAttribute(Qt::WA_NoSystemBackground);


}
//*********************************************************************************
void circle::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    painter.setRenderHint(QPainter::Antialiasing);
    QPen pen(Qt::black);
    QPen dotPen(Qt::black);
    dotPen.setWidth(3);
    painter.setPen(pen);
    painter.drawEllipse(center,alpha,beta);

    painter.setPen(dotPen);
    painter.drawPoint(center);
    painter.drawPoint(gamma);



}
//**************************************************************************
void circle::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        startPos = event->pos();
    }
    else
        mouseMoveEvent(event);
}
//*****************************************************************************
void circle::mouseMoveEvent(QMouseEvent *event)
{
    if (startPos.x() >= hitAlphaXL.x() && startPos.x() <= hitAlphaXR.x() && startPos.y() >= hitBetaYT.y() && startPos.y() <= hitBetaYB.y() )
    {
          // rotate about that point
         // or stretch
        int distance = (event->pos() - startPos).manhattanLength();
        if (distance >= 4 )
        {
            gamma = event->pos();
            moving = true;
            update();
            mouseReleaseEvent(event);
            return;
        }
    }
        else if (startPos.x() >= hitCXL.x() && startPos.x() <= hitCXR.x() && startPos.y() >= hitCYT.y() && startPos.y() <= hitCYB.y())
        {
        // move entire circle
        int distance = (event->pos() - startPos).manhattanLength();
        if (distance >= 4 )
        {
            center = event->pos();
            moving = true;
            update();
            mouseReleaseEvent(event);
            return;
        }
        }
        else if (this)
        {
            // move(drag) circle where user wants
            // move circle about any point on it
            int distance = (event->pos() - startPos).manhattanLength();
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
//******************************************************************************
void circle::mouseReleaseEvent(QMouseEvent *event)
{
     if (event->button() == Qt::LeftButton)
     {
         // update hitbox
         hitAlphaXL.setX(gamma.x() - 6 );
         hitAlphaXL.setY(gamma.y());
         hitAlphaXR.setX(gamma.x() + 6);
         hitAlphaXR.setY(gamma.y() );

         hitBetaYT.setX(gamma.x());
         hitBetaYT.setY(gamma.y() - 6);
         hitBetaYB.setX(gamma.x());
         hitBetaYB.setY(gamma.y() +6 );


         hitCXL.setX(center.x() - 6);
         hitCXL.setY(center.y());
         hitCXR.setX(center.x() + 6);
         hitCXR.setY(center.y() );
         hitCYT.setY(center.y() - 6);
         hitCYT.setX(center.x());
         hitCYB.setY(center.y() + 6);
         hitCYB.setX(center.x());

         if (startPos.x() >= hitAlphaXL.x() && startPos.x() <= hitAlphaXR.x() && startPos.y() >= hitBetaYT.y() && startPos.y() <= hitBetaYB.y() )
         {
                 gamma = event->pos();
                 hitAlphaXL.setX(gamma.x() -  6);
                 hitAlphaXL.setY(gamma.y());
                 hitAlphaXR.setX(gamma.x() + 6);
                 hitAlphaXR.setY(gamma.y() );

                 hitBetaYT.setX(gamma.x());
                 hitBetaYT.setY(gamma.y() - 6);
                 hitBetaYB.setX(gamma.x());
                 hitBetaYB.setY(gamma.y() +6 );

                 moving = false;
                 update();
                 return;

         }
         else if (startPos.x() >= hitCXL.x() && startPos.x() <= hitCXR.x() && startPos.y() >= hitCYT.y() && startPos.y() <= hitCYB.y())
         {
             center = event->pos();

             hitCXL.setX(center.x() - 6);
             hitCXL.setY(center.y());
             hitCXR.setX( center.x() + 6);
             hitCXR.setY(center.y() );
             hitCYT.setY(center.y() - 6);
             hitCYT.setX(center.x());
             hitCYB.setY(center.y() + 6);
             hitCYB.setX(center.x());
             moving = false;
             update();
             return;



         }
         else if (this)
         {
             this->pos() = event->pos();
             moving = false;
             update();
             raise();
             return;
         }
         else
             moving = false;

     }
}
