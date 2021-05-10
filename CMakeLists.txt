cmake_minimum_required (VERSION 3.18)
project(mosk_git_gui)

set(CMAKE_CXX_STANDARD 17)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")
find_package(FormBuilder REQUIRED)
find_package(wxWidgets REQUIRED COMPONENTS core base)
include(${wxWidgets_USE_FILE})

set(FORM_BUILDER_PROJECT ${PROJECT_SOURCE_DIR}/mosk_git_gui.fbp)
set(GENERATED_VIEW_DIR src/view/wx/gen)
set(GENERATED_VIEW_FILE_CPP ${GENERATED_VIEW_DIR}/gen_view.cpp)
set(GENERATED_VIEW_FILE_H ${GENERATED_VIEW_DIR}/gen_view.h)
set(GENERATED_VIEW_FILES
    ${GENERATED_VIEW_FILE_CPP}
    ${GENERATED_VIEW_FILE_H})
execute_process(COMMAND ${CMAKE_COMMAND} -E make_directory ${GENERATED_VIEW_DIR})
execute_process(COMMAND ${FORMBUILDER_EXE} -g ${FORM_BUILDER_PROJECT})

if (CMAKE_SYSTEM_NAME MATCHES Windows)
  set(WIN_WIN32 WIN32)
else()
  set(WIN_WIN32)
endif()
add_executable(mosk_git_gui ${WIN_WIN32})
target_compile_definitions(mosk_git_gui PRIVATE
    ${wxWidgets_DEFINITIONS}
    VIEW_WX)
target_compile_options(mosk_git_gui PRIVATE ${wxWidgets_CXX_FLAGS})
target_include_directories(mosk_git_gui PRIVATE ${wxWidgets_INCLUDE_DIRS})
target_sources(mosk_git_gui PRIVATE
    src/main.cpp
    src/core/core.cpp
    src/core/command.cpp
    src/core/logger.cpp
    src/view/wx/wx_view.cpp
    src/view/wx/wx_main_frame.cpp
    ${GENERATED_VIEW_FILE_CPP})
target_link_directories(mosk_git_gui PRIVATE ${wxWidgets_LIBRARY_DIRS})
target_link_libraries(mosk_git_gui PRIVATE ${wxWidgets_LIBRARIES})

if (CMAKE_SYSTEM_NAME MATCHES Windows)
  target_link_libraries(mosk_git_gui PRIVATE
      comctl32
      Rpcrt4)
endif()
if(CMAKE_BUILD_TYPE MATCHES Debug)
  target_compile_definitions(mosk_git_gui PRIVATE
      ${wxWidgets_DEFINITIONS_DEBUG})
endif()
