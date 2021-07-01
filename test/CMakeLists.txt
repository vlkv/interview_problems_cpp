find_package(GTest REQUIRED)

file(GLOB_RECURSE TEST_SRC src/*.cpp)
include_directories(${CMAKE_SOURCE_DIR})

add_executable(run_tests ${TEST_SRC})

target_compile_features(run_tests PUBLIC cxx_std_17)

target_link_libraries(run_tests PUBLIC
    ${GTEST_BOTH_LIBRARIES}
    pthread
    problems
)
