#include <Standards.hpp>
#include <Vector2d.hpp>
#include <iostream>
#include <cassert>

int main(int argc, char** argv) {
    Vector2d vec(2.1,3.2);
    std::cout << vec << std::endl;

    Vector2d v1 = Vector2d(1.0, 2.0);
    Vector2d v2 = Vector2d(3.0, 4.0);  
    double expected_dotProduct = 11.0;
    double actual_dotProduct = v1.DotProduct(v1, v2);
    assert(expected_dotProduct == actual_dotProduct);
}

