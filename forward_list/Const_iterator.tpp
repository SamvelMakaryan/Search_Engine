#ifndef CONST_ITERATOR_TPP_
#define CONST_ITERATOR_TPP_
#include "Forward_List.hpp"

template <typename T, typename Alloc>
Forward_List<T, Alloc>::const_iterator::const_iterator(const node_base* ptr)
 : m_ptr(ptr) {}

template <typename T, typename Alloc>
Forward_List<T, Alloc>::const_iterator::const_iterator(const const_iterator&) = default;

template <typename T, typename Alloc>
typename Forward_List<T, Alloc>::const_iterator::const_iterator& Forward_List<T, Alloc>::const_iterator::operator++() {
    m_ptr = m_ptr -> m_next;
    return *this;
}

template <typename T, typename Alloc>
typename Forward_List<T, Alloc>::const_iterator::const_iterator Forward_List<T, Alloc>::const_iterator::operator++(int) {
    const_iterator tmp = *this;
    ++(*this);
    return tmp;
}

template <typename T, typename Alloc>
bool Forward_List<T, Alloc>::const_iterator::operator!=(const const_iterator& oth) const {
    return !(oth == *this);
}

template <typename T, typename Alloc>
bool Forward_List<T, Alloc>::const_iterator::operator==(const const_iterator& oth) const {
    return (m_ptr == oth.m_ptr);
}

template <typename T, typename Alloc>
bool Forward_List<T, Alloc>::const_iterator::operator<(const const_iterator& oth) const {
    if (m_ptr < oth.m_ptr) {
        return true;
    }
    return false;
}

template <typename T, typename Alloc>
bool Forward_List<T, Alloc>::const_iterator::operator>(const const_iterator& oth) const {
    if (oth == *this || oth < *this) {
        return false;
    }
    return true;
}

template <typename T, typename Alloc>
bool Forward_List<T, Alloc>::const_iterator::operator<=(const const_iterator& oth) const {
    return !(oth > *this);
}

template <typename T, typename Alloc>
bool Forward_List<T, Alloc>::const_iterator::operator>=(const const_iterator& oth) const {
    return !(oth < *this);
}

template <typename T, typename Alloc>
const T& Forward_List<T, Alloc>::const_iterator::operator*() const {
    return static_cast<Node*>(m_ptr)->m_data;
}

#endif //CONST_ITERATOR_TPP_