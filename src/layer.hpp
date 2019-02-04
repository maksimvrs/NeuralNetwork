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

    void initialize(int, bool isOutputLayer = false);

    double* next(double*);
    double* back(double*);

    int getInputSize();
    int getOutputSize();
private:
    int size;

    int inputSize;

    double gradientStepValue = 0.75;

    bool isOutputLayer;

    double** weights;

    double* outputCache;

    double* inputCache;

    double* xCache;

    Activation *activation;

    Loss *loss;
};

#endif // LAYER_HPP
