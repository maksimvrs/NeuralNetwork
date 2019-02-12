#include <cmath>

#include "sigmoid.hpp"

double Sigmoid::function(double x) const
{
    return 1 / (1 + exp(-x));
}

double Sigmoid::derivative(double x) const
{
    double f = function(x);
    return f * (1 - f);
}
