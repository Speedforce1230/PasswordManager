#include "frame_home.h"
void HomeFrame::createHomeFrame(Cache& cache) {
    generate_password =  std::make_shared<CustomButton>("Generate Password");
    view_password = std::make_shared<CustomButton>("View Password");
    generate_password->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed);
    view_password->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed);
    home_frame = std::make_shared<CustomFrame>();
    home_frame_layout = std::make_unique<QVBoxLayout>();
    home_frame_layout->addWidget(generate_password.get());
    home_frame_layout->addWidget(view_password.get());
    home_frame->setLayout(home_frame_layout.release());
    cache.cacheFrame("Home",home_frame);
    cache.cacheButton("generate_password",generate_password);
    cache.cacheButton("view_password",view_password);
}
