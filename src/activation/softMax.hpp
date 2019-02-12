#ifndef NEURALNETWORK_SOFTMAX_HPP
#define NEURALNETWORK_SOFTMAX_HPP

#include "IActivationFullConnection.hpp"

class SoftMax : public IActivationFullConnection {
public:
    double function(double, std::vector<double>) const override;
    double derivative(double, std::vector<double>) const override;
};


#endif //NEURALNETWORK_SOFTMAX_HPP
