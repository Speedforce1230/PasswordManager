/*
   MIT License
   Copyright (c) 2025 Vasu Dhall(Speedforce1230)
   Please retain this copyright notice when using or modifying this project.
*/

#ifndef FRAME_PASSWORD_H
#define FRAME_PASSWORD_H
#include "forward.h"
#include "frame.h"
#include <QTextEdit>
#include <QLabel>
#include <QBoxLayout>
#include <memory>
using std::shared_ptr;
using std::unique_ptr;
class PasswordFrame : public CustomFrame{
    Q_OBJECT
public:
    void createPasswordFrame(Cache& cache);
    void setPassword();
private:
    // DO NOT PUT PASSWORD FRAME BELOW ANYTHING, IT WILL BREAK FOR GOD KNOWS WHAT REASON!!!
    // ONLY APPLIES TO THIS SPECIFIC FRAME, GOD FORBID YOU ENCOUNTER IT ELSEWHERE!!!
    shared_ptr<CustomFrame> password_frame;
    shared_ptr<QLabel> label_name;
    shared_ptr<QLabel> label_password;
    
    unique_ptr<QBoxLayout> password_frame_layout;
    shared_ptr<CustomLineEntry> username_entry;
    shared_ptr<CustomLineEntry> password_entry;
    
    shared_ptr<CustomButton> save_button;
    shared_ptr<CustomButton> generate_button;
    shared_ptr<CustomButton> back_button;
    
    
    
    enum{
        ID_NUMBERS = 0,
        ID_LOWER_ALPHABETS=1,
        ID_UPPER_ALPHABETS=2,
        ID_SYMBOLS=3
    };
    void cacheWidgets(Cache& cache);
    QString generatePassword();
    void initWidgets(Cache& cache);
    unique_ptr<QBoxLayout> returnFrameLayout();
};
#endif