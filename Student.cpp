//
// Created by Argyris Gkioumous on 10/5/26.
//

#include "Student.h"
#include <iostream>
#include "Course.h"

Student::Student(std::string id, std::string n, std::string g, int sem)
    : Member(n, g), studentID(id), semester(sem) {}

void Student::enrollInCourse(Course* course) {
        if (course!= nullptr) {
            enrolledCourses.push_back(course);
        }
}

void Student::printDetails() const {
    std::cout << "Φοιτητής/τρια: " << name << " [Α.Μ.: " << studentID << "]\n";
    std::cout << "Φύλο: " << gender << " | Εξάμηνο: " << semester << "\n";
    std::cout << "Εγγεγραμμένα Μαθήματα: ";
    if (enrolledCourses.empty()) {
        std::cout << "Κανένα";
    } else {
        for (Course* c : enrolledCourses) {
            std::cout << c->getCode() << " ";
        }
    }
    std::cout << "\n-----------------------------------" << std::endl;
}

void Student::sendEmail(std::string message) {
    std::cout << "[Email προς Φοιτητή/τρια] " << name << " (" << studentID << "): " << message << std::endl;
}