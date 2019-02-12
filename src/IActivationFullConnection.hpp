#ifndef NEURALNETWORK_ACTIVATIONFULLCONNECTION_HPP
#define NEURALNETWORK_ACTIVATIONFULLCONNECTION_HPP

#include <vector>

class IActivationFullConnection {
public:
    virtual ~IActivationFullConnection() = default;
    virtual double function(double, std::vector<double>) const = 0;
    virtual double derivative(double, std::vector<double>) const = 0;
};

#endif //NEURALNETWORK_ACTIVATIONFULLCONNECTION_HPP
