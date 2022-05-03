#include <iostream>
#include <optional>
#include <string>
#include "person.hpp"
#include "personBuilder.hpp"
#include "tree.hpp"

    int main() {

        std::cout << "Welcome to the family tree. \n\n"
                     "Lets start off by creating the main person in the tree >:D \n";


        auto root = nodeTree(ancestorTree::createPerson(false));


        bool quit = false;
        while (!quit) {
            std::cout << "Main menu:"
                      << "\n";

            std::cout << "1: Print tree"
                      << "\n";
            std::cout << "2: Print individual"
                      << "\n";
            std::cout << "3: Add ancestor"
                      << "\n";
            std::cout << "0: Exit"
                      << "\n";

            std::string answer;
            std::cin>> answer;
            int input = -1 ;       //Setting input as -1 then it will return default case input if input is string.
            try {
                 input = std::stoi(answer);
            } catch (std::exception& ex){
            }

            switch (input) {
                case 1:

                    break;

                case 2: {
                    std::shared_ptr<nodeTree> left;
                    break;
                }
                case 3: {

                    auto person = ancestorTree::createPerson(true);
                    if (person.getGender() == "m") {
                        root.addFather(std::make_shared<nodeTree>(person));
                    } else if (person.getGender() == "f") {
                        root.addMother(std::make_shared<nodeTree>(person));
                    }
                    std::cout << "Name of closest relative" << std::endl;
                    std::string relative;
                    std::cin.ignore();
                    std::getline(std::cin, relative);
                    std::cout << "Name: " << relative << std::endl;


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