#ifndef ENTRY_H
#define ENTRY_H
#include <QWidget>
#include <QLineEdit>
#include <QString>
#include <QEvent>
#include <QEnterEvent>
#include <QColor>
#include "animate.h"
class CustomLineEntry : public QLineEdit{
    Q_OBJECT
    Q_PROPERTY(QColor backgroundColor READ backgroundColor WRITE setBackgroundColor)
public:
    
    explicit CustomLineEntry(QWidget* parent=nullptr);
    CustomLineEntry(const QString& contents, QWidget* parent=nullptr);
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
    void animateEntry();
    void animateExit();
};
#endif