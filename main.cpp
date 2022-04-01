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
#include <vector>
#include "person_builder.hpp"
int main() {

    std::cout << "Welcome to Person CLI"
              << "\n\n";

    std::vector<Person> persons;

    bool quit = false;
    while (!quit) {
        std::cout << "Main menu:"
                  << "\n";

        std::cout << "1: Print persons"
                  << "\n";
        std::cout << "2: Print individual"
                  << "\n";
        std::cout << "3: Add Person"
                  << "\n";
        std::cout << "0: Exit"
                  << "\n";

        int answer;
        std::cin >> answer;// Possible issue here. What if user input is not a number?
        //ta inn en string isteden for int og sjekk om stringen e ett tall
        switch (answer) {
            case 1: {
                for (const Person &person: persons) {

                    std::cout << "Name: " << person.get_name() << " Age: " << person.get_age() << std::endl;
                }
                break;
            }
            case 2:

                break;

            case 3: {
                ancestor_tree::person_builder builder;
                builder.insert_name();
                builder.insert_birthYear();
                builder.insert_deathYear();
                builder.insert_age();
                Person p = builder.create();
                persons.push_back(p);
                break;
            }

            case 0:
                quit = true;
                break;
            default:
                std::cout << "Unknown answer: '" << answer << "'"
                          << "\n"
                          << "Pleas try again.."
                          << "\n\n";
                break;
        }
    }


    return 0;
}