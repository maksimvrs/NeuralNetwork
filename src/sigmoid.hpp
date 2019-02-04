#ifndef SIGMOID_HPP
#define SIGMOID_HPP

#include "activation.hpp"

class Sigmoid : public Activation {
public:
    double function(double x) override;
    double derivative(double x) override;
};

#endif // SIGMOID_HPP
