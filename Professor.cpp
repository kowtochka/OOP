#include "Professor.h"

Professor::Professor(const std::string &name) : name_(name) {}

const std::string &Professor::getName() const
{
    return name_;
}
