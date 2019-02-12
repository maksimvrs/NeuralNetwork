#include <cmath>

#include "softMax.hpp"

double SoftMax::function(double x, std::vector<double> output) const
{
    double sum = 0;
    for (auto value : output) {
        sum += exp(value);
    }
    return exp(x) / sum;
}

double SoftMax::derivative(double x, std::vector<double> output) const
{
    double f = function(x, output);
    return f * (1 - f);
}
