/*
   MIT License
   Copyright (c) 2025 Vasu Dhall(Speedforce1230)
   Please retain this copyright notice when using or modifying this project.
*/

#ifndef BUTTON_H 
#define BUTTON_H



#include <QWidget>
#include <QPushButton>
#include <QIcon>
#include <QString>
#include <memory>
#include "forward.h"
#include "animate.h"
#include "resources.h"
class CustomButton : public QPushButton{
    Q_OBJECT
    // Make sure to defind the methods for all and when using the properties, keep the name same as the getter name.
    Q_PROPERTY(QColor backgroundColor READ backgroundColor WRITE setBackgroundColor)
    Q_PROPERTY(QColor textColor READ textColor WRITE setTextColor)
public:
    CustomButton(Cache& cache,QWidget* parent=nullptr);
    CustomButton(const QString& text,Cache& cache, QWidget* parent=nullptr);
    CustomButton(const QIcon& icon, const QString& text,Cache& cache, QWidget* parent=nullptr);
    int factorSize(int factor);
protected:
    void enterEvent(QEnterEvent* event) override;
    void leaveEvent(QEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
private slots:
    void onTimeout();
private:
    // getters and setters for the properties.
    QColor textColor() const;
    QColor backgroundColor() const;
    void setTextColor(const QColor& color);
    void setBackgroundColor(const QColor& color);
    QColor m_backgroundColor;
    QColor m_textColor;
    QColor initial_background_color;
    QColor initial_text_color;
    QColor hover_background_color;
    QColor hover_text_color;
    QColor click_background_color;
    QColor click_text_color;
    Animate animate;
    std::unique_ptr<QTimer> timer;
    std::shared_ptr<QString> button_qss;
    Resources resources;
    void animateEntry();
    void animateExit();
    void updateStylesheets();
};
#pragma once
#endif