#ifndef ANCESTOR_TREE_APP_HPP
#define ANCESTOR_TREE_APP_HPP

#include "tree.hpp"


int getNumberFromUser();

void printTreeMenuOptions();

int getValidNumberBetween(int lower, int upper);

class App {                                                    //Application class that is used in main and gets data from NodeTree and Person.
public:                                                        //This class runs the application
    App() : root_(NodeTree(ancestorTree::createPerson(false))) {}

    void exec();

private:
    NodeTree root_;

    void addAncestor();

    NodeTree *getIndividual();

    void editIndividual();
};

void App::exec() {
    bool quit = false;
    while (!quit) {
        printTreeMenuOptions();

        int userMenuChoice = getValidNumberBetween(0, 4);

        switch (userMenuChoice) {
            case 1:
                root_.printTree();   // Case 1 prints out the tree in 2D
                break;

            case 2: {
                getIndividual();   // Case 2 Gives person info
                break;
            }
            case 3: {
                addAncestor();   // Case 3 Allows user to add ancestor

                break;
            }
            case 4: {
                editIndividual();   //Case 4 Allows user to edit an existing persons attributes

                break;
            }
            case 0:   // Case 0 Exits program
            default:
                quit = true;
                break;
        }
    }

}

int
getValidNumberBetween(int lower, int upper) {   //Checks if number is between lowest and highest number in switch case
    int input = getNumberFromUser();                //and tells user it has to be between them
    while (input < lower || input > upper) {

        std::cout << input << " is not a valid number" << std::endl;
        std::cout << "The number has to be between: " << lower << " and " << upper << std::endl;

        input = getNumberFromUser();
    }

    return input;
}

int getNumberFromUser() {   // Checks if the input from user is valid or not
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

void printTreeMenuOptions() {   // Function that prints Main Menu options for user to see
    std::cout << "\n""Main Menu:""\n";
    std::cout << "──────────────────────────┐" << std::endl;

    std::cout << "1: Print tree             │"
              << "\n";
    std::cout << "2: Person info            │"
              << "\n";
    std::cout << "3: Add ancestor           │"
              << "\n";
    std::cout << "4: Edit Person            │"
              << "\n";
    std::cout << "0: Exit                   │"
              << "\n";

    std::cout << "──────────────────────────┘" << std::endl;

    std::cout << "Type a menu option : "
              << "\n";
}

void printEditPersonMenuOptions() {   // Function that prints Person Editor Menu.
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

    std::cout << "5: Delete Person          │"
              << "\n";

    std::cout << "0: Exit to main menu      │"
              << "\n";

    std::cout << "──────────────────────────┘" << std::endl;


    std::cout << "Type a number to choose which field you would like to edit : "
              << "\n";
}


void App::addAncestor() {   //Function for adding an ancestor in the tree that is used in switch case
    std::cout << "Adding ancestor, please follow instructions. " << std::endl;
    auto person = ancestorTree::createPerson(true);
    bool successfullyAddedParent = false;
    std::string childName;   //NB! childName as name for child nodes in data tree structure
    std::cout << "Plot the name of " << person.getName()
              << "’s child: ";   // Prompting the user which Person this Person should be the parent of
    std::getline(std::cin, childName);

    while (!successfullyAddedParent) {   //Failsafe user input while parent successfully added set input as ancestor
        std::getline(std::cin, childName);
        successfullyAddedParent = root_.addParentFunc(childName,
                                                      person);   //Traversing and sets input from user as ancestor in the tree

        if (!successfullyAddedParent) {   //Failsafe and tells user if ancestor they are trying to add exists or not
            std::cout << "The Person: " << childName << ". Does not exist within the tree.\n";
            std::cout << "Try plotting the name of " << person.getName() << "’s" << ", child again: ";
        } else {
            std::cout << "Ancestor: " << person.getName() << "," << " Successfully added to tree." << std::endl;
        }
    }
}

NodeTree *App::getIndividual() {   //Function that finds individuals information (data)
    std::cout << "Enter individuals name: ";
    std::cin.ignore();
    std::string name;
    std::getline(std::cin, name);
    auto person = root_.findByName(name);
    if (person != nullptr) {
        std::cout << person->data_ << "\n";
    } else {   //Failsafe
        std::cout << "Couldn't find Person: " << name << "\n";

    }

    return person;
    //TODO, Add relative level "Grandfather,mother,grandmother" etc.
}

void App::editIndividual() {   //Function making a switch case which is the "Edit Person Menu"
    bool quit = false;
    while (!quit) {
        printEditPersonMenuOptions();

        int userMenuChoice = getValidNumberBetween(0, 5);   //Lower and upper digits for menu for failsafe

        switch (userMenuChoice) {
            case 1: {   // Case 1 searches for person then user can edit persons name
                auto personToEdit = getIndividual();
                std::cout << "Edit " << personToEdit->data_.getName() << "’s new name here: ";
                std::string newName;
                std::getline(std::cin, newName);
                personToEdit->data_.setName(newName);
                std::cout << newName << ", Successfully changed" << std::endl;
                break;
            }

            case 2: {   //Case 2 searches for person then user can edit persons birth year
                auto personToEdit = getIndividual();
                std::cout << "Edit " << personToEdit->data_.getName() << "’s new year of birth here: " << std::endl;
                int newBirthYear;
                std::cin >> newBirthYear;
                personToEdit->data_.setBirthYear(newBirthYear);
                std::cout << "The year: " << newBirthYear << ", successfully changed to "
                          << personToEdit->data_.getName() << "’s birth day" << std::endl;

                break;
            }
            case 3: {   //Case 3 searches for person then user can edit gender
                auto personToEdit = getIndividual();
                std::cout << "Edit " << personToEdit->data_.getName() << "’s new gender below." << std::endl;
                Gender newGender;
                bool genderTemp = false;
                while (!genderTemp) {   // Failsafe, if gender is something else than options copied from person builder
                    std::string genderString;
                    std::cout << "Insert gender, type Male,(m)/Female,(f)/Other,(o): ";
                    std::cin >> genderString;


                    if (genderString == "Male" || genderString == "m") { //if gender is a valid gender return true
                        newGender = Gender::male;
                        genderTemp = true;
                    } else if (genderString == "Female" || genderString == "f") {
                        newGender = Gender::female;
                        genderTemp = true;
                    } else if (genderString == "Other" || genderString == "o") {
                        newGender = Gender::other;
                        genderTemp = true;
                    } else if (genderTemp == isdigit(genderTemp)) {   //try and catch to check if gender is true
                        try {
                            genderTemp = std::stoi(genderString);
                        }
                        catch (std::exception &ex) {   //if gender is false input from user is not valid gender loop again
                            std::cout << genderString << ", is an unknown input, add a valid gender." << std::endl;
                            genderTemp = false;
                        }
                    } else {
                    }
                }
                personToEdit->data_.setGender(newGender);   //setting edited gender as new gender
                std::cout << "Successfully changed " << personToEdit->data_.getName() << "’s gender" << std::endl;

                break;
            }
            case 4: {   //Case 4 searches for individual then user can edit
                auto personToEdit = getIndividual();
                if (personToEdit->data_.getDeathYear()) {
                    std::cout << "Edit " << personToEdit->data_.getName() << "’s new year of death here: " << std::endl;
                    int newDeathYear;
                    std::cin >> newDeathYear;
                    personToEdit->data_.setDeathYear(newDeathYear);
                } else {   //if person to edit does not have deathyear return "does not have"
                    std::cout << personToEdit->data_.getName() << ", does not have a registered death year."
                              << std::endl;
                }
            }
            case 5: {   //Case 5 searches for individual and deletes data from individual
                auto personToEdit = getIndividual();   //NB! DOES NOT DELETE NODE
                personToEdit->data_.makeEmptyPerson();   //Sets name = "empty", gender as Other and rest of data to 0
                std::cout << "Person successfully deleted" << std::endl;   //To access node again user can edit "empty"
                                                                           // again and give node new name or keep it empty
                break;

            }
            case 0:   //Exits from "Person Editor Menu" and goes back to "Main Menu"
            default:
                quit = true;
                break;
        }
    }
}

#endif //ANCESTOR_TREE_APP_HPP
