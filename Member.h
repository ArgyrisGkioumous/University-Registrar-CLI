//
// Created by Argyris Gkioumous on 8/5/26.
//

#ifndef UNTITLED1_MEMBER_H
#define UNTITLED1_MEMBER_H

#include <string>
#include <iostream>

class Member {
protected:
    std:: string name;
    std:: string gender;

public:
    Member(std::string n, std:: string g): name( n),gender( g) {}

    virtual ~Member() {}

    std::string getGender() const { return gender;}
    std::string getName() const { return name;}

    void setName(std::string n) {name = n;}
    void setGender(std::string g) { gender = g;}

    virtual void sendEmail(std::string message) = 0;
    virtual void printDetails() const = 0 ;
};


#endif