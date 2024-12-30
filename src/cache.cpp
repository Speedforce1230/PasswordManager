#include "cache.h"
void Cache::cacheFrame(const QString& frame_key, std::shared_ptr<CustomFrame> frame){
    frame_cache[frame_key] = frame;
}
void Cache::cacheButton(const QString& button_key,shared_ptr<CustomButton> button){
    button_cache[button_key] = button;
}
shared_ptr<CustomFrame> Cache::getFrame(const QString& frame_key){
    if (frame_cache.find(frame_key) != frame_cache.end()){
        qDebug()<< "getting frame " << frame_key;
        return frame_cache[frame_key];
    }
    qDebug() << "Failed to get frame";
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
void Cache::cacheCache() {
    all_caches["frame_cache"] = std::make_shared<unordered_map<QString, shared_ptr<CustomFrame>>>(frame_cache);
    all_caches["label_cache"] = std::make_shared<unordered_map<QString, shared_ptr<QLabel>>>(label_cache);
    all_caches["button_cache"] = std::make_shared<unordered_map<QString, shared_ptr<CustomButton>>>(button_cache);
    all_caches["entry_cache"] = std::make_shared<unordered_map<QString, shared_ptr<QLineEdit>>>(entry_cache);
}

