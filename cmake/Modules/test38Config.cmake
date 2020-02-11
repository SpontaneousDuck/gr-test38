INCLUDE(FindPkgConfig)
PKG_CHECK_MODULES(PC_TEST38 test38)

FIND_PATH(
    TEST38_INCLUDE_DIRS
    NAMES test38/api.h
    HINTS $ENV{TEST38_DIR}/include
        ${PC_TEST38_INCLUDEDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/include
          /usr/local/include
          /usr/include
)

FIND_LIBRARY(
    TEST38_LIBRARIES
    NAMES gnuradio-test38
    HINTS $ENV{TEST38_DIR}/lib
        ${PC_TEST38_LIBDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/lib
          ${CMAKE_INSTALL_PREFIX}/lib64
          /usr/local/lib
          /usr/local/lib64
          /usr/lib
          /usr/lib64
          )

include("${CMAKE_CURRENT_LIST_DIR}/test38Target.cmake")

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(TEST38 DEFAULT_MSG TEST38_LIBRARIES TEST38_INCLUDE_DIRS)
MARK_AS_ADVANCED(TEST38_LIBRARIES TEST38_INCLUDE_DIRS)
