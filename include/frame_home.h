#ifndef FRAME_HOME_H
#define FRAME_HOME_H

#include "forward.h"
#include "frame.h"
#include <QBoxLayout>
#include <memory>
using std::shared_ptr;
class HomeFrame : CustomFrame{
    Q_OBJECT
public:
    // Creates the home frame. Make sure to pass the correct instance of Cache to ensure proper caching
    void createHomeFrame(Cache& cache);
private:
    // pointers for various widgets
    shared_ptr<CustomButton> generate_password;
    shared_ptr<CustomButton> view_password;
    shared_ptr<CustomFrame> home_frame;
    std::unique_ptr<QBoxLayout> home_frame_layout;
    // All three methods are only meant to be used in createHomeFrame
    void cacheWidgets(Cache& cache);
    void initWidgets(Cache& cache);
    std::unique_ptr<QBoxLayout> returnFrameLayout();
};
#endif