#include <QApplication>
#include "window.h"
#include "widget.h"
// Naming scheme for this project, 
// snake_case for variables or attributes
// camelCase for methods or functions
// PascalCase for classes or objects

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    MainWindow window;
    window.show();    
    return app.exec();
}

