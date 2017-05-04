#ifndef LINE_H
#define LINE_H
#include "shape.h"

/* Наследуюсь от класса Shape,
 * в котором реализован общий для всех фигур функционал
 * */
class Line : public Shape
{
public:
    Line(QObject *parent = 0);
    /* Определяю метод для отрисовки линии
         * */
    void paint(QPainter *painter, const QStyleOptionGraphicsItem*, QWidget*);
};

#endif // LINE_H
