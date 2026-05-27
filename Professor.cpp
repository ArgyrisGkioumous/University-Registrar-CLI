//
// Created by Argyris Gkioumous on 8/5/26.
//

#include "Professor.h"
#include "Course.h"
#include <cstring>
#include <iostream>

// Constructor
Professor::Professor(const char* c, std::string n, std::string g, std::string s)
    : Member(n, g), specialty(s) {
    code = new char[strlen(c) + 1];
    strcpy(code, c);
}

// Destructor
Professor::~Professor() {
    delete[] code;
}

// Υλοποίηση Copy Constructor (Διορθώθηκε η σύνταξη με το & other)
Professor::Professor(const Professor& other)
    : Member(other.name, other.gender), specialty(other.specialty) {
    code = new char[strlen(other.code) + 1];
    strcpy(code, other.code);
    teachingCourses = other.teachingCourses;
}

// Υλοποίηση Assignment Operator
Professor& Professor::operator=(const Professor& other) {
    if (this != &other) {
        Member::name = other.name;
        Member::gender = other.gender;
        specialty = other.specialty;

        delete[] code; // Αποδέσμευση της παλιάς μνήμης

        code = new char[strlen(other.code) + 1];
        strcpy(code, other.code);
        teachingCourses = other.teachingCourses;
    }
    return *this;
}

void Professor::addCourse(Course* course) {
    if (course != nullptr) {
        teachingCourses.push_back(course);
    }
}

void Professor::printDetails() const {
    std::cout << "Καθηγητής/τρια: " << name << " [Κωδικός: " << code << "]\n";
    std::cout << "Ειδικότητα: " << specialty << "\n";
    std::cout << "Μαθήματα Διδασκαλίας: ";
    if (teachingCourses.empty()) {
        std::cout << "Κανένα";
    } else {
        for (Course* c : teachingCourses) {
            std::cout << c->getCode() << " ";
        }
    }
    std::cout << "\n-----------------------------------" << std::endl;
}

void Professor::sendEmail(std::string message) {
    std::cout << "[Email προς Καθηγητή] " << name << " (" << code << "): " << message << std::endl;
}