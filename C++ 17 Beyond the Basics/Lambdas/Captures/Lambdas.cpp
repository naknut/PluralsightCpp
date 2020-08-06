#include<vector>
#include<algorithm>
#include<iostream>
#include<memory>
#include "Resource.h"

int main() {
    auto isOdd = [](int candidate) { return candidate % 2 != 0; };

    auto is3Odd = isOdd(3);
    std::cout << "isOdd(3) " << is3Odd << std::endl;

    auto is4Odd = isOdd(4);
    std::cout << "isOdd(4) " << is4Odd << std::endl;

    auto numbers = std::vector<int> { 2,3,4,-1,1 };

    auto odds = std::count_if(begin(numbers), end(numbers), isOdd);
    std::cout << "Odds in numbers " << odds << std::endl;

    auto evens = std::count_if(begin(numbers), end(numbers), [](auto candidate) { return candidate % 2 == 0; });
    std::cout << "Evens in numbers " << evens << std::endl;

    // Capturing by value and reference explicitly
    auto x = 3;
    auto y = 7;
    std::string message = "elements between ";
    message += std::to_string(x) + " and " + std::to_string(y) + " inclusive:";
    std::for_each(
        begin(numbers),
        end(numbers),
        [x, y, &message](auto n) { if (n >= x && n <= y) message += " " + std::to_string(n); }
    );
    std::cout << message << std::endl;

    x = y = 0;

    std::for_each(
        begin(numbers),
        end(numbers),
        [&, x](auto element) mutable {
            x += element; //captured by value so wont change outside of lambda
            y += element;
        }
    );
    std::cout << "x = " << x << std::endl << "y = " << y << std::endl;

    {
        auto resource = std::make_unique<Resource>(", ");
        std::for_each(
            begin(numbers),
            end(numbers),
            [=, &message, p=std::move(resource)/* Move capture */](auto n) {
                if (n >= x && n <= y) message += p->GetName() + std::to_string(n);
            }
        );
        std::cout << message << std::endl;
    }
}