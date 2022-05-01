#include "person.hpp"

#include <iostream>
#include <map>
#include <string>

#ifndef ANCESTOR_TREE_MAKE_PERSON_HPP
#define ANCESTOR_TREE_MAKE_PERSON_HPP

namespace ancestorTree {
    class personBuilder : public person {
    private:
        std::string name_;
        std::string gender_;
        int birthYear_;
        std::optional<int> deathYear_;

    public:
        static person createPerson() {

            std::string name_;
            std::cout << "Type name: ";
            std::cin.ignore();
            std::getline(std::cin, name_);
            std::cout << "Name: " << name_ << std::endl;

            int birthYear_;
            std::cout << "Plot the year of birth: ";
            std::cin >> birthYear_;

            std::optional<int> deathYear;
            std::cout << "Is person still alive? yes/no: ";
            std::string aliveInput;
            std::cin >> aliveInput;

            if (aliveInput == "yes" || aliveInput == "y") {
                //bool alive = true;
            } else if (aliveInput == "no" || aliveInput == "n") {
                std::cout << "Plot the year of death: ";
                int deathYearTemp;
                std::cin >> deathYearTemp;
                deathYear = deathYearTemp;
            } else {
                std::cout << "Wrong input" << std::endl;
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
        //      person create() {
        //          return {birthYear_, name_, gender_};
        //      }

        //          void insertName() {
        //              std::cout << "Plot your name: ";
        //              std::cin.ignore();
        //              std::getline(std::cin, name_);
        //              std::cout << "Name: " << name_ << std::endl;//Gets name from user and locates it in name_

        //          }

        //          void insertBirthYear() {
        //              std::cout << "Plot your Year of birth: ";
        //              std::cin >> birthYear_;
        //          }
        //          void insertDeathYear() {
        //              std::cout << "Plot your Year of death (if still alive type -1): ";
        //              std::cin >> deathYear_;//NB! Needs to be rebuilt
        //          }

        //      //  void insertAge() {
        //      //      if (deathYear_ > 0) {
        //      //          age_ = deathYear_ - birthYear_;
        //      //          std::cout << "Age: " << age_ << std::endl;

        //      //      } else {
        //      //          age_ = currentYear_ - birthYear_;
        //      //          std::cout << "Age: " << age_ << std::endl;
        //      //      }
        //      //  }
        //          void insertGender() {
        //              std::cout << "Insert your gender m/f/?: ";
        //              std::cin >> gender_;
        //              if (gender_ == "m") {
        //                  gender_ = "Male";
        //              } else if (gender_ == "f") {
        //                  gender_ = "Female";
        //              } else {
        //                  std::cout << "Insert your own gender: ";
        //                  std::cin >> gender_;
        //              }


        //  };
    };}

#endif//ANCESTOR_TREE_MAKE_PERSON_HPP