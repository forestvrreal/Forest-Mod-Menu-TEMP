cmake_minimum_required(VERSION 3.22.1)

project("bnm_template_v252")
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(extern/BNM-Android EXCLUDE_FROM_ALL)
get_property(BNM_INCLUDE_DIRECTORIES TARGET BNM PROPERTY BNM_INCLUDE_DIRECTORIES)

add_library(${CMAKE_PROJECT_NAME} SHARED
        src/native-lib.cpp
)

target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC
    ${BNM_INCLUDE_DIRECTORIES}
    include
)

target_link_libraries(${CMAKE_PROJECT_NAME}
        android
        log
        BNM
)