cmake_minimum_required(VERSION 3.20)
project(NovaLink C)

add_executable(hello tests/host/hello.c)

add_library(unity STATIC third_party/Unity/unity.c)
target_include_directories(unity PUBLIC third_party/Unity)

add_executable(unit_tests tests/host/test_example.c)
target_link_libraries(unit_tests unity)

enable_testing()
add_test(NAME unit_tests COMMAND unit_tests)

# Static analysis. Run with:  cmake --build . --target cppcheck
# Only scans tests/ for now -- add more folders here (e.g. src) once
# real protocol source exists outside tests/.
find_program(CPPCHECK_EXE cppcheck)
if(CPPCHECK_EXE)
    add_custom_target(cppcheck
        COMMAND ${CPPCHECK_EXE}
                --enable=warning,style,performance,portability
                --std=c11
                --language=c
                --inline-suppr
                --error-exitcode=1
                tests
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        COMMENT "Running cppcheck on the C sources"
        VERBATIM)
else()
    message(STATUS "cppcheck not found: the 'cppcheck' target is unavailable")
endif()