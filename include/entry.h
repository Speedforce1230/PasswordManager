/*
   MIT License
   Copyright (c) 2025 Vasu Dhall(Speedforce1230)
   Please retain this copyright notice when using or modifying this project.
*/

#ifndef ENTRY_H
#define ENTRY_H
#include <QWidget>
#include <QLineEdit>
#include <QString>
#include <QEvent>
#include <QEnterEvent>
#include <QColor>
#include <memory>
#include "forward.h"
#include "animate.h"
#include "resources.h"
class CustomLineEntry : public QLineEdit{
    Q_OBJECT
    // Make sure to defind the methods for all and when using the properties, keep the name same as the getter name.
    Q_PROPERTY(QColor backgroundColor READ backgroundColor WRITE setBackgroundColor)
public:
    explicit CustomLineEntry(Cache& cache,QWidget* parent=nullptr);
    CustomLineEntry(const QString& contents,Cache& cache, QWidget* parent=nullptr);
protected:
    void enterEvent(QEnterEvent* event) override;
    void leaveEvent(QEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
private:
    // getter and setter for the property
    QColor backgroundColor() const;
    void setBackgroundColor(const QColor& color);
    QColor m_backgroundColor;
    Animate animate;
    Resources resources;
    std::shared_ptr<QString> entry_qss; 
    QColor hover_color;
    QColor initial_color;
    QColor click_color;
    void animateEntry();
    void animateExit();
};
#pragma once
#endif