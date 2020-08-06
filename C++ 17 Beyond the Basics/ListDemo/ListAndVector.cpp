#include <chrono>
#include <vector>
#include <list>
#include <stdlib.h>
#include <iostream>

using std::list;
using std::vector;
using std::chrono::system_clock;
using std::chrono::steady_clock;
using std::chrono::duration_cast;
using std::chrono::seconds;
using std::chrono::milliseconds;
using std::cout;

template <typename Func>
long long TimeFunc(Func func) {
    auto begin = steady_clock::now();
    func();
    auto end = steady_clock::now();
    return duration_cast<milliseconds>(end - begin).count();
}

void BuildVector(const int& size, vector<int>& vector) {
    for (auto i = 0; i < size; i++) {
        auto random = (int)rand();
        auto inserted = false;
        for (auto iterator = begin(vector); iterator != end(vector); iterator++) {
            if(*iterator > random) {
                vector.insert(iterator, random);
                inserted = true;
                break;
            }
        }
        if (!inserted) vector.push_back(random);
    } 
}

void BuildList(const int& size, list<int>& list) {
    for(auto i = 0; i < size; i++) {
        auto random = (int)rand();
        auto inserted = false;
        for (auto iterator = begin(list); iterator != end(list); iterator++) {
            if(*iterator > random) {
                list.insert(iterator, random);
                inserted = true;
                break;
            }
        }
        if(!inserted) list.push_back(random);
    }
}

int main() {
    int const size = 10000;

    vector<int> vector;
    vector.push_back(0);

    list<int> list;
    list.push_back(0);

    auto vectorTime = TimeFunc([&]() { BuildVector(size,vector); });
    auto listTime = TimeFunc([&]() { BuildList(size,list); });

    cout << "Vector: " << vectorTime << std::endl;
    cout << "List: " << listTime << std::endl;
}