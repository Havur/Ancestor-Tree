//
// Created by Håvard Surface on 03.03.2022.
//
/*
 * 1.   1. populate ancestor chart, 2. show ancestors, 3 edit ancestor,4 exit
 *
 *      1. populate skal inneholde (navn, fødselsår, alder, evt.dødsår/hvis tomt = i live, foreldre mor/far)
 *      2. show ancestor skal inneholde foreldrene til gitt input navn
 *      3. avstlutt programm.
 *
 * 2.
 */
#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <string>
#include "make_person.hpp"
namespace ancestor_tree{

    void make_person::insert_name() {
        std::cout << "Plot your name: ", std::cin >> name_, std::cout << "Name: " << name_ << std::endl; //Gets name from user and locates it in name_

    }
    void make_person::insert_birthYear() {
        std::cout << "Plot your Year of birth: ", std::cin >> birthYear_, std::cout << "Birth Year: " << birthYear_ << std::endl; //Gets Birth year from user and locates it in birthYear
    }

    void make_person::insert_deathYear() {
        std::cout << "Plot your Year of death (if still alive type -1): " , std::cin >> deathYear_;
    }


    void make_person::insert_age() {
        if (deathYear_ > 0) {
            age_ = deathYear_ - birthYear_;
            std::cout << "Age: " << age_ << std::endl;
        }
        else{
            age_= currentYear_ - birthYear_;
            std::cout<< "Age: " << age_ <<std::endl;
        }

    }

    make_person::make_person() {

    }
}

int main(){
   ancestor_tree::make_person mainPerson;
   mainPerson.insert_name();
   mainPerson.insert_birthYear();
   mainPerson.insert_deathYear();
   mainPerson.insert_age();
    return 0;
}