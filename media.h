#ifndef MEDIA_H
#define MEDIA_H

#include <QWidget>
#include <QAction>
#include <phonon>
#include <QDebug>
#include "videolist.h"

class Media
{
public:
    Media(QWidget * parent);
    ~Media();

    //设置路径
    void setPath(QString path);

    //快进播放value时间
    void goFoward(qint64 value);

    //后退播放value时间
    void goBack(qint64 value);

    //MediaObject AudioObject
     Phonon::MediaObject *mediaObject;
     Phonon::AudioOutput *audioOutput;
     Phonon::VideoWidget *videoWidget;
     VideoList * playlist;

 public slots:

     //槽函数与aboutfinish连接
     void readyToPlay();

private:
    //全屏播放,true为全屏,false为非全
    void setFullScreen(bool);

    //退出全屏
    void exitFullScreen();

    //获取当前播放时间
    qint64 currentTime();

    //暂停播放
    void pause();

    //开始播放
    void play();

    //停止播放
    void stop();

    //快速定位至value位置播放
    void locate(qint64 value);

    //设置对比度
    void setContrast(qint8 value);

    //设置饱和度
    void setSaturation(qint8 value);

    //设置亮度
    void setBrightness(qint8 value);

    //设置色调
    void setHue(qint8 value);

    //设置宽高比
    void setAspectRatio(Phonon::VideoWidget::AspectRatio);
};

#endif // MEDIA_H
