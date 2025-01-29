# Tris-Socket

Tris-Socket is a multiplayer tic-tac-toe game based on UDP sockets. The project includes a server that manages player connections and a client that allows players to interact with the game. This project is still a work in progress, and new features will maybe be added in the future.

## Table of Contents

- [Introduction](#introduction)
- [Requirements](#requirements)
- [Building](#building)
- [Running](#running)
- [Testing](#testing)
- [License](#license)

## Introduction

Tris-Socket is a multiplayer tic-tac-toe game that uses UDP sockets for communication between the server and clients. The server manages player connections, creates game rooms, and starts new games when a room is full. Clients connect to the server, send their moves, and receive moves from other players.

## Requirements

- CMake 3.10 or higher
- GCC or another compatible C compiler
- Linux operating system

## Building

You can build the project using CMake and Make.

1. Create a [build](http://_vscodecontentref_/0) directory and navigate into it:
    ```sh
    mkdir build
    cd build
    ```
2. Configure the project with CMake:
    ```sh
    cmake ..
    ```
3. Build the project:
    ```sh
    make
    ```
4. (optional) If you want to include the tests, you can enable the BUILD_TESTS option when configuring the project with CMake:
    ```sh
    cmake -DBUILD_TESTS=ON ..
    make test
    ```

## Running

### Running the Server

To start the server, run the following command from the [build](http://_vscodecontentref_/1) directory:
```sh
./server
```

### Running the Client

To start the client, run the following command from the [build](http://_vscodecontentref_/1) directory:
```sh
./client
```

## Testing

To run the tests, use the following command from the [build](http://_vscodecontentref_/1) directory:
```sh
make test
```

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.