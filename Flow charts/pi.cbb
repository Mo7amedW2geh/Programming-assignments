#include <iostream>
#include <cmath>

int main() {

    int n = 0;
    float t = 1;
    float pi = 0;

    while(std::fabs(t) > std::pow(10, -4)) {
        t = (4 * std::pow(-1, n)) / (2*n + 1);
        pi = pi + t;
        n = n + 1;
    }

    std::cout << pi << std::endl;

    return 0;
}
