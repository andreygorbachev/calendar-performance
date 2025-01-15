cmake_minimum_required(VERSION 3.28)

project("calendar-performance")

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED On)
set(CMAKE_CXX_EXTENSIONS Off)

add_subdirectory(isda_cds_model_c_v1.8.3)

add_subdirectory(gregorian-calendar)
add_subdirectory(isda-cds-model-calendar)
add_subdirectory(quantlib-calendar)
