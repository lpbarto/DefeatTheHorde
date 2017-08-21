cmake_minimum_required(VERSION 3.7)
project(DefeatTheHorde)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(test)

set(SOURCE_FILES main.cpp Game.cpp Game.h GameState.cpp GameState.h GameCharacter.cpp GameCharacter.h Villain.cpp Villain.h Hero.cpp Hero.h Animator.cpp Animator.h Map.cpp Map.h GameState.cpp GameState.h)
add_executable(DefeatTheHorde ${SOURCE_FILES})

add_library(core ${SOURCE_FILES} test/runAllTests.cpp)
target_link_libraries(DefeatTheHorde core)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(DefeatTheHorde ${SFML_LIBRARIES})
endif()