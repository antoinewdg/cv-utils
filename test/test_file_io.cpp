#include "test_common.h"

#include "cv_utils/cv_utils.h"

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