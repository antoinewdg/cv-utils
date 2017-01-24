//
// Created by antoinewdg on 1/24/17.
//

#ifndef CV_UTILS_FILE_IO_H
#define CV_UTILS_FILE_IO_H

#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgcodecs/imgcodecs_c.h>

#include "common.h"

namespace cvu {
    template<class T=Vec3b>
    Mat_ <T> load_color(string name);

    template<class T=uchar>
    Mat_ <T> load_grayscale(string name);


    template<>
    Mat_ <Vec3b> load_color(string name) {
        Mat_<Vec3b> image = cv::imread(name);
        if (image.empty())                      // Check for invalid input
        {
            cerr << "Could not open or find " << name << endl;
        }
        return image;
    }

    template<>
    Mat_ <Vec3f> load_color(string name) {
        Mat_<Vec3b> original = load_color(name);
        Mat_<Vec3f> result;
        original.convertTo(result, CV_32FC3, 1.f / 255);
        return result;
    }

    template<>
    Mat_ <uchar> load_grayscale(string name) {
        Mat_<uchar> image = cv::imread(name, CV_LOAD_IMAGE_GRAYSCALE);
        if (image.empty())                      // Check for invalid input
        {
            cerr << "Could not open or find " << name << endl;
        }
        return image;
    }

    template<>
    Mat_<float> load_grayscale(string name) {
        Mat_<uchar> original = load_grayscale(name);
        Mat_<float> result;
        original.convertTo(result, CV_32F, 1.f / 255);
        return result;
    }

    Mat_<bool> load_binary(string name) {
        Mat_<uchar> original = load_grayscale(name);
        return Mat_<bool>((original > 0) / 255);
    }

}

#endif //CV_UTILS_FILE_IO_H
