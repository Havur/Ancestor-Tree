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

    void addParent(const Person& parent) {
        auto sharedParent = std::make_shared<nodeTree>(parent);

        if (left_ == nullptr) {
            addLeft(sharedParent);
        } else if (right_ == nullptr) {
            addRight(sharedParent);
        }
    }

   void addLeft(std::shared_ptr<nodeTree> parent1) {
        left_ = std::move(parent1);
        left_->parent_ = this;
    }

    void addRight(std::shared_ptr<nodeTree> parent2) {
        right_ = std::move(parent2);
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

    void addParentFunc(const std::string& childName, const Person &ancestor) {
        auto child = traverseDepthFirst([childName](nodeTree *node) {
            return childName == node->data_.getName();
        });

        if (child != nullptr) {
            child->addParent(ancestor);
        }
    }

    explicit nodeTree(Person p) : data_(std::move(p)) {}
};


#endif //ANCESTOR_TREE_TREE_HPP
