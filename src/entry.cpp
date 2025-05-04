#include "entry.h"
#include "cache.h"
CustomLineEntry::CustomLineEntry(Cache& cache,QWidget* parent)
    : QLineEdit(parent){
    hover_color = QColor(255,204,188);
    click_color = QColor(255, 87, 34);
    initial_color = Qt::white;
    m_backgroundColor = initial_color;

    resources.cacheResources(cache);
    entry_qss = cache.getQss("entry_qss");
    setStyleSheet(QString(*entry_qss).arg(backgroundColor().name()));
    setMouseTracking(true);
    setFixedWidth(400);
}
CustomLineEntry::CustomLineEntry(const QString& contents,Cache& cache,QWidget* parent)
    : QLineEdit(contents,parent){
    hover_color = QColor(255,204,188);
    click_color = QColor(255, 87, 34);
    initial_color = Qt::white;
    m_backgroundColor = initial_color;

    resources.cacheResources(cache);
    entry_qss = cache.getQss("entry_qss");
    setStyleSheet(QString(*entry_qss).arg(backgroundColor().name()));
    setMouseTracking(true);
}
// Hover events
void CustomLineEntry::enterEvent(QEnterEvent* event){
    animate.animateColorTransition(this,backgroundColor(),hover_color,"backgroundColor");
    QLineEdit::enterEvent(event);
}
void CustomLineEntry::leaveEvent(QEvent* event){
    animate.animateColorTransition(this,backgroundColor(),initial_color,"backgroundColor");
    QLineEdit::leaveEvent(event);
}
// Click events
void CustomLineEntry::mousePressEvent(QMouseEvent* event){
    if (event->button() == Qt::LeftButton){
        animate.animateColorTransition(this,backgroundColor(),click_color,"backgroundColor");
    }
    QLineEdit::mousePressEvent(event);
}
void CustomLineEntry::mouseReleaseEvent(QMouseEvent* event){
    if (event->button() == Qt::LeftButton){
        animate.animateColorTransition(this,backgroundColor(),initial_color,"backgroundColor");
    }
    QLineEdit::mouseReleaseEvent(event);
}
QColor CustomLineEntry::backgroundColor() const {
    return m_backgroundColor;
}
// Will be called each time the property is changed.
void CustomLineEntry::setBackgroundColor(const QColor& color) {
    m_backgroundColor = color;
    setStyleSheet(QString(*entry_qss).arg(backgroundColor().name()));
}
