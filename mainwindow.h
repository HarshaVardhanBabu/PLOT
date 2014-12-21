#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "gnuplot-iostream.h"
#include "math.h"
#include <QFileDialog>
#include <QGraphicsScene>
#include <QDebug>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionLoad_File_triggered();

    void on_plot_clicked();

private:
    Ui::MainWindow *ui;
    QString fileName;
    QString defaultPath;
    Gnuplot gp;
    QString temp;
    void createTempDir(QString dirPath);

};

#endif // MAINWINDOW_H
