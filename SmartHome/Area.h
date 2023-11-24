#ifndef AREA_H
#define AREA_H

#include <QWidget>
#include <QGroupBox>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <vector>

#include "lightcontrol.h"
#include "curtaincontrol.h"
#include "cameracontrol.h"
#include "fridgecontrol.h"
#include "accontrol.h"

class Area :public QGroupBox
{
public:
    Area(QString title);
    void addButtonsIntoLayout();
    void addButtonControl(QPushButton* btn);
private:
    std::vector<QPushButton*> btns;


};

#endif // AREA_H
