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

class Node{

private:
    person data;
    //std::vector<Node*> children;
    std::shared_ptr<Node> left, right;

public:
    void addMother(std::shared_ptr<Node> mother){
        left = std::move(mother);
    }

    void addFather(std::shared_ptr<Node> father){
        right = std::move(father);
    }
    explicit Node(person data);
};

Node::Node(person p): data(p) {

}


#endif //ANCESTOR_TREE_TREE_HPP
