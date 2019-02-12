#ifndef LAYER_HPP
#define LAYER_HPP

#include <vector>
#include <random>

#include "IActivation.hpp"
#include "ILayer.hpp"


class DenseLayer : public ILayer {
public:
    DenseLayer(unsigned long, IActivation*);
    ~DenseLayer() override;

    std::vector<double> forward(std::vector<double>) override;
    std::vector<double> back(std::vector<double>) override;

    unsigned long inputSize() const override;
    unsigned long outputSize() const override;

    void initialize(unsigned long, bool) override;

private:
    unsigned long m_size;
    unsigned long m_inputSize;

    bool m_isLast;

    double m_gradientStepValue = 0.75;

    std::vector<double> m_inputCache;
    std::vector<double> m_xCache;

    std::vector< std::vector<double> > m_weights;

    IActivation *m_activation;
};


#endif // LAYER_HPP
