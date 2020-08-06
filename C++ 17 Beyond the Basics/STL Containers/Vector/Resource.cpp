#include "Resource.h"
#include <iostream>
#include <string>

Resource::Resource(std::string name) : name(name) {
    std::cout << "constructing " << name << std::endl;
}

Resource::Resource(const Resource& resource) : name(resource.name) {
    std::cout << "copy constructing " << name << std::endl;
}

Resource& Resource::operator=(const Resource& resource) {
    name = resource.GetName();
    std::cout << "copy assigning " << name << std::endl;
    return *this;
}

Resource::~Resource(void) {
    std::cout << "destructing " << name << std::endl;
}