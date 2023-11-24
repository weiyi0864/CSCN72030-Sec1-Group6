#include "fridgecontrol.h"

FridgeControl::FridgeControl(QString name)
{
    // refridgerator 0-4
    setting_temperature_r = 0;
    current_temperature_r = 0;
    // freezer -18 - -25
    setting_temperature_f = -18;
    current_temperature_f = -18;
    // ice making
    ice = false;
    QString degreeSymbol = " Celsius Degree";

    setText("Fridge - " + name);
    fridge_control_dialog = new QDialog();
    fridge_control_dialog->setWindowTitle("Fridge Control");
    connect(this, &FridgeControl::clicked, this, &FridgeControl::onButtonClicked);

    // set up curtain control dialog details
    QVBoxLayout* layout = new QVBoxLayout();
    // Refridgerator
    QGroupBox* r = new QGroupBox("Refridgerator");
    QVBoxLayout* refridgerator_layout = new QVBoxLayout();
    QLabel* r_current_label = new QLabel("Current Temperature:");
    QLabel* r_current_value = new QLabel(qPrintable(QString::number(current_temperature_r) + degreeSymbol));
    QLabel* r_setting_label = new QLabel(qPrintable("Setting Temperature: " + QString::number(setting_temperature_r) + degreeSymbol));
    // slider
    QSlider* r_setting_slider = new QSlider(Qt::Horizontal);
    r_setting_slider->setRange(0, 40); // Set the range of the slider
    r_setting_slider->setValue(0);     // Set the initial value
    QObject::connect(r_setting_slider, &QSlider::valueChanged, [=](int value) {
        float dt = value / 10.0;
        float t = -0.0 - dt;
        r_setting_label->setText(qPrintable("Setting Temperature: " + QString::number(t) + degreeSymbol));
        });
    refridgerator_layout->addWidget(r_current_label);
    refridgerator_layout->addWidget(r_current_value);
    refridgerator_layout->addWidget(r_setting_label);
    refridgerator_layout->addWidget(r_setting_slider);
    r->setLayout(refridgerator_layout);

    // Freezer
    QGroupBox* f = new QGroupBox("Freezer");
    QVBoxLayout* freezer_layout = new QVBoxLayout();
    QLabel* f_current_label = new QLabel("Current Temperature:");
    QLabel* f_current_value = new QLabel(qPrintable(QString::number(current_temperature_f) + degreeSymbol));
    QLabel* f_setting_label = new QLabel(qPrintable("Setting Temperature: " + QString::number(setting_temperature_f) + degreeSymbol)); // Label to display current value
    // slider
    QSlider* f_setting_slider = new QSlider(Qt::Horizontal);
    f_setting_slider->setRange(0, 70); // Set the range of the slider
    f_setting_slider->setValue(0);     // Set the initial value
    QObject::connect(f_setting_slider, &QSlider::valueChanged, [=](int value) {
        float dt = value / 10.0;
        float t = -18.0 - dt;
        f_setting_label->setText(qPrintable("Setting Temperature: " + QString::number(t) + degreeSymbol));

        });
    freezer_layout->addWidget(f_current_label);
    freezer_layout->addWidget(f_current_value);
    freezer_layout->addWidget(f_setting_label);
    freezer_layout->addWidget(f_setting_slider);
    f->setLayout(freezer_layout);
    // Ice making
    QGroupBox* i = new QGroupBox("Ice Making");
    QVBoxLayout* ice_layout = new QVBoxLayout();
    QPushButton* state_btn = new QPushButton();
    state_btn->setText("OFF");
    connect(state_btn, &QPushButton::clicked, this, &FridgeControl::onToggleStateButton);
    ice_layout->addWidget(state_btn);
    i->setLayout(ice_layout);

    layout->addWidget(r);
    layout->addWidget(f);
    layout->addWidget(i);
    fridge_control_dialog->setLayout(layout);
}

void FridgeControl::onButtonClicked() {
    fridge_control_dialog->exec();
}

void FridgeControl::onToggleStateButton() {
    if (ice) {
        ice = false;
    }
    else {
        ice = true;
    }
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    if (ice) {
        button->setText("ON");
    }
    else {
        button->setText("OFF");
    }
}
