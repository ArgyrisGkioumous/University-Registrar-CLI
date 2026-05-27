//
// Created by Argyris Gkioumous on 8/5/26.
//

#ifndef UNTITLED1_PROFESSOR_H
#define UNTITLED1_PROFESSOR_H

#include "Member.h"
#include <vector>
#include <string>

class Course;

class Professor : public Member {
private:
    char* code;
    std::string specialty;
    std::vector<Course*> teachingCourses;

public:

    Professor(const char* c, std::string n, std::string g, std::string s);
    ~Professor() override;


    Professor(const Professor& other);
    Professor& operator=(const Professor& other);
    
    const char* getCode() const { return code; }
    std::string getSpecialty() const { return specialty; }
    void setSpecialty(std::string s) { specialty = s; }

    void addCourse(Course* course);
    void printDetails() const override;
    void sendEmail(std::string message) override;
};

#endif
