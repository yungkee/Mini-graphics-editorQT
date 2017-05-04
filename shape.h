#ifndef SHAPE_H
#define SHAPE_H
#include <QPainter>
#include <QColor>
#include <QGraphicsItem>

//Создаю базовый класс Shape (фигура по-английски) , который наследован от QGraphicsItem
// и реализую весь основной функционал в данном классе, а потом уже создаю три класса (линия, круг и прямоугольник)
// которые будут наследованы от данного класса,
//но реализовать в них только метод отрисовки самой фигуры: Line, Rectangle, ellipse.
class Shape : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    Shape(QObject *parent = 0);
    QRectF boundingRect() const; // Область, в которой содержится фигура

    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem*, QWidget*) = 0; // виртуальная функция обычная
    //определяет свойства, а последующие методы, базирующие на базовом paint, будут их реализовывать

    void setSecondX(float sX); // Установка стартовых точек
    void setSecondY(float sY);
    void setColor(QColor value);
    void setWidth(int width);
    void setPen(QColor color, int width);

    float getFirstX() const;  // Установка конечных точек
    float getFirstY() const;
    float getSecondX() const;
    float getSecondY() const;
    QPen getPen();

private:
    float m_firstX; // Стартовая точка
    float m_firstY;
    float m_secondX; // Конечная точка
    float m_secondY;

    QColor m_color;     // цвет фигуры
    int m_width;        // переменная определяющая размер очертания линии
    QPen m_pen;
    enum Coord {firstCoord = 1, secondCoord};
};

#endif // SHAPE_H
