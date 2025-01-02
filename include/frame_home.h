#include "cache.h"
using home_variant = std::variant<CustomButton*>;
class MainWindow;
class HomeFrame : public CustomFrame{
public:
    // Creates the home frame. Make sure to pass the correct instance of Cache to ensure proper caching
    void createHomeFrame(Cache& cache);
private:
    // pointers for various widgets
    shared_ptr<CustomButton> generate_password;
    shared_ptr<CustomButton> view_password;
    shared_ptr<CustomFrame> home_frame;
    unique_ptr<QBoxLayout> home_frame_layout;
    // All three methods are only meant to be used in createHomeFrame
    void cacheWidgets(Cache& cache);
    void initWidgets();
    unique_ptr<QBoxLayout> returnFrameLayout();
};