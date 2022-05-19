#include "app.hpp"

void printWelcomingMessage();                       //Declaring function printWelcomingMessage()

int main() {
    printWelcomingMessage();                       //Prints welcoming message

    App app;                                      //Running application
    app.exec();

    return 0;
}

void printWelcomingMessage() {                    //Function body that shows welcoming message
    std::cout << "╦ ╦┌─┐┬  ┌─┐┌─┐┌┬┐┌─┐  ┌┬┐┌─┐  ┌┬┐┬ ┬┌─┐  ┌─┐┌─┐┌┬┐┬┬ ┬ ┬  ┌┬┐┬─┐┌─┐┌─┐  ┌┬┐┌─┐┬┌─┌─┐┬─┐\n"
                 "║║║├┤ │  │  │ ││││├┤    │ │ │   │ ├─┤├┤   ├┤ ├─┤│││││ └┬┘   │ ├┬┘├┤ ├┤   │││├─┤├┴┐├┤ ├┬┘\n"
                 "╚╩╝└─┘┴─┘└─┘└─┘┴ ┴└─┘   ┴ └─┘   ┴ ┴ ┴└─┘  └  ┴ ┴┴ ┴┴┴─┘┴    ┴ ┴└─└─┘└─┘  ┴ ┴┴ ┴┴ ┴└─┘┴└─ \n\n"
                 "\n"
                 "Lets start off by creating the main Person in the tree.\n";

}
