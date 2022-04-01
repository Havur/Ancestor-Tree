//
// Created by Robert Alan Moltu on 01/04/2022.
//
#include <string>
#include <vector>
#ifndef ANCESTOR_TREE_PERSON_HPP
#define ANCESTOR_TREE_PERSON_HPP
class Person {

private:
    int age_;
    std::string name_;


public:
    Person(int age, std::string name):age_(age), name_(name){
    }
    int get_age() const{
        return age_;
    }
    std::string get_name() const{
        return name_;
    }
};
#endif //ANCESTOR_TREE_PERSON_HPP
