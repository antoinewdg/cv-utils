#ifndef CV_UTILS_ITERATORS_H
#define CV_UTILS_ITERATORS_H

#include <boost/iterator/iterator_facade.hpp>

#include "common.h"

namespace cvu {
    namespace priv {
        template<class M, class Func>
        void _for_each_pixel(M m, Func f) {
            auto *ptr = m[0];
            for (int i = 0; i < m.rows; i++) {
                for (int j = 0; j < m.cols; j++) {
                    f(i, j, *ptr);
                    ptr++;
                }
            }
        };
    }

    template<class T, class Func>
    void for_each_pixel(Mat_ <T> &m, Func f) {
        priv::_for_each_pixel(m, f);
    };

    template<class T, class Func>
    void for_each_pixel(const Mat_ <T> &m, Func f) {
        priv::_for_each_pixel(m, f);
    };

    template<int P, class T, class Func>
    inline void for_each_patch(const Mat_ <T> &m, Func f) {
        for (int i = P/2; i < m.rows - P/2; i++) {
            for (int j = P/2; j < m.cols - P/2; j++) {
                f(i, j);
            }
        }
    };
}

#endif //CV_UTILS_ITERATORS_H
