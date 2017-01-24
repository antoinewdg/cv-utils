//
// Created by antoinewdg on 1/24/17.
//

#ifndef CV_UTILS_GUI_H
#define CV_UTILS_GUI_H

#include <opencv2/highgui/highgui.hpp>

#include "common.h"

namespace cvu {
    namespace priv {


        template<class T>
        inline float _scale_factor() {
            return 1.f;
        }

        template<>
        inline float _scale_factor<bool>() {
            return 255.f;
        };
    }

    template<class T>
    inline void display_non_blocking(const Mat_ <T> &image, string name = "") {
        cv::imshow(name, image * priv::_scale_factor<T>());
    }

    template<class T>
    inline void display_blocking(const Mat_ <T> &image, string name = "") {
        display_non_blocking(image, name);
        cv::waitKey(0);
    }
}

#endif //CV_UTILS_GUI_H
