find_package(GTest REQUIRED)

file(GLOB_RECURSE TEST_SRC 
    flood_fill_test/*.cpp
    minimal_tree_test/*.cpp
)

add_executable(run_tests ${TEST_SRC})

include_directories(${CMAKE_SOURCE_DIR}/minimal_tree)

target_compile_features(run_tests PUBLIC cxx_std_11)

target_link_libraries(run_tests PUBLIC
    flood_fill
    ${GTEST_BOTH_LIBRARIES}
    pthread
)


