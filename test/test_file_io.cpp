#include "test_common.h"

TEST_CASE("load_color") {

    SECTION("Vec3b") {
        Mat_<Vec3b> image = load_color(assets_dir() + "/colors.png");
        REQUIRE(image(0, 0) == Vec3b(0, 0, 0));
        REQUIRE(image(1, 0) == Vec3b(255, 0, 0));
        REQUIRE(image(0, 1) == Vec3b(0, 0, 255));
        REQUIRE(image(1, 1) == Vec3b(0, 255, 0));
        REQUIRE(image(2, 1) == Vec3b(255, 255, 255));
    }

    SECTION("Vec3f") {
        Mat_<Vec3f> image = load_color<Vec3f>(assets_dir() + "/colors.png");
        REQUIRE(image(0, 0) == Vec3f(0, 0, 0));
        REQUIRE(image(1, 0) == Vec3f(1, 0, 0));
        REQUIRE(image(0, 1) == Vec3f(0, 0, 1));
        REQUIRE(image(1, 1) == Vec3f(0, 1, 0));
        REQUIRE(image(2, 1) == Vec3f(1, 1, 1));
    }

}

TEST_CASE("load_grayscale") {

    SECTION("uchar") {
        Mat_<uchar> image = load_grayscale(assets_dir() + "/colors.png");
        REQUIRE(image(0, 0) == 0);
        REQUIRE(image(1, 0) == 29);
        REQUIRE(image(0, 1) == 76);
        REQUIRE(image(1, 1) == 149);
        REQUIRE(image(2, 1) == 255);
    }

    SECTION("float") {
        Mat_<float> image = load_grayscale<float>(assets_dir() + "/colors.png");
        REQUIRE(image(0, 0) == 0.f);
        REQUIRE(image(1, 0) == Approx(0.114f).epsilon(0.01));
        REQUIRE(image(0, 1) == Approx(0.299f).epsilon(0.01));
        REQUIRE(image(1, 1) == Approx(0.587f).epsilon(0.01));
        REQUIRE(image(2, 1) == 1.f);
    }
}

TEST_CASE("load_binary") {
    Mat_<bool> mask = load_binary(assets_dir() + "/colors.png");
    REQUIRE(!mask(0, 0));
    REQUIRE(mask(1, 0));
    REQUIRE(mask(0, 1));
    REQUIRE(mask(1, 1));
    REQUIRE(mask(2, 1));
}