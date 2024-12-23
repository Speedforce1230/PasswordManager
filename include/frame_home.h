#include "frame.h"
class MainWindow;
class HomeFrame : public CustomFrame{
public:
    HomeFrame();
    std::unique_ptr<CustomFrame> ReturnHomeFrame(bool create=true);
    std::unique_ptr<CustomButton> generate_password;
private:
    std::unique_ptr<CustomButton> view_password;
    std::unique_ptr<CustomFrame> home_frame;
    std::unique_ptr<QBoxLayout> home_frame_layout;
};