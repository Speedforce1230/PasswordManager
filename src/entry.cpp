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
    setStyleSheet(QString(*entry_qss).arg(m_backgroundColor.name()));
    setMouseTracking(true);
}
CustomLineEntry::CustomLineEntry(const QString& contents,Cache& cache,QWidget* parent)
    : QLineEdit(contents,parent){
    hover_color = QColor(255,204,188);
    click_color = QColor(255, 87, 34);
    initial_color = Qt::white;
    m_backgroundColor = initial_color;

    resources.cacheResources(cache);
    entry_qss = cache.getQss("entry_qss");
    setStyleSheet(QString(*entry_qss).arg(m_backgroundColor.name()));
    setMouseTracking(true);
}
void CustomLineEntry::enterEvent(QEnterEvent* event){
    animate.animateColorTransition(this,m_backgroundColor,hover_color,"backgroundColor");
    QLineEdit::enterEvent(event);
}
void CustomLineEntry::leaveEvent(QEvent* event){
    animate.animateColorTransition(this,m_backgroundColor,initial_color,"backgroundColor");
    QLineEdit::leaveEvent(event);
}
void CustomLineEntry::mousePressEvent(QMouseEvent* event){
    if (event->button() == Qt::LeftButton){
        animate.animateColorTransition(this,m_backgroundColor,click_color,"backgroundColor");
    }
    QLineEdit::mousePressEvent(event);
}
void CustomLineEntry::mouseReleaseEvent(QMouseEvent* event){
    if (event->button() == Qt::LeftButton){
        animate.animateColorTransition(this,m_backgroundColor,initial_color,"backgroundColor");
    }
    QLineEdit::mouseReleaseEvent(event);
}
QColor CustomLineEntry::backgroundColor() const {
    return m_backgroundColor;
}

void CustomLineEntry::setBackgroundColor(const QColor& color) {
    m_backgroundColor = color;
    setStyleSheet(QString(*entry_qss).arg(m_backgroundColor.name()));
}
