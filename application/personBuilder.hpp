#include "Person.hpp"
#include <iostream>
#include <map>
#include <string>

#ifndef ANCESTOR_TREE_MAKE_PERSON_HPP
#define ANCESTOR_TREE_MAKE_PERSON_HPP

namespace ancestorTree {
    static Person createPerson(bool hasRootNode) {
        std::string name_;
        std::cout << "Type name: ";
        if (hasRootNode) {
            std::cin.ignore();
        }                       //this fixes so the the first character in root Person name is not skipped...
        std::getline(std::cin, name_);
        std::cout << "Name: " << name_ << std::endl;

        int birthYear_ = -1;
        while (birthYear_ == -1) {
            std::string input;
            std::cout << "Plot the year of birth: ";
            std::cin >> input;
            try {
                birthYear_ = std::stoi(input);
            } catch (std::exception &ex) {
                std::cout << "Unknown input, add a valid birthyear." << std::endl;
            }
        }

        std::optional<int> deathYear;
        std::cout << "Is Person still alive? yes/no: ";
        std::string aliveInput;
        std::cin >> aliveInput;

        if (aliveInput == "yes" || aliveInput == "y") {

        } else if (aliveInput == "no" || aliveInput == "n") {
            int deathYearTemp = -1;
            while (deathYearTemp == -1) {
                std::string input;
                std::cout << "Plot the year of death: ";
                std::cin >> input;
                try {
                    deathYearTemp = std::stoi(input);
                } catch (std::exception &ex) {
                    std::cout << "Unknown input, add a valid birthyear." << std::endl;
                }
            }
        } else {
        }

        Gender gender_;
        std::string genderString;
        std::cout << "Insert gender Male/Female/Other: ";
        std::cin >> genderString;
        if (genderString == "Male" || genderString == "m") {
            gender_ = Gender::male;
        } else if (genderString == "Female" || genderString == "f") {
            gender_ = Gender::female;
        } else if (genderString == "Other" || genderString == "o") {
            gender_ = Gender::other;
        }
    else {
            int genderTemp = -1 ;
            while (genderTemp == -1) {
                genderString = genderTemp;                                            //TODO, Failsafe gender, (halveis)
                try {
                    genderTemp = std::stoi(genderString);
                } catch (std::exception &ex) {
                    std::cout << "Unknown input, add a valid gender." << std::endl;

                }
            }

}

        return Person{name_, gender_, birthYear_, deathYear};
    }

}

#endif//ANCESTOR_TREE_MAKE_PERSON_HPP