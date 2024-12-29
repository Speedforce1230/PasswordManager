#include "cache.h"
void Cache::cacheFrame(const QString& frame_key, std::shared_ptr<CustomFrame> frame){
    frame_cache[frame_key] = frame;
}
shared_ptr<CustomFrame> Cache::getFrame(const QString& frame_key){
    if (frame_cache.find(frame_key) != frame_cache.end()){
        qDebug()<< "getting frame " << frame_key;
        return frame_cache[frame_key];
    }
    qDebug() << "Failed to get frame";
    return nullptr;
}
unordered_map<QString,shared_ptr<CustomFrame>> Cache::getFrameCache(){
    return frame_cache;
}
unordered_map<QString, shared_ptr<CustomButton>> Cache::getButtonCache() {
    return button_cache;
}
unordered_map<QString, shared_ptr<QLabel>> Cache::getLabelCache() {
    return label_cache;
}
unordered_map<QString, shared_ptr<QLineEdit>> Cache::getEntryCache() {
    return entry_cache;
}
