#include "setting.h"
#include "ui_setting.h"

Setting::Setting(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Setting)
{
    ui->setupUi(this);
    setWindowModified(true);

    setContrast = ui->horizontalSlider->value();
    setSaturation = ui->horizontalSlider_2->value();
    setBrightness = ui->horizontalSlider_4->value();
    setHue = ui->horizontalSlider_3->value();
    step = ui->spinBox->value();
    numGif = ui->spinBox_2->value();
}

Setting::~Setting()
{
    delete ui;
}

void Setting::on_buttonOk_clicked()
{
    setContrast = ui->horizontalSlider->value();
    setSaturation = ui->horizontalSlider_2->value();
    setBrightness = ui->horizontalSlider_4->value();
    setHue = ui->horizontalSlider_3->value();
    step = ui->spinBox->value();
    numGif = ui->spinBox_2->value();
    emit settingHaveChanged(setContrast, setSaturation, setBrightness, setHue, step, numGif);
    this->close();
}

void Setting::on_buttonCancel_clicked()
{
    ui->horizontalSlider->setValue(setContrast);
    ui->horizontalSlider_2->setValue(setSaturation);
    ui->horizontalSlider_4->setValue(setHue);
    ui->horizontalSlider_3->setValue(setHue);
    ui->spinBox->setValue(step);
    ui->spinBox_2->setValue(numGif);
    this->close();
}
