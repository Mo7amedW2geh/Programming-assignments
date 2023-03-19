#include <iostream>
#include <cmath>

int main() {

    int n = 0;
    float t = 1;
    float pi = 0;

    while(std::fabs(t) > std::pow(10, -4)) {
        //t = (4 * std::pow(-1, n)) / (2*n + 1);
        t = (std::pow(-1, n)) / (2*n + 1);
        pi = pi + t;
        n = n + 1;
    }
    
    // instead "of t = (4 * std::pow(-1, n)) / (2*n + 1);"
    // we add "pi = pi * 4;"
    pi = pi * 4;
     
        
    std::cout << pi << std::endl;

    return 0;
}
