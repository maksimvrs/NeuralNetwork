#ifndef NEURALNETWORK_LAYER_HPP
#define NEURALNETWORK_LAYER_HPP

#include <vector>

class ILayer {
public:
    virtual ~ILayer() = default;

    virtual std::vector<double> forward(std::vector<double>) = 0;
    virtual std::vector<double> back(std::vector<double>) = 0;

    virtual unsigned long inputSize() const = 0;
    virtual unsigned long outputSize() const = 0;

    virtual void initialize(unsigned long, bool = false) = 0;
};

#endif //NEURALNETWORK_LAYER_HPP
