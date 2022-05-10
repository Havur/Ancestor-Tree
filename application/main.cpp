#include <iostream>
#include <optional>
#include <string>
#include "Person.hpp"
#include "personBuilder.hpp"
#include "tree.hpp"

int main() {

    std::cout << "Welcome to the family tree. \n\n"
                 "Lets start off by creating the main Person in the tree >:D \n";


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
        std::cin >> answer;
        int input = -1;       //Setting input as -1 then it will return default case input if input is string.
        try {
            input = std::stoi(answer);
        } catch (std::exception &ex) {
        }

        switch (input) {
            case 1:

                break;

            case 2: {
                std::cout<< "Enter the name of whom you wish to search for" << std::endl;
                std::cin.ignore();
                std::string name;
                std::getline(std::cin, name);
                root.findByName(name);

                break;
            }
            case 3: {
                // Step 1: Create a new person
                auto person = ancestorTree::createPerson(true);

                // Step 2: Prompt the user which person this person should be the parent of
                std::cout << "Who is the child? (Enter name)" << std::endl;
                std::string childName;
                std::cin.ignore();
                std::getline(std::cin, childName);
                std::cout << "Name: " << childName << std::endl;

                // Step 3: Search the tree for this person to add a parent to
                //root.addParent(std::make_shared<nodeTree>(person));
                root.addParentFunc(childName, person);

                // Step 4: When child is found, child.addParent(person)
                // Step 4b: If child is not found, say child not found and don't add person to
                // tree


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