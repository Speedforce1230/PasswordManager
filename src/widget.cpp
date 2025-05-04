/*
   MIT License
   Copyright (c) 2025 Vasu Dhall(Speedforce1230)
   Please retain this copyright notice when using or modifying this project.
*/

#include "widget.h"
#include "frame.h"
CentralWidget::CentralWidget(QWidget* parent) : QWidget(parent){
    main_layout = std::make_unique<QVBoxLayout>(this);
    main_widget_stack = std::make_unique<QStackedWidget>(this);
    main_layout->addWidget(main_widget_stack.get());
    setLayout(main_layout.get());
    
}
void CentralWidget::setCurrentFrame(std::shared_ptr<CustomFrame> frame){
    
    int index = main_widget_stack->indexOf(frame.get());
    if (index == -1){
        main_widget_stack->addWidget(frame.get());
        index = main_widget_stack->indexOf(frame.get());
    }
    main_widget_stack->setCurrentIndex(index);
    // int current_index = main_widget_stack->currentIndex();
    // QWidget* current_widget = main_widget_stack->widget(current_index);
    // if (current_widget){
    //     qDebug("Current widget is valid");
    // }
    // else{
    //     qDebug("Current widget is invalid");
    // }
    // QVBoxLayout* layout = qobject_cast<QVBoxLayout*>(main_widget_stack->layout());
    // if (layout){
    //     layout->removeWidget(current_widget);
    //     layout->removeWidget(frame.get());
    // }
    // QPropertyAnimation* slide_out = new QPropertyAnimation(current_widget,"pos");
    // slide_out->setDuration(500);
    // slide_out->setStartValue(current_widget->pos());
    // slide_out->setEndValue(QPoint(-current_widget->width(), frame->pos().y()));
    
    // QPropertyAnimation* slide_in = new QPropertyAnimation(frame.get(), "pos");
    // slide_in->setDuration(500);
    // slide_in->setStartValue(QPoint(main_widget_stack->width(),frame->pos().y()));
    // slide_in->setEndValue(frame->pos());
    // QParallelAnimationGroup* group = new QParallelAnimationGroup();
    // group->addAnimation(slide_out);
    // group->addAnimation(slide_in);
    

    // connect(group, &QParallelAnimationGroup::finished,this, [this, index,current_widget,frame,layout](){
    //     main_widget_stack->setCurrentIndex(index);
    //     current_widget->hide();
    //     if (layout){
    //         layout->addWidget(current_widget);
    //         layout->addWidget(frame.get());
    //     }
    // });
    // group->start(QAbstractAnimation::DeleteWhenStopped);
}