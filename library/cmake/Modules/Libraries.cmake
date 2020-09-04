message(STATUS "Finding libraries..")

find_package(PCRE2  REQUIRED)
find_package(JPCRE2 REQUIRED)

set(LIBRARIES ${PCRE2_LIBRARIES})
include_directories(${PCRE2_INCLUDE_DIRS} ${JPCRE2_INCLUDE_DIRS})