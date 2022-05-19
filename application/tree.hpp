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
/*
 * This is a tree header file that has names which contains a data tree structure
 */
class NodeTree {

private:
    NodeTree *parent_ = nullptr;
    // std::vector<nodeTree*> children;
    std::shared_ptr<NodeTree> left_, right_;

public:
    // explicit nodeTree(nodeTree *p);

    void addParent(const Person &parent) {
        auto sharedParent = std::make_shared<NodeTree>(parent);

        if (left_ == nullptr) {
            addLeft(sharedParent);
        } else if (right_ == nullptr) {
            addRight(sharedParent);
        }
    }

    void addLeft(std::shared_ptr<NodeTree> parent1) {
        left_ = std::move(parent1);
        left_->parent_ = this;
    }

    void addRight(std::shared_ptr<NodeTree> parent2) {
        right_ = std::move(parent2);
        right_->parent_ = this;
    }

    bool hasParent() {
        return parent_ != nullptr;
    }

    NodeTree *
    traverseDepthFirst(const std::function<bool(NodeTree *)> &predicate, const std::function<void(NodeTree *, int)> &f,
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
        auto child = traverseDepthFirst([childName](NodeTree *node) {
            return childName == node->data_.getName();
        }, [](NodeTree *, int) {});

        if (child != nullptr) {
            child->addParent(ancestor);
            return true;
        }

        return false;
    }

    // returner en Person (nodeTree*), gitt et navn (std::string)
    NodeTree *findByName(std::string &name) {
        // returner personen du får fra traverseDepthFirst direkte
        return traverseDepthFirst([name](NodeTree *node) { return name == node->data_.getName(); },
                                  [](NodeTree *, int) {});
    }

    void printTree() {
        auto l1 = [](NodeTree *) { return false; };
        auto l2 = [](NodeTree *node, int depth) {
            for (size_t i = 0; i < depth; i++) {
                std::cout << "    ";
            }

            if (depth != 0) {
                std::cout << " └─── ";
            }

            std::cout << node->data_.getName() << "\n";
        };

        traverseDepthFirst(l1, l2);
    }

    explicit NodeTree(Person p) : data_(std::move(p)) {}

    Person data_;
};

#endif // ANCESTOR_TREE_TREE_HPP
