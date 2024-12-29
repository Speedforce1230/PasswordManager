#ifndef WIDGET_H
#define WIDGET_H
#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QStackedWidget>
#include <QString>
#include "frame.h"
#include <memory>
#pragma once
class CentralWidget : public QWidget{
    Q_OBJECT
public:
    CentralWidget(QWidget* parent=nullptr);
    void setCurrentFrame(std::shared_ptr<CustomFrame> frame);
    std::unique_ptr<QStackedWidget> main_widget_stack;
private:
    std::unique_ptr<QVBoxLayout> main_layout;
};
#endif // WIDGET_H