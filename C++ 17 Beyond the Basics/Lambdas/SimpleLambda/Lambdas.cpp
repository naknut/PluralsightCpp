#include<vector>
#include<algorithm>
#include<iostream>

int main() {
    auto isOdd = [](int candidate) { return candidate % 2 != 0; };

    auto is3Odd = isOdd(3);
    std::cout << "isOdd(3) " << is3Odd << std::endl;

    auto is4Odd = isOdd(4);
    std::cout << "isOdd(4) " << is4Odd << std::endl;

    auto numbers = std::vector<int> { 2,3,4,-1,1 };

    int odds = std::count_if(begin(numbers), end(numbers), isOdd);
    std::cout << "Odds in numbers " << odds << std::endl;

    int evens = std::count_if(begin(numbers), end(numbers), [](int candidate) { return candidate % 2 == 0; });
    std::cout << "Evens in numbers " << evens << std::endl;
}