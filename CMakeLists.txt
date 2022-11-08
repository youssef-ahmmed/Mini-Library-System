cmake_minimum_required(VERSION 3.25)

project(Library_System)

target_include_directories(Library_System PUBLIC include/)

add_executable(Library_System main.cpp Books.cpp Users.cpp LibrarySystem.cpp)

