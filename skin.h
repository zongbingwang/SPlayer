#ifndef SKIN_H
#define SKIN_H
#include <QMainWindow>

namespace Ui {
    class skin;
}

class skin : public QMainWindow
{
    Q_OBJECT

public:
    explicit skin(QWidget *parent = 0);
    ~skin();

private slots:
    void on_toolButton_clicked();

    void on_toolButton_2_clicked();

    void on_toolButton_3_clicked();

    void on_toolButton_4_clicked();

    void on_toolButton_5_clicked();

    void on_toolButton_6_clicked();

private:
    Ui::skin *ui;
};

#endif // SKIN_H
