file(GLOB PROBLEMS_SRC
    "*.hpp"
    "*.cpp"
)

add_library(problems STATIC ${PROBLEMS_SRC})

target_include_directories(problems PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_compile_features(problems PUBLIC cxx_std_11)
