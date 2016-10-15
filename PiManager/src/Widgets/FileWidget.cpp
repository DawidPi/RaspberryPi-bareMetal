//
// Created by Dawid on 15.10.2016.
//

#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLineEdit>
#include "FileWidget.hpp"


FileWidget::FileWidget(const QString &title, QWidget *parent)
        : QWidget(parent) {
    auto *layout = new QHBoxLayout(this);

    setTitle(layout, title);
    setFileText(layout);
    setChooseFileButton(layout);
}

void FileWidget::setFileText(QLayout *layout) {
    auto *fileText = new QLineEdit;
    layout->addWidget(fileText);

}

void FileWidget::setChooseFileButton(QLayout *layout) {
    auto *chooseFileButton = new QPushButton;
    layout->addWidget(chooseFileButton);

}

void FileWidget::setTitle(QLayout *layout, const QString &title) {
    auto *titleText = new QLineEdit(title);
    titleText->setEnabled(false);
    layout->addWidget(titleText);
}

