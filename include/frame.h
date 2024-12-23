#ifndef FRAME_H
#define FRAME_H
#include <QFrame>
#include <memory>
#include <QPushButton>
#include <QWidget>
#include <QApplication>
#include "button.h"
#include <QBoxLayout>
#include "characters.h"

#pragma once
// Class has multiple derived classes.
// Dated 23rd of December, 2024. Class has two derived classes, PasswordFrame and HomeFrame.
// Any derivative classes should have a header inheriting from CustomFrame and should be named frame_xxx.h
class CustomFrame : public QFrame{
    Q_OBJECT
public:
    CustomFrame(QWidget* parent=nullptr);
private:
    
    
    std::unique_ptr<QBoxLayout> main_layout;
    void GeneratePassword();
    void SavePassword();
    // CustomFrame ReturnPasswordFrame();
    
    
    
};
#endif