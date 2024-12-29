#ifndef CACHE_TPP
#define CACHE_TPP
#include "cache.h"
template <typename type>
shared_ptr<type> Cache::getCache(const QString& cache_key){
    if (all_caches.empty()) {
        cacheCache();
    }
    auto it = all_caches.find(cache_key);
    if (it != all_caches.end()) {
        qDebug("Cache exists, returning it");
        if (auto value = std::get_if<shared_ptr<type>>(&it->second)) {
            return *value;
        }
        qDebug() << "Cache found but type mismatch the key: " << cache_key;
        return nullptr;
    }
    qDebug() << "Cache doesn't exist " << cache_key;
    return nullptr;
};

#endif