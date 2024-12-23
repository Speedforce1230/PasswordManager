#include "frame.h"
#include <QLineEdit>
#include <QTextEdit>
#include <QLabel>
#include <array>
class PasswordFrame : public CustomFrame{
public:
    PasswordFrame();
    std::unique_ptr<CustomFrame> ReturnPasswordFrame(bool create=true);
    std::unique_ptr<CustomButton> generate_button;
private:
    std::unique_ptr<CustomFrame> password_frame;
    std::unique_ptr<QLineEdit> username_entry;
    std::unique_ptr<QLineEdit> password_entry;
    std::unique_ptr<QLabel> label_name;
    std::unique_ptr<QLabel> label_password;
    std::unique_ptr<CustomButton> save_button;
    std::unique_ptr<QBoxLayout> password_frame_layout;
    enum{
        ID_NUMBERS = 0,
        ID_LOWER_ALPHABETS=1,
        ID_UPPER_ALPHABETS=2,
        ID_SYMBOLS=3
    };
    void GeneratePassword();
};