#ifndef LAB2_05_CIRCULAR_BUFFER_H
#define LAB2_05_CIRCULAR_BUFFER_H

#include <cstdio>
#include <iostream>
#include <iterator>
#include <cstddef>

template<class T>
class circular_buffer {
public:
    class iterator;

    circular_buffer();

    explicit circular_buffer(size_t capacity);

    circular_buffer(const circular_buffer<T> &other);

    void swap(circular_buffer &other);

    circular_buffer<T> &operator=(const circular_buffer<T> &other);

    ~circular_buffer();

    void push_back(const T &item) { *(end_++) = item; }
    void push_front(const T &item) { *(--begin_) = item; }

    void pop_back() { --end_; }
    void pop_front() { ++begin_; }

    iterator begin() const { return begin_; }
    iterator end() const { return end_; }

    T front() const { return array_[begin_]; }
    T back() const { return array_[end_ % capacity_]; };

    T operator[](size_t index) const { return array_[(begin_ + index) % capacity_]; };
    T &operator[](size_t index) { return array_[(begin_ + index) % capacity_]; }

    void set_capacity(size_t capacity);
    [[nodiscard]] size_t capacity() const { return capacity_; }
    [[nodiscard]] size_t size() const { return (end_ - begin_) % capacity_; }

    template<class U>
    friend std::ostream &operator<<(std::ostream &os, const circular_buffer<U> &cb);


private:
    T *array_;
    size_t capacity_{};
    iterator begin_{};
    iterator end_{};

    void mod(T &item) {
        item %= capacity_;
    }
};

template<class T>
std::ostream &operator<<(std::ostream &os, const circular_buffer<T> &cb) {
    for (auto i : cb)
        os << i << ' ';
    os << '\n';
    return os;
}

template<class T>
circular_buffer<T>::circular_buffer(size_t capacity) :
        array_(new T[capacity + 1]),
        capacity_(capacity + 1),
        begin_(array_),
        end_(array_) {
            iterator a(nullptr);
            typename iterator::difference_type iterator::size = capacity + 1;
        }

template<class T>
circular_buffer<T>::circular_buffer() :
        circular_buffer(1) {}

template<class T>
circular_buffer<T>::circular_buffer(const circular_buffer<T> &other) :
        array_(new T[other.capacity_]),
        capacity_(other.capacity_),
        begin_(other.begin_),
        end_(other.end_) {
    for (size_t i = 0; i != other.capacity_; i++)
        array_[i] = other.array_[i];
}

template<class T>
void circular_buffer<T>::swap(circular_buffer &other) {
    std::swap(this->array_, other.array_);
    std::swap(this->begin_, other.begin_);
    std::swap(this->end_, other.end_);
    std::swap(this->capacity_, this->capacity_);
}

template<class T>
circular_buffer<T> &circular_buffer<T>::operator=(const circular_buffer<T> &other) {
    circular_buffer(other).swap(*this);
    return *this;
}

template<class T>
circular_buffer<T>::~circular_buffer() {
    delete[] array_;
    array_ = nullptr;
}

template<class T>
void circular_buffer<T>::set_capacity(size_t capacity) {
    T *array = new T[capacity + 1];
    for (size_t i = 0; i != capacity_; i++)
        array[i] = array_[i];
    delete[] array_;
    array_ = array;
}

template<class T>
class circular_buffer<T>::iterator {
public:
    using iterator_category = std::random_access_iterator_tag;
    using difference_type = std::ptrdiff_t;
    using value_type = T;
    using pointer = T *;
    using reference = T &;

    explicit iterator(pointer ptr) : ptr_(ptr) {}

    reference operator*() const { return *ptr_; }
    pointer operator->() { return ptr_; }

    iterator &operator++() { forth(++ptr_); return *this; }
    iterator operator++(int) { iterator tmp = *this; ++(*this); return tmp; }
    iterator &operator--() { back(--ptr_); return *this; }
    iterator operator--(int) { iterator tmp = *this; --(*this); return tmp; }

//        iterator &operator+=(difference_type n) { forth(ptr_ += n, n); return *this; }
//        iterator &operator-=(difference_type n) { back(ptr_ -= n, n); return *this; }

    friend bool operator==(const iterator &a, const iterator &b) { return a.ptr_ == b.ptr_; }
    friend bool operator!=(const iterator &a, const iterator &b) { return a.ptr_ != b.ptr_; }

//        friend iterator operator+(iterator a, difference_type n) { return a += n; }
//        friend iterator operator+(difference_type n, iterator a) { return a += n; }
//        friend iterator operator-(iterator a, difference_type n) { return a -= n; }
//        friend iterator operator-(iterator a, iterator b) { return (a.ptr_ - b.ptr_) % size; }

    static pointer begin;
    static difference_type size;
private:
    pointer ptr_;

    void forth(pointer &ptr) {
        forth(ptr, 1);
    }
    void back(pointer &ptr) {
        back(ptr, 1);
    }
    void forth(pointer &ptr, difference_type n) {
        ptr = begin + (ptr - begin + n) % (size);
    }
    void back(pointer &ptr, difference_type n) {
        ptr = begin + (ptr - begin - n) % (size);
    }
};

#endif //LAB2_05_CIRCULAR_BUFFER_H
