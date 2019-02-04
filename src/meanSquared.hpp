#ifndef MEAN_SQUARED_HPP
#define MEAN_SQUARED_HPP

#include "loss.hpp"

class MeanSquared : public Loss {
public:
    double function(double, double) override;
    double derivative(double, double) override;
};

#endif // MEAN_SQUARED_HPP
