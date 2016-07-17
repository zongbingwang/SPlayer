#ifndef VIDEOLIST_H
#define VIDEOLIST_H

#include <QDebug>
#include <List>
#include <QTextCodec>
#include <QFileInfo>
#include <QDesktopServices>
#include <QUrl>

class VideoList
{
public:
    VideoList();
    ~VideoList();

    //清空队列
    void clearList();

    //增加至队列,返回文件名
    QString addFile(QString);

    //获取文件名
    QString getFileName(QString);

    //从队列删除
    void deleteFile(int);

    //下一首
    bool next();

    //上一首
    bool last();


    //打开文件所在目录
    void openDir(int);

    //设置要播放的项
    void setCurrentItem(int);

    //获取要播放项的URL
    QString getCurrentItem();

    //获取第row项的文件
    QString getItem(int);

    //获取当前播放的序号
    int getCurrentItemNum();

    //从文件读取信息
    void readFromFile();

    //写入信息到文件
    void writeToFile();

    //返回播放队列
    QList<QString> getList();

private:
    //目前播放的序号
    int currentItem;

    //播放队列
    QList<QString> LIST;
};

#endif // VIDEOLIST_H
