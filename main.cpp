#include <iostream>
#include "Game.hpp"
using namespace std;
#define MAGENTA "\u001b[35m"
#define RESET "\u001b[0m"

int main() {
  Game game;
  while(!game.getQuit()){
    game.Update();
  }
  cout << RESET;
  cout << MAGENTA;
  cout << "\n" ;
  system("read -p 'Press Enter to continue...' var");
	return 0;
}