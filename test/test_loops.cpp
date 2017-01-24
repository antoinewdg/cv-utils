#include "test_common.h"

TEST_CASE("for_each_pixel") {
    Mat_<Vec3b> image = load_color(assets_dir() + "/colors.png");
    int count = 0;

    for_each_pixel(image, [&count, &image](int i, int j) {
        REQUIRE(count % image.cols == j);
        REQUIRE(count / image.cols == i);
        count++;
    });

    REQUIRE(count == image.cols * image.rows);

}