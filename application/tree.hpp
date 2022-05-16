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
    nodeTree *parent_ = nullptr;
    // std::vector<nodeTree*> children;
    std::shared_ptr<nodeTree> left_, right_;

public:
    // explicit nodeTree(nodeTree *p);

    void addParent(const Person &parent) {
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

    nodeTree *
    traverseDepthFirst(const std::function<bool(nodeTree *)> &predicate, const std::function<void(nodeTree *, int)> &f,
                       int currDepth = 0) {
        f(this, currDepth);

        if (left_ != nullptr) {

            auto person = left_->traverseDepthFirst(predicate, f, currDepth + 1);
            if (person != nullptr)
                return person;
        }

        if (right_ != nullptr) {

            auto person = right_->traverseDepthFirst(predicate, f, currDepth + 1);
            if (person != nullptr)
                return person;
        }
        if (predicate(this)) {
            return this;
        }
        return nullptr;
    }

    bool addParentFunc(const std::string &childName, const Person &ancestor) {
        auto child = traverseDepthFirst([childName](nodeTree *node) {
            return childName == node->data_.getName();
        }, [](nodeTree *, int) {});

        if (child != nullptr) {
            child->addParent(ancestor);
            return true;
        }

        return false;
    }

    // returner en person (nodeTree*), gitt et navn (std::string)
    nodeTree *findByName(std::string &name) {
        // returner personen du får fra traverseDepthFirst direkte
        return traverseDepthFirst([name](nodeTree *node) { return name == node->data_.getName(); },
                                  [](nodeTree *, int) {});
    }

    void printTree() {
        auto l1 = [](nodeTree *) { return false; };
        auto l2 = [](nodeTree *node, int depth) {
            for (size_t i = 0; i < depth; i++) {
                std::cout << "    ";
            }

            if (depth != 0) {
                std::cout << " └───";
            }

            std::cout << node->data_.getName() << "\n";
        };

        traverseDepthFirst(l1, l2);
    }

    explicit nodeTree(Person p) : data_(std::move(p)) {}

    Person data_;
};

#endif // ANCESTOR_TREE_TREE_HPP