##-----------------------------------------------------------------------------
##  See COPYRIGHT.TXT and LICENSE.TXT for copyright and license information
##-----------------------------------------------------------------------------

macro (dataclasp_test test_name test_cmd test_args)
    message (STATUS ">> ${CMAKE_SOURCE_DIR}/testing/dataclasp_test.cmake")
    add_test (${test_name}
	${CMAKE_COMMAND} 
	"-Dtest_name=${test_name}"
	"-Dtest_cmd=${test_cmd}"
	"-Dtest_args:string=${test_args}"
	"-DCMAKE_BUILD_DIR1=${CMAKE_BUILD_DIR}"
	-P "${CMAKE_SOURCE_DIR}/testing/dataclasp_test.cmake"
	)
endmacro ()

set (DST_DIR "${CMAKE_SOURCE_DIR}/testing")
set (DB_DIR "${CMAKE_BINARY_DIR}/src")
set (DBT_DIR "${CMAKE_BINARY_DIR}/testing")

dataclasp_test (
    ls
    "ls"
    ""
    )

dataclasp_test (
    dataclasp-example-1
    "${DB_DIR}/dataclasp"
    "${DST_DIR}/example-1.yaml"
    )
