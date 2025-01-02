#include "button.h"

CustomButton::CustomButton(QWidget* parent) : QPushButton(parent){
    setStyleSheet("QPushButton {"
        "background-color: rgb(255,255,255);" 
        "color: rgb(0,0,0)"
        "}"
        "QPushButton:hover {"
        "background-color: rgb(0, 0, 0);" 
        "color:rgb(255, 255, 255);"
        "}"
    );
    setAutoFillBackground(true);
}
CustomButton::CustomButton(const QString& text, QWidget* parent): QPushButton(text,parent){
    setStyleSheet("QPushButton {"
        "background-color: rgb(255,255,255);" 
        "color: rgb(0,0,0)"
        "}"
        "QPushButton:hover {"
        "background-color: rgb(0, 0, 0);" 
        "color:rgb(255, 255, 255);"
        "}"
    );
    adjustSize();
    setAutoFillBackground(true);
    setFixedWidth(factorSize(1.5));
}
CustomButton::CustomButton(const QIcon& icon,const QString& text,QWidget* parent): QPushButton(icon,text,parent){
    setStyleSheet("QPushButton {"
        "background-color: rgb(255,255,255);" 
        "color: rgb(0,0,0)"
        "}"
        "QPushButton:hover {"
        "background-color: rgb(0, 0, 0);" 
        "color:rgb(255, 255, 255);"
        "}"
    );
    setAutoFillBackground(true);
}
int CustomButton::factorSize(int factor) {
    int new_width = static_cast<int>(sizeHint().width() * factor);
    return new_width;
}
