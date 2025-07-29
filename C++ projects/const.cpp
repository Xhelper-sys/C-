#include <iostream>

int main() {
    // The const keyword specifies that a variable's value is constant
    // tells the compilater to prevent anything from modifying iy
    // (read only)

    const double PI = 3.14159;
    double radius = 10;
    double circumference = 2 * PI * radius;

    std::cout << circumference << "cm";

    const int LIGHT_SPEED = 299792458;
    const int WIDTH = 1920;
    const int HEIGHT = 1080;

    return 0;
}