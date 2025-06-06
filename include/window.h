/*
   MIT License
   Copyright (c) 2025 Vasu Dhall(Speedforce1230)
   Please retain this copyright notice when using or modifying this project.
*/

#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QString>
#include <QBoxLayout>
#include <QPushButton>
#include <QTimer>
#include "forward.h"
#include "cache.h"
#include "frame_home.h"
#include "frame_password.h"
#include "frame_view.h"
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
    std::unique_ptr<QBoxLayout> main_layout;
    PasswordFrame passwordFrame;
    Cache cache;
    HomeFrame home_frame;
    ViewFrame view_frame;
    void connectEventHandlers();
    void startFadeOut();
};
#pragma once
#endif // WINDOW_H