//
// Created by antoinewdg on 1/24/17.
//

#ifndef CV_UTILS_FILE_IO_H
#define CV_UTILS_FILE_IO_H

#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs.hpp>

#include "common.h"

namespace cvu {
    template<class T=Vec3b>
    Mat_<T> load_color(string name);

    template<>
    Mat_<Vec3b> load_color(string name) {
        Mat_<Vec3b> image = cv::imread(name);
        if (image.empty())                      // Check for invalid input
        {
            cerr << "Could not open or find " << name << endl;
        }
        return image;
    }

    template<>
    Mat_<Vec3f> load_color(string name) {
        Mat_<Vec3b> original = load_color(name);
        Mat_<Vec3f> result;
        original.convertTo(result, CV_32FC3, 1.f / 255);
        return result;
    }
}

#endif //CV_UTILS_FILE_IO_H
