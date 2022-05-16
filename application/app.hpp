#ifndef ANCESTOR_TREE_APP_HPP
#define ANCESTOR_TREE_APP_HPP

#include "tree.hpp"


int getNumberFromUser();
void printMenuOptions();
int getValidNumberBetween(int lower, int upper);

class App {
public:
    App() : root_(nodeTree(ancestorTree::createPerson(false))) {}
    void exec();
private:
    nodeTree root_;

    void addAncestor();
    void printIndividual();
};

void App::exec() {
    bool quit = false;
    while (!quit) {
        printMenuOptions();

        int userMenuChoice = getValidNumberBetween(0, 3);

        switch (userMenuChoice) {
            case 1:
                root_.printTree();
                break;

            case 2: {
                printIndividual();
                break;
            }
            case 3: {
                addAncestor();

                break;
            }
            case 0:
                quit = true;
                break;
        }
    }

}

int getValidNumberBetween(int lower, int upper) {
    int input = getNumberFromUser();
    while (input < lower || input > upper) {

        std::cout << input << " is not a valid number" << std::endl;
        std::cout << "The number has to be between: " << lower << " and " << upper << std::endl;

        input = getNumberFromUser();
    }

    return input;
}

int getNumberFromUser() {
    std::string choice;
    std::cin >> choice;
    int input;

    try {
        input = std::stoi(choice);
    } catch (std::exception &ex) {
        std::cout << "The input is not recognized as a number. Please try again!";
    }

    return input;
}

void printMenuOptions() {
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

}

void App::addAncestor() {
    // Step 1: Create a new person
    // Step 2: Prompt the user which person this person should be the parent of
    //std::cout << "Who is the child? (Enter name)" << std::endl;
    auto person = ancestorTree::createPerson(true);
    bool successfullyAddedParent = false;

    while (!successfullyAddedParent) {
        // Step 2: Prompt the user which person this person should be the parent of
        std::string firstName;
        std::string lastName;

        std::cout << "Who is the child?" << std::endl;

        char childName[256];
        std::cin.getline(childName, 256);

        successfullyAddedParent = root_.addParentFunc(childName, person);

        if (!successfullyAddedParent) {
            std::cout << "Couldn't find person in tree with the name: " << childName << std::endl;
        }
    }


    //std::cout << "Name: " << childName << std::endl;

    //}
    // Step 4: When child is found, child.addParent(person)
    // Step 4b: If child is not found, say child not found and don't add person to
    // tree
}

void App::printIndividual() {
    std::cout << "Enter the name of whom you wish to search for" << std::endl;
    std::cin.ignore();
    std::string name;
    std::getline(std::cin, name);
    auto person = root_.findByName(name);
    if (person != nullptr) {
        std::cout << person->data_ << "\n";
    } else {
        std::cout << "Couldn't find person " << name << "\n";
    }
    //TODO, make an edit option so that user can edit the person searched for.
    //TODO, Add relative level "Grandfather,mother,grandmother" etc.
}

#endif //ANCESTOR_TREE_APP_HPP
