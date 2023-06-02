#ifndef ALLOCATOR_HPP_
#define ALLOCATOR_HPP_
#include <utility>
#include <cstddef>
#include <limits>
#include <new>

namespace my {
    template <typename T>
    class Allocator {
    public:
        using value_type      = T;
		using size_type       = size_t;
		using difference_type = std::ptrdiff_t;
    public:
        constexpr Allocator() noexcept = default;
        constexpr Allocator(const Allocator&) noexcept = default;
        constexpr ~Allocator() = default;
    public:
        [[nodiscard]] constexpr T* allocate(size_t n) {
            return static_cast<T*>(::operator new (sizeof(T) * n));
        }
        constexpr void deallocate(T* ptr, size_t n) {
            ::operator delete(ptr, n * sizeof(T));
        }
        template <typename... Args>
        void construct(T* ptr, Args&&... args) {
            ::new (ptr) T(std::forward<Args>(args)...);
        }
        void destroy(T* ptr) noexcept {
            ptr->~T();
        }
        size_type max_size() const noexcept { 
            return (std::numeric_limits<size_type>::max() / sizeof(value_type));
        }
    };
}

#endif //ALLOCATOR_HPP_