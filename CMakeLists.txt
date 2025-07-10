cmake_minimum_required(VERSION 3.21)

project(Fractals)

find_package(Groot REQUIRED)
find_program(GLSLC glslc)

set(SOURCES
  ${CMAKE_SOURCE_DIR}/src/main.cpp
)

set(SHADERS
  ${CMAKE_SOURCE_DIR}/shaders/quad.vert
  ${CMAKE_SOURCE_DIR}/shaders/quad.frag
  ${CMAKE_SOURCE_DIR}/shaders/mandelbrot.comp
  ${CMAKE_SOURCE_DIR}/shaders/newton.comp
)

foreach(SHADER ${SHADERS})
  get_filename_component(FILE_NAME ${SHADER} NAME)
  set(SPV ${CMAKE_BINARY_DIR}/shaders/${FILE_NAME}.spv)

  add_custom_command(OUTPUT ${SPV}
    COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_BINARY_DIR}/shaders
    COMMAND ${GLSLC} -o ${SPV} ${SHADER}
    DEPENDS ${SHADER}
    COMMENT "compiling ${SHADER}..."
  )

  list(APPEND SPVS ${SPV})
endforeach()

add_custom_target(shaders ALL DEPENDS ${SPVS})
add_executable(fractals ${SOURCES})
add_dependencies(fractals shaders)

target_include_directories(fractals PRIVATE
  ${CMAKE_SOURCE_DIR}
  /usr/local/include
  /opt/homebrew/include
)

target_link_directories(fractals PRIVATE
  /usr/local/lib
  /opt/homebrew/lib
)

target_link_libraries(fractals PRIVATE
  groot::groot
)