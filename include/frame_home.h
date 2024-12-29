#include "cache.h"
using home_variant = std::variant<CustomButton*>;
class MainWindow;
class HomeFrame : public CustomFrame{
public:
    void createHomeFrame(Cache& cache);
private:
    unique_ptr<CustomButton> generate_password;
    unique_ptr<CustomButton> view_password;
    shared_ptr<CustomFrame> home_frame;
    unique_ptr<QBoxLayout> home_frame_layout;
    std::unordered_map<QString, CustomButton*> home_widget_cache;
    void cacheWidgets();
};