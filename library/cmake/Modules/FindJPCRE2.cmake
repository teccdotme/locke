# here goes nothing
# JPCRE2 package
# defines JPCRE2_INCLUDE_DIRS and JPCRE2_FOUND
# hopefully this works

# build jpcre
message(STATUS "Checking JPCRE2 build..")
set(libdir ${CMAKE_CURRENT_SOURCE_DIR}/lib/jpcre2)

find_path(JPCRE2_INCLUDE_DIR NAMES jpcre2.hpp HINTS ${libdir})

include(FindPackageHandleStandardArgs)
include(SelectLibraryConfigurations)

select_library_configurations(JPCRE2)
find_package_handle_standard_args(JPCRE2 DEFAULT_MSG JPCRE2_INCLUDE_DIR)

if (JPCRE2_FOUND)
    set(JPCRE2_INCLUDE_DIRS ${JPCRE2_INCLUDE_DIR})
else()
    set(JPCRE2_INCLUDE_DIRS)
endif()

mark_as_advanced(JPCRE2_INCLUDE_DIRS)