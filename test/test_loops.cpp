#include <vector>

#include "test_common.h"

TEST_CASE("for_each_pixel") {
    Mat_<Vec3b> image = load_color(assets_dir() + "/colors.png");


    std::vector<Vec3b> expected = {
            Vec3b(0, 0, 0), Vec3b(0, 0, 255), Vec3b(255, 255, 255),
            Vec3b(255, 0, 0), Vec3b(0, 255, 0), Vec3b(255, 255, 255),
            Vec3b(255, 255, 255), Vec3b(255, 255, 255), Vec3b(255, 255, 255)
    };

    int width = image.cols;
    SECTION("regular") {
        std::vector<Vec3b> actual;
        for_each_pixel(image, [&actual, width](int i, int j, Vec3b &v) {
            REQUIRE(actual.size() % width == j);
            REQUIRE(actual.size() / width == i);
            actual.push_back(v);
        });


        REQUIRE(actual == expected);
    }

    SECTION("const") {
        const Mat_<Vec3b> &ref = image;
        std::vector<Vec3b> actual;
        for_each_pixel(ref, [&actual, width](int i, int j, const Vec3b &v) {
            REQUIRE(actual.size() % width == j);
            REQUIRE(actual.size() / width == i);
            actual.push_back(v);
        });


        REQUIRE(actual == expected);
    }
}


TEST_CASE("for_each_patch") {
    Mat_<uchar> image(5, 4);
    std::vector<Vec2i> expected = {
            Vec2i(1, 1), Vec2i(1, 2),
            Vec2i(2, 1), Vec2i(2, 2),
            Vec2i(3, 1), Vec2i(3, 2),
    };

    std::vector<Vec2i> actual;
    for_each_patch<3>(image, [&actual](int i, int j) {
        actual.emplace_back(i, j);
    });

    REQUIRE(actual == expected);

}