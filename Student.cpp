#include "Student.h"
#include "Course.h" // Полный заголовок здесь

Student::Student(const std::string &name) : name_(name) {}

void Student::enroll(Course *c)
{
    if (c == nullptr)
        return;
    for (Course *existing : courses_)
    {
        if (existing == c)
            return; // Защита от дубликатов
    }
    courses_.push_back(c);
}

const std::string &Student::getName() const
{
    return name_;
}

const std::vector<Course *> &Student::getCourses() const
{
    return courses_;
}
