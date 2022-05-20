#include "Person.hpp"
#include <iostream>
#include <map>
#include <string>

#ifndef ANCESTOR_TREE_MAKE_PERSON_HPP
#define ANCESTOR_TREE_MAKE_PERSON_HPP

namespace ancestorTree {
    static Person
    createPerson(bool hasRootNode) {   //function that prompts user questions to get data to store in an object (person)
        std::string name_;
        std::cout << "Type name: ";
        if (hasRootNode) {
            std::cin.ignore();
        }                       //this fixes so the first character in root Person name is not skipped.
        std::getline(std::cin, name_);

        int birthYear_ = -1;
        while (birthYear_ == -1) {
            std::string input;
            std::cout << "Plot the year of birth: ";
            std::cin >> input;
            try {
                birthYear_ = std::stoi(input);
            } catch (std::exception &ex) {   //Failsafe in case if user input i not valid
                std::cout << "Unknown input, add a valid birth year." << std::endl;
            }
        }

        std::optional<int> deathYear;   //Death year as optional because person is either alive or not
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
                    std::cout << "Unknown input, add a valid death year." << std::endl;
                }
            }
        } else {
        }
        Gender gender_;   //Gender as an enum class and not string so user input can not be random
        bool genderTemp = false;   //For Failsafe in while loop if gender something else than true, try again
        while (!genderTemp) {
            std::string genderString;
            std::cout << "Insert gender Male(m)/Female(f)/Other(o): ";
            std::cin >> genderString;

            if (genderString == "Male" || genderString == "m") {
                gender_ = Gender::male;
                genderTemp = true;
            } else if (genderString == "Female" || genderString == "f") {
                gender_ = Gender::female;
                genderTemp = true;
            } else if (genderString == "Other" || genderString == "o") {
                gender_ = Gender::other;
                genderTemp = true;
            } else if (genderTemp == isdigit(genderTemp)) {
                try {
                    genderTemp = std::stoi(genderString);
                }
                catch (std::exception &ex) {
                    std::cout << genderString << ", is an unknown input, add a valid gender." << std::endl;
                    genderTemp = false;
                }
            } else {


            }

        }

        return Person{name_, gender_, birthYear_, deathYear};
    }
}

#endif//ANCESTOR_TREE_MAKE_PERSON_HPP