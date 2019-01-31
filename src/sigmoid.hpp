#ifndef SIGMOID_HPP
#define SIGMOID_HPP

#include "activation.hpp"

class Sigmoid : public Activation {
public:
    double function(double x);
    double derivative(double x);
};

#endif // SIGMOID_HPP
