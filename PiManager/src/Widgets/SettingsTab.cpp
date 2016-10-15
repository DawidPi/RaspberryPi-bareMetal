//
// Created by Dawid on 15.10.2016.
//

#include <QtWidgets/QHBoxLayout>
#include "SettingsTab.hpp"
#include "SerialPortsComboBox.hpp"
#include "FileWidget.hpp"

SettingsTab::SettingsTab(QWidget *parent) {
    auto *layout = new QVBoxLayout(this);
    layout->addWidget(new SerialPortsComboBox);
    layout->addWidget(new FileWidget("Binary file: "));
    layout->addWidget(new FileWidget("Translator File:"));

    setLayout(layout);
}
