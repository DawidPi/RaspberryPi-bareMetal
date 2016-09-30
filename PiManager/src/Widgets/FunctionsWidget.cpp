//
// Created by Dawid on 30.09.2016.
//

#include <QtWidgets/QHBoxLayout>
#include "FunctionsWidget.hpp"

FunctionsWidget::FunctionsWidget(QWidget *parent) :
        QWidget(parent) {
    initializeMembers();
    widgetSetUp();
}

void FunctionsWidget::widgetSetUp() {
    mTreeWidget->setHeaderLabel(mHeaderText);
    auto *layout = new QHBoxLayout;
    layout->addWidget(mTreeWidget);
    setLayout(layout);
}

void FunctionsWidget::initializeMembers() {
    mTreeWidget = new QTreeWidget(this);
    mLastItem = nullptr;
}

void FunctionsWidget::newMainLoop() {
    auto *newTopLevelItem = new QTreeWidgetItem(mTreeWidget, QStringList{"void MainLoop()"});
    mLastItem = newTopLevelItem;
}

void FunctionsWidget::newFunctionCall(const FunctionsWidget::FunctionName &functionSignature) {
    assertLastItemValid();
    assertParentHasChildren();

    auto *newItem = new QTreeWidgetItem(QStringList{functionSignature.first + " " + functionSignature.second});
    mLastItem->parent()->addChild(newItem);
    mLastItem = newItem;
}

void FunctionsWidget::newSubFunctionCall(const FunctionsWidget::FunctionName &functionSignature) {
    assertLastItemValid();

    auto *newItem = new QTreeWidgetItem(QStringList{functionSignature.first + " " + functionSignature.second});
    mLastItem->addChild(newItem);

    mLastItem = newItem;
}

void FunctionsWidget::functionReturn() {
    assertLastItemHasParent();
    mLastItem = mLastItem->parent();
}

void FunctionsWidget::assertLastItemValid() {
    if (mLastItem == nullptr)
        throw std::logic_error("Last item not available");
}

void FunctionsWidget::assertParentHasChildren() {
    if (mLastItem->parent()->childCount() <= 0)
        throw std::logic_error("NewFunctionCall called before newMainLoop method call (parent has no children)");
}

void FunctionsWidget::assertLastItemHasParent() {
    if (mLastItem->parent() == nullptr)
        throw std::logic_error("No parent available");
}
