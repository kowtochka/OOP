#include "Course.h"
#include "Professor.h" // Полный заголовок здесь

Course::Course(const std::string &name, Professor *prof)
    : name_(name), professor_(prof) {}

void Course::addTopic(const std::string &topic)
{
    topics_.push_back(topic);
}

const std::string &Course::getName() const
{
    return name_;
}

const std::vector<std::string> &Course::getTopics() const
{
    return topics_;
}

const Professor *Course::getProfessor() const
{
    return professor_;
}
