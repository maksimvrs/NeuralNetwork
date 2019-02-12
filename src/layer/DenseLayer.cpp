#include <iostream>
#include "layer/DenseLayer.hpp"

DenseLayer::DenseLayer(unsigned long size, IActivation *activation)
    : m_size(size)
    , m_activation(activation)
{
}

DenseLayer::~DenseLayer()
{
    delete m_activation;
}

void DenseLayer::initialize(unsigned long inputSize, bool isLast)
{
    m_inputSize = inputSize;

    m_inputCache.resize(m_size);

    m_xCache.resize(m_inputSize);

    m_isLast = isLast;

    std::random_device random_device;
    std::mt19937 generator(random_device());
    std::uniform_real_distribution<double> distribution(-0.5, 0.5);

    for (unsigned long i = 0; i < m_inputSize; ++i) {
        std::vector<double> vec(m_size);
        generate(vec.begin(), vec.end(), [&distribution, &generator]() { return distribution(generator); });
        m_weights.push_back(vec);
    }
}

std::vector<double> DenseLayer::forward(std::vector<double> input)
{
    input.push_back(1);

    assert(input.size() == m_inputSize);

//    m_xCache = input;
//    for (size_t i = 0; i < m_weights.size(); ++i) {
//        m_inputCache[i] = std::inner_product(m_weights[i].begin(), m_weights[i].end(), input.begin(), 0.0);
//    }
//    std::vector<double> result(m_size);
//    std::transform(m_inputCache.begin(), m_inputCache.end(), result.begin(),
//            [=](double x) { return m_activation->function(x); });
//    return result;


    std::vector<double> result(m_size);
    for (int outputIndex = 0; outputIndex < m_size; ++outputIndex) {
        result[outputIndex] = 0;
        for (int inputIndex = 0; inputIndex < m_inputSize; ++inputIndex) {
            result[outputIndex] += m_weights[inputIndex][outputIndex] * input[inputIndex];
            m_xCache[inputIndex] = input[inputIndex];
        }
        m_inputCache[outputIndex] = result[outputIndex];
        result[outputIndex] = m_activation->function(result[outputIndex]);
    }
    return result;
}

std::vector<double> DenseLayer::back(std::vector<double> value)
{
    if (m_isLast) {
        assert(value.size() == m_size);
    } else {
        assert(value.size() == m_size + 1);
    }

    std::vector<double> result(m_inputSize);
//    std::vector<double> derivative(m_size);
//    std::transform(m_inputCache.begin(), m_inputCache.end(), derivative.begin(),
//            [&](double x) { return m_activation->derivative(x); });
    for (size_t inputIndex = 0; inputIndex < m_inputSize; ++inputIndex) {
        result[inputIndex] = 0;
        for (size_t outputIndex = 0; outputIndex < m_size; ++outputIndex) {
            double tempValue = value[outputIndex] * m_activation->derivative(m_inputCache[outputIndex]);
            result[inputIndex] += tempValue * m_weights[inputIndex][outputIndex];
            m_weights[inputIndex][outputIndex] += tempValue * m_xCache[inputIndex] * -m_gradientStepValue;
        }
    }
//    for (const auto &row : m_weights) {
//        for (auto i : row) {
//            std::cout << i << " ";
//        }
//        std::cout << std::endl;
//    }
    return result;
}

unsigned long DenseLayer::inputSize() const
{
    return m_inputSize;
}

unsigned long DenseLayer::outputSize() const
{
    return m_size;
}
