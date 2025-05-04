/*
   MIT License
   Copyright (c) 2025 Vasu Dhall(Speedforce1230)
   Please retain this copyright notice when using or modifying this project.
*/
#include "button.h"
#include "cache.h"
CustomButton::CustomButton(Cache& cache,QWidget* parent) 
    : QPushButton(parent), m_backgroundColor(Qt::black),m_textColor(Qt::white){
    // Colors
    initial_background_color = Qt::white;
    initial_text_color = QColor(255, 87, 34);
    hover_background_color = QColor(255, 87, 34);
    hover_text_color = Qt::white;
    click_background_color = QColor(255,204,188);
    click_text_color = Qt::white;
    m_textColor = initial_text_color;
    m_backgroundColor = initial_background_color;
    // Initializing cache
    timer = std::make_unique<QTimer>();
    resources.cacheResources(cache);
    button_qss = cache.getQss("button_qss");
    // Connecting timer
    connect(timer.get(), &QTimer::timeout, this, &CustomButton::onTimeout);
    timer->setSingleShot(true);
    
    setStyleSheet(QString(*button_qss).arg(m_backgroundColor.name(),m_textColor.name()));
    setMouseTracking(true);
    setMinimumWidth(factorSize(2));
}
CustomButton::CustomButton(const QString& text, Cache& cache,QWidget* parent)
    : QPushButton(text,parent){
    // Colors
    initial_background_color = Qt::white;
    initial_text_color = QColor(255, 87, 34);
    hover_background_color = QColor(255, 87, 34);
    hover_text_color = Qt::white;
    click_background_color = QColor(255,204,188);
    click_text_color = Qt::white;
    m_textColor = initial_text_color;
    m_backgroundColor = initial_background_color;
    // Initializing cache
    timer = std::make_unique<QTimer>();
    resources.cacheResources(cache);
    button_qss = cache.getQss("button_qss");
    // Connecting timer
    connect(timer.get(), &QTimer::timeout, this, &CustomButton::onTimeout);
    timer->setSingleShot(true);
    
    setStyleSheet(QString(*button_qss).arg(m_backgroundColor.name(),m_textColor.name()));
    setMouseTracking(true);
    setMinimumWidth(factorSize(2));
}
CustomButton::CustomButton(const QIcon& icon,const QString& text, Cache& cache,QWidget* parent)
    : QPushButton(icon,text,parent), m_backgroundColor(Qt::black),m_textColor(Qt::white){
    // Colors
    initial_background_color = Qt::white;
    initial_text_color = QColor(255, 87, 34);
    hover_background_color = QColor(255, 87, 34);
    hover_text_color = Qt::white;
    click_background_color = QColor(255,204,188);
    click_text_color = Qt::white;
    m_textColor = initial_text_color;
    m_backgroundColor = initial_background_color;
    // Initializing cache
    timer = std::make_unique<QTimer>();
    resources.cacheResources(cache);
    button_qss = cache.getQss("button_qss");
    // Connecting timer
    connect(timer.get(), &QTimer::timeout, this, &CustomButton::onTimeout);
    timer->setSingleShot(true);
    
    setStyleSheet(QString(*button_qss).arg(backgroundColor().name(),textColor().name()));
    setMouseTracking(true);
    setMinimumWidth(factorSize(2));
}
int CustomButton::factorSize(int factor) {
    int new_width = static_cast<int>(sizeHint().width() * factor);
    return new_width;
}
// Hover events.
void CustomButton::enterEvent(QEnterEvent* event){
    animate.animateColorTransition(this,backgroundColor(),hover_background_color,"backgroundColor");
    animate.animateColorTransition(this,textColor(),hover_text_color,"textColor");
    QPushButton::enterEvent(event);
}
void CustomButton::leaveEvent(QEvent* event){
    animate.animateColorTransition(this,backgroundColor(),initial_background_color,"backgroundColor");
    animate.animateColorTransition(this,textColor(),initial_text_color,"textColor");
    QPushButton::leaveEvent(event);
}
// Click events.
void CustomButton::mousePressEvent(QMouseEvent* event){
    if (event->button() == Qt::LeftButton){
        timer->stop();
        animate.animateColorTransition(this,backgroundColor(),click_background_color,"backgroundColor");
        animate.animateColorTransition(this,textColor(),click_text_color,"textColor");
    }
    QPushButton::mousePressEvent(event);
}
void CustomButton::mouseReleaseEvent(QMouseEvent* event){
    if (event->button() == Qt::LeftButton){
        timer->start(100);
    }
    QPushButton::mouseReleaseEvent(event);
}
void CustomButton::onTimeout(){
    animate.animateColorTransition(this,backgroundColor(),initial_background_color,"backgroundColor");
    animate.animateColorTransition(this,textColor(),initial_text_color,"textColor");
}
QColor CustomButton::backgroundColor() const {
    return m_backgroundColor;
}
QColor CustomButton::textColor() const{
    return m_textColor;
}
// These setters are called each time the color transition happens.
void CustomButton::setBackgroundColor(const QColor& color) {
    m_backgroundColor = color;
    updateStylesheets();
}
void CustomButton::setTextColor(const QColor& color){
    m_textColor = color;
    updateStylesheets();
}
void CustomButton::updateStylesheets(){
    setStyleSheet(QString(*button_qss).arg(backgroundColor().name(),textColor().name()));
}
