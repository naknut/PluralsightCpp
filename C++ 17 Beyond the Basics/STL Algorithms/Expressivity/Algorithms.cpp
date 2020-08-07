#include<vector>
#include<algorithm>
#include<numeric>

int main() {
    std::vector<int> vector;

    //Standard for
    for(auto i = 0; i < 5; i++) {
        vector.push_back(i);
    }

    //for with increment in body
    for(auto i = 0; i < 5;) {
        vector.push_back(i++);
    }

    //STL Algorithm
    auto i = 0;
    std::generate_n(std::back_inserter(vector), 5, [&]() { return i++; });

    // Totalling the elements

    //Standard for
    auto total = 0;
    for(auto index = 0; index < 5; index++) {
        total += vector[index];
    }

    //for with increment in body
    total = 0;
    for(auto element : vector) {
        total += element;
    }

    //STL Algorithm
    total = std::accumulate(begin(vector), end(vector), 0);
}