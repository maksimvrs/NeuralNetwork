#ifndef LOSS_HPP
#define LOSS_HPP

class ILoss {
public:
    virtual ~ILoss() = default;
    virtual double function(double, double) const = 0;
    virtual double derivative(double, double) const = 0;
};

#endif // LOSS_HPP
