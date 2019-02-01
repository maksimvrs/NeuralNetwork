#include "layer.hpp"

Layer::Layer(int size, Activation *activation, Loss *loss)
    : size(size)
    , activation(activation)
    , loss(loss)
{
    outputCache = new double[size];
    neuronsInputCache = new double[size];
}

~Layer::Layer()
{
    delete[] outputCache;
    delete[] neuronsInputCache;
    delete activation;
    delete loss;
    for(int i = 0; i < inputSize; ++i) {
        delete[] weights[i];
    }
    delete[] weights;
}

void Layer::initialize(int inputSize)
{
    this->inputSize = inputSize;

    std::random_device random_device;
    std::mt19937 generator(random_device());
    std::uniform_real_distribution<double> distribution(-0.5, 0.5);

    int** weights = new int*[inputSize];
    for (int i = 0; i < inputSize; ++i) {
        weights[i] = new int[5];
        for (int j = 0; j < size; ++j) {
            weights[i][j] = distribution(generator);
        }
    }
}

double* Layer::next(double* input)
{
    // TODO: Add exceptions (check what weights initialize)
    for (int outputIndex = 0; outputIndex < size; ++outputIndex) {
        for (int inputIndex = 0; inputIndex < inputSize; ++inputIndex) {
            outputCache[outputIndex] += weights[inputIndex][outputIndex] * input[inputIndex];
        }
        neuronsInputCache[outputIndex] = outputCache[outputIndex];
        outputCache[outputIndex] = activation->function(outputCache[outputIndex]);
    }
    return outputCache;
}

double* Layer::back(double* output)
{
    // TODO: Add exceptions (check what weights initialize)
    double* result = new double[inputSize];
    for (int inputIndex = 0; inputIndex < inputSize; ++inputIndex) {
        result[inputIndex] = 0;
        for (int outputIndex = 0; outputIndex < size; ++outputIndex) {
            result[inputIndex] += loss->derivative(outputCache[outputIndex], output[outputIndex])
                * activation->derivative(neuronsInputCache[outputIndex])
                * weights[inputIndex][outputIndex];
        }
        result[inputIndex] *= -gradientStepValue;
    }
    return result;
}

void Layer::gradientStep(double* output)
{
    for (int inputIndex = 0; inputIndex < inputSize; ++inputIndex) {
        for (int outputIndex = 0; outputIndex < size; ++outputIndex) {
            weights[inputIndex][outputIndex] += loss->derivative(outputCache[outputIndex], output[outputIndex])
                * activation->derivative(neuronsInputCache[outputIndex])
                * -gradientStepValue;
        }

    }
}

int Layer::getInputSize()
{
    return inputSize;
}

int Layer::getOutputSize()
{
    return size;
}
