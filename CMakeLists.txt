cmake_minimum_required(VERSION 3.28)
project(Zork-Taylor)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED
)


add_executable(Zork-Taylor ZorkMain.cpp
        mainWindow.h
        mainWindow.cpp
        Room.h
        Room.cpp
        Item.cpp
        Item.h
        JSONclass.cpp
        JSONclass.h)

target_link_libraries(Zork-Taylor
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
)