#ifndef RESOURCES_H
#define RESOURCES_H

#include "forward.h"
#include <QString>
#include <memory>
using std::shared_ptr;
class Resources{
public:
    Resources();
    void cacheResources(Cache& cache);
private:
    
    shared_ptr<QString> entry_qss;
    shared_ptr<QString> button_qss;
    shared_ptr<Cache> cache;
};
#pragma once
#endif // RESOURCES_H