
project(SPLProjects)
cmake_minimum_required(VERSION 3.17)


set(CMAKE_CXX_STANDARD 11)

add_executable(Assignment1 main.cpp Agent.cpp Agent.h Graph.cpp Graph.h Session.cpp Session.h Tree.cpp Tree.h Virus.cpp ContactTracer.cpp Bfs.cpp Bfs.h json.hpp Tester.cpp FiveRuleTester.cpp Tester.h tests.json)