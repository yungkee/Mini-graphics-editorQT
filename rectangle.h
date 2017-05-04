#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "shape.h"

/* Наследуюсь от класса Shape,
 * в котором реализован общий для всех фигур функционал
 * */
class Rectangle : public Shape
{
public:
    Rectangle(QObject *parent = 0);
    /* Определяю метод для отрисовки прямоульника
         * */
    void paint(QPainter *painter, const QStyleOptionGraphicsItem*, QWidget*);
};

#endif // RECTANGLE_H
