//
// Created by Ilya Rudyak on 2/17/16.
//

#ifndef SMART_POINTER_SMARTPOINTER_H
#define SMART_POINTER_SMARTPOINTER_H


#include <stddef.h>

template <typename T> class SmartPointer {
public:

    // constructor and destructor
    explicit SmartPointer(T* memory);
    ~SmartPointer();

    // copy constructor and = operator
    SmartPointer(const SmartPointer& other);
    SmartPointer& operator =(const SmartPointer& other);

    // operator overloading
    T& operator*  () const;
    T* operator-> () const;

private:

    struct Intermediary {
        T* resource;
        size_t refCount;
    };
    Intermediary* data;

    // helper functions
    void detach();
    void attach(Intermediary* other);
};

template <typename T> SmartPointer<T>::SmartPointer(T *memory) {
    data = new Intermediary;
    data->resource = memory;
    data->refCount = 1;
}
template <typename T> SmartPointer<T>::~SmartPointer() {
    detach();
}

template <typename T> SmartPointer<T>::SmartPointer(const SmartPointer& other) {
    attach(other.data);
}
template <typename T> SmartPointer<T>& SmartPointer<T>::operator =(const SmartPointer& other) {
    if(this != &other) {
        detach();
        attach(other.data);
    }
    return *this;
}

template <typename T> T& SmartPointer<T>::operator * () const {
    return *data->resource;
}
template <typename T> T* SmartPointer<T>::operator -> () const {
    return data->resource;
}

// helper functions
template <typename T> void SmartPointer<T>::detach() {
    --data->refCount;
    if(data->refCount == 0) {
        delete data->resource;
        delete data;
    }
}
template <typename T> void SmartPointer<T>::attach(Intermediary* to) {
    data = to;
    ++data->refCount;
}


#endif //SMART_POINTER_SMARTPOINTER_H









































