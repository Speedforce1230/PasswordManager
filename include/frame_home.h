#include "frame.h"
using home_variant = std::variant<CustomButton*>;
class MainWindow;
class HomeFrame : public CustomFrame{
public:
    HomeFrame();
    std::unique_ptr<CustomFrame> ReturnHomeFrame(bool create=true);
    CustomButton* getButton(const QString& key);
private:
    std::unique_ptr<CustomButton> generate_password;
    std::unique_ptr<CustomButton> view_password;
    std::unique_ptr<CustomFrame> home_frame;
    std::unique_ptr<QBoxLayout> home_frame_layout;
    void cacheWidgets();
    
    std::unordered_map<QString, home_variant> home_widget_cache;
};