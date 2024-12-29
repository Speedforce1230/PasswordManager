#include "frame_home.h"
void HomeFrame::cacheWidgets(){
    home_widget_cache["generate"] = generate_password.get();
    home_widget_cache["view"] = view_password.get();
}
void HomeFrame::createHomeFrame(Cache& cache) {
    generate_password =  std::make_unique<CustomButton>("Generate Password");
    view_password = std::make_unique<CustomButton>("View Password");
    generate_password->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed);
    view_password->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed);
    cacheWidgets();

    home_frame = std::make_shared<CustomFrame>();
    home_frame_layout = std::make_unique<QVBoxLayout>();
    home_frame_layout->addWidget(generate_password.release());
    home_frame_layout->addWidget(view_password.release());
    home_frame->setLayout(home_frame_layout.release());
    cache.cacheFrame("Home",home_frame);
}
