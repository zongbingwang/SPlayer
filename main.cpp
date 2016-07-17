#include <QtGui/QApplication>
#include "mainwindow.h"
#include <QTextCodec>
#include "player.h"
#include "ui_player.h"
#include <QMotifStyle>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setApplicationName("SPlayer");
    QTextCodec::setCodecForTr(QTextCodec::codecForLocale());
    QTextCodec::setCodecForLocale(QTextCodec::codecForLocale());
    QTextCodec::setCodecForCStrings(QTextCodec::codecForLocale());
    MainWindow pg;
    pg.show();
    pg.processbar();

    player *w = new player();
    w->setWindowFlags(Qt::FramelessWindowHint);
    pg.close();

    w->show();

    /*
    player w;
    w.setWindowFlags(Qt::FramelessWindowHint);
    pg.close();

    w.show();
    */

    return a.exec();
}
