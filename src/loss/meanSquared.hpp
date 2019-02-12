#ifndef MEAN_SQUARED_HPP
#define MEAN_SQUARED_HPP

#include "ILoss.hpp"

class MeanSquared : public ILoss {
public:
    double function(double, double) const override;
    double derivative(double, double) const override;
};

#endif // MEAN_SQUARED_HPP
