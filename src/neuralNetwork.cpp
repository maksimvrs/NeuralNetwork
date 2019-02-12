#include "neuralNetwork.hpp"

#include <vector>
#include <iterator>
#include <iostream>

NeuralNetwork::NeuralNetwork()
    : m_inputSize(0ul)
    , m_loss(nullptr)
{

}

NeuralNetwork::~NeuralNetwork()
{
    for (auto &m_layer : m_layers) {
        delete m_layer;
    }
    delete m_loss;
}

void NeuralNetwork::add(ILayer* layer)
{
    m_layers.push_back(layer);
}

void NeuralNetwork::initialize(unsigned long inputSize, ILoss* loss)
{
    m_inputSize = inputSize;
    m_loss = loss;
    for (std::vector<ILayer*>::const_iterator layer = m_layers.begin(); layer != m_layers.end(); ++layer) {
        if (layer == m_layers.begin()) {
            (*layer)->initialize(m_inputSize + 1, layer == m_layers.end() - 1);
        } else (*layer)->initialize((*(layer - 1))->outputSize() + 1, layer == m_layers.end() - 1);
    }
}

void NeuralNetwork::step(std::vector<double> input, std::vector<double> output)
{
    for (std::vector<ILayer*>::const_iterator layer = m_layers.begin(); layer != m_layers.end(); ++layer) {
        input = (*layer)->forward(input);
    }

    assert(input.size() == output.size());

    std::transform(input.begin(), input.end(), output.begin(), output.begin(),
            [=](double x, double y) {
        return m_loss->derivative(x, y);
    });

    for (std::vector<ILayer*>::const_reverse_iterator layer = m_layers.rbegin(); layer != m_layers.rend(); ++layer) {
        output = (*layer)->back(output);
    }
}

void NeuralNetwork::fit(std::vector<std::pair<std::vector<double>, std::vector<double> > > train, unsigned long epochs)
{
    for (size_t i = 0; i < epochs; ++i) {
        for (auto &input : train) {
            step(input.first, input.second);
        }
        std::cout << "Epoch: " << i << std::endl;
    }
}

std::vector<double> NeuralNetwork::predict(std::vector<double> input)
{
    for (std::vector<ILayer*>::const_iterator layer = m_layers.begin(); layer != m_layers.end(); ++layer) {
        input = (*layer)->forward(input);
    }
    return input;
}
