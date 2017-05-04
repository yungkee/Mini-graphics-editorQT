/* Здесь я описываю функционал:
Добавление графической сцены, отрисовка объектов на графической сцене с помощью линий,
 изменение размеров графической сцены в зависимости от изменения размеров экрана, */
#ifndef SCENE_H
#define SCENE_H
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsSceneMouseEvent>
#include <QList>
#include "shape.h"
enum Regim {isDraw = 1, isScale}; //я использую булеву переменную isDraw  чтобы дать сигнал программе начать рисовать,
//если draw = 1. значит true и можно рисовать мышкой, и .....дальше выбирается фигура и так далее

enum Shapes {line = 1, rectangle, ellips};

class Scene : public QGraphicsScene //класс где содержится сцена где мы  будем всё рисовать
{
    Q_OBJECT
public:
    Scene(Shape* item, QObject *parent = 0);
private:
   // Функция, в которой производится отслеживание положения мыши
    void mousePressEvent(QGraphicsSceneMouseEvent* event);
    //метод mouseMoveEvent производится перерисовка фигуры в зависимости от положения курсора мыши до тех пор, пока кнопка мыши не будет отпущена.
    void mouseMoveEvent(QGraphicsSceneMouseEvent* event);
private:
    /* Объект для временного хранения рисуемой фигуры
         * Является объектом базового класса для всех типов фигур в моём примере (то есть для прямоугольника, круга  и линии
         * */
    Shape* m_item;
    int m_shapeName; // текущий тип фигуры

    Regim m_regim;
    float m_startCoordSceneX;
    float m_startCoordSceneY;
    float m_setScreenPosX;
    float m_setScreenPosY;
    QColor m_color;             // создают объект класса Qcolor для определения цвета линии
    int m_width;                // размер линии
    QList<Shape*> m_shapeList;  // контейнер где буду содержать фигуры

    enum{vScale = 2};
public:
    void SetFigure(int idFigure);
    void SetColor(QColor color);
    void SetWidth(int width);
    void clearShapelist();
};

#endif // SCENE_H
