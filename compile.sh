#!/bin/bash
g++ -c dijkstra.cpp
g++ -c fib_heap.cpp
g++ -c data.cpp
g++ main.cpp dijkstra.o fib_heap.o data.o -o dijkstra