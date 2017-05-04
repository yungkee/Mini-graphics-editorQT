#include "scene.h"
#include "rectangle.h"
#include "ellipse.h"
#include "line.h"
#include <QDebug>
Scene::Scene(Shape *item, QObject *parent) : m_item(item), m_shapeName(1), m_regim(isDraw), QGraphicsScene(parent), m_width(1)
{

}

/* Когда нажимается кнопка мыши, создаётся фигура одного из трёх типов (линия, кргу или прямоугольник
 * и помещаем её на сцену, сохранив указатель на неё в переменных
 * m_startCoordScene
 * */
void Scene::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
    //отрисовка по координатам
    if (((event->scenePos().x() >= m_setScreenPosX) && event->scenePos().x() <= m_setScreenPosX + vScale) &&
            ((event->scenePos().y() >= m_setScreenPosY) && event->scenePos().y() <= m_setScreenPosY + vScale)) {
        m_regim = isScale;
    }
    else
    {
        m_regim = isDraw; //использую булеву переменную isDraw  чтобы дать сигнал программе начать рисовать,
        //если draw = 1. значит true и можно рисовать мышкой, и дальше выбирается фигура
    }
    if (m_regim == isDraw) {
        switch (m_shapeName)
        {
        case line: //выбираю линию
            m_item = new Line(this);
            break;
        case rectangle: //выбираю прямоугольник
            m_item = new Rectangle(this);
            break;
        case ellips: //выбираю круг
            m_item = new Ellipse(this);
            break;
        default:
            break;
        }
        m_item->setPos(event->scenePos());
        m_item->setPen(m_color,m_width); //m_width по умолчанию 1 равен (размер линий не задавал, стандарт)
        m_startCoordSceneX = event->scenePos().x();
        m_startCoordSceneY = event->scenePos().y();

            m_shapeList.append(m_item);
            addItem(m_item);
        }
    }




void Scene::mouseMoveEvent(QGraphicsSceneMouseEvent* event)
{
    m_setScreenPosX = event->scenePos().x();
    m_setScreenPosY = event->scenePos().y();
    m_item->setSecondX(event->scenePos().x() - m_startCoordSceneX);
    m_item->setSecondY(event->scenePos().y() - m_startCoordSceneY);
    /* Обновляем содержимое сцены,
        * необходимо для устранения артефактов при отрисовке фигур
        * */
    update(QRectF(0,0,width(), height()));
}

void Scene::clearShapelist() {
    while(!m_shapeList.empty()) {
        m_shapeList.pop_front();
    }
}



void Scene::SetColor(QColor color)
{
    m_color = color;
}

void Scene::SetFigure(int idFigure)
{
    m_shapeName = idFigure;
}
