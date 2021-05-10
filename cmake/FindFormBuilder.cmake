cmake_minimum_required(VERSION 3.18)

find_program(FORMBUILDER_EXE
    NAMES
    wxformbuilder
    wxFormBuilder
    wxformbuilder.exe
    wxFormBuilder.exe
    PATHS
    "C:/Program Files (x86)/wxFormBuilder"  # default windows
    "/usr/local/bin"  # default linux
    REQUIRED)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(FormBuilder DEFAULT_MSG
    FORMBUILDER_EXE)
