#include "entry.h"

CustomLineEntry::CustomLineEntry(QWidget* parent)
    : QLineEdit(parent){
    setStyleSheet("QLineEdit{"
        "border-radius: 5px;"
        "background-color: #ADD8E6;"
        "color: #000080;"
        "border: none;"
        "}"
    );
    setMouseTracking(true);
}
CustomLineEntry::CustomLineEntry(const QString& contents,QWidget* parent)
    : QLineEdit(contents,parent){
    setStyleSheet("QLineEdit{"
        "border-radius: 5px;"
        "background-color: #ADD8E6;"
        "color: #000080;"
        "border: none;"
        
        "}"
    );
    setMouseTracking(true);
}
void CustomLineEntry::enterEvent(QEnterEvent* event){
    animateEntry();
    QLineEdit::enterEvent(event);
}
void CustomLineEntry::leaveEvent(QEvent* event){
    animateExit();
    QLineEdit::leaveEvent(event);
}
void CustomLineEntry::animateEntry(){
    QPropertyAnimation* animation = new QPropertyAnimation(this,"backgroundColor");
    animation->setDuration(150);
    animation->setStartValue(QColor(173,216,230));
    animation->setEndValue(QColor(135,206,235));
    animation->start(QAbstractAnimation::DeleteWhenStopped);
}
void CustomLineEntry::animateExit(){
    QPropertyAnimation* animation = new QPropertyAnimation(this,"backgroundColor");
    animation->setDuration(150);
    animation->setStartValue(QColor(135,206,235));
    animation->setEndValue(QColor(173,216,230));
    animation->start(QAbstractAnimation::DeleteWhenStopped);
}
QColor CustomLineEntry::backgroundColor() const {
    return m_backgroundColor;
}

void CustomLineEntry::setBackgroundColor(const QColor& color) {
    m_backgroundColor = color;
    QString qss = QString("QLineEdit { background-color: %1; color: #000080; border-radius: 5px; border: none; }")
                      .arg(color.name());
    setStyleSheet(qss);
}
