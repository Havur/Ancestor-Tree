//
// Created by Håvard Surface on 21.04.2022.
//

#ifndef ANCESTOR_TREE_TREE_HPP
#define ANCESTOR_TREE_TREE_HPP
#include <iostream>
#include <functional>
#include <utility>
#include <vector>
#include <string>
#include "personBuilder.hpp"
#include "person.hpp"

class nodeTree{

private:
    struct Node{
        person person_;
        int number;
    };
    person data;
    //std::vector<nodeTree*> children;
    std::shared_ptr<nodeTree> left, right;

public:
    void addMother(std::shared_ptr<nodeTree> mother){
        left = std::move(mother);
    }

    void addFather(std::shared_ptr<nodeTree> father){
        right = std::move(father);
    }
    explicit nodeTree(person data);

    void setRoot(person data){
    }

};

void printTree(){

}

nodeTree::nodeTree(person p): data(p) {

}



#endif //ANCESTOR_TREE_TREE_HPP
