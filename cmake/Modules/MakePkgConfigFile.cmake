# begin copygen.cmake
function(MakePkgConfigFile 
    SAM_LIB_DIR 
    SAM_CMAKE_DIR 
    SAM_BUILD_DIR 
    CMAKE_CURRENT_BINARY_DIR 
    CMAKE_INSTALL_PREFIX    
    )
  # Produce a pkg-config file for linking against the shared lib
  ## 1.) Generate a string that holds the names of each library
  ##     with appropriate -l command
  file(GLOB SAM_LIBS RELATIVE ${SAM_LIB_DIR} lib/*.so)
  
  # 2.) Add each library to LIBS_STRING 
  foreach(I ${SAM_LIBS})
    get_filename_component(CUR_LIB ${I} NAME)
    set (LIBS_STRING "${LIBS_STRING} -l${CUR_LIB}")
  endforeach()

  # 3.) Use the sam.pc.in file to generate the 
  #     the final sam.pc file
  configure_file (
    "${SAM_CMAKE_DIR}/Modules/sam.pc.in" 
    "${SAM_BUILD_DIR}/sam.pc" 
    @ONLY)
endfunction()

MakePkgConfigFile(
  ${SAM_LIB_DIR} 
  ${SAM_CMAKE_DIR} 
  ${SAM_BUILD_DIR}
  ${CMAKE_CURRENT_BINARY_DIR} 
  ${CMAKE_INSTALL_PREFIX}
  )
# end copygen.cmake
