#ifndef ANCESTOR_TREE_TREE_HPP
#define ANCESTOR_TREE_TREE_HPP

#include <iostream>
#include <functional>
#include <utility>
#include <vector>
#include <string>
#include "personBuilder.hpp"
#include "Person.hpp"
#include <memory>

class nodeTree {

private:

    Person data_;
    nodeTree *parent_ = nullptr;
    //std::vector<nodeTree*> children;
    std::shared_ptr<nodeTree> left_, right_;

public:
    //explicit nodeTree(nodeTree *p);

    void addParent(Person parent) {
        auto sharedParent = std::make_shared<nodeTree>(parent);

        if (left_ == nullptr) {
            addLeft(sharedParent);
        } else if (right_ == nullptr) {
            addRight(sharedParent);
        }
    }

    void addLeft(std::shared_ptr<nodeTree> parent1) {
        left_ = parent1;
        left_->parent_ = this;
    }

    void addRight(std::shared_ptr<nodeTree> parent2) {
        right_ = parent2;
        right_->parent_ = this;
    }

    bool hasParent() {
        return parent_ != nullptr;
    }

    nodeTree *traverseDepthFirst(const std::function<bool(nodeTree *)> &f) {
        //f(this);
        if (left_ != nullptr) {
            left_->traverseDepthFirst(f);
        }
        if (right_ != nullptr) {
            right_->traverseDepthFirst(f);
        }
        if (f(this)) {
            return this;
        }
        return nullptr;
    }

    void addParentFunc(std::string childName, const Person &ancestor) {
        auto child = traverseDepthFirst([childName](nodeTree *node) {
            return childName == node->data_.getName();
        });

        if (child != nullptr) {
            this->addParent(ancestor);
        }
    }

    nodeTree(Person p) : data_(p) {}
};


#endif //ANCESTOR_TREE_TREE_HPP
