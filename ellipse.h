#ifndef ELLIPSE_H
#define ELLIPSE_H
#include "shape.h"

/* Наследуюсь от класса Shape,
 * в котором реализован общий для всех фигур функционал
 * */
class Ellipse : public Shape
{
public:
    Ellipse(QObject *parent = 0);
    /* Определяю метод для отрисовки круга
         * */
    void paint(QPainter *painter, const QStyleOptionGraphicsItem*, QWidget*);
};

#endif // ELLIPSE_H
