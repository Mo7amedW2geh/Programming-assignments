#include <iostream>
#include <cmath>

int main() {

    double x;

    std::cout << "enter x(angle in radians): ";
    std::cin >> x;

    int n = 2;
    double t = x;
    double sinx = 0;

    while(std::fabs(t) > std::pow(10, -6)) {
        sinx = sinx + t;
        t = t * (-std::pow(x, 2)) / (n * (n + 1));
        n = n + 2;
    }

    std::cout << "sqrt(sin(" << x << ")) = " << std::sqrt(sinx) << std::endl;

    return 0;
}
