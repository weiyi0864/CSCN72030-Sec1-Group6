#ifndef ACCONTROL_H
#define ACCONTROL_H

#include <QWidget>
#include <QPushButton>
#include <QDialog>
#include <QVBoxLayout>
#include <QLabel>
#include <QSlider>
#include <QComboBox>

class ACControl :public QPushButton
{
public:
    ACControl(QString name);
private:
    int current_temperature;
    int humidity;
    int setting_temperature;
    QString mode;
    QString fan_speed;
    bool sleep;

    QDialog* ac_control_dialog;

private slots:
    void onButtonClicked();
    void onToggleStateButton();
};

#endif // ACCONTROL_H
