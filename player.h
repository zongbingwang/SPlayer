#ifndef PLAYER_H
#define PLAYER_H

#include <phonon>
#include <QWidget>
#include <QLabel>
#include <QLayout>
#include <QPushButton>
#include <QMessageBox>
#include <QString>
#include <QFileDialog>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QDateTime>
#include <QDebug>
#include <QDragEnterEvent>
#include <QUrl>
#include <QFile>
#include <QTextStream>
#include <QListWidget>
#include <QMenu>
#include <QtGui>
#include "media.h"
#include "setting.h"

namespace Ui {
    class player;
}

class player : public QWidget
{
    Q_OBJECT

public:
    explicit player(QWidget *parent = 0);
    ~player();
    void keyPressEvent(QKeyEvent * event);
    int flat;
    ////////////获取和设置按钮状态///////////////
    bool getPlayState();
    bool getScreenState();
    bool getHideState();
    void setPlayState(bool value);
    void setScreenState(bool value);
    void setHideState(bool value);
    ///////////////////////////////////////
protected:
    void dragEnterEvent(QDragEnterEvent *event);
    void dropEvent(QDropEvent *event);
    void mousePressEvent (QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent (QMouseEvent *event);
    bool eventFilter(QObject *obj,QEvent *event);
    //////////////列表处理函数/////////////////
    void initList();
    /////////////////////////////////////////

private slots:
    void onClickedButtonPlay();
    void onClickedButtonStop();
    void onClickedButtonScreen();
    void onClickedButtonGoFarword();
    void onClickedButtonDrawBack();
    void onClickedButtonShot();
    QImage gifscreenShot();
    void onClickedButtonClose();
    void onClickedButtonMaximize();
    void onClickedButtonMinimize();
    void onClickedButtonSet();
    void onClickedButtonFile();
    void onClickedButtonSkin();
    void onClickedButtonNext();
    void onClickedButtonLast();
    void onClickedButtonGif();
    //void onClickedButtonHide();
    //////////////时间处理函数/////////////////
    void setTotalTime();
    void setTotalTime(qint64);
    void setCurrentTime(qint64);
    /////////////////////////////////////////
    //////////////设置选项处理函数/////////////////
    void setSetting(int, int, int, int, int, int);
    /////////////////////////////////////////
    ////////////////列表处理函数//////////////////
    void addList();
    void playList();
    void deleteList();
    void insertList();
    void openDirList();
    void clearList();
    void playContine();
    void on_videoList_customContextMenuRequested(const QPoint &pos);
    void setBackgroundList();
    ///////////////////////////////////////////


private:
    Ui::player *ui;
    //Phonon::VideoWidget *videoWidget;
    //Phonon::MediaObject *mediaObject;
    //Phonon::AudioOutput *audioOutput;
    Media *media;

    QPushButton *buttonPlay;
    QPushButton *buttonStop;
    QPushButton *buttonGoFarword;
    QPushButton *buttonDrawBack;
    QPushButton *buttonFullScreen;
    QPushButton *buttonHide;
    QPushButton *buttonShot;
    QPushButton *buttonClose;
    QPushButton *buttonMaximize;
    QPushButton *buttonMinimize;
    QPushButton *buttonSet;
    QPushButton *buttonFile;
    QPushButton *buttonSkin;
    QPushButton *buttonNext;
    QPushButton *buttonLast;
    QPushButton *buttonGif;
    QLabel *currentTime;
    QLabel *totalTime;

    bool m_Drag;            //看是否应该改变窗口的位置
    QPoint m_DragPosition;  //移动前窗口的位置

    QListWidget *videoList; //播放列表
    Setting *setting; //设置窗口

    bool buttonPlayState;   //true:显示播放按钮 false:显示暂停按钮
    bool buttonScreenState; //true:显示全屏按钮 false:显示非全屏按钮
    bool buttonHideState;   //true:显示列表     false:隐藏列表

    int step;//前进后退的时间
    int numGif;//GIF图片的张数

protected:
    QPoint dragPosition;
    bool bPressFlag;
    QSplitter *splitter;
    QWidget *contentFrame;
    QWidget *listFrame;
    QPushButton *pushButton;
    QIcon leftIcon;
    QIcon rightIcon;

    //QPushButton *setButton;

//    void mousePressEvent (QMouseEvent *event);
//    void mouseMoveEvent(QMouseEvent *event);
//    void mouseReleaseEvent(QMouseEvent *event);
    void resizeEvent(QResizeEvent *event);
    //bool eventFilter(QObject *obj, QEvent *event);

private:
    void setBtnPos();
    void setBtnIcon();

private slots:
    void slotClickedBtn();
    void slotSplitterMoved(int pos, int index);
};

#endif // PLAYER_H
