cmake_minimum_required(VERSION 3.15)
set(CMAKE_CXX_STANDARD 17)

project(locke)

option(BUILD_SHARED_LIBS ON)

# uncomment for debug messages
include(Debug)

set(GLOBAL_FILES Tokenizer Util)

set(HEADERS ${GLOBAL_FILES})
set(SOURCES ${GLOBAL_FILES}
        )

foreach(HEADER IN LISTS HEADERS)
    set(SRC ${SRC} include/locke/${HEADER}.h)
endforeach()
foreach(SOURCE IN LISTS SOURCES)
    set(SRC ${SRC} src/${SOURCE}.cpp)
endforeach()

add_library(locke ${SRC})
target_include_directories(locke PUBLIC include)

include(Libraries)
# target_link_libraries(locke ${LIBRARIES})
target_link_libraries(locke ${LIBRARIES})
target_include_directories(locke PUBLIC ${INCLUDE_DIRS})