#ifndef LOSS_HPP
#define LOSS_HPP

class Loss {
public:
    virtual double function(double, double) = 0;
    virtual double derivative(double, double) = 0;
};

#endif // LOSS_HPP
