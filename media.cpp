#include "media.h"

Media::Media(QWidget * parent = 0)
{
    //创建媒体图
    mediaObject = new Phonon::MediaObject(parent);
    audioOutput = new Phonon::AudioOutput(Phonon::VideoCategory,parent);
    videoWidget = new Phonon::VideoWidget(parent);

    playlist = new VideoList();

    //连接起来
    Phonon::createPath(mediaObject, videoWidget);
    Phonon::createPath(mediaObject, audioOutput);

    //aboutFinish
    //在widget类里面连接
    //connect(mediaObject, SIGNAL(aboutToFinish()), this, SLOT(readyToPlay()));
}

Media::~Media()
{
    //delete mediaObject;
    //delete audioOutput;
    //delete videoWidget;
    //delete playlist;
}

void Media::setPath(QString fileName)
{
    mediaObject->setCurrentSource(Phonon::MediaSource(fileName));
}

void Media::readyToPlay()
{
    //next
    //current+
    //加入队列

    if (playlist->next())
    {
        mediaObject->enqueue(Phonon::MediaSource(playlist->getCurrentItem()));
    }

    //如果是下一首
    //mediaObject->stop();
    //。。。。
    //mediaObject->play();
}


//暂停播放
void Media::pause()
{
    mediaObject->pause();
}

//开始播放
void Media::play()
{
    mediaObject->play();
}

//停止播放
void Media::stop()
{
    mediaObject->stop();
}

//快进播放value时间
void Media::goFoward(qint64 value)
{
    if (value <= mediaObject->remainingTime())
    {
        mediaObject->seek(mediaObject->currentTime() + value);
    }
    else
    {
        mediaObject->seek(mediaObject->totalTime());
    }
}

//后退播放value时间
void Media::goBack(qint64 value)
{
    if (value <= mediaObject->currentTime())
    {
        mediaObject->seek(mediaObject->currentTime() - value);
    }
    else
    {
        mediaObject->seek(0);
    }
}

//快速定位至value位置播放
void Media::locate(qint64 value)
{
    mediaObject->seek(value);
}

//全屏播放,true为全屏,false为非全屏
void Media::setFullScreen(bool flag)
{
    videoWidget->setFullScreen(flag);
}

//退出全屏
void Media::exitFullScreen()
{
    videoWidget->exitFullScreen();
}

//设置对比度
void Media::setContrast(qint8 value)
{
    videoWidget->setContrast(value / 10.0);
}

//设置饱和度
void Media::setSaturation(qint8 value)
{
    videoWidget->setSaturation(value / 10.0);
}

//设置亮度
void Media::setBrightness(qint8 value)
{
    videoWidget->setBrightness(value / 10.0);
}

//设置色调
void Media::setHue(qint8 value)
{
    videoWidget->setBrightness(value / 10.0);
}

//设置分辨率
void Media:: setAspectRatio(Phonon::VideoWidget::AspectRatio value)
{
    videoWidget->setAspectRatio(value);
}

//获取当前时间
qint64 Media::currentTime()
{
    return mediaObject->currentTime();
}

