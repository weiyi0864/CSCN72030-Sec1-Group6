#include "accontrol.h"

ACControl::ACControl(QString name)
{
    // default setting
    current_temperature = 26;
    humidity = 50;
    setting_temperature = 26;
    mode = "Cool";
    fan_speed = "Low";
    sleep = false;

    setText("Air Conditioner - " + name);
    ac_control_dialog = new QDialog();
    ac_control_dialog->setWindowTitle("Air Conditioner Control");
    connect(this, &ACControl::clicked, this, &ACControl::onButtonClicked);


    QString degreeSymbol = " Celsius Degree";

    // set up ac control dialog details
    QVBoxLayout* layout = new QVBoxLayout();

    // Current Temperature & humidity
    QLabel* current_t_label = new QLabel("Current Temperature:");
    QLabel* current_t_value = new QLabel(qPrintable(QString::number(current_temperature) + degreeSymbol));
    QLabel* current_h_label = new QLabel("Current Humidity:");
    QLabel* current_h_value = new QLabel(qPrintable(QString::number(humidity) + "%"));
    // setting temperature
    QLabel* valueLabel = new QLabel(qPrintable("Setting Temperature: " + QString::number(setting_temperature) + degreeSymbol)); // Label to display current value
    // slider
    QSlider* slider = new QSlider(Qt::Horizontal);
    slider->setRange(16, 30); // Set the range of the slider
    slider->setValue(setting_temperature);     // Set the initial value
    QObject::connect(slider, &QSlider::valueChanged, [=](int value) {
        valueLabel->setText(qPrintable("Setting Temperature: " + QString::number(value) + degreeSymbol)); // Update label with slider value
        });
    // sleep mode
    QLabel* sleep_label = new QLabel("Sleep Mode:");
    QPushButton* state_btn = new QPushButton();
    state_btn->setText("OFF");
    connect(state_btn, &QPushButton::clicked, this, &ACControl::onToggleStateButton);
    // mode
    // drop down control
    QComboBox* comboBox = new QComboBox();
    comboBox->addItem("Cool");
    comboBox->addItem("Heat");
    comboBox->addItem("Fan");
    comboBox->addItem("Dry");
    comboBox->addItem("Eco");
    comboBox->addItem("Auto");
    comboBox->addItem("Turbo");

    QLabel* dropLabel = new QLabel("Current Mode: ");
    QObject::connect(comboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), [=](int index) {
        mode = comboBox->itemText(index);
        dropLabel->setText("Current Mode: " + mode);
        });

    // fan speed
    QComboBox* comboBox_fan = new QComboBox();
    comboBox_fan->addItem("Low");
    comboBox_fan->addItem("Medium");
    comboBox_fan->addItem("High");
    QLabel* drop_label_fan = new QLabel("Fan Speed: ");
    QObject::connect(comboBox_fan, QOverload<int>::of(&QComboBox::currentIndexChanged), [=](int index) {
        fan_speed = comboBox_fan->itemText(index);
        drop_label_fan->setText("Fan Speed: " + fan_speed);
        });

    // current temperature and humidity
    layout->addWidget(current_t_label);
    layout->addWidget(current_t_value);
    layout->addWidget(current_h_label);
    layout->addWidget(current_h_value);
    // setting temperature
    layout->addWidget(valueLabel);
    layout->addWidget(slider);
    // sleep mode
    layout->addWidget(sleep_label);
    layout->addWidget(state_btn);
    // mode
    layout->addWidget(dropLabel);
    layout->addWidget(comboBox);
    // fan speed
    layout->addWidget(drop_label_fan);
    layout->addWidget(comboBox_fan);

    ac_control_dialog->setLayout(layout);
}

void ACControl::onButtonClicked() {
    ac_control_dialog->exec();
}

void ACControl::onToggleStateButton() {
    if (sleep) {
        sleep = false;
    }
    else {
        sleep = true;
    }
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    if (sleep) {
        button->setText("ON");
    }
    else {
        button->setText("OFF");
    }
}
