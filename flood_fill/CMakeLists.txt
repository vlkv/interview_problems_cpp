file(GLOB FLOOD_FILL_SRC
    "*.hpp"
    "*.cpp"
)

add_library(flood_fill STATIC ${FLOOD_FILL_SRC})

target_include_directories(flood_fill PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_compile_features(flood_fill PUBLIC cxx_std_11)
