#include "shape.h"

#include <QPainterPath>
#include <QPainter>
#include <QMouseEvent>
#include <QtGui>
#include <QtCore>
#include <QPen>
#include <QApplication>
#include <QtMath>
#include <QSize>
#include <QRubberBand>


void shape::paintEvent(QPaintEvent *event)
{
    QPainterPath path1;
    path1.moveTo(20 , 80);
    path1.lineTo(20 , 30);
    path1.cubicTo(80 , 0 , 50 , 50 , 80 , 80);

    int angleInt = 20 * 16;
    int arcLen = 120 * 16;

    QPainter painter(this);

    QPen pen(Qt::black);
    QPen penDot(Qt::black);
    penDot.setWidth(3);
    painter.setRenderHint(QPainter::Antialiasing);

    switch (s) {
    case rect:
    {
        painter.setPen(pen);

        painter.drawRect(rect1);

        QPoint pos;
        QPoint pos1;
        QPoint pos2;
        QPoint pos3;

        painter.setPen(penDot);
        pos = rect1.bottomLeft();
        p.setX( pos.x() );
        p.setY( pos.y() );

        // update hitbox
        pXL.setX( p.x() - 6 );
        pXR.setX( p.x() + 6 );
        pXL.setY( p.y() );
        pXR.setY( p.y() );
        pYT.setX( p.x() );
        pYB.setX( p.x() );
        pYT.setY( p.y() - 6 );
        pYB.setY( p.y() + 6 );

        pos1 = rect1.bottomRight();                     // zeta
        p1.setX( pos1.x() );                          // set points for rect
        p1.setY( pos1.y() );                     // set points for rect

        // update hitbox
        p1XL.setX( p1.x() - 6 );
        p1XR.setX( p1.x() + 6 );
        p1XL.setY( p1.y() );
        p1XR.setY( p1.y() );
        p1YT.setX( p1.x() );
        p1YB.setX( p1.x() );
        p1YT.setY( p1.y() - 6 );
        p1YB.setY( p1.y() + 6 );

        pos2 = rect1.topLeft();                     // eta
        p2.setX( pos2.x() );                     // set points for rect
        p2.setY( pos2.y() );                     // set points for rect

        // update hitbox
        p2XL.setX( p2.x() - 6 );
        p2XR.setX( p2.x() + 6 );
        p2XL.setY( p2.y() );
        p2XR.setY( p2.y() );
        p2YT.setX( p2.x() );
        p2YB.setX( p2.x() );
        p2YT.setY( p2.y() - 6 );
        p2YB.setY( p2.y() + 6 );

        pos3 = rect1.topRight();
        p3.setX( pos3.x() );                     // set points for rect
        p3.setY( pos3.y() );                     // set points for rect


        // update hitbox
        p3XL.setX( p3.x() - 6 );
        p3XR.setX( p3.x() + 6 );
        p3XL.setY( p3.y() );
        p3XR.setY( p3.y() );
        p3YT.setX( p3.x() );
        p3YB.setX( p3.x() );
        p3YT.setY( p3.y() - 6 );
        p3YB.setY( p3.y() + 6 );

        painter.drawPoint(pos);
        painter.drawPoint(pos1);
        painter.drawPoint(pos2);
        painter.drawPoint(pos3);

        break;
    }
    case arc:
    {
        painter.setPen(pen);
        painter.drawArc(rect1 , angleInt , arcLen );

        QPoint pos;
        QPoint pos1;
        QPoint pos2;
        QPoint pos3;

        painter.setPen(penDot);
        pos = rect1.bottomLeft();
        p.setX( pos.x() );
        p.setY( pos.y() );
        // update hitbox
        pXL.setX( p.x() - 6 );
        pXR.setX( p.x() + 6 );
        pXL.setY( p.y() );
        pXR.setY( p.y() );
        pYT.setX( p.x() );
        pYB.setX( p.x() );
        pYT.setY( p.y() - 6 );
        pYB.setY( p.y() + 6 );

        pos1 = rect1.bottomRight();
        p1.setX( pos1.x() );
        p1.setY( pos1.y() );
        // update hitbox
        p1XL.setX( p1.x() - 6 );
        p1XR.setX( p1.x() + 6 );
        p1XL.setY( p1.y() );
        p1XR.setY( p1.y() );
        p1YT.setX( p1.x() );
        p1YB.setX( p1.x() );
        p1YT.setY( p1.y() - 6 );
        p1YB.setY( p1.y() + 6 );

        pos2 = rect1.topLeft();
        p2.setX( pos2.x() );
        p2.setY( pos2.y() );
        // update hitbox
        p2XL.setX( p2.x() - 6 );
        p2XR.setX( p2.x() + 6 );
        p2XL.setY( p2.y() );
        p2XR.setY( p2.y() );
        p2YT.setX( p2.x() );
        p2YB.setX( p2.x() );
        p2YT.setY( p2.y() - 6 );
        p2YB.setY( p2.y() + 6 );

        pos3 = rect1.topRight();
        p3.setX( pos3.x() );
        p3.setY( pos3.y() );
        // update hitbox
        p3XL.setX( p3.x() - 6 );
        p3XR.setX( p3.x() + 6 );
        p3XL.setY( p3.y() );
        p3XR.setY( p3.y() );
        p3YT.setX( p3.x() );
        p3YB.setX( p3.x() );
        p3YT.setY( p3.y() - 6 );
        p3YB.setY( p3.y() + 6 );

        painter.drawPoint(pos);
        painter.drawPoint(pos1);
        painter.drawPoint(pos2);
        painter.drawPoint(pos3);

        break;
    }
    case path:
    {
        painter.setPen(pen);
        painter.drawPath(path1);


        break;
    }
    case text:
    {
        painter.drawText(rect1 , Qt::AlignCenter , tr("Qt Text"));

        painter.setPen(penDot);
        QPoint pos;
        QPoint pos1;
        QPoint pos2;
        QPoint pos3;

        pos = rect1.bottomLeft();
        p.setX( pos.x() );
        p.setY( pos.y() );
        // update hitbox
        pXL.setX( p.x() - 6 );
        pXR.setX( p.x() + 6 );
        pXL.setY( p.y() );
        pXR.setY( p.y() );
        pYT.setX( p.x() );
        pYB.setX( p.x() );
        pYT.setY( p.y() - 6 );
        pYB.setY( p.y() + 6 );

        pos1 = rect1.bottomRight();
        p1.setX( pos1.x() );
        p1.setY( pos1.y() );
        // update hitbox
        p1XL.setX( p1.x() - 6 );
        p1XR.setX( p1.x() + 6 );
        p1XL.setY( p1.y() );
        p1XR.setY( p1.y() );
        p1YT.setX( p1.x() );
        p1YB.setX( p1.x() );
        p1YT.setY( p1.y() - 6 );
        p1YB.setY( p1.y() + 6 );

        pos2 = rect1.topLeft();
        p2.setX( pos2.x() );
        p2.setY( pos2.y() );
        // update hitbox
        p2XL.setX( p2.x() - 6 );
        p2XR.setX( p2.x() + 6 );
        p2XL.setY( p2.y() );
        p2XR.setY( p2.y() );
        p2YT.setX( p2.x() );
        p2YB.setX( p2.x() );
        p2YT.setY( p2.y() - 6 );
        p2YB.setY( p2.y() + 6 );

        pos3 = rect1.topRight();
        p3.setX( pos3.x() );
        p3.setY( pos3.y() );
        // update hitbox
        p3XL.setX( p3.x() - 6 );
        p3XR.setX( p3.x() + 6 );
        p3XL.setY( p3.y() );
        p3XR.setY( p3.y() );
        p3YT.setX( p3.x() );
        p3YB.setX( p3.x() );
        p3YT.setY( p3.y() - 6 );
        p3YB.setY( p3.y() + 6 );


        painter.drawPoint(pos);
        painter.drawPoint(pos1);
        painter.drawPoint(pos2);
        painter.drawPoint(pos3);

        break;
}
    case polygon:
    {
        static const QPoint points[4] = {
            QPoint(10 , 100),
            QPoint(20 , 10),
            QPoint(100 , 30),
            QPoint(90 , 72)

        };
        painter.setPen(pen);
        painter.drawPolygon(points , 4);

        p.setX( points[0].x() );
        p.setY( points[0].y() );
        // update hitbox
        pXL.setX( p.x() - 6 );
        pXR.setX( p.x() + 6 );
        pXL.setY( p.y() );
        pXR.setY( p.y() );
        pYT.setX( p.x() );
        pYB.setX( p.x() );
        pYT.setY( p.y() - 6 );
        pYB.setY( p.y() + 6 );

        p1.setX( points[1].x() );
        p1.setY( points[1].y() );
        // update hitbox
        p1XL.setX( p1.x() - 6 );
        p1XR.setX( p1.x() + 6 );
        p1XL.setY( p1.y() );
        p1XR.setY( p1.y() );
        p1YT.setX( p1.x() );
        p1YB.setX( p1.x() );
        p1YT.setY( p1.y() - 6 );
        p1YB.setY( p1.y() + 6 );

        p2.setX( points[2].x() );
        p2.setY( points[2].y() );
        // update hitbox
        p2XL.setX( p2.x() - 6 );
        p2XR.setX( p2.x() + 6 );
        p2XL.setY( p2.y() );
        p2XR.setY( p2.y() );
        p2YT.setX( p2.x() );
        p2YB.setX( p2.x() );
        p2YT.setY( p2.y() - 6 );
        p2YB.setY( p2.y() + 6 );

        p3.setX( points[3].x() );
        p3.setY( points[3].y() );
        // update hitbox
        p3XL.setX( p3.x() - 6 );
        p3XR.setX( p3.x() + 6 );
        p3XL.setY( p3.y() );
        p3XR.setY( p3.y() );
        p3YT.setX( p3.x() );
        p3YB.setX( p3.x() );
        p3YT.setY( p3.y() - 6 );
        p3YB.setY( p3.y() + 6 );



        painter.drawPoint(points[0]);
        painter.drawPoint(points[1]);
        painter.drawPoint(points[2]);
        painter.drawPoint(points[3]);

    }
    }

}
//*****************************************************************************************************************
void shape::setShape(shape::Shape forma)
{
    this->s = forma;
    update();
}
                                                    // referenced from basicdrawing qt ex
                                                   // http://doc.qt.io/qt-5/qtwidgets-painting-basicdrawing-example.html
//*******************************************************************************
void shape::getShape(char p)
{
    v = p;
    if (p == 'r')
    {
        setShape(rect);
        return;
    }
    else if ( p == 'a' )
    {
        setShape(arc);
        return;
    }
    else if ( p == 'p')
    {
        setShape(path);
        return;
    }
    else if (p == 't')
    {
        setShape(text);
        return;
    }
    else
        setShape(polygon);
    return;
}
//***************************************************************************************************************
void shape::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        startPos = event->pos();
        moving = true;
        mouseMoveEvent(event);
    }
   // shape::mouseMoveEvent(event);

}
//***************************************************************************************************************
void shape::mouseMoveEvent(QMouseEvent *event)
{
    if( (event->buttons() & Qt::LeftButton) && moving)
    {


            if(startPos.x() >= p1XL.x() && startPos.x() <= p1XR.x() && startPos.y() >= p1YT.y() && startPos.y() <= p1YB.y())
            {
                zeta = event->pos();
                rect1.setBottomRight(zeta);
                moving = true;
                update();
                mouseReleaseEvent(event);
                return;
            }
            else if (startPos.x() >= p2XL.x() && startPos.x() <= p2XR.x() && startPos.y() >= p2YT.y() && startPos.y() <= p2YB.y() )
            {
                eta = event->pos();
                rect1.setTopLeft(eta);
                moving = true;
                update();
                mouseReleaseEvent(event);
                return;
            }
            else if (this)
            {
                // move(drag) object where user wants
                int distance = (event->pos() - startPos).manhattanLength();
                if (distance >= 4)
                    this->pos() = event->pos();
                    move( mapToParent(event->pos() ));
                    moving = true;
                    update();
                    raise();
                    mouseReleaseEvent(event);
                    return;
            }
            else
            {
                moving = false;
            }

        // }
    }
}
//***************************************************************************************************************
void shape::mouseReleaseEvent(QMouseEvent *event)
{
/*
    if ((event->button() & Qt::LeftButton) && moving)
    {
        p2 = eta;
        // updat hit box for zeta
        p2XL.setX( p2.x() - 6 );
        p2XR.setX( p2.x() + 6 );
        p2XL.setY( p2.y() );
        p2XR.setY( p2.y() );
        p2YT.setX( p2.x() );
        p2YB.setX( p2.x() );
        p2YT.setY( p2.y() - 6 );
        p2YB.setY( p2.y() + 6 );

        p1 = zeta;
        // update hitbox for eta
        p1XL.setX( p1.x() - 6 );
        p1XR.setX( p1.x() + 6 );
        p1XL.setY( p1.y() );
        p1XR.setY( p1.y() );
        p1YT.setX( p1.x() );
        p1YB.setX( p1.x() );
        p1YT.setY( p1.y() - 6 );
        p1YB.setY( p1.y() + 6 );

        if(startPos.x() >= p1XL.x() && startPos.x() <= p1XR.x() && startPos.y() >= p1YT.y() && startPos.y() <= p1YB.y())
        {
            zeta = event->pos();

            p1 = zeta;

            // update hitbox for eta
            p1XL.setX( p1.x() - 6 );
            p1XR.setX( p1.x() + 6 );
            p1XL.setY( p1.y() );
            p1XR.setY( p1.y() );
            p1YT.setX( p1.x() );
            p1YB.setX( p1.x() );
            p1YT.setY( p1.y() - 6 );
            p1YB.setY( p1.y() + 6 );

            moving = false;
            update();
            return;
        }
        else if (startPos.x() >= p2XL.x() && startPos.x() <= p2XR.x() && startPos.y() >= p2YT.y() && startPos.y() <= p2YB.y() )
        {

            eta = event->pos();
            p2 = eta;
            // updat hit box for zeta
            p2XL.setX( p2.x() - 6 );
            p2XR.setX( p2.x() + 6 );
            p2XL.setY( p2.y() );
            p2XR.setY( p2.y() );
            p2YT.setX( p2.x() );
            p2YB.setX( p2.x() );
            p2YT.setY( p2.y() - 6 );
            p2YB.setY( p2.y() + 6 );

            moving = false;
            update();

            return;
        }
        else if (this )
        {
            this->pos() = event->pos();
            moving = false;
            update();
            raise();

            return;
        }
    }
*/
}
//*****************************************************************************************************************
shape::shape(QWidget *parent) : QWidget(parent) , p(0,0) , p3(0,0) , startPos(0 , 0) ,
                                eta(0 , 0) , zeta(100 , 50)
{

    s = polygon;     

   rect1.setBottomRight(zeta);
   rect1.setTopLeft(eta);
   p1 = zeta;
   p2 = eta;

    pXL.setX( p.x() - 6 );
    pXR.setX( p.x() + 6 );
    pXL.setY( p.y() );
    pXR.setY( p.y() );
    pYT.setX( p.x() );
    pYB.setX( p.x() );
    pYT.setY( p.y() - 6 );
    pYB.setY( p.y() + 6 );

    p1XL.setX( p1.x() - 6 );
    p1XR.setX( p1.x() + 6 );
    p1XL.setY( p1.y() );
    p1XR.setY( p1.y() );
    p1YT.setX( p1.x() );
    p1YB.setX( p1.x() );
    p1YT.setY( p1.y() - 6 );
    p1YB.setY( p1.y() + 6 );

    p2XL.setX( p2.x() - 6 );
    p2XR.setX( p2.x() + 6 );
    p2XL.setY( p2.y() );
    p2XR.setY( p2.y() );
    p2YT.setX( p2.x() );
    p2YB.setX( p2.x() );
    p2YT.setY( p2.y() - 6 );
    p2YB.setY( p2.y() + 6 );

    p3XL.setX( p3.x() - 6 );
    p3XR.setX( p3.x() + 6 );
    p3XL.setY( p3.y() );
    p3XR.setY( p3.y() );
    p3YT.setX( p3.x() );
    p3YB.setX( p3.x() );
    p3YT.setY( p3.y() - 6 );
    p3YB.setY( p3.y() + 6 );






//    setBackgroundRole(QPalette::NoSy);
//    setAutoFillBackground(true);
    setAttribute(Qt::WA_NoSystemBackground);

}


//*****************************************************************************************************************


