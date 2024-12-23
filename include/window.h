#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QString>
#include <QBoxLayout>
#include "widget.h"
#include "all_frames.h"
#include <memory>
#pragma once
class MainWindow : public QWidget{
    Q_OBJECT
public:
    MainWindow();
    void ManageWindows(const QString& window_name);
private:
    std::unique_ptr<CentralWidget> central_widget;
    std::unique_ptr<QVBoxLayout> main_layout;
    std::unique_ptr<CustomFrame> custom_frame;
    std::unique_ptr<CustomFrame> new_frame;
    std::unique_ptr<PasswordFrame> password_frame; 
    std::unique_ptr<HomeFrame> home_frame;
    void ConnectEventHandlers();
};
#endif // WINDOW_H