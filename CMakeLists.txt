cmake_minimum_required(VERSION 3.5)
project(study2 CXX)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(Qt5_DIR /home/aslab/Qt5.12.4/5.12.4/gcc_64/lib/cmake)
list(APPEND CMAKE_PREFIX_PATH ${Qt5_DIR})

find_package(
	Eigen3 REQUIRED
	Boost 1.58 REQUIRED
)

find_package(
	Qt5 COMPONENTS
	Core
	Gui
	Widgets
	REQUIRED
)

include_directories(
	${PROJECT_SOURCE_DIR}/include
	${EIGEN3_INCLUDE_DIR}
	${BOOST_INCLUDE_DIRS}	
)

add_library(
	character
	SHARED
	src/Unit.cpp
	src/Character.cpp
	src/Knight.cpp
	src/Warrior.cpp
	src/Archer.cpp
)

add_library(
	enemy
	SHARED
	src/Unit.cpp
	src/Enemy.cpp
	src/Trol.cpp
)

set(CMAKE_AUTOMOC ON)

qt5_wrap_cpp(moc_source
	include/Mainwindow.h
	include/Battle.h
)

add_executable(main
	src/main.cpp
	src/Battle.cpp
	src/Board.cpp
	src/Mainwindow.cpp
	${moc_source}
)
target_link_libraries(main
	character
	enemy
	Qt5::Core
	Qt5::Widgets
	Qt5::Gui
)

