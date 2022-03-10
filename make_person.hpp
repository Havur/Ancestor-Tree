//
// Created by Håvard Surface on 03.03.2022.
//
#include <iostream>
#include <string>

#ifndef ANCESTOR_TREE_MAKE_PERSON_HPP
#define ANCESTOR_TREE_MAKE_PERSON_HPP

namespace ancestor_tree {
    class make_person {

    private:
        std::string name_{""};
        int birthYear_{0};
        int age_{0};
        int deathYear_{0};
        std::string parent_{""};
        int currentYear_{2022};

    public:
        make_person();

        void insert_name();

        void insert_birthYear();

        void insert_deathYear();

        void insert_age();
    };
}

#endif //ANCESTOR_TREE_MAKE_PERSON_HPP