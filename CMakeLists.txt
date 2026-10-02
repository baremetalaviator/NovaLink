cmake_minimum_required(VERSION 3.20)
project(NovaLink C)

add_executable(hello tests/host/hello.c)

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