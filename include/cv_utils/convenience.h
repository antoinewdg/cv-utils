//
// Created by antoinewdg on 1/25/17.
//

#ifndef CV_UTILS_CONVENIENCE_H
#define CV_UTILS_CONVENIENCE_H

#include "common.h"

namespace cvu {

    namespace priv {
        template<class T>
        inline float max_value() {
            return 255.f;
        }

        template<>
        inline float max_value<float>() {
            return 1.f;
        }
    }

    template<class T>
    void stretch_histogram(Mat_ <T> &m) {
        cv::normalize(m, m, priv::max_value<T>(), 0, cv::NORM_MINMAX);
    }
}

#endif //CV_UTILS_CONVENIENCE_H
