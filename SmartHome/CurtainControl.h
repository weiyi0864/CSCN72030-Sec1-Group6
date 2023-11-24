#ifndef CURTAINCONTROL_H
#define CURTAINCONTROL_H

#include <QWidget>
#include <QPushButton>
#include <QDialog>
#include <QVBoxLayout>
#include <QLabel>
#include <QSlider>

class CurtainControl :public QPushButton
{
public:
    CurtainControl(QString name);
private:
    int slide_percentage;
    int shade_percentage;
    QDialog* curtain_control_dialog;

private slots:
    void onButtonClicked();
};

#endif // CURTAINCONTROL_H
