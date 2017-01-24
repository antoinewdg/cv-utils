#include "test_common.h"

const string filename = assets_dir() + "/lena.png";

TEST_CASE("display_and_block", "[visual]") {
    SECTION("Vec3b") {
        cout << "Testing Vec3b display" << endl;
        display_blocking(load_color(filename));
    }

    SECTION("Vec3f") {
        cout << "Testing Vec3f display" << endl;
        display_blocking(load_color<Vec3f>(filename));
    }

    SECTION("uchar") {
        cout << "Testing uchar display" << endl;
        display_blocking(load_grayscale(filename));
    }

    SECTION("float") {
        cout << "Testing float display" << endl;
        display_blocking(load_grayscale<float>(filename));
    }

    SECTION("bool") {
        cout << "Testing bool display" << endl;
        display_blocking(load_binary(assets_dir() + "/blank_square.png"));
    }


}