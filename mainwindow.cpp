#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    temp = "Output.png";
    defaultPath = "/home/harshavardhanbabu/Documents/Gnuplot/gnuplot-iostream";
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionLoad_File_triggered()
{
   fileName = QFileDialog::getOpenFileName(this, tr("Open File"),defaultPath,tr("Data files (*.dat)"));
   qDebug()<<fileName<<endl;

}

void MainWindow::on_plot_clicked()
{
    int x = ui->X->value();
    int y = ui->Y->value();
    int z = ui->Z->value();

    qDebug()<<x<<y<<z<<endl;

    createTempDir(QFileInfo(fileName).path() + "/tmp");
    gp<<"set t png;\n";
    gp<<"set output '"<<temp.toStdString()<<"';\n";
    gp<<"set pm3d map;\n";
    gp<<"unset key;\n";
    gp<<"splot '"<<fileName.toStdString()<<"' u "<<x<<":"<<y<<":"<<z<<";\n";
    gp<< std::endl;
    gp<<"reset;\n";
    qDebug()<<"Plotted"<<fileName<<"....."<<temp;
    QPixmap image;
    QImage  *imageObject;
    QGraphicsScene *scene;
    imageObject = new QImage();
    imageObject->load(temp);
    image = QPixmap::fromImage(*imageObject);
    int height = image.height();
    int width = image.width();
    scene = new QGraphicsScene(this);
    scene->addPixmap(image);
    scene->setSceneRect(image.rect());
    ui->graphicsView->setFixedHeight(height+20);
    ui->graphicsView->setFixedWidth(width+20);
    ui->graphicsView->setScene(scene);
}
void MainWindow::createTempDir(QString dirPath)
{
    QDir dir(dirPath);
    if (!dir.exists())
    {
        dir.mkpath(".");
        qDebug()<<"Temporary folder created..."<<endl;
    }
}
