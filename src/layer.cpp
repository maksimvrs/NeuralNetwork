#include "layer.hpp"

Layer::Layer(int size, Activation *activation, Loss *loss)
    : size(size)
    , activation(activation)
    , loss(loss)
{
}

Layer::~Layer()
{
    delete[] outputCache;
    delete[] inputCache;
    delete[] xCache;
    delete activation;
    delete loss;
    for(int i = 0; i < inputSize; ++i) {
        delete[] weights[i];
    }
    delete[] weights;
}

void Layer::initialize(int inputSize, bool isOutputLayer)
{
    this->inputSize = inputSize;
    this->isOutputLayer = isOutputLayer;

    outputCache = new double[size];
    inputCache = new double[size];
    xCache = new double[inputSize];

    std::random_device random_device;
    std::mt19937 generator(random_device());
    std::uniform_real_distribution<double> distribution(-0.5, 0.5);

    weights = new double*[inputSize];
    for (int i = 0; i < inputSize; ++i) {
        weights[i] = new double[size];
        for (int j = 0; j < size; ++j) {
            weights[i][j] = distribution(generator);
        }
    }
}

double* Layer::next(double* input)
{
    // TODO: Add exceptions (check what weights initialize)
    for (int outputIndex = 0; outputIndex < size; ++outputIndex) {
        outputCache[outputIndex] = 0;
        for (int inputIndex = 0; inputIndex < inputSize; ++inputIndex) {
            outputCache[outputIndex] += weights[inputIndex][outputIndex] * input[inputIndex];
            xCache[inputIndex] = input[inputIndex];
        }
        inputCache[outputIndex] = outputCache[outputIndex];
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
            double value = isOutputLayer ? loss->derivative(outputCache[outputIndex], output[outputIndex]) :
                output[outputIndex] * activation->derivative(inputCache[outputIndex]);
            result[inputIndex] += value * weights[inputIndex][outputIndex];
            weights[inputIndex][outputIndex] += value * xCache[inputIndex] * -gradientStepValue;
        }
    }
    return result;
}

int Layer::getInputSize()
{
    return inputSize;
}

int Layer::getOutputSize()
{
    return size;
}
