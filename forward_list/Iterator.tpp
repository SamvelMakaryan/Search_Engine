#ifndef ITERATOR_TPP_
#define ITERATOR_TPP_
#include "Forward_List.hpp"

template <typename T, typename Alloc>
Forward_List<T, Alloc>::iterator::iterator(node_base* ptr)
 : m_ptr(ptr) {}

template <typename T, typename Alloc>
Forward_List<T, Alloc>::iterator::iterator(const iterator&) = default;

template <typename T, typename Alloc>
typename Forward_List<T, Alloc>::iterator::iterator& Forward_List<T, Alloc>::iterator::operator++() {
    m_ptr = m_ptr -> m_next;
    return *this;
}

template <typename T, typename Alloc>
typename Forward_List<T, Alloc>::iterator::iterator Forward_List<T, Alloc>::iterator::operator++(int) {
    iterator tmp = *this;
    ++(*this);
    return tmp;
}

template <typename T, typename Alloc>
bool Forward_List<T, Alloc>::iterator::operator!=(const iterator& oth) const {
    return !(oth == *this);
}

template <typename T, typename Alloc>
bool Forward_List<T, Alloc>::iterator::operator==(const iterator& oth) const {
    return (m_ptr == oth.m_ptr);
}

template <typename T, typename Alloc>
bool Forward_List<T, Alloc>::iterator::operator<(const iterator& oth) const {
    if (m_ptr < oth.m_ptr) {
        return true;
    }
    return false;
}

template <typename T, typename Alloc>
bool Forward_List<T, Alloc>::iterator::operator>(const iterator& oth) const {
    if (oth == *this || oth < *this) {
        return false;
    }
    return true;
}

template <typename T, typename Alloc>
bool Forward_List<T, Alloc>::iterator::operator<=(const iterator& oth) const {
    return !(oth > *this);
}

template <typename T, typename Alloc>
bool Forward_List<T, Alloc>::iterator::operator>=(const iterator& oth) const {
    return !(oth < *this);
}

template <typename T, typename Alloc>
const T& Forward_List<T, Alloc>::iterator::operator*() const {
    return static_cast<Node*>(m_ptr)->m_data;
}

template <typename T, typename Alloc>
T& Forward_List<T, Alloc>::iterator::operator*() {
    return static_cast<Node*>(m_ptr)->m_data;
}

#endif //ITERATOR_TPP_