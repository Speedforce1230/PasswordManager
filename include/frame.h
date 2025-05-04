/*
   MIT License
   Copyright (c) 2025 Vasu Dhall(Speedforce1230)
   Please retain this copyright notice when using or modifying this project.
*/

#ifndef FRAME_H
#define FRAME_H
#include <QFrame>
#include <QPushButton>
#include <QWidget>
#include <QBoxLayout>
#include <variant>
#include <QLabel>
using std::unique_ptr;
#pragma once
// Class has multiple derived classes.
// Dated 23rd of December, 2024. Class has two derived classes, PasswordFrame and HomeFrame.
// Any derivative classes should have a header class inheriting from CustomFrame and should be named frame_xxx.h as per convention
class CustomFrame : public QFrame{
    Q_OBJECT
public:
    CustomFrame(QWidget* parent=nullptr);
private:
    unique_ptr<QBoxLayout> main_layout;
    
};
#pragma once
#endif