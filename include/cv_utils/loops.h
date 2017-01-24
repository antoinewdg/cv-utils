#ifndef CV_UTILS_ITERATORS_H
#define CV_UTILS_ITERATORS_H

#include <boost/iterator/iterator_facade.hpp>

#include "common.h"

namespace cvu {
    template<class T, class Func>
    void for_each_pixel(Mat_ <T> &m, Func f) {
        T *ptr = m[0];
        for (int i = 0; i < m.rows; i++) {
            for (int j = 0; j < m.cols; j++) {
                f(i, j, *ptr);
                ptr++;
            }
        }
    };

    template<class T, class Func>
    void for_each_pixel(const Mat_ <T> &m, Func f) {
        const T *ptr = m[0];
        for (int i = 0; i < m.rows; i++) {
            for (int j = 0; j < m.cols; j++) {
                f(i, j, *ptr);
                ptr++;
            }
        }
    };
}

#endif //CV_UTILS_ITERATORS_H
