#include "animate.h"

void Animate::animateColorTransition(QObject* target,const QColor& start_color, const QColor& end_color, const QString& property_name){
    QPropertyAnimation* animation = new QPropertyAnimation(target,property_name.toUtf8());
    animation->setDuration(150);
    animation->setStartValue(start_color);
    animation->setEndValue(end_color);
    animation->start(QAbstractAnimation::DeleteWhenStopped);
}
void Animate::animateSizeChange(QObject* target,const QSize& initial_size, const QSize& final_size, const QString& property_name, int duration){
    QPropertyAnimation* animation = new QPropertyAnimation(target,property_name.toUtf8());
    animation->setDuration(duration);
    animation->setStartValue(initial_size);
    animation->setEndValue(final_size);
    animation->start(QAbstractAnimation::DeleteWhenStopped);
}
