#include "window.h"
MainWindow::MainWindow(){
    setWindowTitle("Password Manager");
    resize(400,600);
    central_widget = std::make_unique<CentralWidget>(this);
    main_layout = std::make_unique<QVBoxLayout>(this);
    password_frame = std::make_unique<PasswordFrame>();
    home_frame = std::make_unique<HomeFrame>();
    main_layout->addWidget(central_widget.get());
    ManageWindows("Home");
    ConnectEventHandlers();
    setLayout(main_layout.get());
}
void MainWindow::ManageWindows(const QString& window_name){
    if (window_name == "Home"){
        new_frame.reset();
        
        new_frame = home_frame->ReturnHomeFrame();
        central_widget->setCurrentFrame(std::move(new_frame));
        
    }
    else if (window_name == "Generate"){
        new_frame.reset();
        new_frame = password_frame->ReturnPasswordFrame();
        central_widget->setCurrentFrame(std::move(new_frame));

    }
}
void MainWindow::ConnectEventHandlers(){
    connect(home_frame->generate_password.get(),&QPushButton::clicked,this,[=](){
        ManageWindows("Generate");
    });
}