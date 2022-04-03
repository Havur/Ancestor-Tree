//
// Created by Robert Alan Moltu on 01/04/2022.
//
#include <string>
#include <vector>

#ifndef ANCESTOR_TREE_PERSON_HPP
#define ANCESTOR_TREE_PERSON_HPP

class person {
    private:
        int age_;
        int id_;
        std::string name_;
        std::string gender_;

    public:
        person(int id, int age, std::string name, std::string gender):
        id_(id), age_(age), name_(name), gender_(gender){
        }
        int getAge() const{
            return age_;
        }
        int getId(){
            return id_;
        }
        std::string getName() const{
            return name_;
        }
        std::string getGender() const{
            return gender_;
        }
};

#endif //ANCESTOR_TREE_PERSON_HPP
