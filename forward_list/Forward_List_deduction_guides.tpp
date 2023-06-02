#ifndef FORWARD_LIST_DEDUCTION_GUIDES_
#define FORWARD_LIST_DEDUCTION_GUIDES_
#include "Forward_List.hpp"

template <typename InputIt,
typename Alloc = my::Allocator<typename std::iterator_traits<InputIt>::value_type>>
Forward_List(InputIt, InputIt, Alloc = Alloc())
 -> Forward_List<typename std::iterator_traits<InputIt>::value_type, Alloc>;

#endif //FORWARD_LIST_DEDUCTION_GUIDES_
