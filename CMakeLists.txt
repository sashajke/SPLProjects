
project(SPLProjects)
cmake_minimum_required(VERSION 3.17)


set(CMAKE_CXX_STANDARD 11)

add_executable(Assignment1 main.cpp Agent.cpp Agent.h Graph.cpp Graph.h Session.cpp Session.h Tree.cpp Tree.h Bfs.cpp Bfs.h json.hpp Tester.h Tester.cpp)

