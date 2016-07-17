/********************************************************************************
** Form generated from reading UI file 'skin.ui'
**
** Created: Wed Jul 6 13:32:40 2016
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SKIN_H
#define UI_SKIN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_skin
{
public:
    QWidget *centralwidget;
    QToolButton *toolButton;
    QToolButton *toolButton_2;
    QToolButton *toolButton_3;
    QToolButton *toolButton_4;
    QToolButton *toolButton_5;
    QToolButton *toolButton_6;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *skin)
    {
        if (skin->objectName().isEmpty())
            skin->setObjectName(QString::fromUtf8("skin"));
        skin->resize(400, 300);
        centralwidget = new QWidget(skin);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        toolButton = new QToolButton(centralwidget);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setGeometry(QRect(6, 27, 111, 91));
        toolButton->setStyleSheet(QString::fromUtf8("border-image: url(:/image/img/lanfen.jpg);"));
        toolButton_2 = new QToolButton(centralwidget);
        toolButton_2->setObjectName(QString::fromUtf8("toolButton_2"));
        toolButton_2->setGeometry(QRect(140, 30, 121, 91));
        toolButton_2->setStyleSheet(QString::fromUtf8("border-image: url(:/image/img/purple.jpg);"));
        toolButton_3 = new QToolButton(centralwidget);
        toolButton_3->setObjectName(QString::fromUtf8("toolButton_3"));
        toolButton_3->setGeometry(QRect(280, 27, 111, 91));
        toolButton_3->setStyleSheet(QString::fromUtf8("\n"
"border-image: url(:/image/img/pink1.jpg);"));
        toolButton_4 = new QToolButton(centralwidget);
        toolButton_4->setObjectName(QString::fromUtf8("toolButton_4"));
        toolButton_4->setGeometry(QRect(6, 137, 111, 91));
        toolButton_4->setStyleSheet(QString::fromUtf8("\n"
"border-image: url(:/image/img/green1.jpg);"));
        toolButton_5 = new QToolButton(centralwidget);
        toolButton_5->setObjectName(QString::fromUtf8("toolButton_5"));
        toolButton_5->setGeometry(QRect(140, 140, 121, 91));
        toolButton_5->setStyleSheet(QString::fromUtf8("border-image: url(:/image/img/red1.jpg);"));
        toolButton_6 = new QToolButton(centralwidget);
        toolButton_6->setObjectName(QString::fromUtf8("toolButton_6"));
        toolButton_6->setGeometry(QRect(280, 140, 111, 91));
        toolButton_6->setStyleSheet(QString::fromUtf8("border-image: url(:/image/img/green.jpg);"));
        skin->setCentralWidget(centralwidget);
        menubar = new QMenuBar(skin);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 400, 18));
        skin->setMenuBar(menubar);
        statusbar = new QStatusBar(skin);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        skin->setStatusBar(statusbar);

        retranslateUi(skin);

        QMetaObject::connectSlotsByName(skin);
    } // setupUi

    void retranslateUi(QMainWindow *skin)
    {
        skin->setWindowTitle(QApplication::translate("skin", "MainWindow", 0, QApplication::UnicodeUTF8));
        toolButton->setText(QString());
        toolButton_2->setText(QString());
        toolButton_3->setText(QString());
        toolButton_4->setText(QString());
        toolButton_5->setText(QString());
        toolButton_6->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class skin: public Ui_skin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SKIN_H
