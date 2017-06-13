cmake_minimum_required(VERSION 3.0)

PROJECT(Metaclass)

SET( CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/build_temp/${ENGINE_LIB_DIR} )
SET( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin/metaclass_win32 )
SET( CMAKE_TEMP_DIR ${CMAKE_CURRENT_SOURCE_DIR}/CMakeTemp/Metaclass_Win32/${CMAKE_GENERATOR}/${CMAKE_BUILD_TYPE} )

SET(
Metaclass_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/include/Metaclass/BaseGet.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/Metaclass/BaseSet.h    
    ${CMAKE_CURRENT_SOURCE_DIR}/include/Metaclass/Metaclass.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/Metaclass/MetastreamGet.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/Metaclass/MetastreamSet.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/Metaclass/PropertyGet.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/Metaclass/PropertySet.h
    
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Metaclass.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/MetastreamGet.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/MetastreamSet.cpp
)

INCLUDE_DIRECTORIES( Metaclass include ) 

ADD_LIBRARY( Metaclass STATIC ${Metaclass_SOURCES} )

if(METACLASS_SANDBOX)
    set(
    Sandbox_SOURCES
        sandbox/main.cpp
    )
    
    ADD_DEFINITIONS(-D_CRT_SECURE_NO_DEPRECATE -D_SCL_SECURE_NO_WARNINGS)

    INCLUDE_DIRECTORIES( Sandbox ../include )

    ADD_EXECUTABLE( Sandbox ${Sandbox_SOURCES} )

    TARGET_LINK_LIBRARIES( Sandbox Metaclass )
endif()