#include <iostream>
#include "src/circular_buffer.h"

template<class T>
class Integers
{
public:
    struct Iterator
    {
        using iterator_category = std::forward_iterator_tag;
        using difference_type   = std::ptrdiff_t;
        using value_type        = T;
        using pointer           = T*;
        using reference         = T&;

        Iterator(pointer ptr) : m_ptr(ptr) {}

        reference operator*() const { return *m_ptr; }
        pointer operator->() { return m_ptr; }
        Iterator& operator++() { m_ptr++; return *this; }
        Iterator operator++(int) { Iterator tmp = *this; ++(*this); return tmp; }
        friend bool operator== (const Iterator& a, const Iterator& b) { return a.m_ptr == b.m_ptr; };
        friend bool operator!= (const Iterator& a, const Iterator& b) { return a.m_ptr != b.m_ptr; };

    private:
        pointer m_ptr;
    };

    Integers(T k) : value(k) {
        Iterator it(nullptr);
    };

    Iterator begin() { return Iterator(&m_data[0]); }
    Iterator end()   { return Iterator(&m_data[200]); }

private:
    T m_data[200];
    T value;
};

int main() {

//    Integers<int> a(4);
//    a.begin();
//    a.end();
    circular_buffer<int> a(3);
//    a.push_back(1);
//    a.push_back(2);
//    a.push_back(3);

//    std:: cout << a;

    return 0;
}
