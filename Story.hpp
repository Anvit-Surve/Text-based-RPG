#include <iostream>
using namespace std;
#define BGREEN "\u001b[32;1m"
#define BCYAN "\u001b[36;1m"
#define MAGENTA "\u001b[35m"
#define RESET "\u001b[0m"
void printBeginning(){
  cout << BGREEN;
  cout << "Hi Arthur..." << endl;
  cout << "Buckle up as you will be going on a QUEST" << endl;
  cout << "Quest to redeem your stolen Kingdom" << endl;
  cout << RESET;
  cout << MAGENTA;
  cout << "\n" ;
  system("read -p '...' var");
  cout.width(100);
  cout << BCYAN;
  cout << right << "What!!! My Kingdom! Who took it?\n" << endl;
  cout << RESET;
  cout << MAGENTA;
  cout << "\n" ;
  system("read -p '...' var");
  cout << BGREEN;
  cout << "MURLOCK!!!... The Dragon..." << endl;
  cout << RESET;
  cout << MAGENTA;
  cout << "\n" ;
  system("read -p 'Press Enter to continue...' var");
}