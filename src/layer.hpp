#ifndef LAYER_HPP
#define LAYER_HPP

#include <vector>
#include <random>

#include "activation.hpp"
#include "loss.hpp"

class Layer {
public:
    Layer(int, Activation*, Loss*);
    ~Layer();

    void initialize(int);

    double* next(double*);
    double* back(double*);
private:
    // Neurons count
    int size;

    int inputSize;

    double gradientStepValue = 0.5;

    // weights[input_neuron][output_neuron]
    double** weights;

    // Last layer neurons output
    double* outputCache;

    double* neuronsInputCache;

    // Activation function
    Activation *activation;

    Loss *loss;

    void gradientStep(double*);

};

#endif // LAYER_HPP
