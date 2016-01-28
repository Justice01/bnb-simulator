cmake_minimum_required(VERSION 3.0)

set(PROJECT pools)

project(${PROJECT})

set(SOURCES ../abstract_task_pool.cpp ../simple_pool.cpp)

add_library(${PROJECT} ${SOURCES})
