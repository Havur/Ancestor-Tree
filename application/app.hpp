#ifndef ANCESTOR_TREE_APP_HPP
#define ANCESTOR_TREE_APP_HPP

#include "tree.hpp"


int getNumberFromUser();

void printTreeMenuOptions();

int getValidNumberBetween(int lower, int upper);

class App {
public:
    App() : root_(nodeTree(ancestorTree::createPerson(false))) {}

    void exec();

private:
    nodeTree root_;

    void addAncestor();

    nodeTree *getIndividual();

    void editIndividual();
};

void App::exec() {
    bool quit = false;
    while (!quit) {
        printTreeMenuOptions();

        int userMenuChoice = getValidNumberBetween(0, 4);

        switch (userMenuChoice) {
            case 1:
                root_.printTree();
                break;

            case 2: {
                getIndividual();
                break;
            }
            case 3: {
                addAncestor();

                break;
            }
            case 4: {
                editIndividual();

                break;
            }
            case 0:
            default:
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
        std::cout << "The input is not recognized as a number. Please try again!" << std::endl;
    }

    return input;
}

void printTreeMenuOptions() {
    std::cout << "\n""Main menu:""\n";
    std::cout << "──────────────────────────┐" << std::endl;

    std::cout << "1: Print tree             │"
              << "\n";
    std::cout << "2: Person info            │"
              << "\n";
    std::cout << "3: Add ancestor           │"
              << "\n";
    std::cout << "4: Edit person            │"
              << "\n";
    std::cout << "0: Exit                   │"
              << "\n";

    std::cout << "──────────────────────────┘" << std::endl;

    std::cout << "Type a menu option : "
              << "\n";
}

void printEditPersonMenuOptions() {
    std::cout << "\n""Person Editor Menu:""\n";
    std::cout << "──────────────────────────┐" << std::endl;

    std::cout << "1: Edit name              │"
              << "\n";
    std::cout << "2: Edit birth year        │"
              << "\n";
    std::cout << "3: Edit gender            │"
              << "\n";

    std::cout << "4: Edit death year        │"
            << "\n";

    std::cout << "5: Delete person          │"
              << "\n";

    std::cout << "0: Exit to main menu      │"
              << "\n";

    std::cout << "──────────────────────────┘" << std::endl;


    std::cout << "Type a number to choose which field you would like to edit : "
              << "\n";
}


void App::addAncestor() {
    std::cout << "Adding ancestor, please follow instructions. " << std::endl;
    auto person = ancestorTree::createPerson(true);
    bool successfullyAddedParent = false;
    std::string childName;
    std::cout << "Plot the name of " << person.getName() << "’s child: ";
    std::getline(std::cin, childName);

    while (!successfullyAddedParent) {
        // Step 2: Prompt the user which person this person should be the parent of
        std::getline(std::cin, childName);
        successfullyAddedParent = root_.addParentFunc(childName, person);

        if (!successfullyAddedParent) {
            std::cout << "The person: " << childName << ". Does not exist within the tree.\n";
            std::cout << "Try plotting the name of " << person.getName() << "’s" << ", child again: ";
        } else {
            std::cout << "Ancestor: " << person.getName() << "," << " Successfully added to tree." << std::endl;
        }
    }
}

nodeTree *App::getIndividual() {
    std::cout << "Enter individuals name: ";
    std::cin.ignore();
    std::string name;
    std::getline(std::cin, name);
    auto person = root_.findByName(name);
    if (person != nullptr) {
        std::cout << person->data_ << "\n";
    } else {
        std::cout << "Couldn't find person: " << name << "\n";
    }

    return person;
    //TODO, Add relative level "Grandfather,mother,grandmother" etc.
}

void App::editIndividual() {
    bool quit = false;
    while (!quit) {
        printEditPersonMenuOptions();

        int userMenuChoice = getValidNumberBetween(0, 5);

        switch (userMenuChoice) {
            case 1: {
                auto personToEdit = getIndividual();
                std::cout << "Edit " << personToEdit->data_.getName() << "’s new name here: ";
                std::string newName;
                std::getline(std::cin, newName);
                personToEdit->data_.setName(newName);
                std::cout << newName << ", Successfully changed" << std::endl;
                break;
            }

            case 2: {
                auto personToEdit = getIndividual();
                std::cout << "Edit " << personToEdit->data_.getName() << "’s new year of birth here: " << std::endl;
                int newBirthYear;
                std::cin >> newBirthYear;
                personToEdit->data_.setBirthYear(newBirthYear);
                std::cout << "The year: " << newBirthYear << ", successfully changed to " << personToEdit->data_.getName() << "’s birth day" << std::endl;

                break;
            }
            case 3: {
                auto personToEdit = getIndividual();
                std::cout << "Edit " << personToEdit->data_.getName() << "’s new gender below." << std::endl;
                Gender newGender;
                bool genderTemp = false;
                while (!genderTemp) {
                    std::string genderString;
                    std::cout << "Insert gender Male/Female/Other: ";
                    std::cin >> genderString;

                    if (genderString == "Male" || genderString == "m") {
                        newGender = Gender::male;
                        genderTemp = true;
                    } else if (genderString == "Female" || genderString == "f") {
                        newGender = Gender::female;
                        genderTemp = true;
                    } else if (genderString == "Other" || genderString == "o") {
                        newGender = Gender::other;
                        genderTemp = true;
                    } else if (genderTemp == isdigit(genderTemp)) {
                        try {
                            genderTemp = std::stoi(genderString);
                        }
                        catch (std::exception &ex) {
                            std::cout << genderString << ", is an unknown input, add a valid gender." << std::endl;
                            genderTemp = false;
                        }
                    } else {
                    }
                }
                personToEdit->data_.setGender(newGender);
                std::cout << "Successfully changed " << personToEdit->data_.getName() << "’s gender" << std::endl;

                break;
            }
            case 4: {
                auto personToEdit = getIndividual();
                if (personToEdit->data_.getDeathYear()) {  //Todo, fix logikken slik at den funka
                    std::cout << "Edit " << personToEdit->data_.getName() << "’s new year of death here: " << std::endl;
                    int newDeathYear;
                    std::cin >> newDeathYear;
                    personToEdit->data_.setDeathYear(newDeathYear);
                } else {
                    std::cout << personToEdit->data_.getName() << ", does not have a registered death year."
                              << std::endl;
                }
            }
                case 5: {
                    auto personToEdit = getIndividual();
                    personToEdit->data_.makeEmptyPerson();
                    std::cout << "Person successfully deleted" << std::endl;
                    break;

                }
            case 0:
                default:
                quit = true;
                break;
        }
    }
}

#endif //ANCESTOR_TREE_APP_HPP
