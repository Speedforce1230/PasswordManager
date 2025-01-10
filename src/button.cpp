#include "button.h"
#include "cache.h"
CustomButton::CustomButton(Cache& cache,QWidget* parent) 
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
CustomButton::CustomButton(const QString& text, Cache& cache,QWidget* parent)
    : QPushButton(text,parent){
    m_textColor = QColor(255, 87, 34);
    m_backgroundColor = QColor(255,255,255);
    timer = std::make_unique<QTimer>();
    resources.cacheResources(cache);
    button_qss = cache.getQss("button_qss");
    setStyleSheet(QString(*button_qss).arg(m_backgroundColor.name(),m_textColor.name()));
    setMouseTracking(true);
    setMinimumWidth(factorSize(2));
}
CustomButton::CustomButton(const QIcon& icon,const QString& text, Cache& cache,QWidget* parent)
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
            animate.animateColorTransition(this,m_backgroundColor,QColor(255,255,255),"backgroundColor");
            animate.animateColorTransition(this,m_textColor,QColor(255, 87, 34),"textColor");
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
    setStyleSheet(QString(*button_qss).arg(m_backgroundColor.name(),m_textColor.name()));
}
