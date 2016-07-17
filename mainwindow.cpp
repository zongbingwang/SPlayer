#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "windows.h"
#include "player.h"
#include "ui_player.h"
#include <QMovie>
#include <QPalette>
#include <QDesktopWidget>
#include <QPoint>
#include <QMotifStyle>
#include <QPlastiqueStyle>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
      ui->setupUi(this);
      QMovie *movie = new QMovie(":/image/donghua.gif");//welcome gif
      ui->label->setMovie(movie);
      movie->start();
      num=100;
      ui->progressBar->setRange(0,num);
      ui->progressBar->setStyle(new QPlastiqueStyle);
      setWindowFlags(Qt::FramelessWindowHint);//ÎÞ±ß¿ò
      setAttribute(Qt::WA_TranslucentBackground);//±³¾°Í¸Ã÷
      //ÆÁÄ»¾ÓÖÐÏÔÊ¾
      int frmX = width();
      int frmY = height();
      QDesktopWidget w;
      int deskWidth = w.width();
      int deskHeight = w.height();
      QPoint movePoint(deskWidth / 2 - frmX / 2, deskHeight / 2 - frmY / 2);
      move(movePoint);
    QPalette palette1 = ui->label2->palette();
    palette1.setColor(QPalette::WindowText,Qt::cyan);
    ui->label2->setPalette(palette1);
//    QPalette palette2 = ui->progressBar->palette();
//    palette2.setColor(QPalette::ToolTipText,Qt::yellow);
//    ui->progressBar->setPalette(palette2);

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::processbar()
{
    for(int i=1;i<=num;++i)
    {
        ui->progressBar->setValue(i);
        Sleep(5);
    }
}

