message(STATUS "Finding libraries..")

find_package(PCRE2  REQUIRED)
find_package(JPCRE2 REQUIRED)
find_package(LLVM   CONFIG REQUIRED)

llvm_map_components_to_libnames(LLVM_LIBRARIES support core irreader)
add_definitions(${LLVM_DEFINITIONS})

set(LIBRARIES ${PCRE2_LIBRARIES} ${LLVM_LIBRARIES})
set(INCLUDE_DIRS ${PCRE2_INCLUDE_DIRS} ${JPCRE2_INCLUDE_DIRS} ${LLVM_INCLUDE_DIRS})