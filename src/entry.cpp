#include "entry.h"

CustomLineEntry::CustomLineEntry(QWidget* parent)
    : QLineEdit(parent),m_backgroundColor(QColor(173,216,230)){
    setStyleSheet("QLineEdit{"
        "border-radius: 10px;"
        "background-color: #FFFFFF;"
        "color: #3E2723;"
        "border: 1px solid #FF5722;"
        "padding: 2px;"
        "}"
    );
    setMouseTracking(true);
}
CustomLineEntry::CustomLineEntry(const QString& contents,QWidget* parent)
    : QLineEdit(contents,parent){
    setStyleSheet("QLineEdit{"
        "border-radius: 10px;"
        "background-color: #FFFFFF;"
        "color: #3E2723;"
        "border: none;"
        
        "}"
    );
    setMouseTracking(true);
}
void CustomLineEntry::enterEvent(QEnterEvent* event){
    animate.animateColorTransition(this,m_backgroundColor,QColor(255, 204, 188),"backgroundColor");
    QLineEdit::enterEvent(event);
}
void CustomLineEntry::leaveEvent(QEvent* event){
    animate.animateColorTransition(this,m_backgroundColor,QColor(255,255,255),"backgroundColor");
    QLineEdit::leaveEvent(event);
}
void CustomLineEntry::mousePressEvent(QMouseEvent* event){
    if (event->button() == Qt::LeftButton){
        animate.animateColorTransition(this,m_backgroundColor,QColor(255, 87, 34),"backgroundColor");
    }
    QLineEdit::mousePressEvent(event);
}
void CustomLineEntry::mouseReleaseEvent(QMouseEvent* event){
    if (event->button() == Qt::LeftButton){
        animate.animateColorTransition(this,m_backgroundColor,QColor(255,255,255),"backgroundColor");
    }
    QLineEdit::mouseReleaseEvent(event);
}
QColor CustomLineEntry::backgroundColor() const {
    return m_backgroundColor;
}

void CustomLineEntry::setBackgroundColor(const QColor& color) {
    m_backgroundColor = color;
    QString qss = QString("QLineEdit { background-color: %1; color: #3E2723; border-radius: 10px; border: 1px solid #FF5722; padding: 2px;}")
                      .arg(color.name());
    setStyleSheet(qss);
}
