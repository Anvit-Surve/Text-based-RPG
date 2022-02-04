#pragma once
#include <iostream>
#include <map>
using namespace std;

template<typename Map>
void printMap(Map& m)
{
  for (auto &item : m) {
      cout << item.first << " : " << item.second << " "<< endl;
  }
}

void initiateMap(){
  map<string, string> map1 = {{"Level 2", "Sword",},{"Level 3", "Sheild",},{"Level 4", "Armour",},{"Level 5", "Bow",},{"Level 6", "Murlock",}};
  printMap(map1);
}