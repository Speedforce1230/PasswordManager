#ifndef FRAME_H
#define FRAME_H
#include <QFrame>
#include <memory>
#include <QPushButton>
#include <QWidget>
#include "button.h"
#include <QBoxLayout>
#include <variant>
template <typename type>
using unique_ptr = std::unique_ptr<type>;
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
#endif