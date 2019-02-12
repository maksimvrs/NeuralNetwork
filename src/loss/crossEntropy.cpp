#include <cmath>

#include "crossEntropy.hpp"

double CrossEntropy::function(double x, double y) const
{
    return -y * log(x);
}

double CrossEntropy::derivative(double x, double y) const
{
    return x - y;
}