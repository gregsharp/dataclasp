##-----------------------------------------------------------------------------
##  See COPYRIGHT.TXT and LICENSE.TXT for copyright and license information
##-----------------------------------------------------------------------------

execute_process (
    COMMAND ${test_cmd} ${test_args}
    RESULT_VARIABLE RESULT
    OUTPUT_VARIABLE STDOUT
    ERROR_VARIABLE STDERR
)

set (STDOUT_FN "${CMAKE_BINARY_DIR}/${test_name}.stdout.txt")
file (WRITE ${STDOUT_FN} ${STDOUT})

set (STDERR_FN "${CMAKE_BINARY_DIR}/${test_name}.stderr.txt")
file (WRITE ${STDERR_FN} ${STDERR})
