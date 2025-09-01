 
cmake_minimum_required(VERSION 3.31)

find_package(qjs CONFIG REQUIRED)

set (scripting-js-lib-src
        src/scripting-js/systems/ScriptingJSSystems.cpp
)

set (scripting-js-lib-modules
        src/scripting-js/services/ScriptingJSSystemsService.cppm
        src/scripting-js/systems/ScriptingJSSystems.cppm
)

add_library(scripting-js-lib STATIC ${scripting-js-lib-src} ${scripting-js-lib-modules})

target_sources(scripting-js-lib PUBLIC FILE_SET modules TYPE CXX_MODULES FILES ${scripting-js-lib-modules})
target_compile_features(scripting-js-lib PUBLIC cxx_std_23)
target_link_libraries(scripting-js-lib PUBLIC core-lib qjs)
target_include_directories(scripting-js-lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

#add_subdirectory(tests)
