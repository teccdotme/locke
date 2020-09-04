cmake_minimum_required(VERSION 3.15)
set(CMAKE_CXX_STANDARD 17)

project(locke)
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake/Modules/)

# uncomment for debug messages
include(Debug)

set(HEADERS
        regex Definitions Primitives
        # lexing
        lexing/Token lexing/Tokenizer
        )
set(SOURCES Primitives lexing/Tokenizer lexing/Token)

foreach(HEADER IN LISTS HEADERS)
    set(SRC ${SRC} include/locke/${HEADER}.h)
endforeach()
foreach(SOURCE IN LISTS SOURCES)
    set(SRC ${SRC} src/${SOURCE}.cpp)
endforeach()

add_library(locke SHARED ${SRC})
include_directories(include)

include(Libraries)
target_link_libraries(locke ${LIBRARIES})