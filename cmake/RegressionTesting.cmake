##-----------------------------------------------------------------------------
##  RegressionTesting.cmake
##-----------------------------------------------------------------------------
##  This file is in the public domain.
##-----------------------------------------------------------------------------

#set (ENV{PATH} "$ENV{PATH};${ITK_LIBRARY_PATH};${PLM_PLASTIMATCH_PATH};${PLM_FFTW_PATH}")

macro (regression_test_add TEST_NAME TEST_COMMAND TEST_ARGS)
    set (options "")
    set (one_value_args EXPECTED_ERRNO WORKING_DIR)
    set (multi_value_args EXTRA_PATHS)
    cmake_parse_arguments (ARG "${options}" "${one_value_args}" 
	"${multi_value_args}")

    set (expected_errno "")
    if (ARG_EXPECTED_ERRNO)
	set (expected_errno "-DEXPECTED_ERRNO=${ARG_EXPECTED_ERRNO}")
    endif ()
    set (working_dir "")
    if (ARG_WORKING_DIR)
	set (working_dir "-DWORKING_DIR=${ARG_WORKING_DIR}")
    endif ()

    # This is more convenient to retrieve from a global variable 
    # rather than pass for each invokation
    set (extra_paths "")
    if (REGRESSION_TEST_EXTRA_PATHS)
	set (extra_paths "-DEXTRA_PATHS=${REGRESSION_TEST_EXTRA_PATHS}")
    endif ()

    # CMake doesn't allow "=" to be passed in a -D parameter.  So we substitute 
    # with replacement string, which will get substituted back within the 
    # cmake script itself
    string (REPLACE "=" "&equal&" TMP_PARMS "${TEST_ARGS}")

    set (BUILD_TESTING_DIR "${CMAKE_BINARY_DIR}/Testing")

    add_test (${TEST_NAME} ${CMAKE_COMMAND} 
	-DTEST_NAME=${TEST_NAME}
	-DTEST_COMMAND=${TEST_COMMAND}
	-DTESTING_SOURCE_DIR=${TESTING_SOURCE_DIR}
	-DBUILD_TESTING_DIR=${BUILD_TESTING_DIR}
	"-DPARMS=${TMP_PARMS}"
	${expected_errno}
	${extra_paths}
	${working_dir}
	-P "${CMAKE_SOURCE_DIR}/cmake/RunRegressionTest.cmake"
	)
endmacro ()
