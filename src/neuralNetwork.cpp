#include "neuralNetwork.hpp"

#include <vector>
#include <iterator>
//#include <iostream>

NeuralNetwork::NeuralNetwork() {}

NeuralNetwork::~NeuralNetwork()
{
    for (std::vector<Layer*>::iterator i = layers.begin(); i != layers.end(); ++i) {
        delete *i;
    }
}

void NeuralNetwork::add(Layer* layer)
{
    layers.push_back(layer);
}

void NeuralNetwork::initialize(int inputSize)
{
    this->inputSize = inputSize;
    for (int i = 0; i < static_cast<int>(layers.size()); ++i) {
        if (i == 0) {
            layers[i]->initialize(inputSize);
        } else if (i == static_cast<int>(layers.size()) - 1) {
            layers[i]->initialize(layers[i-1]->getOutputSize(), true);
        } else {
            layers[i]->initialize(layers[i-1]->getOutputSize());
        }
    }
}

void NeuralNetwork::step(double* input, double* output)
{
    std::vector<double> values(input, input + inputSize);
    double* result;
    for (int i = 0; i < static_cast<int>(layers.size()); ++i) {
        result = layers[i]->next(values.data());
        values.assign(result, result + layers[i]->getOutputSize());
    }
    values.assign(output, output + layers.back()->getOutputSize());
    for (int i = layers.size() - 1; i > 0; --i) {
        result = layers[i]->back(values.data());
        values.assign(result, result + layers[i]->getInputSize());
    }
}

void NeuralNetwork::fit(std::vector<std::pair<std::vector<double>, std::vector<double>>> data, int epoch)
{
    for (int i = 0; i < epoch; ++i) {
        for (std::vector<std::pair<std::vector<double>, std::vector<double>>>::iterator input = data.begin();
        input != data.end(); ++input) {
            step(input->first.data(), input->second.data());
        }
//        std::cout << "Epoch: " << i << std::endl;
    }
}

std::vector<double> NeuralNetwork::predict(std::vector<double> input)
{
    double* result;
    for (int i = 0; i < static_cast<int>(layers.size()); ++i) {
        result = layers[i]->next(input.data());
        input.assign(result, result + layers[i]->getOutputSize());
    }
    return input;
}
