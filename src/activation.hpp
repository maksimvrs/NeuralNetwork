#ifndef ACTIVATION_HPP
#define ACTIVATION_HPP

class Activation {
public:
    virtual ~Activation() = default;
    virtual double function(double) = 0;
    virtual double derivative(double) = 0;
};

#endif // ACTIVATION_HPP

