#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "Person.hpp"
#include "../application/tree.hpp"


#include <sstream>

TEST_CASE("Print individual") {   //Test to print individual
    Person person{"Ola", Gender::male, 2000, 2010};    //Giving person data and printing it to console
    std::cout << person << std::endl;
    std::cout << "──────────────────────────────────────────" << "\n";
}

TEST_CASE("Print tree") {

    std::cout << "TEST FOR PRINTING TREE:" << "\n";  //Test to see if case 1 print tree works and looks as it should.
    std::cout << "\n";                              //Making nodes and giving them names and pointing them to each other
    NodeTree ola{Person{"Ola", Gender::male, 2000, 0}};

    auto connie = std::make_shared<NodeTree>(Person{"Connie", Gender::male, 2000, 0});
    auto berit = std::make_shared<NodeTree>(Person{"Berit", Gender::female, 2000, 0});
    ola.addLeft(connie);
    ola.addRight(berit);


    auto synne = std::make_shared<NodeTree>(Person{"Synne", Gender::female, 2000, 0});
    auto bob = std::make_shared<NodeTree>(Person{"Bob", Gender::male, 2000, 0}); //
    connie->addRight(synne);
    connie->addLeft(bob);


    auto marit = std::make_shared<NodeTree>(Person{"Marit", Gender::female, 2000, 0});
    auto peder = std::make_shared<NodeTree>(Person{"Peder", Gender::male, 2000, 0});
    berit->addRight(marit);
    berit->addLeft(peder);


    auto beate = std::make_shared<NodeTree>(Person{"Beate", Gender::female, 2000, 0});
    auto per = std::make_shared<NodeTree>(Person{"Per", Gender::male, 2000, 0});
    bob->addRight(beate);
    bob->addLeft(per);


    auto kirsti = std::make_shared<NodeTree>(Person{"Kirsti", Gender::female, 2000, 0});
    auto arnold = std::make_shared<NodeTree>(Person{"Arnold", Gender::male, 2000, 0});
    synne->addRight(kirsti);
    synne->addLeft(arnold);

    auto sander = std::make_shared<NodeTree>(Person{"Sander", Gender::male, 2000, 0});
    auto camilla = std::make_shared<NodeTree>(Person{"Camilla", Gender::female, 2000, 0});
    per->addLeft(sander);
    per->addRight(camilla);

    ola.printTree();


}