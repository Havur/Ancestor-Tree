#include <iostream>
#include <vector>

#include "person.hpp"
#include "personBuilder.hpp"
#include "tree.hpp"

bool hasRootNode = false;

person createPerson(){
    std::string name_;
    std::cout << "Type name: " ;
    if(hasRootNode) {
        std::cin.ignore();
    } else {
        hasRootNode = true;
    }//stupid fix, this fixes so the the first character in root person name is not skipped...

    std::getline(std::cin, name_);
    std::cout << "Name: " <<  name_ << std::endl;

    int birthYear_;
    std::cout << "Plot the year of birth: ";
    std::cin >> birthYear_;

    int deathYear_;
    std::cout << "Is person still alive? yes/no: "; //TODO NB! Needs to be rewritten.. working on it.
    std::string isAlive;
    std::cin >> isAlive;   //Ide! i funksjon (Is person still alive yes/no) bool, if no plot year of death.

    if (isAlive == "yes" || "y"){
        bool alive = true;
    }
    else if (isAlive == "no" || "n") {
        std::cout << "Plot the year of death: ";
        std::cin >> deathYear_;
    }
    else {
        std::cout<<"Wrong input"<<std::endl;
    }


    std::string gender_;
    std::cout << "Insert gender m/f/?: ";
    std::cin >> gender_;
    if (gender_ == "m") {
        gender_ = "Male";
    } else if (gender_ == "f") {
        gender_ = "Female";
    } else {
        std::cout << "Insert own gender: ";
        std::cin >> gender_;
    }
    return person(name_,gender_,birthYear_,deathYear_);
}
int main() {

    std::cout << "Welcome to the family tree. \n\n"
                 "Lets start off by creating yourself in the tree >:D \n";


   auto root = std::make_shared<Node>(createPerson());
  // auto mother = std::make_shared<Node>();
  // auto father = std::make_shared<Node>();
  // root->addFather(father);
  // root->addMother(mother);

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

        int answer;
        std::cin >> answer;// Possible issue here. What if user input is not a number?
        //ta inn en string isteden for int og sjekk om stringen e ett tall
        switch (answer) {
            case 1:
          // for (const person &person: ) {

          //     << " Name: " << person.getName() test
          //     << " Age: " << person.getAge()
          //     << " Gender: " << person.getGender() << std::endl;

                break;

            case 2:

                break;

            case 3: {
                //lag en person
                auto person = createPerson();
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