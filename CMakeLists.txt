cmake_minimum_required(VERSION 3.12)
project(NeuralNetwork)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_executable(NeuralNetwork
        src/activation.hpp
        src/layer.cpp
        src/layer.hpp
        src/loss.hpp
        src/meanSquared.cpp
        src/meanSquared.hpp
        src/neuralNetwork.cpp
        src/neuralNetwork.hpp
        src/sigmoid.cpp
        src/sigmoid.hpp
        main.cpp)
