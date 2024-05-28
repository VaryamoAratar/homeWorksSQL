CMAKE_MINIMUM_REQUIRED (VERSION 3.20)
project(lessonDataBase004 VERSION 1.0 LANGUAGES CXX)
set(PostrgeSQL_ADDITIONAL_VERSIONS "16")
add_subdirectory("D://Code//tools//libpqxx-7.9.0" libpqxx-build)

add_executable(${PROJECT_NAME} main.cpp)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)
target_link_libraries(${PROJECT_NAME} PRIVATE pqxx)