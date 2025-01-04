#include "button.h"

CustomButton::CustomButton(QWidget* parent) 
    : QPushButton(parent), m_backgroundColor(Qt::black),m_textColor(Qt::white){
    setStyleSheet("QPushButton {"
        "border-radius: 5px;"
        "background-color: rgb(255,255,255);" 
        "color: rgb(0,0,0);"
        "border: none;"
        "}"
    );
    setAutoFillBackground(true);
    setMouseTracking(true);
}
CustomButton::CustomButton(const QString& text, QWidget* parent)
    : QPushButton(text,parent){
    m_textColor = QColor(255, 87, 34);
    m_backgroundColor = QColor(255,255,255);
    timer = std::make_unique<QTimer>();
    timer->setSingleShot(true);
    setStyleSheet("QPushButton {"
        "border-radius: 5px;"
        "background-color: rgb(255,255,255);" 
        "color: rgb(255, 87, 34);"
        "border: 1px solid #FF5722;"
        "padding: 3px;"
        "}"
    );
    setMouseTracking(true);
    setFixedWidth(factorSize(2));
}
CustomButton::CustomButton(const QIcon& icon,const QString& text,QWidget* parent)
    : QPushButton(icon,text,parent), m_backgroundColor(Qt::black),m_textColor(Qt::white){
    setStyleSheet("QPushButton {"
        "border-radius: 5px;"
        "background-color: rgb(255,255,255);" 
        "color: rgb(0,0,0);"
        "border: none;"
        "}"
    );
    setAutoFillBackground(true);
    setMouseTracking(true);
}
int CustomButton::factorSize(int factor) {
    int new_width = static_cast<int>(sizeHint().width() * factor);
    return new_width;
}
void CustomButton::enterEvent(QEnterEvent* event){
    animate.animateColorTransition(this,m_backgroundColor,QColor(255, 87, 34),"backgroundColor");
    animate.animateColorTransition(this,m_textColor,QColor(255,255,255),"textColor");
    QPushButton::enterEvent(event);
}
void CustomButton::leaveEvent(QEvent* event){
    animate.animateColorTransition(this,m_backgroundColor,QColor(255,255,255),"backgroundColor");
    animate.animateColorTransition(this,m_textColor,QColor(255, 87, 34),"textColor");
    QPushButton::leaveEvent(event);
}
void CustomButton::mousePressEvent(QMouseEvent* event){
    if (event->button() == Qt::LeftButton){
        animate.animateColorTransition(this,m_backgroundColor,QColor(76, 175, 80),"backgroundColor");
        animate.animateColorTransition(this,m_textColor,QColor(255,255,255),"textColor");
        timer->stop();
    }
    QPushButton::mousePressEvent(event);
}
void CustomButton::mouseReleaseEvent(QMouseEvent* event){
    if (event->button() == Qt::LeftButton){
        timer->start(200);
        connect(timer.get(), &QTimer::timeout,this,[this](){
            animate.animateColorTransition(this,m_backgroundColor,QColor(255, 87, 34),"backgroundColor");
            animate.animateColorTransition(this,m_textColor,QColor(255, 255, 255),"textColor");
        });
    }
    QPushButton::mouseReleaseEvent(event);
}
QColor CustomButton::backgroundColor() const {
    return m_backgroundColor;
}
QColor CustomButton::textColor() const{
    return m_textColor;
}
void CustomButton::setBackgroundColor(const QColor& color) {
    if (m_backgroundColor!=color){
        m_backgroundColor = color;
        updateStylesheets();
    }
}
void CustomButton::setTextColor(const QColor& color){
    if (m_textColor!=color){
        m_textColor = color;
        updateStylesheets();
    }
}
void CustomButton::updateStylesheets(){
    QString qss= QString("QPushButton{"
    "background-color: %1;" 
    "color: %2;" 
    "border-radius: 5px;" 
    "border:1px solid %1;" 
    "padding: 3px;"
    "}")
    .arg(m_backgroundColor.name(),m_textColor.name());
    setStyleSheet(qss);
}
