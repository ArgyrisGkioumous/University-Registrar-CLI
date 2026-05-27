//
// Created by Argyris Gkioumous on 8/5/26.
//

#include "Course.h"
#include "Professor.h"
#include <iostream>

Course::Course(std::string c, std::string d, int s, Professor* hp)
    : code(c), description(d), semester(s), headProfessor(hp) {}

void Course::printCourseDetails() const {
    std::cout << "Μάθημα: " << description << " [" << code << "] | Εξάμηνο: " << semester << "\n";
    if (headProfessor != nullptr) {
        std::cout << "Υπεύθυνος Καθηγητής: " << headProfessor->getName() << "\n";
    } else {
        std::cout << "Υπεύθυνος Καθηγητής: Δεν έχει οριστεί\n";
    }
    std::cout << "-----------------------------------" << std::endl;
}


