#ifndef SIGMOID_HPP
#define SIGMOID_HPP

#include "IActivation.hpp"

class Sigmoid : public IActivation {
public:
    double function(double x) const override;
    double derivative(double x) const override;
};

#endif // SIGMOID_HPP
