# we will use the network to fetch Google Test sources
# make it possible to disable unit tests when not on network
option(ENABLE_UNIT_TESTS "Enable unit tests" ON)
message(STATUS "Enable testing: ${ENABLE_UNIT_TESTS}")

include(gtestResources/googletest.cmake)

if(ENABLE_UNIT_TESTS)
  fetch_googletest(
    ${CMAKE_CURRENT_SOURCE_DIR}/gtestResources
    ${CMAKE_CURRENT_BINARY_DIR}
    )

  set(Tests tests/ApplicationTests.cpp
            tests/TicTacToeGameTests.cpp
            tests/HumanTests.cpp)
  
  add_executable(unit_tests ${Tests})

  target_link_libraries(unit_tests PRIVATE gtest_main gmock_main Application_lib)

  add_test(unit ${PROJECT_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/unit_tests)

  # Auto-run the tests and fail the build if the tests fail
  add_custom_command(
     TARGET unit_tests
     COMMENT "Run tests"
     POST_BUILD 
     COMMAND unit_tests
  )
endif()