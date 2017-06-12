PROJECT(Metaclass)

MACRO( ADD_FILTER group_name )
	SOURCE_GROUP( ${group_name} FILES ${ARGN} )
	SET( SRC_FILES ${SRC_FILES} ${ARGN} )
ENDMACRO()

ADD_FILTER(
Metaclass
    include/Metaclass/BaseGet.h
    include/Metaclass/BaseSet.h
    include/Metaclass/Metabase.h
    include/Metaclass/Metaclass.h
    include/Metaclass/MetastreamGet.h
    include/Metaclass/MetastreamSet.h
    include/Metaclass/PropertyGet.h
    include/Metaclass/PropertySet.h
    src/Metabase.cpp
)

INCLUDE_DIRECTORIES( ${PROJECT_NAME} include ) 

ADD_LIBRARY( ${PROJECT_NAME} STATIC ${SRC_FILES} )