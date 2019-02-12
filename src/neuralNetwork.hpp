#ifndef NEURAL_NETWORK_HPP
#define NEURAL_NETWORK_HPP

#include <vector>
#include <algorithm>
#include <iterator>

#include "layer/DenseLayer.hpp"
#include "IActivation.hpp"
#include "IActivationFullConnection.hpp"

#include "loss/meanSquared.hpp"
#include "loss/crossEntropy.hpp"
#include "activation/sigmoid.hpp"
#include "activation/softMax.hpp"

class NeuralNetwork {
public:
    NeuralNetwork();
    ~NeuralNetwork();
    void initialize(unsigned long, ILoss*);
    void add(ILayer*);
    std::vector<double> predict(std::vector<double>);
    void fit(std::vector<std::pair<std::vector<double>, std::vector<double> > >, unsigned long);
private:
    unsigned long m_inputSize;

    std::vector<ILayer*> m_layers;

    ILoss* m_loss;

    void step(std::vector<double>, std::vector<double>);
};

#endif // NEURAL_NETWORK_HPP
