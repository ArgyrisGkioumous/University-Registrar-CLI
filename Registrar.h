//
// Created by Argyris Gkioumous on 15/5/26.
//

#ifndef UNTITLED1_REGISTER_H
#define UNTITLED1_REGISTER_H

#include <vector>
#include <string>
#include "Member.h"
#include "Course.h"

class Registrar {
private:
    std::vector<Member*> allMembers;
    std::vector<Course*> allCourses;

public:
    Registrar() = default;
    ~Registrar();

    void addMember(Member* m);
    Member* searchMember(std::string targetName) const;
    void updateMemberGender(std::string targetName, std::string newGender);
    void deleteMember(std::string targetName);

    void addCourse(Course* c);
    Course* searchCourse(std::string targetCode) const;

    void saveToCSV(std::string fileName);
    void loadFromCSV(std::string fileName);
    void sendBulkEmails(std::string message, std::string targetGroup = "ALL");
    void showAll() const;
};


#endif
