//
// Created by Håvard Surface on 03.03.2022.
//
/*
 * 1.   1. populate ancestor chart, 2. show ancestors, 3 edit ancestor,4 exit
 *
 *      1. populate skal inneholde (navn, fødselsår, alder, evt.dødsår/hvis tomt = i live, foreldre mor/far)
 *      2. show ancestor skal inneholde foreldrene til gitt input navn
 *      3. avstlutt programm.
 *
 * 2.
 */

#include "make_person.hpp"

#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <string>

namespace ancestor_tree{

}
int main(){
   ancestor_tree::make_person mainPerson;
   mainPerson.insert_name();
   mainPerson.insert_birthYear();
   mainPerson.insert_deathYear();
   mainPerson.insert_age();
    return 0;
}