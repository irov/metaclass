cmake_minimum_required(VERSION 3.0)

PROJECT(Metaclass)

SET(
Metaclass_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/include/Metaclass/BaseGet.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/Metaclass/BaseSet.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/Metaclass/Metabase.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/Metaclass/Metaclass.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/Metaclass/MetastreamGet.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/Metaclass/MetastreamSet.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/Metaclass/PropertyGet.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/Metaclass/PropertySet.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Metabase.cpp
)

INCLUDE_DIRECTORIES( Metaclass include ) 

ADD_LIBRARY( Metaclass STATIC ${Metaclass_SOURCES} )

if(METACLASS_SANDBOX)
    set(
    Sandbox_SOURCES
        sandbox/main.cpp
    )

    INCLUDE_DIRECTORIES( Sandbox ../include )

    ADD_EXECUTABLE( Sandbox ${Sandbox_SOURCES} )

    TARGET_LINK_LIBRARIES( Sandbox Metaclass )
endif()