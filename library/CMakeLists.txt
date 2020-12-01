cmake_minimum_required(VERSION 3.15)
set(CMAKE_CXX_STANDARD 17)

project(locke)

option(BUILD_SHARED_LIBS ON)

# uncomment for debug messages
include(Debug)

set(GLOBAL_FILES
        Tokenizer
        Util
        internal/TokenizationUtils
        )

set(HEADERS ${GLOBAL_FILES}
        TokenTypes
        )

set(SOURCES ${GLOBAL_FILES}
        )

foreach(HEADER IN LISTS HEADERS)
    set(SRC ${SRC} include/locke/${HEADER}.h)
endforeach()
foreach(SOURCE IN LISTS SOURCES)
    set(SRC ${SRC} src/${SOURCE}.cpp)
endforeach()

add_library(locke ${SRC})

set(INCLUDE_DIRS include)
# target_link_libraries(locke ${LIBRARIES})
target_include_directories(locke PUBLIC ${INCLUDE_DIRS})