##-----------------------------------------------------------------------------
##  See COPYRIGHT.TXT and LICENSE.TXT for copyright and license information
##-----------------------------------------------------------------------------
project (dataclasp_src)

include_directories (BEFORE ${LIBYAML_INCLUDE_DIR})
include_directories (BEFORE ${CMAKE_CURRENT_SOURCE_DIR})

set (DATACLASP_LIBRARY_SRC
    dataclasp.cxx dataclasp.h 
    dataclasp_node.cxx dataclasp_node.h 
    yaml_loader.cxx yaml_loader.h
)

set (DATACLASP_APPLICATION_SRC
    main.cxx
)

add_library (dataclasp ${DATACLASP_LIBRARY_SRC})
target_link_libraries (dataclasp ${LIBYAML_LIBRARIES})

add_executable (dataclasp_app ${DATACLASP_APPLICATION_SRC})
set_target_properties (dataclasp_app PROPERTIES OUTPUT_NAME dataclasp)
target_link_libraries (dataclasp_app dataclasp)

