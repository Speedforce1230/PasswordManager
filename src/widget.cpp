#include "widget.h"

CentralWidget::CentralWidget(QWidget* parent) : QWidget(parent){
    main_layout = std::make_unique<QVBoxLayout>(this);
    main_widget_stack = std::make_unique<QStackedWidget>(this);
    main_layout->addWidget(main_widget_stack.get());
    setLayout(main_layout.get());
    
}
void CentralWidget::setCurrentFrame(std::unique_ptr<CustomFrame> frame){
    int index = main_widget_stack->indexOf(frame.get());
    if (index == -1){
        main_widget_stack->addWidget(frame.get());
        index = main_widget_stack->indexOf(frame.get());
    }
    main_widget_stack->setCurrentIndex(index);
    frame.release();
}