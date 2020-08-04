#pragma once
#include <string>

class Resource {
private:
    std::string name;
public:
    Resource(std::string name);
    Resource(const Resource& resource);
    Resource& operator=(const Resource& resource);
    ~Resource(void);
    std::string GetName() const { return name; }
};