project(ChiisaiLLVM)

option(LLVM_GENERATE_PARSER "Generate LLVM parser code using ANTLR-4" ON)

if (LLVM_GENERATE_PARSER)
    message(STATUS "Generating LLVM parser code using ANTLR-4")
    execute_process(
            COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/parser-codegen.sh "java" ${ANTLR_JAR}
            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
            RESULT_VARIABLE result
            OUTPUT_VARIABLE output
            ERROR_VARIABLE error_output
    )
    message(STATUS "ANTLR-4 Code Generation Output:\n${output}")
    message(STATUS "ANTLR-4 Code Generation Error Output:\n${error_output}")
else ()
    message(STATUS "Globbing generated source files...")
endif ()

file(GLOB_RECURSE SOURCES src/*.cpp src/*.cc)
file(GLOB_RECURSE HEADERS include/*.h include/*.hpp)

add_library(mini-llvm ${SOURCES} ${HEADERS})
target_include_directories(mini-llvm
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/mini-llvm/autogen
        PUBLIC ${ANTLR_RUNTIME_INCLUDE_DIR}/antlr-runtime
)
target_link_libraries(mini-llvm mystl antlr-runtime minilog)

file(GLOB_RECURSE APPS apps/*.cc)
foreach (APP ${APPS})
    get_filename_component(APP_NAME ${APP} NAME_WE)
    add_executable(${APP_NAME} ${APP})
    target_link_libraries(${APP_NAME} mini-llvm cxxopts)
endforeach ()

file(GLOB_RECURSE TESTS tests/*.cc)
foreach (TEST ${TESTS})
    get_filename_component(TEST_NAME ${TEST} NAME_WE)
    add_executable(${TEST_NAME} ${TEST})
    target_link_libraries(${TEST_NAME} mini-llvm gtest gtest_main)
    add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME})
endforeach ()
