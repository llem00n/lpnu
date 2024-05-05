#ifndef MSIZE_T_HPP
#define MSIZE_T_HPP

#include <cstdint>

namespace mtx {
    typedef struct msize {
        uint32_t rows;
        uint32_t cols;
    } msize_t;
}

#endif // MSIZE_T_HPP