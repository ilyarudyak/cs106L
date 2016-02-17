//
// Created by Ilya Rudyak on 2/17/16.
//

#ifndef VECTOR_VECTOR_H
#define VECTOR_VECTOR_H


#include <stddef.h>
#include <algorithm>

template <typename T> class Vector {
public:

    Vector();
    ~Vector();

    // copy constructor
    Vector(const Vector& other);

    // assignment operator
    Vector& operator =(const Vector& other);


    typedef T* iterator;
    typedef const T* const_iterator;

    iterator begin();
    iterator end();
    const_iterator begin() const;
    const_iterator end() const;



private:
    T* array;

    // current allocated size
    size_t allocatedLength;

    // actual number of stored elements
    size_t logicalLength;

    // start (default) allocated size
    static const size_t kStartSize = 16;

    // helper functions
    void clear() {

    }
    void copyOther(const Vector &other);
};

template <typename T>
Vector<T>::Vector() {

    allocatedLength = kStartSize;
    logicalLength = 0;
    array = new T[kStartSize];
}

template <typename T>
Vector<T>::~Vector() {
    clear();
}

template <typename T> // copy constructor
Vector<T>::Vector(const Vector<T> &other) {
    copyOther(other);
}

template<typename T> // assignment operator
Vector<T>& Vector<T>::operator=(const Vector &other) {
    if (this != &other) {
        clear();
        copyOther(other);
    }
    return *this;
}

// -------------- helper functions --------------

template <typename T>
void Vector<T>::clear() {
    delete [] array;
}

template <typename T>
void Vector<T>::copyOther(const Vector& other) {
    logicalLength = other.logicalLength;
    allocatedLength = other.allocatedLength;
    array = new T[allocatedLength];
    std::copy(other.begin(), other.end(), array);
}



#endif //VECTOR_VECTOR_H



























