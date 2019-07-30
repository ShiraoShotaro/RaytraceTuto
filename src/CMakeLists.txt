
# Source Files
file(GLOB viewer_cpp_files src/*.cpp)
file(GLOB viewer_hpp_files src/*.hpp)
file(GLOB viewer_test_cpp_files test/*.cpp)

### Project Settings

add_executable(viewer ${viewer_cpp_files} ${viewer_hpp_files})
add_executable(viewer-test ${viewer_cpp_files} ${viewer_hpp_files} ${viewer_test_cpp_files})
target_include_directories(viewer-test PUBLIC src)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
set(SFML_DIR "${CMAKE_SOURCE_DIR}/lib/SFML")
target_include_directories(viewer PRIVATE ${CMAKE_SOURCE_DIR}/lib/SFML/include)

assign_source_group(${viewer_cpp_files})
assign_source_group(${viewer_hpp_files})
assign_source_group(${viewer_test_cpp_files})

### add sfml
find_package(SFML 2 REQUIRED system window graphics network audio)
if(SFML_FOUND)
  include_directories(${SFML_INCLUDE_DIR})
  target_link_libraries(viewer ${SFML_LIBRARIES})
endif()

file(GLOB sfml_dlls ${CMAKE_SOURCE_DIR}/lib/SFML/bin/*.dll)
foreach(dll ${sfml_dlls})
    configure_file(${dll} ${CMAKE_BINARY_DIR}/src/viewer COPYONLY)
endforeach()


