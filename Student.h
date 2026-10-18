#pragma once

class Course; // Forward declaration

#include <string>
#include <vector>

class Student
{
    std::string name_;
    std::vector<Course *> courses_; // Агрегация

public:
    explicit Student(const std::string &name);

    void enroll(Course *c);

    const std::string &getName() const;
    const std::vector<Course *> &getCourses() const;

    ~Student() = default;
};
