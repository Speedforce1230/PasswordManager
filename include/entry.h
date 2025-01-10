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