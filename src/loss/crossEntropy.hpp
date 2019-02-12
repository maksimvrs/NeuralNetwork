#ifndef NEURALNETWORK_CROSSENTROPY_HPP
#define NEURALNETWORK_CROSSENTROPY_HPP

#include "ILoss.hpp"

class CrossEntropy : public ILoss {
public:
    double function(double, double) const override;
    double derivative(double, double) const override;
};


#endif //NEURALNETWORK_CROSSENTROPY_HPP
