#ifndef TABTEST_H
#define TABTEST_H

#include <QWidget>
#include <QFileDialog>
#include <QMenu>
#include "videolist.h"

namespace Ui {
    class TabTest;
}

class TabTest : public QWidget
{
    Q_OBJECT

public:
    explicit TabTest(QWidget *parent = 0);
    ~TabTest();
    void initList();

private slots:
    void on_addButton_clicked();

    void on_deleteButton_clicked();

    void on_insertButton_clicked();

    void on_pushButton_clicked();

    void on_clearButton_clicked();

    void on_videoWidget_customContextMenuRequested(const QPoint &pos);

private:
    Ui::TabTest *ui;
    VideoList *playlist;
};

#endif // TABTEST_H
