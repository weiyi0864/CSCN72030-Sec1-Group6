#include <QtWidgets>
#include "dialog.h"

Dialog::Dialog()
{
    // Ground Floor,Second Floor, Third Floor, Basement Garage
    areas.push_back(new Area("Ground Floor"));
    areas.push_back(new Area("Second Floor"));
    areas.push_back(new Area("Third Floor"));
    areas.push_back(new Area("Basement"));
    areas.push_back(new Area("Garage"));

    QVBoxLayout* mainLayout = new QVBoxLayout;
    QVBoxLayout* areaLayout = new QVBoxLayout;
    for (int i = 0; i < areas.size(); i++) {
        areas[i]->addButtonControl(new LightControl("1"));
        areas[i]->addButtonControl(new CurtainControl("1"));
        areas[i]->addButtonControl(new CameraControl("1"));
        areas[i]->addButtonControl(new FridgeControl("1"));
        areas[i]->addButtonControl(new ACControl("1"));
        areas[i]->addButtonsIntoLayout();
        areaLayout->addWidget(areas[i]);
    }
    mainLayout->addLayout(areaLayout);

    // add new area dialog
    QPushButton* add_button = new QPushButton("Add New Area");
    connect(add_button, &QPushButton::clicked, this, &Dialog::addButtonClicked);
    mainLayout->addWidget(add_button);
    add_new_area_dialog = new QDialog();
    add_new_area_dialog->setWindowTitle("Add New Area");

    QFormLayout* add_layout = new QFormLayout;
    add_layout->addRow(new QLabel(tr("New Area Name:")), new QLineEdit);
    add_layout->addRow(new QPushButton("Add"));
    add_layout->addRow(new QPushButton("Cancel"));

    add_new_area_dialog->setLayout(add_layout);


    setLayout(mainLayout);
    // set dialog title
    setWindowTitle(tr("Smart Home"));


}

void Dialog::addButtonClicked() {
    add_new_area_dialog->exec();
}

Dialog::~Dialog()
{
}

