# we will use the network to fetch Google Test sources
# make it possible to disable unit tests when not on network
option(ENABLE_UNIT_TESTS "Enable unit tests" ON)
message(STATUS "Enable testing: ${ENABLE_UNIT_TESTS}")

include(googletest.cmake)

if(ENABLE_UNIT_TESTS)
  fetch_googletest(
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_BINARY_DIR}/googletest
    )

  add_executable(unit_tests "")

  target_sources(
    unit_tests
    PRIVATE
      # Test files to be included
      Example.cpp
    )

  target_link_libraries(
    unit_tests
    PRIVATE
      gtest_main
      # libraries to be included? Possibly connected to src/CMakeLists.txt
    )

  add_test(unit ${PROJECT_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/unit_tests)

  # Auto-run the tests and fail the build if the tests fail
  add_custom_command(
     TARGET unit_tests
     COMMENT "Run tests"
     POST_BUILD 
     COMMAND unit_tests
  )
endif()