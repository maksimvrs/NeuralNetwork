#ifndef ACTIVATION_HPP
#define ACTIVATION_HPP

#include <vector>

class IActivation {
public:
    virtual ~IActivation() = default;
    virtual double function(double) const = 0;
    virtual double derivative(double) const = 0;
};

#endif // ACTIVATION_HPP

