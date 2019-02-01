#ifndef NEURAL_NETWORK_HPP
#define NEURAL_NETWORK_HPP

#include <vector>
#include <algorithm>
#include <iterator>

#include "layer.hpp"

class NeuralNetwork {
public:
    NeuralNetwork();
    ~NeuralNetwork();
    void initialize();
    void add(Layer*);
    std::vector<double> predict(std::vector<double>);
    void fit(std::vector<std::pair<std::vector<double>, std::vector<double>>>, int);
private:
    int inputSize;
    int outputSize;

    std::vector<Layer*> layers;

    void step(double*, double*);
};

#endif // NEURAL_NETWORK_HPP
