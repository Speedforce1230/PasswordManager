#ifndef BUTTON_H 
#define BUTTON_H



#include <QWidget>
#include <QPushButton>
#include <QIcon>
#include <QString>
#include "animate.h"
class CustomButton : public QPushButton{
    Q_OBJECT
    Q_PROPERTY(QColor backgroundColor READ backgroundColor WRITE setBackgroundColor)
    Q_PROPERTY(QColor textColor READ textColor WRITE setTextColor)
public:
    CustomButton(QWidget* parent=nullptr);
    CustomButton(const QString& text, QWidget* parent=nullptr);
    CustomButton(const QIcon& icon, const QString& text, QWidget* parent=nullptr);
    int factorSize(int factor);
protected:
    void enterEvent(QEnterEvent* event) override;
    void leaveEvent(QEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
private:
    QColor textColor() const;
    QColor backgroundColor() const;
    void setTextColor(const QColor& color);
    void setBackgroundColor(const QColor& color);
    QColor m_backgroundColor;
    QColor m_textColor;
    Animate animate;
    std::unique_ptr<QTimer> timer;
    void animateEntry();
    void animateExit();
    void updateStylesheets();
};
#endif