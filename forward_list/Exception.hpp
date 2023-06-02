#ifndef EXCEPTION_HPP_
#define EXCEPTION_HPP_
#include <exception>

namespace my {
    class out_of_range : public std::exception {
    public:
        const char* what() {
            return msg;
        }
    public:
        out_of_range(const char* str)
        : msg(str)
        {}
    private:
        const char* msg;
    };
}

#endif //EXCEPTION_HPP_