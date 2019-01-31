#ifndef MEAN_SQUARED_HPP
#define MEAN_SQUARED_HPP

#include "loss.hpp"

class MeanSquared : public Loss {
public:
    double function(double, double);
    double derivative(double, double);
};

#endif // MEAN_SQUARED_HPP
