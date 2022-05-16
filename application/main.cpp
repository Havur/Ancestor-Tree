#include "app.hpp"

void printWelcomingMessage();

int main() {
    printWelcomingMessage();

    App app;
    app.exec();

    return 0;
}

void printWelcomingMessage() {
    std::cout << "╦ ╦┌─┐┬  ┌─┐┌─┐┌┬┐┌─┐  ┌┬┐┌─┐  ┌┬┐┬ ┬┌─┐  ┌─┐┌─┐┌┬┐┬┬ ┬ ┬  ┌┬┐┬─┐┌─┐┌─┐  ┌┬┐┌─┐┬┌─┌─┐┬─┐\n"
                 "║║║├┤ │  │  │ ││││├┤    │ │ │   │ ├─┤├┤   ├┤ ├─┤│││││ └┬┘   │ ├┬┘├┤ ├┤   │││├─┤├┴┐├┤ ├┬┘\n"
                 "╚╩╝└─┘┴─┘└─┘└─┘┴ ┴└─┘   ┴ └─┘   ┴ ┴ ┴└─┘  └  ┴ ┴┴ ┴┴┴─┘┴    ┴ ┴└─└─┘└─┘  ┴ ┴┴ ┴┴ ┴└─┘┴└─ \n\n"
                 "\n"
                 "Lets start off by creating the main person in the tree.\n";

}
