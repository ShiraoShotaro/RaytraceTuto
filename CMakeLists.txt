## CMakeLists for FX System

cmake_minimum_required(VERSION 3.8)
project(RaytraceTuto)

### Project Settings
if(UNIX) # for Linux
    set(CMAKE_CXX_STANDARD 17)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
    set(CMAKE_CXX_EXTENSIONS OFF)

elseif(WIN32) # for Windows

    set(CMAKE_CXX_FLAGS_RELEASE "/MT")
    #set(CMAKE_CXX_FLAGS_DEBUG "/MTd")

endif(UNIX)

### Filter Settings for Visual Studio
# Build the visual studio filter same as source directories form.
function(assign_source_group)
    foreach(_source IN ITEMS ${ARGN})
        if (IS_ABSOLUTE "${_source}")
            file(RELATIVE_PATH _source_rel "${CMAKE_CURRENT_SOURCE_DIR}" "${_source}")
        else()
            set(_source_rel "${_source}")
        endif()
        get_filename_component(_source_path "${_source_rel}" PATH)
        string(REPLACE "/" "\\" _source_path_msvc "${_source_path}")
        source_group("${_source_path_msvc}" FILES "${_source}")
        message(STATUS "add source : ${_source}")
    endforeach()
endfunction(assign_source_group)

###

# Source Files
file(GLOB raytrace_cpp_files src/*.cpp)
file(GLOB raytrace_hpp_files src/*.hpp)

set(SFML_DIR "${CMAKE_SOURCE_DIR}/lib/SFML/lib/cmake/SFML")

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
add_executable(raytrace ${raytrace_cpp_files} ${raytrace_hpp_files})
target_include_directories(raytrace PUBLIC src)

target_link_libraries(raytrace sfml-system sfml-window sfml-graphics sfml-network sfml-audio)
# target_include_directories(raytrace PRIVATE ${SFML_DIR}/include)


message(STATUS ${SFML_DIR})
message(STATUS ${SFML_INCLUDE_DIR})


assign_source_group(${raytrace_cpp_files})
assign_source_group(${raytrace_hpp_files})


file(GLOB sfml_dlls ${CMAKE_SOURCE_DIR}/lib/SFML/bin/*.dll)
foreach(dll ${sfml_dlls})
    configure_file(${dll} ${CMAKE_BINARY_DIR}/src COPYONLY)
endforeach()

if(WIN32) # for Windows
	
    # Source code are treated as UTF-8 (Must to use UTF-8 BOM)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /source-charset:utf-8")

endif(WIN32)

