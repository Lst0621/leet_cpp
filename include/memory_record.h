#pragma once
#include "all_include.h"
#include "glog/logging.h"

namespace lst {
namespace leet {
template <class T>
class MemoryRecord {
   private:
    static MemoryRecord<T> INSTANCE;
    vector<T*> vec;

   public:
    void add_pt(T* pt) {
        vec.push_back(pt);
    }

    static MemoryRecord& get() {
        return INSTANCE;
    }

   private:
    MemoryRecord<T>() {
        LOG(INFO) << "Hello " << sizeof(T);
    };

    ~MemoryRecord<T>() {
        for (T* ptr : vec) {
            delete ptr;
        }
        LOG(INFO) << "Goodbye " << sizeof(T)<< ". pt count "<<vec.size();
    }
};

template <class T>
MemoryRecord<T> MemoryRecord<T>::INSTANCE = MemoryRecord<T>();

template <class T>
void add_pt_to_record(T* ptr) {
    MemoryRecord<T>::get().add_pt(ptr);
}

}  // namespace leet
}  // namespace lst
