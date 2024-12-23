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
    setAutoFillBackground(true);
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
