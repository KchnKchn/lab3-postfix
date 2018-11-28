function(create_project_lib TARGET )
    file(GLOB TARGET_SRC "*.c*")
    file(GLOB TARGET_HD "*.h*")
    add_library(${TARGET} STATIC ${TARGET_SRC} ${TARGET_HD})
    
    get_property ( INCLUDE_DIRS GLOBAL PROPERTY INC_DIR)
    list(APPEND INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR})
    set_property ( GLOBAL PROPERTY INC_DIR ${INCLUDE_DIRS})
    
    get_property ( LIB_LIST GLOBAL PROPERTY LIBS_P)
    list(APPEND LIB_LIST ${TARGET})
    set_property ( GLOBAL PROPERTY LIBS_P ${LIB_LIST})
    
endfunction()

function(create_executable_project TARGET)
    file(GLOB TARGET_SRC "*.cpp") 
    file(GLOB TARGET_HD "*.h*")
    add_executable(${TARGET} ${TARGET_SRC} ${TARGET_HD})
    
    get_property ( INCLUDE_DIRS GLOBAL PROPERTY INC_DIR)
    target_include_directories(${TARGET} PUBLIC ${INCLUDE_DIRS})
    
    get_property ( LIB_LIST GLOBAL PROPERTY LIBS_P)
    target_link_libraries(${TARGET} ${LIB_LIST})
    
endfunction()