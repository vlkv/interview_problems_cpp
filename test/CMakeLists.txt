find_package(GTest REQUIRED)

file(GLOB_RECURSE sources_test 
    flood_fill_test/*.cpp
    minimal_tree_test/*.cpp
)

add_executable(unit_tests ${sources_test})

include_directories(${CMAKE_SOURCE_DIR}/minimal_tree)

target_compile_features(unit_tests PUBLIC cxx_std_11)

target_link_libraries(unit_tests PUBLIC
    flood_fill
    ${GTEST_BOTH_LIBRARIES}
    pthread
)


