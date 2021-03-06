#include "minotauro.h"

minotauro::minotauro(QObject *parent) : QObject(parent)
{
    timer = new QTimer();
    filas = 0;
    columnas = 0;

    pixmap = new QPixmap(":/pictures/minotauro.png");

    timer->start(120);
    connect(timer,&QTimer::timeout,this,&minotauro::actualizacion_sprites_minotauro);
}

QRectF minotauro::boundingRect() const
{
    return QRectF(-ancho/2,-alto/2,ancho,alto);
}

void minotauro::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-ancho/2,-alto/2,*pixmap,columnas,filas,ancho,alto);
}

void minotauro::actualizar_minotauro()
{
    setPos(posx,posy);
    actualizacion_sprites_minotauro();
}

void minotauro::actualizacion_sprites_minotauro()
{
    if (moment == 0 ){
        filas = 0;
        columnas += 52;
        if(columnas >= 260){
            columnas =0;
        }
    }
    else if (moment == 1){
        filas = 42;
        columnas += 52;
        if(columnas >= 260){
            columnas =0;
        }
    }
    else if (moment == 2){
        filas = 84;
        columnas += 52;
        if(columnas >= 416){
            columnas =0;
        }
    }
    else if (moment == 3){
        filas = 126;
        columnas += 52;
        if(columnas >= 416){
            columnas =0;
        }
    }

    if (moment == 3){moment = 1;}
    if (moment == 2){moment = 0;}

    this->update(-ancho/2, -alto/2, ancho, alto);
}
