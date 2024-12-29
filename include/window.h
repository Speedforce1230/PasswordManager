#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QString>
#include <QBoxLayout>
#include "widget.h"
#include "all_frames.h"
#include "cache.h"
#include <memory>
#pragma once
class MainWindow : public QWidget{
    Q_OBJECT
public:
    MainWindow();
    // All new frames should be added into this method.
    void ManageWindows(const QString& window_name);
private:
    // For each derived frame, include it and declare it here then, if you need,
    // attach your connections in the ConnectEventHandlers method to avoid circular includes.
    std::unique_ptr<CentralWidget> central_widget;
    std::unique_ptr<QVBoxLayout> main_layout;
    std::unique_ptr<CustomFrame> custom_frame;
    Cache cache;
    HomeFrame home_frame;
    PasswordFrame password_frame;
    void ConnectEventHandlers();
};
#endif // WINDOW_H