#include <iostream>
#include <string>
#include <array>
#include <limits>   //  for infinity()
#include <cmath>    // for abs()
#include <iomanip>  // for setting presicion of output

std::array<double, 12> E12 = {
    1.0, 1.2, 1.5, 1.8, 2.2, 2.7, 
    3.3, 3.9, 4.7, 5.6, 6.8, 8.2
};
std::array<double, 24> E24 = {
    1.0, 1.1, 1.2, 1.3, 1.5, 1.6, 
    1.8, 2.0, 2.2, 2.4, 2.7, 3.0, 
    3.3, 3.6, 3.9, 4.3, 4.7, 5.1, 
    5.6, 6.2, 6.8, 7.5, 8.2, 9.1
};
std::array<double, 48> E48 = {
    1.00, 1.05, 1.10, 1.15, 1.21, 1.27,
    1.33, 1.40, 1.47, 1.54, 1.62, 1.69,
    1.78, 1.87, 1.96, 2.05, 2.15, 2.26,
    2.37, 2.49, 2.61, 2.74, 2.87, 3.01,
    3.16, 3.32, 3.48, 3.65, 3.83, 4.02,
    4.22, 4.42, 4.64, 4.87, 5.11, 5.36,
    5.62, 5.90, 6.19, 6.49, 6.81, 7.15,
    7.50, 7.87, 8.25, 8.66, 9.09, 9.53
};

struct Solution {
    double R1;
    double R2;
};

template<size_t seriesSize>
Solution findBestR1andR2(const std::array<double, seriesSize>& series, double targetRatio) {
    double minDeltaRatio = std::numeric_limits<double>::infinity();
    double bestR1 = series[0];
    double bestR2 = series[0];

    for (size_t i = 0; i < series.size(); i++) {
        for (size_t j = 0; j < series.size(); j++) {
            double ratio = series[i]/series[j];
            double deltaRatio = std::abs(ratio - targetRatio);
            if(deltaRatio < minDeltaRatio) {
                bestR1 = series[i];
                bestR2 = series[j];
                minDeltaRatio = deltaRatio;
            }
        }
    }

    return {bestR1, bestR2};
}

int main() {

    double targetRatio = 0;
    std::string targetRatioString; 

    std::cout << "Resistor Value Calculator\nPlease input your desired ratio between R1 and R2:\n";
    std::cin >> targetRatioString;

    // take user input until they input q or quit or exit or a valid ratio
    while(true) {
        if(targetRatioString == "q" or targetRatioString == "quit" or targetRatioString == "exit") {
            // std::cout << "bye!" << std::endl;
            return 0;
        }
        try{
            targetRatio = stod(targetRatioString);
        } catch(std::invalid_argument& e) {}

        if(targetRatio > 0) {
            break;
        }
        std::cout << "Invalid input. Please input a value > 0:\n";
        std::cin >> targetRatioString;
    }

    //get ratio in range 0.1 to 1.
    double nearestPow10 = powf(10.0f, std::ceil(log10f(targetRatio)));
    // std::cout << "\t[DEBUG] nearest power of 10 = " << nearestPow10 << '\n';

    targetRatio /= nearestPow10;

    // std::cout << "\t[DEBUG] new targetRatio = " << targetRatio << '\n';
    
    Solution E12Solution = findBestR1andR2(E12, targetRatio);
    Solution E24Solution = findBestR1andR2(E24, targetRatio);
    Solution E48Solution = findBestR1andR2(E48, targetRatio);

    if(nearestPow10 > 1) {
        E12Solution.R1 *= nearestPow10;
        E24Solution.R1 *= nearestPow10;
        E48Solution.R1 *= nearestPow10;
    } else if(nearestPow10 < 1) {
        E12Solution.R2 /= nearestPow10;
        E24Solution.R2 /= nearestPow10;
        E48Solution.R2 /= nearestPow10;

    }

    std::cout << "[E12] " << E12Solution.R1 << ":" << E12Solution.R2 << " (" << E12Solution.R1/E12Solution.R2 << ")\n";
    std::cout << "[E24] " << E24Solution.R1 << ":" << E24Solution.R2 << " (" << E24Solution.R1/E24Solution.R2 << ")\n";
    std::cout << "[E48] " << E48Solution.R1 << ":" << E48Solution.R2 << " (" << E48Solution.R1/E48Solution.R2 << ")\n";
    
}