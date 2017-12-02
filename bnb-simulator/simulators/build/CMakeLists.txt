cmake_minimum_required(VERSION 3.0)

set(PROJECT simulators)

project(${PROJECT})

set(SOURCES ../resolver.cpp ../sched_initializer.cpp)

add_library(${PROJECT} ${SOURCES})
