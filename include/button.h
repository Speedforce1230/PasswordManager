#ifndef BUTTON_H 
#define BUTTON_H



#include <QWidget>
#include <QPushButton>
#include <QIcon>
#include <QString>
class CustomButton : public QPushButton{
    Q_OBJECT
public:
    CustomButton(QWidget* parent=nullptr);
    CustomButton(const QString& text, QWidget* parent=nullptr);
    CustomButton(const QIcon& icon, const QString& text, QWidget* parent=nullptr);
private:

};
#endif