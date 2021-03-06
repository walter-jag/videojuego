#ifndef DIS_JEFE_2_H
#define DIS_JEFE_2_H

#include <QObject>
#include <QPixmap>
#include <QTimer>
#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include "elemento.h"
#include <stdlib.h>
#include <time.h>

class dis_jefe_2: public QObject, public QGraphicsItem
{
public:
    explicit dis_jefe_2(QObject *parent = nullptr);

    QTimer *timer;
    QPixmap *pixmap;

    float filas, columnas;
    int moment = 0;

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,QWidget *widget);

    void dis_jefe();

    float posx = 0; //Posicion en X
    float posy = 0;  //Posicion en Y
    float ancho = 21; //Ancho de la figura
    float alto = 49; // Alto de la figura

public slots:
    void actualizar_dis_jefe();
};

#endif // DIS_JEFE_2_H
