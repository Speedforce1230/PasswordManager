#include "window.h"
#include "button.h"
#include "widget.h"
MainWindow::MainWindow(){
    setWindowTitle("Password Manager");
    setFixedSize(600, 800);
    central_widget = std::make_unique<CentralWidget>(this);
    main_layout = std::make_unique<QVBoxLayout>(this);
    home_frame.createHomeFrame(cache);
    passwordFrame.createPasswordFrame(cache);
    view_frame.createViewFrame(cache);
    main_layout->addWidget(central_widget.get());
    setLayout(main_layout.get());
    setStyleSheet("MainWindow{background-color:rgb(58, 55, 55)}");
    ManageWindows("Home");
    ConnectEventHandlers();
}
void MainWindow::ManageWindows(const QString& window_name){
    qDebug() << "Attempting to get Frame: " << window_name;
    auto new_frame = cache.getFrame(window_name);
    if (new_frame){
        qDebug() << "Frame is valid, setting it.";
        central_widget->setCurrentFrame(new_frame);
    }
    else{
        qDebug() << "Frame is null\n Here's all the available keys";
        auto test = cache.getCache<unordered_map<QString,shared_ptr<CustomFrame>>>("frame_cache");
        // prints all keys
        if (test) {
            for (const auto& pair : *test) {
                qDebug() << pair.first;
            }
        }
        qDebug() << "Cache doesn't exist in the map, please recheck your types and keys";
    }
}
void MainWindow::ConnectEventHandlers(){
    connect(cache.getButton("generate_password").get(),&QPushButton::clicked,this,[=](){
        ManageWindows("Password");
    });
    connect(cache.getButton("back").get(),&QPushButton::clicked,this,[=](){
        ManageWindows("Home");
    });
    connect(cache.getButton("generateButton").get(),&QPushButton::clicked,this,[=](){
        passwordFrame.setPassword();
    });
    connect(cache.getButton("saveButton").get(),&QPushButton::clicked,this,[=](){
        ManageWindows("Home");
    });
    connect(cache.getButton("testButton1").get(),&QPushButton::clicked,this,[=](){
        ManageWindows("Home");
    });
}
