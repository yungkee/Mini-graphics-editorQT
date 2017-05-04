#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /* Инициализируем виджет с графикой */
    m_scene = new Scene(new Rectangle, this);
    m_view = new QGraphicsView(this);
    /* Устанавливаю размер сцены по размеру виджета
        * Первая координата - это левый верхний угол,
        * а Вторая - это правый нижний угол
        * */
    m_scene->setSceneRect(0, 0, MainWindow::width(), MainWindow::height());
    m_view->setScene(m_scene);
    setCentralWidget(m_view);

}

MainWindow::~MainWindow()
{
    delete ui;
}

// обьявления события изменение размеров графической сцены в зависимости от изменения размеров экрана
void MainWindow::resizeEvent(QResizeEvent* event)
{
    m_scene->setSceneRect(0,0, MainWindow::width(), MainWindow::height());
    QMainWindow::resizeEvent(event);
}
//линия
void MainWindow::on_actionCreate_Line_triggered()
{
   m_scene->SetFigure(line);
}

//прямоугольник
void MainWindow::on_actionCreate_Rectangle_triggered()
{
    m_scene->SetFigure(rectangle);
}
//эллипс
void MainWindow::on_actionCreate_Ellipse_triggered()
{
    m_scene->SetFigure(ellips);
}

//палитра
void MainWindow::on_actionCreate_Color_triggered()
{
    m_color = QColorDialog::getColor(Qt::white, this); //белый по умолчанию
    m_scene->SetColor(m_color);
}

//очистка экрана
void MainWindow::on_actionErase_triggered()
{
    m_scene->clear();
    m_scene->clearShapelist();
    m_scene->update(0, 0, MainWindow::width(), MainWindow::height());

}
