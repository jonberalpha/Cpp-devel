add_executable (Application
  src/spiderapp.cpp
)

target_link_libraries(Application PUBLIC ${EXTRA_LIBS} ${OS_LIBS})

target_include_directories(Application PUBLIC
                            ${PROJECT_BINARY_DIR} 
                            ${EXTRA_INCLUDES}
						                ${CMAKE_CURRENT_SOURCE_DIR}/include
                          )

