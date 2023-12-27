cmake_minimum_required(VERSION 3.15)

project(turnip VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(SYSTEM "libraries/SDL/include")
add_subdirectory("libraries/SDL")


#turnip
set(PROJECT_SOURCES
        src/main.cpp
)
add_executable(turnip ${PROJECT_SOURCES})
target_link_libraries(turnip PRIVATE SDL2)

if(WIN32)
    set_target_properties(${PROJECT_NAME} PROPERTIES WIN32_EXECUTABLE TRUE)
endif()




#examples
set(EXAMPLES_SOURCES
    examples/main.cpp
)
add_executable(examples ${EXAMPLES_SOURCES})
target_link_libraries(examples PRIVATE SDL2)

if(WIN32)
    set_target_properties(examples PROPERTIES WIN32_EXECUTABLE TRUE)
endif()


