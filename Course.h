#pragma once

class Professor; // Forward declaration

#include <string>
#include <vector>

class Course
{
    std::string name_;
    std::vector<std::string> topics_; // Композиция
    Professor *professor_;            // Агрегация

public:
    Course(const std::string &name, Professor *prof);

    void addTopic(const std::string &topic);

    const std::string &getName() const;
    const std::vector<std::string> &getTopics() const;
    const Professor *getProfessor() const;

    ~Course() = default;
};
