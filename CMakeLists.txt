 
cmake_minimum_required(VERSION 3.31)

find_package(qjs CONFIG REQUIRED)

set(ortha-scripting-js-src
        src/scripting-js/systems/ScriptingJSSystems.cpp
)

set(ortha-scripting-js-modules
        src/scripting-js/services/ScriptingJSSystemsService.cppm
        src/scripting-js/systems/ScriptingJSSystems.cppm
)

add_library(ortha-scripting-js STATIC ${ortha-scripting-js-src} ${ortha-scripting-js-modules})

target_sources(ortha-scripting-js PUBLIC FILE_SET modules TYPE CXX_MODULES FILES ${ortha-scripting-js-modules})
target_compile_features(ortha-scripting-js PUBLIC cxx_std_23)
target_link_libraries(ortha-scripting-js PUBLIC ortha-core qjs)
target_include_directories(ortha-scripting-js PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

#add_subdirectory(tests)
