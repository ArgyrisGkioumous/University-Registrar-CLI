//
// Created by Argyris Gkioumous on 8/5/26.
//

#ifndef UNTITLED1_COURSE_H
#define UNTITLED1_COURSE_H

#include <string>

class Professor;

class Course {
private:
    std::string code;
    std::string description;
    int semester;
    Professor* headProfessor;

public:
    Course(std::string c, std:: string d, int s, Professor* hp);

    std::string getCode() const { return code;}
    std::string getDescription() const { return description;}
    int getSemester() const { return semester;}
    Professor* getHeadProfessor() const { return headProfessor;}

    void setDescription(std::string d) { description = d;}
    void setSemester(int s) { semester = s; }
    void setHeadProfessor(Professor* hp) { headProfessor = hp; }

    void printCourseDetails() const;

};


#endif
