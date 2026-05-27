//
// Created by Argyris Gkioumous on 10/5/26.
//

#ifndef UNTITLED1_STUDENT_H
#define UNTITLED1_STUDENT_H

#include "Member.h"
#include <vector>
#include <string>

class Course;

class Student : public Member {
private:
    std:: string studentID;
    int semester;
    std::vector<Course*> enrolledCourses;

    public:
    Student(std::string id, std::string n, std::string g, int sem);

    std::string getStudentID() const { return studentID; }
    int getSemester() const { return semester; }
    void setSemester(int sem) { semester = sem; }\

    void enrollInCourse(Course* course);
    void printDetails() const override;
    void sendEmail(std::string message) override;
};

#endif