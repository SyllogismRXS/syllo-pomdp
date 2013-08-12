# begin copygen.cmake
function(copygen SAM_BUILD_DIR SAM_INC_DIR)
# Copy generated header files to include path
File(GLOB_RECURSE GEN_INCLUDE_FILES RELATIVE 
  ${SAM_BUILD_DIR}/src 
  ${SAM_BUILD_DIR}/src/idl/*.h ${SAM_BUILD_DIR}/src/idl/*.inl
  )
foreach(I ${GEN_INCLUDE_FILES})
  configure_file(${SAM_BUILD_DIR}/src/${I} ${SAM_INC_DIR}/sam/${I} @ONLY)
endforeach()
endfunction()

copygen(${SAM_BUILD_DIR} ${SAM_INC_DIR})
# end copygen.cmake
