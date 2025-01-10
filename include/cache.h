#ifndef CACHE_H
#define CACHE_H


#include <memory>
#include <QFrame>
#include <QLabel>
#include <QString>
#include "forward.h"
using std::unordered_map;
using std::shared_ptr;
using all_variant_types = std::variant<
    shared_ptr<unordered_map<QString, shared_ptr<CustomFrame>>>,
    shared_ptr<unordered_map<QString, shared_ptr<CustomButton>>>,
    shared_ptr<unordered_map<QString, shared_ptr<QLabel>>>,
    shared_ptr<unordered_map<QString, shared_ptr<CustomLineEntry>>>
>;
class Cache{
public:
    void cacheFrame(const QString& frame_key, shared_ptr<CustomFrame> frame);
    void cacheButton(const QString& button_key,shared_ptr<CustomButton> button);
    void cacheQss(const QString& qss_key,shared_ptr<QString> qss);
    template <typename type>
    shared_ptr<type> getCache(const QString& cache_key);
    shared_ptr<CustomFrame> getFrame(const QString& frame_key);
    shared_ptr<QString> getQss(const QString& qss_key);
    void cacheCache();
    shared_ptr<CustomButton> getButton(const QString& button_key);
private:
    unordered_map<QString, shared_ptr<CustomFrame>> frame_cache;
    unordered_map<QString, shared_ptr<CustomButton>> button_cache;
    unordered_map<QString, shared_ptr<QLabel>> label_cache;
    unordered_map<QString, shared_ptr<CustomLineEntry>> entry_cache;
    unordered_map<QString, all_variant_types> all_caches;
    unordered_map<QString, shared_ptr<QString>> qss_cache;
};
#include "cache.tpp"
#pragma once
#endif
