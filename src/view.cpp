#include "frame_view.h"
#include "button.h"
#include "cache.h"
#include "entry.h"
void ViewFrame::createViewFrame(Cache& cache){
    initWidgets(cache);
    testFrame1 = std::make_shared<CustomFrame>();
    testFrameLayout = returnFrameLayout();
    testFrame1->setLayout(testFrameLayout.get());
    cacheWidgets(cache);
}
void ViewFrame::initWidgets(Cache& cache) {
    // Initializing widgets and connecting.
    // IMPORTANT!!
    // if you want to connect a outside function to a button or anything else,
    // use the desired cache.getXXX method to attach it.
    // Avoid direct includes to prevent circular dependencies.
    testButton1 = std::make_shared<CustomButton>("TESTING 1",cache);
    testButton2 = std::make_shared<CustomButton>("TESTING 2",cache);
    testEntry1 = std::make_shared<CustomLineEntry>(cache);
    testEntry2 = std::make_shared<CustomLineEntry>(cache);
}
std::unique_ptr<QBoxLayout> ViewFrame::returnFrameLayout(){
    std::unique_ptr<QBoxLayout> layout = std::make_unique<QVBoxLayout>();
    QSpacerItem* top_spacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);
	QSpacerItem* bottom_spacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);
    layout->addSpacerItem(top_spacer);
    layout->addWidget(testButton1.get());
    layout->addWidget(testButton2.get());
    layout->addWidget(testEntry1.get());
    layout->addWidget(testEntry2.get());
    layout->addSpacerItem(bottom_spacer);
    return std::move(layout);
}
void ViewFrame::cacheWidgets(Cache& cache){
    cache.cacheFrame("testFrame1",testFrame1);
    cache.cacheButton("testButton1",testButton1);
    cache.cacheButton("testButton2",testButton2);
}