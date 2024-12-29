#ifndef RESOURCES_H
#define RESOURCES_H


#include <memory>
#include <QFrame>
#include <QLineEdit>
#include "frame.h"
using std::unordered_map;
using std::shared_ptr;
#pragma once
class Cache{
public:
    void cacheFrame(const QString& frame_key, shared_ptr<CustomFrame> frame);
    unordered_map<QString, shared_ptr<CustomFrame>> getFrameCache();
    unordered_map<QString, shared_ptr<CustomButton>> getButtonCache();
    unordered_map<QString, shared_ptr<QLabel>> getLabelCache();
    unordered_map<QString, shared_ptr<QLineEdit>> getEntryCache();

    shared_ptr<CustomFrame> getFrame(const QString& frame_key);
    shared_ptr<CustomButton> getButton(const QString& button_key);
private:
    unordered_map<QString, shared_ptr<CustomFrame>> frame_cache;
    unordered_map<QString, shared_ptr<CustomButton>> button_cache;
    unordered_map<QString, shared_ptr<QLabel>> label_cache;
    unordered_map<QString, shared_ptr<QLineEdit>> entry_cache;
};
#endif
