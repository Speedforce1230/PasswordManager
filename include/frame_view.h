/*
   MIT License
   Copyright (c) 2025 Vasu Dhall(Speedforce1230)
   Please retain this copyright notice when using or modifying this project.
*/

#ifndef FRAME_VIEW_H
#define FRAME_VIEW_H
#include "forward.h"
#include "frame.h"
#include <QBoxLayout>
#include <memory>
using std::shared_ptr;
using std::unique_ptr;
class ViewFrame : public CustomFrame{
    Q_OBJECT
public:
    void createViewFrame(Cache& cache);
private:
    // pointers for various widgets
    shared_ptr<CustomButton> testButton1;
    shared_ptr<CustomButton> testButton2;
    shared_ptr<CustomLineEntry> testEntry1;
    shared_ptr<CustomLineEntry> testEntry2;
    unique_ptr<QBoxLayout> testFrameLayout;
    shared_ptr<CustomFrame> testFrame1;
    
    // All three methods are only meant to be used in createHomeFrame
    void cacheWidgets(Cache& cache);
    void initWidgets(Cache& cache);
    unique_ptr<QBoxLayout> returnFrameLayout();
};
#endif