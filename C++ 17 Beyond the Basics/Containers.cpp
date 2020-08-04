#include <vector>
#include <stdexcept>
#include <iostream>
#include "Resource.h"

int main() {
    auto numbers = std::vector<int> { 0,1,2 };
    numbers.push_back(-2);
    numbers[0] = 3;

    for (auto i : numbers) {
        std::cout << i << '\n';
    }

    Resource resource("local");
    {
        std::cout << "--------------------------" << std::endl;
        std::vector<Resource> resources;
        resources.push_back(resource);
        std::cout << "--------------------------" << std::endl;
        resources.push_back(Resource("first"));
        std::cout << "--------------------------" << std::endl;
        resources.push_back(Resource("second"));
        std::cout << "--------------------------" << std::endl;
    }
}