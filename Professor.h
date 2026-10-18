#pragma once

#include <string>

class Professor
{
    std::string name_;

public:
    explicit Professor(const std::string &name);
    const std::string &getName() const;
};