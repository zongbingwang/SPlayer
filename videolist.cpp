#include "videolist.h"

VideoList::VideoList()
{
    readFromFile();
}

VideoList::~VideoList()
{
    writeToFile();
    //LIST.clear();
}

void VideoList::readFromFile()
{
    currentItem = 0;
    LIST.clear();

    QFile myfile("playlist.txt");
    if(!myfile.open(QIODevice::ReadOnly | QIODevice::Text)) return;
    QString currentItemLine = myfile.readLine();
    currentItem = currentItemLine.mid(0, currentItemLine.length()-1).toInt();
    qDebug() << currentItem;
    while(!myfile.atEnd())
    {
        QString line = myfile.readLine();
        LIST.append(line.mid(0,line.length()-1));
        qDebug() << line;
    }
    myfile.close();
}

void VideoList::writeToFile()
{
    QFile myfile("playlist.txt");
    if(!myfile.open(QIODevice::WriteOnly | QIODevice::Truncate| QIODevice::Text)) return;
    QTextStream out(&myfile);
    out << currentItem << "\n";
    for(int i = 0; i < LIST.size(); ++i)
    {
        QString path=LIST.at(i);
        out <<path<<"\n";
    }
    myfile.close();
}

void VideoList::clearList()
{
    currentItem = 0;
    LIST.clear();
}

QString VideoList::addFile(QString filepath)
{
    LIST.append(filepath);
    return getFileName(filepath);
}

QString VideoList::getFileName(QString filepath)
{
    int pathsize;
    pathsize = filepath.length() - 1;
    while(pathsize>0)
    {
        if(filepath.compare(filepath.mid(pathsize,1),"/")==0) break;
        pathsize--;
    }
    filepath=filepath.mid(pathsize + 1, filepath.length());
    return filepath;
}

void VideoList::deleteFile(int row)
{
    qDebug() << "row:" << row;

    //如果删除的在前边需要减一
    if (row < currentItem) currentItem--;
    LIST.takeAt(row);
}

QString VideoList::getItem(int row)
{
    if (row >= 0 && row <LIST.size())
        return LIST.at(row);
    else
        qDebug() << "error in getItem!";
    return "error";
}

int VideoList::getCurrentItemNum()
{
    return currentItem;
}

bool VideoList::next()
{
    if(currentItem + 1 < LIST.size())
    {
       currentItem++;
       return true;
    }
    else
    {
        return false;
    }
}

bool VideoList::last()
{
    if(currentItem - 1 >= 0)
    {
       currentItem--;
       return true;
    }
    else
    {
        return false;
    }
}


QString VideoList::getCurrentItem()
{

    return LIST.at(currentItem);
}

void VideoList::setCurrentItem(int row)
{
    currentItem = row;
}

QList<QString> VideoList::getList()
{
    return LIST;
}

void VideoList::openDir(int row)
{
    QString filepath;
    int pathsize;

    filepath = LIST.at(row);
    qDebug() << row;
    qDebug() << filepath;
    pathsize = filepath.length() - 1;
    while(pathsize>0)
    {
        if(filepath.compare(filepath.mid(pathsize,1),"/")==0) break;
        pathsize--;
    }
    filepath=QString("file:///")+filepath.mid(0,pathsize);
    qDebug() << filepath;
    QDesktopServices::openUrl(QUrl(filepath, QUrl::TolerantMode));
}

