#include "cache.h"
#include "characters.h"
#include <QLineEdit>
#include <QTextEdit>
#include <QLabel>
#include <memory>


class PasswordFrame : public CustomFrame{
public:
    void createPasswordFrame(Cache& cache);
private:
    shared_ptr<CustomButton> generate_button;
    shared_ptr<CustomButton> back_button;
    shared_ptr<CustomFrame> password_frame;
    shared_ptr<QLineEdit> username_entry;
    shared_ptr<QLineEdit> password_entry;
    shared_ptr<QLabel> label_name;
    shared_ptr<QLabel> label_password;
    shared_ptr<CustomButton> save_button;
    unique_ptr<QBoxLayout> password_frame_layout;
    int button_width = 2;
    std::unordered_map<QString,std::variant<CustomButton*, QLineEdit*,QLabel*>> password_widget_cache;
    
    enum{
        ID_NUMBERS = 0,
        ID_LOWER_ALPHABETS=1,
        ID_UPPER_ALPHABETS=2,
        ID_SYMBOLS=3
    };
    void cacheWidgets(Cache& cache);
    void generatePassword();
    void initWidgets();
    unique_ptr<QBoxLayout> returnFrameLayout();
};