cmake_minimum_required( VERSION 2.6 )
set ( CMAKE_BUILD_TYPE Release )
add_definitions ( -Wall -std=c++0x  )

CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT(BlockEraser2)
INCLUDE(FindPkgConfig)
PKG_SEARCH_MODULE(SDL REQUIRED sdl)
PKG_SEARCH_MODULE(SDLTTF REQUIRED SDL_ttf)
INCLUDE_DIRECTORIES(${SDL_INCLUDE_DIRS})
INCLUDE_DIRECTORIES(${SDLTTF_INCLUDE_DIRS})
set ( BlockEraser2_HDRS
	blocksmanager.h
	block.h
	header.h
	engine/engine.h
	engine/graphic.h
	engine/events.h
	game.h
	engine/config.h
	engine/timer.h
	menu.h
        engine/events.h
        engine/eventelement.h
        engine/position.h
	)

set ( BlockEraser2_SRCS
	blocksmanager.cpp
	block.cpp
	game.cpp
	engine/engine.cpp
	engine/graphic.cpp
	engine/events.cpp
	main.cpp
	engine/config.cpp
	engine/timer.cpp
	menu.cpp
        engine/eventelement.cpp
	)

add_executable ( BlockEraser2 ${BlockEraser2_SRCS} ${UIS} ${RSCS} ${TRS} ${MOCS} )
TARGET_LINK_LIBRARIES(BlockEraser2 ${SDLTTF_LIBRARIES} )
TARGET_LINK_LIBRARIES(BlockEraser2 ${SDL_LIBRARIES} )
