//
// Created by Dawid on 15.10.2016.
//

#include <QtWidgets/QPushButton>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QFileDialog>
#include "FileWidget.hpp"


FileWidget::FileWidget(const QString &extensions, QWidget *parent)
        : QWidget(parent), mFilePathWidget(new QLineEdit), mExtensions(extensions) {

    auto *layout = new QHBoxLayout(this);
    setFileText(layout);
    setChooseFileButton(layout);
    layout->setMargin(0);

    connect(mFileChooseButton, SIGNAL(clicked()), this, SLOT(chooseFileButtonPressed()));
}


void FileWidget::setChooseFileButton(QLayout *layout) {
    mFileChooseButton = new QPushButton("...");
    mFileChooseButton->setFixedWidth(30);
    layout->addWidget(mFileChooseButton);
}

void FileWidget::setFileText(QLayout *layout) {
    layout->addWidget(mFilePathWidget);
}

QString FileWidget::getFilePath() const {
    return mFilePathWidget->text();
}

void FileWidget::chooseFileButtonPressed() {
    auto filePath = QFileDialog::getOpenFileName(this, "Open file", QDir::currentPath(),
                                                 mExtensions, nullptr);
    mFilePathWidget->setText(filePath);
}

