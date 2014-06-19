cmake_minimum_required( VERSION 2.6 )
set ( CMAKE_BUILD_TYPE Release )
add_definitions ( -Wall -std=c++0x )

CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT(BlockEraser2)
INCLUDE(FindPkgConfig)
PKG_SEARCH_MODULE(SDL REQUIRED sdl)
PKG_SEARCH_MODULE(SDLTTF REQUIRED SDL_ttf)
INCLUDE_DIRECTORIES(${SDL_INCLUDE_DIRS})
INCLUDE_DIRECTORIES(${SDLTTF_INCLUDE_DIRS})
set ( blockEngine_HDRS
	engine/engine.h
	engine/graphic.h
	engine/events.h
        engine/eventelement.h
	engine/position.h
	engine/config.h
	engine/timer.h
	)
set ( blockEngine_SRCS
	engine/engine.cpp
	engine/graphic.cpp
	engine/events.cpp
	engine/config.cpp
	engine/timer.cpp
	engine/eventelement.cpp
	)
set ( BlockEraser2_HDRS
	blocksmanager.h
	block.h
	header.h
	game.h
	menu.h
	)

set ( BlockEraser2_SRCS
	blocksmanager.cpp
	block.cpp
	game.cpp
	main.cpp
	menu.cpp
	)
add_library(blockEngine SHARED ${blockEngine_SRCS} ${blockEngine_HDRS} )
add_executable ( BlockEraser2 ${BlockEraser2_SRCS} ${UIS} ${RSCS} ${TRS} ${MOCS} )
TARGET_LINK_LIBRARIES(BlockEraser2  blockEngine)
TARGET_LINK_LIBRARIES(BlockEraser2 ${SDLTTF_LIBRARIES} )
TARGET_LINK_LIBRARIES(BlockEraser2 ${SDL_LIBRARIES} )
