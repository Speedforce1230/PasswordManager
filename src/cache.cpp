/*
   MIT License
   Copyright (c) 2025 Vasu Dhall(Speedforce1230)
   Please retain this copyright notice when using or modifying this project.
*/

#include "cache.h"
#include "button.h"
#include "entry.h"
void Cache::cacheFrame(const QString& frame_key, std::shared_ptr<CustomFrame> frame){
    frame_cache[frame_key] = frame;
}
void Cache::cacheButton(const QString& button_key,shared_ptr<CustomButton> button){
    if (button_cache.find(button_key) != button_cache.end()){
        qDebug() << "Duplicate Key detected: " << button_key;
    }
    else{
        button_cache[button_key] = button;
    }
}
void Cache::cacheEntry(const QString& entry_key, shared_ptr<CustomLineEntry> entry){
    entry_cache[entry_key] = entry;
}
void Cache::cacheQss(const QString& qss_key, shared_ptr<QString> qss){
    qss_cache[qss_key] = qss; 
}
shared_ptr<CustomFrame> Cache::getFrame(const QString& frame_key){
    if (frame_cache.find(frame_key) != frame_cache.end()){
        qDebug()<< "getting frame " << frame_key;
        return frame_cache[frame_key];
    }
    qDebug() << "Failed to get frame";
    return nullptr;
}
shared_ptr<CustomLineEntry> Cache::getEntry(const QString& entry_key){
    if (entry_cache.find(entry_key) != entry_cache.end()){
        qDebug() << "getting entry " << entry_key; 
        return entry_cache[entry_key];
    }
    qDebug() << "Failed to get entry";
    return nullptr;
}
shared_ptr<CustomButton> Cache::getButton(const QString& button_key){
    if (button_cache.find(button_key) != button_cache.end()){
        qDebug()<< "getting button " << button_key;
        return button_cache[button_key];
    }
    qDebug() << "Failed to get button";
    return nullptr;
}
shared_ptr<QString> Cache::getQss(const QString& qss_key){
    if (qss_cache.find(qss_key) != qss_cache.end()){
        qDebug() << "getting qss " << qss_key;
        return qss_cache[qss_key];
    }
    qDebug() << "Failed to get qss";
    return nullptr;
}
void Cache::cacheCache() {
    all_caches["frame_cache"] = std::make_shared<unordered_map<QString, shared_ptr<CustomFrame>>>(frame_cache);
    all_caches["label_cache"] = std::make_shared<unordered_map<QString, shared_ptr<QLabel>>>(label_cache);
    all_caches["button_cache"] = std::make_shared<unordered_map<QString, shared_ptr<CustomButton>>>(button_cache);
    all_caches["entry_cache"] = std::make_shared<unordered_map<QString, shared_ptr<CustomLineEntry>>>(entry_cache);
}

