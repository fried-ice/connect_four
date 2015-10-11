cmake_minimum_required( VERSION 2.6 )

project(Connect_Four)


# Definition der Headerdateien
set(HEADERS
	../include/game.h
	../include/field.h
	../include/player.h
	../include/disc.h
	../include/color.h
	)

# Definition der Sourcedateien
set(SOURCES
	../src/main.cpp
	../src/game.cpp
	../src/field.cpp
	../src/player.cpp
	../src/disc.cpp
	../src/color.cpp
)

# Includeverzeichnisse setzen
include_directories(
    ../include
)


# Support fuer C++-11 aktivieren
set(CMAKE_CXX_FLAGS "-std=c++11 -O3")

# Ziel hinzufuegen
add_executable(connect_four
    ${SOURCES}
    ${HEADERS}
)

# Bibliotheken linken
target_link_libraries(connect_four)
