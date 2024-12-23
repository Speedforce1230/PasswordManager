#include "frame.h"

CustomFrame::CustomFrame(QWidget* parent) : QFrame(parent){
    setFrameStyle(QFrame::Box | QFrame::Raised);
    // No borders
    setLineWidth(2);
    setMidLineWidth(2);
    
}

