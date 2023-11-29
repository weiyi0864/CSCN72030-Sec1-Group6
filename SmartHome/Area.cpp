#include "area.h"
#include <QtWidgets>



Area::Area(QString title)
{
    setTitle(title);
    mainLayout = new QVBoxLayout();
    addControlLayout = new QVBoxLayout();
    controlLayout = new QVBoxLayout();

    QPushButton* add_button = new QPushButton("Add New Control");
    addControlLayout->addWidget(add_button);
    connect(add_button, &QPushButton::clicked, this, &Area::addButtonClicked);

    mainLayout->addLayout(controlLayout);
    mainLayout->addLayout(addControlLayout);
    setLayout(mainLayout);

    // new control dialog
    add_new_control_dialog = new QDialog;
    add_new_control_dialog->setWindowTitle("Add New Control");

    QFormLayout* add_layout = new QFormLayout;
    typ = new QLineEdit;
    add_layout->addRow(new QLabel(tr("New Control Name:")), typ);

    //drop down control
    comboBox = new QComboBox();
    comboBox->addItem("AC");
    comboBox->addItem("Camera");
    comboBox->addItem("Curtain");
    comboBox->addItem("Fridge");
    comboBox->addItem("Light");

    add_layout->addRow(comboBox);

    //add add and cancel button
    QPushButton* add_control_button = new QPushButton("Add");
    add_layout->addRow(add_control_button);
    connect(add_control_button, &QPushButton::clicked, this, &Area::addControlButtonClicked);
    QPushButton* cancel_button = new QPushButton("Cancel");
    add_layout->addRow(cancel_button);
    connect(cancel_button, &QPushButton::clicked, this, &Area::cancelButtonClicked);




    add_new_control_dialog->setLayout(add_layout);








}


void Area::addButtonControl(QPushButton* btn) {
    btns.push_back(btn);
}

void Area::addButtonsIntoLayout() {
    QVBoxLayout* layout = new QVBoxLayout();

    int i = 0;
    // add 4 buttons every row
    while (i < btns.size()) {
        QHBoxLayout* row = new QHBoxLayout();
        for (int j = 0; j < 4; j++) {
            if (i < btns.size()) {
                row->addWidget(btns[i++]);
            }
            else {
                row->addSpacerItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum));
            }
        }
        layout->addLayout(row);
    }

    controlLayout->addLayout(layout);

}

void Area::addButtonClicked() {
    add_new_control_dialog->exec();
}

void Area::addControlButtonClicked() {
    if (typ->text().isEmpty()) {
        QMessageBox::warning(add_new_control_dialog, "Empty Control Name", "Please add a name to your new control.");
        return;
    }
    QPushButton* new_control;
    if (comboBox->itemText(comboBox->currentIndex()).toStdString() == "AC") {
        new_control = new ACControl(typ->text());
    }
    else if (comboBox->itemText(comboBox->currentIndex()).toStdString() == "Camera") {
        new_control = new CameraControl(typ->text());
    }
    else if (comboBox->itemText(comboBox->currentIndex()).toStdString() == "Curtain") {
        new_control = new CurtainControl(typ->text());
    }
    else if (comboBox->itemText(comboBox->currentIndex()).toStdString() == "Fridge") {
        new_control = new FridgeControl(typ->text());
    }
    else if (comboBox->itemText(comboBox->currentIndex()).toStdString() == "Light") {
        new_control = new LightControl(typ->text());
    }

    btns.push_back(new_control);
    addButtonsIntoLayout();

    typ->clear();
    add_new_control_dialog->close();
}

void Area::cancelButtonClicked() {
    add_new_control_dialog->close();
}