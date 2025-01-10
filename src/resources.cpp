#include "resources.h"
#include "cache.h"
Resources::Resources(){
    entry_qss = std::make_shared<QString>("QLineEdit{"
        "border-radius: 10px;"
        "background-color: %1;"
        "color: %2;"
        "border: 1px solid #FF5722;"
        "padding: 2px;"
        "}");
    button_qss = std::make_shared<QString>("QPushButton {"
        "border-radius: 10px;"
        "background-color: %1;" 
        "color: %2;"
        "border: none;"
        "padding: 3px;"
        "}");
}
void Resources::cacheResources(Cache& cache){
    cache.cacheQss("entry_qss",entry_qss);
    cache.cacheQss("button_qss",button_qss);
}