/********************************************************************************
** Form generated from reading UI file 'tabtest.ui'
**
** Created: Wed Jul 6 13:06:32 2016
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TABTEST_H
#define UI_TABTEST_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QTabWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TabTest
{
public:
    QPushButton *addButton;
    QPushButton *deleteButton;
    QPushButton *clearButton;
    QPushButton *insertButton;
    QTabWidget *tabWidget;
    QWidget *video;
    QListWidget *videoWidget;
    QWidget *music;
    QListWidget *listWidget_2;
    QPushButton *pushButton;

    void setupUi(QWidget *TabTest)
    {
        if (TabTest->objectName().isEmpty())
            TabTest->setObjectName(QString::fromUtf8("TabTest"));
        TabTest->resize(629, 443);
        addButton = new QPushButton(TabTest);
        addButton->setObjectName(QString::fromUtf8("addButton"));
        addButton->setGeometry(QRect(90, 60, 75, 23));
        deleteButton = new QPushButton(TabTest);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));
        deleteButton->setGeometry(QRect(90, 120, 75, 23));
        clearButton = new QPushButton(TabTest);
        clearButton->setObjectName(QString::fromUtf8("clearButton"));
        clearButton->setGeometry(QRect(90, 180, 75, 23));
        insertButton = new QPushButton(TabTest);
        insertButton->setObjectName(QString::fromUtf8("insertButton"));
        insertButton->setGeometry(QRect(90, 230, 75, 23));
        tabWidget = new QTabWidget(TabTest);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(310, 30, 251, 311));
        video = new QWidget();
        video->setObjectName(QString::fromUtf8("video"));
        videoWidget = new QListWidget(video);
        videoWidget->setObjectName(QString::fromUtf8("videoWidget"));
        videoWidget->setGeometry(QRect(0, 0, 261, 301));
        videoWidget->setContextMenuPolicy(Qt::CustomContextMenu);
        videoWidget->setStyleSheet(QString::fromUtf8("font: 75 72pt \"Adobe \346\245\267\344\275\223 Std R\";\n"
""));
        tabWidget->addTab(video, QString());
        music = new QWidget();
        music->setObjectName(QString::fromUtf8("music"));
        listWidget_2 = new QListWidget(music);
        listWidget_2->setObjectName(QString::fromUtf8("listWidget_2"));
        listWidget_2->setGeometry(QRect(0, 0, 256, 301));
        tabWidget->addTab(music, QString());
        pushButton = new QPushButton(TabTest);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(90, 280, 75, 23));

        retranslateUi(TabTest);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(TabTest);
    } // setupUi

    void retranslateUi(QWidget *TabTest)
    {
        TabTest->setWindowTitle(QApplication::translate("TabTest", "Form", 0, QApplication::UnicodeUTF8));
        addButton->setText(QApplication::translate("TabTest", "add", 0, QApplication::UnicodeUTF8));
        deleteButton->setText(QApplication::translate("TabTest", "delete", 0, QApplication::UnicodeUTF8));
        clearButton->setText(QApplication::translate("TabTest", "clear", 0, QApplication::UnicodeUTF8));
        insertButton->setText(QApplication::translate("TabTest", "insert", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(video), QApplication::translate("TabTest", "video", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(music), QApplication::translate("TabTest", "list", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("TabTest", "opendir", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class TabTest: public Ui_TabTest {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TABTEST_H
