cmake_minimum_required(VERSION 3.28.1)
project(Zork-Taylor)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS Core Gui Widgets REQUIRED)

find_library(OPENGL_LIBRARY OpenGL)
find_library(AGL_LIBRARY AGL)

add_executable(Zork-Taylor
        ZorkMain.cpp
        mainWindow.h
        mainWindow.cpp
        mainWindow.ui
        Room.h
        Room1.h
        Game.h
        Game.cpp
        IntroRoom.h
        TourRoom.h
        Room2.h
        FinalRoom.h
        TaylorManager.h
        TaylorManager.cpp

)

target_link_libraries(Zork-Taylor
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        ${OPENGL_LIBRARY}
        ${AGL_LIBRARY}
)
