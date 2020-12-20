cmake_minimum_required(VERSION 3.12)

project(d3d8to9 CXX)

set(SRCS
  source/d3d8to9_base.cpp
  source/d3d8to9.cpp
  source/d3d8to9_device.cpp
  source/d3d8to9.hpp
  source/d3d8to9_index_buffer.cpp
  source/d3d8to9_surface.cpp
  source/d3d8to9_swap_chain.cpp
  source/d3d8to9_texture.cpp
  source/d3d8to9_vertex_buffer.cpp
  source/d3d8to9_volume.cpp
  source/d3d8.hpp
  source/d3d8types.cpp
  source/d3d8types.hpp
  source/d3dx9.hpp
  source/interface_query.cpp
  source/interface_query.hpp
  res/d3d8to9.rc
)

set(CMAKE_CXX_STANDARD 17)

option(D3D8TO9_STATIC "Build as a static library" OFF)

if(D3D8TO9_STATIC)
  add_library(d3d8to9 STATIC ${SRCS})
else()
  add_library(d3d8to9 SHARED ${SRCS})
  set_target_properties(d3d8to9 PROPERTIES PREFIX "")
  set_target_properties(d3d8to9 PROPERTIES OUTPUT_NAME "d3d8")
endif()

target_compile_definitions(d3d8to9 PUBLIC
  $<$<CONFIG:Debug>:D3D_DEBUG_INFO;_DEBUG>
  $<$<CONFIG:RelWithDebInfo>:D3D_DEBUG_INFO;_DEBUG>
  $<$<CONFIG:Release>:D3D8TO9NOLOG>
  $<$<CONFIG:MinSizeRel>:D3D8TO9NOLOG>
)

if(MSVC)
  target_compile_options(d3d8to9 PRIVATE /W3)
  target_link_options(d3d8to9 PRIVATE /DEF:${CMAKE_CURRENT_SOURCE_DIR}/res/d3d8.def)
else()
  target_compile_options(d3d8to9 PRIVATE -Wall -Wno-delete-non-virtual-dtor -Wno-unknown-pragmas)
  target_link_options(d3d8to9 PRIVATE -Wl,--enable-stdcall-fixup ${CMAKE_CURRENT_SOURCE_DIR}/res/d3d8.def)
endif()

target_link_libraries(d3d8to9 d3d9)
