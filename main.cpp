#include <iostream>
#include <sstream>
#include <vector>
#include <iomanip>

#include "src/neuralNetwork.hpp"
#include "src/loss/meanSquared.hpp"
#include "src/activation/sigmoid.hpp"

int main()
{
    std::cout << "Write train dataset:" << std::endl;
    std::vector<std::pair<std::vector<double>, std::vector<double>>> train;
    std::string lineX;
    std::string lineY;
    while (std::getline(std::cin, lineX)) {
        if (lineX.empty()) {
            std::cout << "Dataset was read." << std::endl;
            break;
        }
        std::stringstream inputX;
        inputX.str(lineX);
        std::vector<double> x, y;
        double value;
        while (inputX >> value) {
            x.push_back(value);
        }
        std::getline(std::cin, lineY);
        std::stringstream inputY;
        inputY.str(lineY);
        while (inputY >> value) {
            y.push_back(value);
        }
        train.emplace_back(x, y);
    }

    NeuralNetwork network;
    network.add(new DenseLayer(2, new Sigmoid));
    network.add(new DenseLayer(2, new Sigmoid));
    network.add(new DenseLayer(1, new Sigmoid));

    network.initialize(2, new MeanSquared);

    network.fit(train, 10000);


    std::cout << "Write test data:" << std::endl;
    lineX.erase();
    while (std::getline(std::cin, lineX)) {
        std::stringstream input(lineX);
        std::vector<double> vec;
        double value;
        while (input >> value) {
            vec.push_back(value);
        }
        std::vector<double> predict = network.predict(vec);
        for (double &i : predict) {
            std::cout << std::fixed << std::setprecision(6) << i;
        }
        std::cout << std::endl;
    }
    return 0;
}
