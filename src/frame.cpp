/*
   MIT License
   Copyright (c) 2025 Vasu Dhall(Speedforce1230)
   Please retain this copyright notice when using or modifying this project.
*/

#include "frame.h"
CustomFrame::CustomFrame(QWidget* parent) : QFrame(parent){
    setFrameStyle(QFrame::Box | QFrame::Raised);
    // No borders
    setLineWidth(0);
}