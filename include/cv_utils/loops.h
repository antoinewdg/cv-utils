#ifndef CV_UTILS_ITERATORS_H
#define CV_UTILS_ITERATORS_H

#include <boost/iterator/iterator_facade.hpp>

#include "common.h"

namespace cvu {
    template<class T, class Func>
    void for_each_pixel(const Mat_ <T> &m, Func f) {
        for (int i = 0; i < m.rows; i++) {
            for (int j = 0; j < m.cols; j++) {
                f(i, j);
            }
        }
    };
}

#endif //CV_UTILS_ITERATORS_H
