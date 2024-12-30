#include "window.h"
MainWindow::MainWindow(){
    setWindowTitle("Password Manager");
    resize(400,600);
    central_widget = std::make_unique<CentralWidget>(this);
    main_layout = std::make_unique<QVBoxLayout>(this);
    home_frame.createHomeFrame(cache);
    password_frame.createPasswordFrame(cache);
    main_layout->addWidget(central_widget.get());
    setLayout(main_layout.get());
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
        if (test) {
            for (const auto& pair : *test) {
                qDebug() << pair.first;
            }
            return;
        }
        qDebug() << "Cache doesn't exist in test";
        return;
    }
}
void MainWindow::ConnectEventHandlers(){
    connect(cache.getButton("generate_password").get(),&QPushButton::clicked,this,[=](){
        ManageWindows("Password");
    });
}