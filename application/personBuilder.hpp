#include "person.hpp"
#include <iostream>
#include <map>
#include <string>

#ifndef ANCESTOR_TREE_MAKE_PERSON_HPP
#define ANCESTOR_TREE_MAKE_PERSON_HPP

namespace ancestorTree {
    static person createPerson(bool hasRootNode) {
        std::string name_;
        std::cout << "Type name: ";
        if (hasRootNode) {
            std::cin.ignore();
        }                       //this fixes so the the first character in root person name is not skipped...
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
                std::cout<< "Unknown input, add a valid birthyear." << std::endl;
            }
        }

        std::optional<int> deathYear;
        std::cout << "Is person still alive? yes/no: ";
        std::string aliveInput;
        std::cin >> aliveInput;

        if (aliveInput == "yes" || aliveInput == "y") {

        } else if (aliveInput == "no" || aliveInput == "n") {
            int deathYearTemp = -1;
            while (deathYearTemp == -1){
                std::string input;
                std::cout << "Plot the year of death: ";
                std::cin >> input;
                try {
                    deathYearTemp = std::stoi(input);
                } catch (std::exception &ex) {
                    std::cout<< "Unknown input, add a valid birthyear." << std::endl;
                }
            }
        } else {
        }


        std::string gender_;
        std::cout << "Insert gender m/f/?: ";
        std::cin >> gender_;
        if (gender_ == "m") {
            gender_ = "Male";
        } else if (gender_ == "f") {
            gender_ = "Female";
        } else {
            std::cout << "Insert own gender: ";
            std::cin >> gender_;
        }
        return person{name_, gender_, birthYear_, deathYear};
    }

}

#endif//ANCESTOR_TREE_MAKE_PERSON_HPP