#include "circular_buffer.h"

//template<class T>
//circular_buffer<T>::circular_buffer(size_t capacity) :
//        array_(new T[capacity]),
//        capacity_(capacity),
//        begin_(0),
//        end_(0) {}
//
//template<class T>
//circular_buffer<T>::circular_buffer() :
//        circular_buffer(1) {}
//
//template<class T>
//circular_buffer<T>::circular_buffer(const circular_buffer<T> &other) :
//        array_(new T[other.capacity_]),
//        capacity_(other.capacity_),
//        begin_(other.begin_),
//        end_(other.end_) {
//    for (size_t i = 0; i != other.capacity_; i++)
//        array_[i] = other.array_[i];
//}
//
//template<class T>
//void circular_buffer<T>::swap(circular_buffer &other) {
//    std::swap(this->array_, other.array_);
//    std::swap(this->begin_, other.begin_);
//    std::swap(this->end_, other.end_);
//    std::swap(this->capacity_, this->capacity_);
//}
//
//template<class T>
//circular_buffer<T> &circular_buffer<T>::operator=(const circular_buffer<T> &other) {
//    circular_buffer(other).swap(*this);
//    return *this;
//}
//
//template<class T>
//circular_buffer<T>::~circular_buffer() {
//    delete[] array_;
//    array_ = nullptr;
//}

//template<class T>
//void circular_buffer<T>::push_back(const T &item) {
//    array_[end_] = item;
//    mod(++end_);
//}
//
//template<class T>
//void circular_buffer<T>::push_front(const T &item) {
//    mod(--begin_);
//    array_[begin_] = item;
//}
//
//template<class T>
//void circular_buffer<T>::set_capacity(size_t capacity) {
//    T *array = new T[capacity];
//    for (size_t i = 0; i != capacity_; i++)
//        array[i] = array_[i];
//    delete[] array_;
//    array_ = array;
//}



