//
// Created by Argyris Gkioumous on 15/5/26.
//

#include "Registrar.h"
#include "Student.h"
#include "Professor.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdexcept>


Registrar::~Registrar() {
    for (Member* m: allMembers) delete m;
    for (Course* c: allCourses) delete c;
}

void Registrar::addMember(Member* m) {
    if (m == nullptr) throw std::invalid_argument("Σφάλμα : προσπάθεια εισαγωγής κενού μέλους");
    allMembers.push_back(m);
}

void Registrar::addCourse(Course* c) {
    if (c == nullptr) throw std::invalid_argument(" Σφάλμα : προσπάθεια εισαγωγής κενού μαθήματος ");
    allCourses.push_back(c);
}

Member* Registrar::searchMember(std::string targetName) const {
    for (Member* m : allMembers) {
        if (m->getName() == targetName) return m;
    }
    return nullptr;
}

void Registrar::updateMemberGender(std::string targetName, std::string newGender) {
    Member* m = searchMember(targetName);
    if (!m) throw std::runtime_error("Σφάλμα: Το μέλος '" + targetName + "' δεν βρέθηκε.");
    m->setGender(newGender);
}

void Registrar::deleteMember(std::string targetName) {
    for (auto it = allMembers.begin(); it != allMembers.end(); ++it) {
        if ((*it)->getName() == targetName) {
            delete *it;
            allMembers.erase(it);
            std::cout << "Επιτυχής διαγραφή του μέλους: " << targetName << std::endl;
            return;
        }
    }
    throw std::runtime_error("Σφάλμα: Το μέλος '" + targetName + "' δεν βρέθηκε για διαγραφή.");
}

Course* Registrar::searchCourse(std::string targetCode) const {
    for (Course* c : allCourses) {
        if (c->getCode() == targetCode) return c;
    }
    return nullptr;
}

void Registrar::saveToCSV(std::string filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error(" Σφαλμα : αδυναμια ανοιγματος αρχειου για εγγραφη");
    }

    for (Member* m: allMembers) {
        file << m->getName() << "," << m->getGender() << "\n";
    }
    file.close();
    std::cout<< " Τα δεδομενα αποθηκευτηκαν στο αρχειο:" << filename << std::endl;
}

void Registrar::loadFromCSV(std::string fileName) {
    std::ifstream file(fileName);
    if (!file.is_open()) {
        throw std::runtime_error("Σφάλμα: Το αρχείο δεν βρέθηκε.");
    }

    for (Member* m : allMembers) delete m;
    allMembers.clear();

    std::string line;
    while (std::getline(file, line)) {
        if (line.empty()) continue;
        std::stringstream ss(line);
        std::string type, name, gender, uniqueID, extraInfo;

        std::getline(ss, type, ',');
        std::getline(ss, name, ',');
        std::getline(ss, gender, ',');
        std::getline(ss, uniqueID, ',');
        std::getline(ss, extraInfo, ',');

        if (type == "STUDENT") {
            int sem = std::stoi(extraInfo);
            addMember(new Student(uniqueID, name, gender, sem));
        } else if (type == "PROFESSOR") {
            addMember(new Professor(uniqueID.c_str(), name, gender, extraInfo));
        }
    }
    file.close();
}

void Registrar::sendBulkEmails(std::string message, std::string targetGroup) {
    std::cout << "\n--- Μαζική Αποστολή Email (Ομάδα: " << targetGroup << ") ---" << std::endl;
    for (Member* m : allMembers) {
        if (targetGroup == "STUDENTS" && dynamic_cast<Student*>(m)) {
            m->sendEmail(message);
        } else if (targetGroup == "PROFESSORS" && dynamic_cast<Professor*>(m)) {
            m->sendEmail(message);
        } else if (targetGroup == "ALL") {
            m->sendEmail(message);
        }
    }
}

void Registrar::showAll() const {
    std::cout << "\n=== ΚΑΤΑΛΟΓΟΣ ΜΕΛΩΝ ===" << std::endl;
    for (Member* m : allMembers) m->printDetails();
    std::cout << "\n=== ΚΑΤΑΛΟΓΟΣ ΜΑΘΗΜΑΤΩΝ ===" << std::endl;
    for (Course* c : allCourses) c->printCourseDetails();
}