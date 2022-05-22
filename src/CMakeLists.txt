add_library(Application_lib STATIC Application.cpp)
target_include_directories(Application_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(Application main.cpp)
target_link_libraries(Application PRIVATE Application_lib)

# installs executable in build/bin
install(
  TARGETS Application
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)