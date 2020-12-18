project(westerstrom_utils_test)

add_executable(${PROJECT_NAME} set_cross.cpp test.cpp pow_int.cpp tuple_math.cpp grid.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE Catch2::Catch2)

target_include_directories(${PROJECT_NAME} PRIVATE ../include)
