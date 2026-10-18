#include <iostream>
#include "Professor.h"
#include "Course.h"
#include "Student.h"

int main()
{

    Professor prof1("Dr. Smith");
    Professor prof2("Dr. Johnson");
    Course math("Mathematics", &prof1);
    Course physics("Physics", &prof2);
    math.addTopic("Algebra");
    math.addTopic("Calculus");
    physics.addTopic("Mechanics");
    physics.addTopic("Thermodynamics");
    Student student("Alice");
    student.enroll(&math);
    student.enroll(&physics);
    student.enroll(&math);
    std::cout << "Professor: " << prof1.getName() << " teaches " << math.getName() << "\n";
    std::cout << "Professor: " << prof2.getName() << " teaches " << physics.getName() << "\n\n";
    std::cout << "Student: " << student.getName() << " is enrolled in:\n";
    for (const auto *c : student.getCourses())
    {
        std::cout << " - " << c->getName() << " (Topics count: " << c->getTopics().size() << ")\n";
    }
    return 0;
}
