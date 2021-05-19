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

  void push_back(const T &item) {
    *(begin_ + size_++) = item;
    if (size_ == capacity_) {
      begin_++;
      size_--;
    }
  }
  void push_front(const T &item) {
    *(--begin_) = item;
    size_++;
    if (size_ == capacity_)
      size_--;
  }

  void pop_back() {
    size_ = std::max(0ul, size_ - 1);
  }
  void pop_front() {
    ++begin_;
    size_ = std::max(0ul, size_ - 1);
  }

  iterator begin() const { return begin_; }
  iterator end() const { return begin_ + size_; }
  T front() const { return *begin(); }
  T back() const { return *end(); };

  T operator[](size_t index) const { return *(begin_ + index); };
  T &operator[](size_t index) { return *(begin_ + index); }

  void set_capacity(size_t capacity);

  [[nodiscard]] size_t capacity() const { return capacity_; }
  [[nodiscard]] size_t size() const { return size_; }

  template<class U>
  friend std::ostream &operator<<(std::ostream &os, const circular_buffer<U> &cb);

 private:
  T *array_;
  size_t capacity_;
  size_t size_;
  iterator begin_;
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
    size_(0) {
  begin_ = iterator(array_, &array_, capacity_);
}

template<class T>
circular_buffer<T>::circular_buffer() :
    circular_buffer(0) {}

template<class T>
circular_buffer<T>::circular_buffer(const circular_buffer<T> &other) :
    array_(new T[other.capacity_]),
    capacity_(other.capacity_),
    begin_(other.begin_),
    size_(other.size_) {
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
  capacity_ = capacity + 1;
  begin_ = iterator(array + (static_cast<T *>(begin_) - array_), &array_, capacity_);
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

  iterator() : ptr_(nullptr), begin_(nullptr), size_(0) {}
  explicit iterator(pointer ptr, pointer *begin, difference_type size) :
      ptr_(ptr),
      begin_(begin),
      size_(size) {}

  reference operator*() const { return *ptr_; }
  pointer operator->() { return ptr_; }
  explicit operator T *() const { return ptr_; }

  iterator &operator++() {
    ++ptr_;
    if (ptr_ == *begin_ + size_)
      ptr_ = *begin_;
    return *this;
  }
  iterator operator++(int) {
    iterator tmp = *this;
    ++(*this);
    return tmp;
  }

  iterator &operator--() {
    --ptr_;
    if (ptr_ == *begin_ - 1)
      ptr_ = *begin_ + size_ - 1;
    return *this;
  }
  iterator operator--(int) {
    iterator tmp = *this;
    --(*this);
    return tmp;
  }

  iterator &operator+=(difference_type n) {
    ptr_ = *begin_ + (ptr_ - *begin_ + n) % size_;
    return *this;
  }
  iterator &operator-=(difference_type n) {
    ptr_ = *begin_ + (ptr_ - *begin_ - n % size_ + size_) % size_;
    return *this;
  }

  reference operator[](difference_type index) { return *(ptr_ + index); }
  value_type operator[](difference_type index) const { return *(ptr_ + index); }

  friend bool operator==(const iterator &a, const iterator &b) { return a.ptr_ == b.ptr_; }
  friend bool operator!=(const iterator &a, const iterator &b) { return a.ptr_ != b.ptr_; }
  friend bool operator<(const iterator &a, const iterator &b) { return a.ptr_ < b.ptr_; }
  friend bool operator>(const iterator &a, const iterator &b) { return b < a; }
  friend bool operator<=(const iterator &a, const iterator &b) { return a.ptr_ <= b.ptr_; }
  friend bool operator>=(const iterator &a, const iterator &b) { return b <= a; }

  friend iterator operator+(iterator a, difference_type n) { return a += n; }
  friend iterator operator+(difference_type n, iterator a) { return a += n; }
  friend iterator operator-(iterator a, difference_type n) { return a -= n; }
  friend difference_type operator-(iterator a, iterator b) { return a.ptr_ - b.ptr_; }

 private:
  pointer *begin_;
  difference_type size_;
  pointer ptr_;
};

#endif //LAB2_05_CIRCULAR_BUFFER_H
