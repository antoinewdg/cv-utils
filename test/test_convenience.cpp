#include "test_common.h"

TEST_CASE("stretch_histogram") {
    SECTION("uchar") {
        Mat_<uchar> image = load_grayscale(assets_dir() + "/low_contrast.png");
        stretch_histogram(image);

        REQUIRE(image(0, 0) == 0);
        REQUIRE(image(0, 1) == 134);
        REQUIRE(image(0, 2) == 255);
    }

    SECTION("float") {
        Mat_<float> image = load_grayscale<float>(assets_dir() + "/low_contrast.png");
        image *= 6000;
        stretch_histogram(image);

        REQUIRE(image(0, 0) == Approx(0));
        REQUIRE(image(0, 1) == Approx(0.52667f));
        REQUIRE(image(0, 2) == Approx(1));
    }
}