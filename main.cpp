#include <iostream>
#include <clocale>
#include "Registrar.h"
#include "Professor.h"
#include "Student.h"
#include "Course.h"

int main() {
    std::setlocale(LC_ALL, "el_GR.UTF-8");

    try {
        Registrar myRegistrar;

        std::cout << "=== Αρχικοποίηση Δεδομένων ===" << std::endl;

        Professor* prof1 = new Professor("P100", "Νίκος Παπαδόπουλος", "Άνδρας", "Αντικειμενοστρεφής Προγραμματισμός");
        Course* cppCourse = new Course("CS701", "Προγραμματισμός C++", 2, prof1);

        prof1->addCourse(cppCourse);

        Student* stud1 = new Student("123456", "Μαρία Παππά", "Γυναίκα", 2);
        stud1->enrollInCourse(cppCourse);

        myRegistrar.addMember(prof1);
        myRegistrar.addMember(stud1);
        myRegistrar.addCourse(cppCourse);

        myRegistrar.showAll();

        std::cout << "\n=== Έλεγχος Λειτουργιών CRUD ===" << std::endl;
        myRegistrar.updateMemberGender("Μαρία Παππά", "Γυναίκα (Ενεργή)");

        myRegistrar.sendBulkEmails("Η αυριανή διάλεξη θα ξεκινήσει στις 10:00 πμ", "STUDENTS");

        myRegistrar.saveToCSV("university_data.csv");

        std::cout << "\n=== Έλεγχος Διαχείρισης Εξαιρέσεων ===" << std::endl;
        myRegistrar.deleteMember("Ανύπαρκτο Όνομα"); // Θα ενεργοποιήσει το catch block

    }
    catch (const std::exception& e) {
        std::cerr << "Προέκυψε σφάλμα: " << e.what() << std::endl;
    }

    std::cout << "\nΤο πρόγραμμα ολοκληρώθηκε κανονικά!" << std::endl;
    return 0;
}