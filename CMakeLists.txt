cmake_minimum_required(VERSION 3.10)
project(tris-socket)

set(CMAKE_C_STANDARD 99)

# Aggiungi i file sorgente per il server e il client
set(SERVER_SOURCES src/server.c src/game.c src/room.c src/arena.c)
set(CLIENT_SOURCES src/client.c src/game.c src/room.c src/arena.c)


# Crea l'eseguibile per il server
add_executable(server ${SERVER_SOURCES})

# Crea l'eseguibile per il client
add_executable(client ${CLIENT_SOURCES})

option(BUILD_TESTS "Build test executables" OFF)

if(BUILD_TESTS)
    set(TEST_GAME_SOURCES test/game_test.c src/game.c)

    add_executable(game_test ${TEST_GAME_SOURCES})
endif()