/*
   MIT License
   Copyright (c) 2025 Vasu Dhall(Speedforce1230)
   Please retain this copyright notice when using or modifying this project.
*/


#include "frame_home.h"
#include "frame.h"
#include "button.h"
#include "cache.h"
void HomeFrame::createHomeFrame(Cache& cache) {
    // IMPORTANT!! This is strictly to cache the created frame, 
    // if you want to use it, call cache.getFrame and pass the correct key in your file.
    initWidgets(cache);
    home_frame = std::make_shared<CustomFrame>();    
    home_frame_layout = returnFrameLayout();
    home_frame->setLayout(home_frame_layout.get());
    cacheWidgets(cache);
}
void HomeFrame::initWidgets(Cache& cache) {
    // Initializing widgets and connecting.
    // IMPORTANT!!
    // if you want to connect a outside function to a button or anything else,
    // use the desired cache.getXXX method to attach it.
    // Avoid direct includes to prevent circular dependencies.
    generate_password = std::make_shared<CustomButton>("Generate Password",cache);
    view_password = std::make_shared<CustomButton>("View Password",cache);
    generate_password->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    view_password->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
}
unique_ptr<QBoxLayout> HomeFrame::returnFrameLayout() {
    // creates a top to bottom layout and returns it.
    unique_ptr<QBoxLayout> layout = std::make_unique<QVBoxLayout>();
    layout->addWidget(generate_password.get());
    layout->addWidget(view_password.get());
    return std::move(layout);
}
void HomeFrame::cacheWidgets(Cache& cache) {
    // The cache is unordered so don't worry about the order you cache your widgets in. Be careful with the keys!
    cache.cacheFrame("Home", home_frame);
    cache.cacheButton("generate_password", generate_password);
    cache.cacheButton("view_password", view_password);
}
