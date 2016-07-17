#include "tabtest.h"
#include "ui_tabtest.h"

TabTest::TabTest(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TabTest)
{
    ui->setupUi(this);
    playlist = new VideoList();
    initList();
}

TabTest::~TabTest()
{
    playlist->~VideoList();
    delete ui;
}

void TabTest::initList()
{
    QList<QString> LIST = playlist->getList();
    for (int i = 0; i < LIST.size(); i++)
    {
         ui->videoWidget->addItem(LIST.at(i));
    }
}


void TabTest::on_addButton_clicked()
{
    QString path = QFileDialog::getOpenFileName(this, tr("Open Video"),".",tr("Movie(*.avi *.rmvb *.flv *.wmv *mp4);"));
    if (path.length() != 0)
    {
        ui->videoWidget->addItem(playlist->addFile(path));
    }
}

void TabTest::on_deleteButton_clicked()
{
    playlist->deleteFile(ui->videoWidget->currentRow());
    ui->videoWidget->takeItem(ui->videoWidget->currentRow());

}

void TabTest::on_insertButton_clicked()
{
    QString path = QFileDialog::getOpenFileName(this, tr("Open Video"),".",tr("Movie(*.avi *.rmvb *.flv *.wmv *mp4);;"));
    if (path.length() != 0)
    {
        ui->videoWidget->insertItem(ui->videoWidget->currentRow() + 1, path);
    }
}

void TabTest::on_pushButton_clicked()
{
    playlist->openDir(ui->videoWidget->currentRow());
}

void TabTest::on_clearButton_clicked()
{
    ui->videoWidget->clear();
    playlist->clearList();
}

void TabTest::on_videoWidget_customContextMenuRequested(const QPoint &pos)
{
    QMenu *popMenu =new QMenu(this);//定义一个右键弹出菜单

    QAction *addfileAction = new QAction("&addfile...", this);
    popMenu->addAction(addfileAction);
    connect(addfileAction, SIGNAL(triggered()), this, SLOT(on_addButton_clicked()));

    QAction *deletefileAction = new QAction("&deletefile...", this);
    popMenu->addAction(deletefileAction);//往菜单内添加QAction
    connect(deletefileAction, SIGNAL(triggered()), this, SLOT(on_deleteButton_clicked()));

    QAction *clearlistAction = new QAction("&clearlist...", this);
    popMenu->addAction(clearlistAction);
    connect(clearlistAction, SIGNAL(triggered()), this, SLOT(on_clearButton_clicked()));

    QAction *opendirAction = new QAction("&opendir...", this);
    popMenu->addAction(opendirAction);
    connect(opendirAction, SIGNAL(triggered()), this, SLOT(on_pushButton_clicked()));

    QListWidgetItem* curItem=ui->videoWidget->itemAt(pos);

    if(curItem==NULL)
    {
        //设置无效
        deletefileAction->setEnabled(false);
        opendirAction->setEnabled(false);
    }
    popMenu->exec(QCursor::pos());//弹出右键菜单，菜单位置为光标位置
}
