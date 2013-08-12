set (APP_NAME "ValueIteration")

file (GLOB SRCS *.cpp)

add_executable( ${APP_NAME} ${SRCS})

#INSTALL( TARGETS ${APP_NAME} RUNTIME DESTINATION bin )
