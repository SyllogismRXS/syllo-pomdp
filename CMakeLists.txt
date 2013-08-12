###############################################################################
# POMDP cmake projec
###############################################################################
cmake_minimum_required (VERSION 2.6)
project (POMDP)

set(POMDP_VERSION_MAJOR "0")
set(POMDP_VERSION_MINOR "0")
set(POMDP_VERSION_PATCH "0")
set(POMDP_VERSION "${POMDP_VERSION_MAJOR}.${POMDP_VERSION_MINOR}.${POMDP_VERSION_PATCH}")
set(POMDP_VERSION_DATE "2012.12.30")

# give POMDP 1 series a few more soversions
set(POMDP_SOVERSION "00")

set(CMAKE_INSTALL_PREFIX /usr/local)

# fetch all the local directories for generated code
get_filename_component(POMDP_LIB_DIR ./lib ABSOLUTE)
get_filename_component(POMDP_BIN_DIR ./bin ABSOLUTE)
get_filename_component(POMDP_INC_DIR ./include ABSOLUTE)
get_filename_component(POMDP_SRC_DIR ./src ABSOLUTE)
get_filename_component(POMDP_SHARE_DIR ./share ABSOLUTE)
get_filename_component(POMDP_BUILD_DIR ./build ABSOLUTE)
get_filename_component(POMDP_SCRIPTS_DIR ./scripts ABSOLUTE)
get_filename_component(POMDP_CMAKE_DIR ./cmake ABSOLUTE)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

set(CMAKE_CXX_FLAGS "-g -Wall")

set(EXECUTABLE_OUTPUT_PATH ${POMDP_BIN_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${POMDP_LIB_DIR})

## set the cmake defaults for libraries and binaries
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${POMDP_LIB_DIR} CACHE PATH 
  "Output directory for the dynamic libraries" )
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${POMDP_BIN_DIR} CACHE PATH
  "Output directory for the binaries" )
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${POMDP_LIB_DIR} CACHE PATH 
  "Output directory for the static libraries (archives)" )

find_package(Eigen3 3.1.2 REQUIRED)
include_directories(${EIGEN3_INCLUDE_DIR})

###############################################################################
# POMDP Build Specific Settings
###############################################################################
#set(BUILD_MODULES ON CACHE BOOL "Build POMDP's modules")

###############################################################################
# Copy header files to include directory
###############################################################################
# Copy standard header files
file(GLOB_RECURSE INCLUDE_FILES RELATIVE ${POMDP_SRC_DIR} src/*.h)
foreach(I ${INCLUDE_FILES})
  configure_file(${POMDP_SRC_DIR}/${I} ${POMDP_INC_DIR}/sam/${I} @ONLY)
endforeach()

###############################################################################
# Internal and External Includes
###############################################################################
include_directories(${POMDP_INC_DIR})

###############################################################################
# Recurse into subdirectory
###############################################################################
add_subdirectory(src)

##################################################################################
#### Installation
##################################################################################
#### Install header files to system
#### The CMakeLists.txt for each library contains the 
#### commands to install the library
###INSTALL(
###  DIRECTORY ${POMDP_INC_DIR} 
###  DESTINATION ${CMAKE_INSTALL_PREFIX}
###  FILES_MATCHING REGEX .*\\.h|.*\\.proto|.*\\.inl
###  )
###
###IF(UNIX AND NOT APPLE)
###  # 1.) Add each library to LIBS_STRING 
###  # POMDP_LIBS is a "global" variable that is passed
###  # down to each sub directory and every library that is
###  # generated in this project appends its name to this
###  # variable.
###  foreach(I ${POMDP_LIBS})
###    #get_filename_component(CUR_LIB ${I} NAME)
###    set (LIBS_STRING "${LIBS_STRING} -l${I}")
###  endforeach()
###
###  # 3.) Use the sam.pc.in file to generate the 
###  #     the final sam.pc file
###  configure_file (
###    "${CMAKE_MODULE_PATH}/sam.pc.in" 
###    "${POMDP_BUILD_DIR}/sam.pc" 
###    @ONLY)
###
###  # 4.) Install the sam.pc file to lib/pkgconfig
###  install (
###    FILES "${CMAKE_CURRENT_BINARY_DIR}/sam.pc"
###    DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig"
###    )
###ENDIF()
###
##################################################################################
#### CMake Debug Tricks
##################################################################################
#### message(STATUS "2-*********")
#### message(STATUS ${DDS_LIBS})
