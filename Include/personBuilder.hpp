
#include "Include/person.hpp"

#include <iostream>
#include <map>
#include <string>

#ifndef ANCESTOR_TREE_MAKE_PERSON_HPP
#define ANCESTOR_TREE_MAKE_PERSON_HPP

namespace ancestorTree {
    class personBuilder {
        private:
            std::string name_;
            std::string gender_;
            int birthYear_{0};
            int age_{0};
            int deathYear_{0};
            int currentYear_{2022};
            int id_{0};

        public:
            personBuilder() = default;
            person create() {
                return {id_, age_, name_, gender_};
            }

            void insertName() {
                std::cout << "Plot your name: ";
                std::cin.ignore();
                std::getline(std::cin, name_);
                std::cout << "Name: " << name_ << std::endl;//Gets name from user and locates it in name_

            }

            void insertBirthYear() {
                std::cout << "Plot your Year of birth: ";
                std::cin >> birthYear_;
            }
            void insertDeathYear() {
                std::cout << "Plot your Year of death (if still alive type -1): ";
                std::cin >> deathYear_;//NB! Needs to be rebuilt
            }

            void insertAge() {
                if (deathYear_ > 0) {
                    age_ = deathYear_ - birthYear_;
                    std::cout << "Age: " << age_ << std::endl;

                } else {
                    age_ = currentYear_ - birthYear_;
                    std::cout << "Age: " << age_ << std::endl;
                }
            }
            void insertGender() {
                std::cout << "Insert your gender m/f/?: ";
                std::cin >> gender_;
                if (gender_ == "m") {
                    gender_ = "Male";
                } else if (gender_ == "f") {
                    gender_ = "Female";
                } else {
                    std::cout << "Insert your own gender: ";
                    std::cin >> gender_;
                }
            }
            void insertId(std::vector<person> person2) {
                id_ = person2.size();
            }

    };

#endif//ANCESTOR_TREE_MAKE_PERSON_HPP
}