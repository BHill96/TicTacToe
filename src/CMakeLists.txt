add_executable(project.x "")

target_sources(
  project.x
  PRIVATE
    main.cpp
)

target_include_directories(
  project.x
  PRIVATE
    ${PROJECT_BINARY_DIR}/generated
)

# installs executable in build/bin
install(
  TARGETS project.x
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)