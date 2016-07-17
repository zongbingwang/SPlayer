#ifndef SETTING_H
#define SETTING_H

#include <QWidget>
#include <QSlider>
#include <QSpinBox>
#include <QPushButton>
namespace Ui {
    class Setting;
}

class Setting : public QWidget
{
    Q_OBJECT

public:
    explicit Setting(QWidget *parent = 0);
    ~Setting();

private slots:
    void on_buttonOk_clicked();

    void on_buttonCancel_clicked();
signals:
    void settingHaveChanged(int, int, int, int, int, int);

private:
    Ui::Setting *ui;
    int setContrast; //对比度
    int setSaturation;//饱和度
    int setBrightness;//设置亮度
    int setHue; //设置色调
    int step;//快进快退步长
    int numGif;//gif图片数量
};

#endif // SETTING_H
