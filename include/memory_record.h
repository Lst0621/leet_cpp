#pragma once
#include "all_include.h"
#include "glog/logging.h"

namespace lst {
namespace leet {

template <class T>
class Pool {
   private:
    static Pool<T> INSTANCE;
    vector<T*> vec;

   public:
    static void add(T* ptr);

   private:
    Pool<T>() {
        LOG(INFO) << "Hello " << sizeof(T);
    };
    ~Pool<T>() {
        for (T* ptr : vec) {
            delete ptr;
        }
        LOG(INFO) << "Goodbye " << sizeof(T);
    }
};

template <class T>
Pool<T> Pool<T>::INSTANCE = Pool<T>();

template <class T>
void Pool<T>::add(T* ptr) {
    INSTANCE.vec.push_back(ptr);
}

}  // namespace leet
}  // namespace lst
