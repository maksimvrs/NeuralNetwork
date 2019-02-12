cmake_minimum_required(VERSION 3.12)
project(NeuralNetwork)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_executable(NeuralNetwork
        src/IActivation.hpp
        src/layer/DenseLayer.cpp
        src/layer/DenseLayer.hpp
        src/ILoss.hpp
        src/loss/meanSquared.cpp
        src/loss/meanSquared.hpp
        src/neuralNetwork.cpp
        src/neuralNetwork.hpp
        src/activation/sigmoid.cpp
        src/activation/sigmoid.hpp
        main.cpp)
