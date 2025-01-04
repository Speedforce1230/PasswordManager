#ifndef ANIMATE_H
#define ANIMATE_H
#include <QWidget>
#include <QPropertyAnimation>
#include <QMouseEvent>
#include <QTimer>
class Animate : QPropertyAnimation{
    Q_OBJECT
public:
    void animateColorTransition(QObject* target,const QColor& start_color, const QColor& end_color, const QString& property_name);
    void animateSizeChange(QObject* target,const QSize& initial_size, const QSize& final_size, const QString& property_name, int duration=150);
private:
};
#endif