#include "meanSquared.hpp"

double MeanSquared::function(double x, double y) const
{
    double value = x - y;
    return value * value / 2;
}

double MeanSquared::derivative(double x, double y) const
{
    return x - y;
}
