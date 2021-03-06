cmake_minimum_required(VERSION 2.8)
project(cv_utils)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")

set(SOURCE_FILES
        include/cv_utils/cv_utils.h
        include/cv_utils/common.h
        include/cv_utils/file_io.h
        include/cv_utils/gui.h
        include/cv_utils/loops.h
        include/cv_utils/convenience.h
        )

set(TEST_FILES
        test/test_common.h
        test/test_file_io.cpp
        test/test_gui.cpp
        test/test_loops.cpp
        test/test_convenience.cpp
        )


include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/lib
        ${CMAKE_CURRENT_SOURCE_DIR}/test
)


add_executable(run_tests test/main.cpp ${SOURCE_FILES} ${TEST_FILES})


# EXTERNAL LIBRAIRIES =====================

# OpenCV
FIND_PACKAGE(OpenCV 3.1 REQUIRED)
INCLUDE_DIRECTORIES(${OpenCV_INCLUDE_DIRS})
set(TARGET_LIBS ${TARGET_LIBS} ${OpenCV_LIBS})

TARGET_LINK_LIBRARIES(run_tests ${TARGET_LIBS})