#ifndef WIDGET_H
#define WIDGET_H
#include <QApplication>
#include <QWidget>
#include <QBoxLayout>
#include <QStackedWidget>
#include <QString>
#include <memory>
#include "forward.h"
#pragma once
class CentralWidget : public QWidget{
    Q_OBJECT
public:
    CentralWidget(QWidget* parent=nullptr);
    void setCurrentFrame(std::shared_ptr<CustomFrame> frame);
    std::unique_ptr<QStackedWidget> main_widget_stack;
private:
    std::unique_ptr<QBoxLayout> main_layout;
};
#pragma once
#endif // WIDGET_H