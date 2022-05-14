#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "Person.hpp"
#include "../application/tree.hpp"


#include <sstream>

TEST_CASE("Print induvidual") {
    Person person{"Ola", Gender::male, 2000, 0};
    std::cout<< person << std::endl;
}
TEST_CASE("Print tree") {
    nodeTree ola{Person{"Ola", Gender::male, 2000, 0}};

    auto connie = std::make_shared<nodeTree>(Person{"Connie", Gender::male, 2000, 0});
    auto berit = std::make_shared<nodeTree>(Person{"Berit", Gender::female, 2000, 0});    ola.addLeft(connie);
    ola.addRight(connie);
    ola.addLeft(berit);

 nodeTree marit{Person{"Marit", Gender::female, 2000, 0}};

   auto synne = std::make_shared<nodeTree>(Person{"Synne", Gender::female, 2000, 0});
   auto bob = std::make_shared<nodeTree>(Person{"Bob", Gender::male, 2000, 0}); //
 //
 //  nodeTree åge{Person{"Åge", Gender::male, 2000, 0}};
 //
 //  nodeTree guro{Person{"Guro", Gender::female, 2000, 0}};
 //  nodeTree peter{Person{"Peter", Gender::male, 2000, 0}}


}
