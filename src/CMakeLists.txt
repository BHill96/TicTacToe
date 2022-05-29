set(Interfaces interfaces/IUI.h
               interfaces/IGameFactory.h
               interfaces/ITicTacToeGame.h)
set(Structures structures/GameSettings.cpp
               structures/GameResults.cpp)
set(Entities entities/TicTacToeGame.h
             entities/TicTacToeGame.cpp
             entities/GameFactory.h
             entities/GameFactory.cpp)

add_library(Application_lib STATIC Application.cpp ${Interfaces} ${Structures} ${Entities})
target_include_directories(Application_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(Application main.cpp)
target_link_libraries(Application PRIVATE Application_lib)

# installs executable in build/bin
install(
  TARGETS Application
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)