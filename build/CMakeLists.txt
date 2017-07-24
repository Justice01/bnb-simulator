cmake_minimum_required(VERSION 3.0)

set(PROJECT bnbtest)

project(${PROJECT})

set(CMAKE_CXX_FLAGS "-ldl -pthread -std=c++14 -Wall")

include_directories(../BNB-solver ../bnb-simulator)

set(SOURCES ../bnbtest.cpp ../apply_settings.cpp)

add_executable(${PROJECT} ${SOURCES})

set(LIBRARIES processes communicators serializers simulators pools)

foreach(LIB ${LIBRARIES})
    add_subdirectory(../bnb-simulator/${LIB}/build bin/${LIB})
endforeach()

set(JSON json)

add_library(${JSON} STATIC IMPORTED)

set_target_properties(${JSON} PROPERTIES
    IMPORTED_LOCATION ../BNB-solver/libjson/libjson.a
)

target_link_libraries(${PROJECT} ${LIBRARIES} ${JSON} ${CMAKE_DL_LIBS})
