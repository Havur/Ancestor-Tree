
#include "Person.hpp"
#include <iostream>
#include <map>
#include <string>
#ifndef ANCESTOR_TREE_MAKE_PERSON_HPP
#define ANCESTOR_TREE_MAKE_PERSON_HPP

namespace ancestor_tree {
    class person_builder {

    private:
        std::string name_;
        int birthYear_{0};
        int age_{0};
        int deathYear_{0};
        int currentYear_{2022};

    public:
        person_builder() = default;
        Person create() {
            return {age_, name_};
        }

        void insert_name() {
            std::cout << "Plot your name: ";
            std::cin.ignore();
            std::getline(std::cin, name_);
            std::cout << "Name: " << name_ << std::endl;//Gets name from user and locates it in name_

        }

        void insert_birthYear() {
            std::cout << "Plot your Year of birth: ";
            std::cin >> birthYear_;
        }
        void insert_deathYear() {
            std::cout << "Plot your Year of death (if still alive type -1): ";
            std::cin >> deathYear_;//NB! Needs to be rebuilt
        }

        void insert_age() {
            if (deathYear_ > 0) {
                age_ = deathYear_ - birthYear_;
                std::cout << "Age: " << age_ << std::endl;

            } else {
                age_ = currentYear_ - birthYear_;
                std::cout << "Age: " << age_ << std::endl;
            }
        }
    };

#endif//ANCESTOR_TREE_MAKE_PERSON_HPP
}