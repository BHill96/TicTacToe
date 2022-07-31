# User-serviceable variables here
SET_PROPERTY(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release" "RelWithDebInfo")
IF (NOT CMAKE_BUILD_TYPE)
  SET (CMAKE_BUILD_TYPE "Release")
ENDIF ()
SET (CMAKE_BUILD_TYPE "Release" CACHE STRING "Select which configuration to build")
SET (CMAKE_INSTALL_PREFIX CACHE PATH "Installation location for binaries, sample inputs, and licenses")
SET (DO_PROFILE FALSE CACHE BOOL "Enable profiling via gprof")
SET (CMAKE_VERBOSE_MAKEFILE on)
SET (CMAKE_EXPORT_COMPILE_COMMANDS on)

# Output more info if debuging
IF (${CMAKE_BUILD_TYPE} STREQUAL "Debug")
  ADD_DEFINITIONS(-DVERBOSE=true)
ELSE ()
  ADD_DEFINITIONS(-DVERBOSE=false)
ENDIF ()

SET (CMAKE_INSTALL_PREFIX /usr/local/share)


# Define compiler-specific options
IF (CMAKE_COMPILER_IS_GNUCXX)
  # support Core2 at a minimum, haswell ideally
  #SET (CMAKE_CXX_FLAGS "-Wall -Wformat -Wno-int-in-bool-context -std=c++17 -march=core2 -mtune=haswell")
  SET (CMAKE_CXX_FLAGS "-Wall -Wformat -std=c++17 -Wno-int-in-bool-context")
  SET (CMAKE_CXX_FLAGS_DEBUG "-O0 -g -ggdb3")
  SET (CMAKE_CXX_FLAGS_RELEASE "-O3 -march=native")
  SET (CMAKE_CXX_FLAGS_RELWITHDEBINFO "-O3 -march=native -g -ggdb3")
  IF (DO_PROFILE)
    SET (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pg")
  ENDIF ()
ELSEIF (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
  SET (CMAKE_CXX_FLAGS "-Wall -Wformat -std=c++17")
  SET (CMAKE_CXX_FLAGS_DEBUG "-O0 -g -ggdb")
  SET (CMAKE_CXX_FLAGS_RELEASE "-O3")
  SET (CMAKE_CXX_FLAGS_RELWITHDEBINFO "-O3 -g -ggdb")
ENDIF ()


# because clang is stupid
IF (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
  SET (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
ENDIF ()

INCLUDE_DIRECTORIES ( /System/Library/Frameworks )
FIND_LIBRARY(COCOA_LIBRARY Cocoa)
FIND_LIBRARY(IOKIT_LIBRARY IOKit)
FIND_LIBRARY(COREVIDEO_LIBRARY CoreVideo)
FIND_LIBRARY(OpenGL_LIBRARY OpenGL )
MARK_AS_ADVANCED (COCOA_LIBRARY
                  IOKIT_LIBRARY
                  OpenGL_LIBRARY)

FIND_LIBRARY( FRAMEWORK_LIBS NAMES glfw3 glfw libglfw PATHS /usr/local/lib)

INCLUDE_DIRECTORIES ( "/usr/local/include" )

SET( CMAKE_MACOSX_RPATH 1 )
SET( GUI_LIBS ${FRAMEWORK_LIBS} ${COCOA_LIBRARY} ${IOKIT_LIBRARY} ${COREVIDEO_LIBRARY} ${OpenGL_LIBRARY} )

# Define files and targets
ADD_DEFINITIONS (${CPREPROCDEFS})

INCLUDE_DIRECTORIES( "../lib" )

IF (CMAKE_COMPILER_IS_GNUCXX)
  SET_SOURCE_FILES_PROPERTIES("../lib/imgui/imgui_draw.cpp" PROPERTIES COMPILE_FLAGS -Wno-maybe-uninitialized)
ENDIF()

FILE(GLOB IMGUISOURCES "../lib/imgui/*.cpp" )
SET(SOURCES "interfaces/IBoard.h"
            "interfaces/IPlayer.h"
            "interfaces/IPlayerQueue.h"
            "interfaces/ITicTacToeGame.h"
            "interfaces/ITicTacToeGameFactory.h"
            "interfaces/IUI.h"
            "structures/GameResults.cpp"
            "structures/GameSettings.cpp"
            "entities/TicTacToeGame.h"
            "entities/TicTacToeGame.cpp"
            "ui/GUI.h"
            "ui/GUI.cpp")

# Create library
add_library(Application_lib STATIC Application.cpp ${SOURCES})
target_include_directories(Application_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# create a binary
ADD_EXECUTABLE( ${PROJECT_NAME} ${IMGUISOURCES} ${SOURCES} "main.cpp" )
SET_TARGET_PROPERTIES( ${PROJECT_NAME} PROPERTIES OUTPUT_NAME "${PROJECT_NAME}.bin" )
TARGET_LINK_LIBRARIES( ${PROJECT_NAME} ${GUI_LIBS} Application_lib)
TARGET_COMPILE_DEFINITIONS( ${PROJECT_NAME} PRIVATE "-DUSE_GL" )
TARGET_COMPILE_DEFINITIONS( ${PROJECT_NAME} PRIVATE "-DUSE_IMGUI" )
INSTALL( TARGETS ${PROJECT_NAME} DESTINATION bin )