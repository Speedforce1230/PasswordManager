#include "frame_home.h"
HomeFrame::HomeFrame(){
    generate_password =  std::make_unique<CustomButton>("Generate Password");
    view_password = std::make_unique<CustomButton>("View Password");

    
    generate_password->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed);
    view_password->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed);
    home_frame = std::make_unique<CustomFrame>();
    home_frame_layout = std::make_unique<QVBoxLayout>();
    home_frame_layout->addWidget(generate_password.get(),0,Qt::AlignVCenter);
    home_frame_layout->addWidget(view_password.get());
    home_frame->setLayout(home_frame_layout.get());
    cacheWidgets();
}
std::unique_ptr<CustomFrame> HomeFrame::ReturnHomeFrame(bool create){
    return std::move(home_frame);
}
void HomeFrame::cacheWidgets(){
    home_widget_cache["generate_password"] = generate_password.get();
    home_widget_cache["view_password"] = view_password.get();
}
CustomButton* HomeFrame::getButton(const QString& key){
    if (home_widget_cache.find(key) != home_widget_cache.end()){
        CustomButton* button = std::get<CustomButton*>(home_widget_cache[key]);
        return button;
    }
}
