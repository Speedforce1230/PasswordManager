#include "frame.h"
#include "characters.h"
#include <QLineEdit>
#include <QTextEdit>
#include <QLabel>
#include <memory>


class PasswordFrame : public CustomFrame{
public:
    PasswordFrame();
    unique_ptr<CustomFrame> ReturnPasswordFrame(bool create=true);
    CustomButton* getButton(const QString& key);
    QLabel* getLabel(const QString& key);
    QLineEdit* getEntry(const QString& key);
private:
    std::unordered_map<QString, std::variant<CustomButton*,CustomFrame*,QLineEdit*,QLabel*>> password_widget_cache;
    unique_ptr<CustomButton> generate_button;
    unique_ptr<CustomFrame> password_frame;
    unique_ptr<QLineEdit> username_entry;
    unique_ptr<QLineEdit> password_entry;
    unique_ptr<QLabel> label_name;
    unique_ptr<QLabel> label_password;
    unique_ptr<CustomButton> save_button;
    unique_ptr<QBoxLayout> password_frame_layout;
    
    void cacheWidgets();
    enum{
        ID_NUMBERS = 0,
        ID_LOWER_ALPHABETS=1,
        ID_UPPER_ALPHABETS=2,
        ID_SYMBOLS=3
    };
    void GeneratePassword();
};