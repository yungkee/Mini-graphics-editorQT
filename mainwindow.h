#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QAction>
#include <QResizeEvent>
#include <QColorDialog>
#include <QSpinBox>
#include "scene.h"
#include "rectangle.h"
#include "line.h"
#include <QList>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    /* Перегружаю событие  изменение размеров графической сцены в зависимости от изменения размеров экрана
      говоря рабоче-крестьянским языком, если этого не делать, то можно расширить главное окно
     *  (например на весь экран, а размер окна рисования останется прежним, что очень неудобно
        * */
     void resizeEvent(QResizeEvent* event);

private:
    Ui::MainWindow *ui;

    Scene* m_scene;
    QGraphicsView* m_view; // мой кастомный виджет
    QColor m_color;
    int m_lineWidth;

private slots:
    void on_actionCreate_Line_triggered(); // Включаю отрисовку линии

    void on_actionCreate_Rectangle_triggered(); // Включаю отрисовку прямоугольника

    void on_actionCreate_Ellipse_triggered(); // Включаю отрисовку круга

    void on_actionCreate_Color_triggered(); // Включаю палитру цветов

    void on_actionErase_triggered(); // очистка

};

#endif // MAINWINDOW_H
