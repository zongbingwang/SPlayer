#include "skin.h"
#include "ui_skin.h"
#include <QFile>

skin::skin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::skin)
{
    ui->setupUi(this);
    this->setFixedSize(this->width(),this->height());
    this->setWindowModality(Qt::ApplicationModal);
}

skin::~skin()
{
    delete ui;
}

void skin::on_toolButton_clicked()
{
    QFile file(":/qss/my.qss");
    // 只读方式打开该文件
    file.open(QFile::ReadOnly);
    // 读取文件全部内容，使用tr()函数将其转换为QString类型
    QString styleSheet = tr(file.readAll());
    // 为QApplication设置样式表
    qApp->setStyleSheet(styleSheet);
}

void skin::on_toolButton_2_clicked()
{
    QFile file(":/qss/my1.qss");
    file.open(QFile::ReadOnly);
    QString styleSheet = tr(file.readAll());
    qApp->setStyleSheet(styleSheet);
}

void skin::on_toolButton_3_clicked()
{
    QFile file(":/qss/my2.qss");
    file.open(QFile::ReadOnly);
    QString styleSheet = tr(file.readAll());
    qApp->setStyleSheet(styleSheet);
}

void skin::on_toolButton_4_clicked()
{
    QFile file(":/qss/my3.qss");
    file.open(QFile::ReadOnly);
    QString styleSheet = tr(file.readAll());
    qApp->setStyleSheet(styleSheet);
}

void skin::on_toolButton_5_clicked()
{
    QFile file(":/qss/my4.qss");
    file.open(QFile::ReadOnly);
    QString styleSheet = tr(file.readAll());
    qApp->setStyleSheet(styleSheet);
}

void skin::on_toolButton_6_clicked()
{
    QFile file(":/qss/my5.qss");
    file.open(QFile::ReadOnly);
    QString styleSheet = tr(file.readAll());
    qApp->setStyleSheet(styleSheet);
}
