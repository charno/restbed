# Copyright (c) 2013, 2014 Corvusoft

find_path( gtest_INCLUDE gtest/gtest.h HINTS "${CMAKE_SOURCE_DIR}/dependency/gtest/include" "/usr/include" "/usr/local/include" "/opt/local/include" )
find_library( gtest_LIBRARY NAMES gtest HINTS "${CMAKE_SOURCE_DIR}/dependency/gtest" "${CMAKE_SOURCE_DIR}/dependency/gtest/build" "${CMAKE_SOURCE_DIR}/dependency/gtest/lib" "/usr/lib" "/usr/local/lib" "/opt/local/lib" )
find_library( gtest_MAIN_LIBRARY NAMES gtest_main HINTS "${CMAKE_SOURCE_DIR}/dependency/gtest" "${CMAKE_SOURCE_DIR}/dependency/gtest/build" "${CMAKE_SOURCE_DIR}/dependency/gtest/lib" "/usr/lib" "/usr/local/lib" "/opt/local/lib" ) 

if ( gtest_INCLUDE AND gtest_LIBRARY AND gtest_MAIN_LIBRARY )
    set( GTEST_FOUND TRUE )

    if ( NOT gtest_FIND_QUIETLY )
        message( STATUS "Found gtest header: ${gtest_INCLUDE}" )
        message( STATUS "Found gtest library: ${gtest_LIBRARY}" )
        message( STATUS "Found gtest main library: ${gtest_MAIN_LIBRARY}" )
    endif ( )
else ( )
    if ( gtest_FIND_REQUIRED )
        message( FATAL_ERROR "Failed to locate gtest!" )
    endif ( )
endif ( )
