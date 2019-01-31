#include "meanSquared.hpp"

double MeanSquared::function(double x, double y)
{
    double value = x - y;
    return value * value;
}

double MeanSquared::derivative(double x, double y)
{
    return 2 * (x - y);
}
