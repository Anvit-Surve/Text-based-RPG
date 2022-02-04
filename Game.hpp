#pragma once
#include <iostream>
#include <vector>
#include "Story.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include "Levels.hpp"
#include "Map.hpp"
#define BRED "\u001b[33;1m"
#define RED "\u001b[31;9m"
#define BGREEN "\u001b[32;1m"
#define BCYAN "\u001b[36;1m"
#define RESET "\u001b[0m"
#define MAGENTA "\u001b[35m"
using namespace std;

class Game{
  private:
    //Variables
    bool quit;
    char choice;
  public:
    //Constructors and Destructors
    Game(){
      quit = false;
    };
    ~Game(){
      
    };
    //Accessor
    const bool& getQuit() const{
      return this->quit;
    }
    //Modifier

    //Functions
    void printMenu() const{
      cout<<"\e[2J\e[H";
      cout<<BRED;
      cout << "        ARTHUR'S QUEST        " << endl;
      cout << "<<< Main Menu >>>" << endl 
           << "(1) Start" << endl
           << "(0) Quit" << endl;
      cout << RESET;
    }
    const int getChoice() const{
      int choice = 0;
      cout << MAGENTA;
      cout << "Enter Choice: ";
      cin >> choice;
      return choice;
    }
    void battleLoop(Player *player, Minions *minion){
      char playerChoice;
      do{
        
        cout<<"\n______________________________________________________________________________________________________\n";
        cout<<"______________________________________________________________________________________________________\n\n";
        cout<< RESET;
        cout<< MAGENTA;
        cout<<"\nPress A to attack or Press H to heal "<<endl;
        cin >> playerChoice;
        cout<<"\e[2J\e[H";
        cout<< RESET;
        cout<< BRED;
        cout<<"\n______________________________________________________________________________________________________\n";
        cout<<"______________________________________________________________________________________________________\n";

        if(playerChoice == 'a' || playerChoice =='A')
        {
          cout<< RESET;
          cout<< BCYAN;
          minion->takeDamage(player->giveDamage());
          cout << RESET;
          cout << MAGENTA;
          if(player->getHealth()> 0 && minion->getHealth() > 0)
            {
              cout<< RESET;
              cout<< BRED;
              cout<<"\n______________________________________________________________________________________________________\n";
              cout<<"______________________________________________________________________________________________________\n\n";
              cout<< RESET;
              cout<< RED;
              cout.width(100);
              cout << right;
              cout<<"Dragon: It's my turn...!"<<endl;
              player->takeDamage(minion->giveDamage());
              cout<< RESET;
              cout<< BRED;
            }
        }
        else if(playerChoice == 'h' || playerChoice =='H')
        {
          cout<< RESET;
          cout<< BCYAN;
          player->healSpell();
          if(player->getHealth()> 0 && minion->getHealth() >0)
            {
              cout<< RESET;
              cout<< BRED;
              cout<<"\n______________________________________________________________________________________________________\n";
              cout<<"______________________________________________________________________________________________________\n\n";
              cout<< RESET;
              cout<< RED;
              cout.width(100);
              cout << right;
              cout<<"Dragon: It's my turn...!"<<endl;
              player->takeDamage(minion->giveDamage());
              cout<< RESET;
              cout<< BRED;
            }
        }
        else
        {
          cout<<"Invalid Input! , please give valid input"<<endl;
        }
        
      }while(player->getHealth()> 0 && minion->getHealth() >0);
    }
    void battleLoop(Player *player, Boss *enemy){
      char playerChoice;
      do{
        cout<<"\n______________________________________________________________________________________________________\n";
        cout<<"______________________________________________________________________________________________________\n\n";
        cout<< RESET;
        cout<< MAGENTA;
        cout<<"\nPress A to attack or Press H to heal "<<endl;
        cin >> playerChoice;
        cout<<"\e[2J\e[H";
        cout<< RESET;
        cout<< BRED;
        cout<<"\n______________________________________________________________________________________________________\n";
        cout<<"______________________________________________________________________________________________________\n";

        if(playerChoice == 'a' || playerChoice =='A')
        {
          cout<< RESET;
          cout<< BCYAN;
          enemy->takeDamage(player->giveDamage());
          cout << RESET;
          cout << MAGENTA;
          if(player->getHealth()> 0 && enemy->getHealth() > 0)
            {
              cout<< RESET;
              cout<< BRED;
              cout<<"\n______________________________________________________________________________________________________\n";
              cout<<"______________________________________________________________________________________________________\n\n";
              cout<< RESET;
              cout<< RED;
              cout.width(100);
              cout << right;
              cout<<"Murlock: It's my turn...!"<<endl;
              player->takeDamage(enemy->giveDamage());
              cout<< RESET;
              cout<< BRED;
            }
        }
        else if(playerChoice == 'h' || playerChoice =='H')
        {
          cout<< RESET;
          cout<< BCYAN;
          player->healSpell();

          if(player->getHealth()> 0 && enemy->getHealth() >0)
            {
              cout<< RESET;
              cout<< BRED;
              cout<<"\n______________________________________________________________________________________________________\n";
              cout<<"______________________________________________________________________________________________________\n\n";
              cout<< RESET;
              cout<< RED;
              cout.width(100);
              cout << right;
              cout<<"Murlock: It's my turn...!"<<endl;
              player->takeDamage(enemy->giveDamage());
              cout<< RESET;
              cout<< BRED;
            }
        }
        else
        {
          cout<<"Invalid Input! , please give valid input"<<endl;
        }
        
      }while(player->getHealth()> 0 && enemy->getHealth() >0);
    }
    void Update(){
      this->printMenu();
      switch(this->getChoice()){
        case 0:{
          cout<<"\e[2J\e[H";
          cout << BRED;
          cout << "<<< QUITTING GAME >>>" << endl;
          this->quit = true;
          break;
        }
        case 1:{
          cout<<"\e[2J\e[H";
          cout << "<<< STARTING GAME >>>" << endl;
          printBeginning();
          cout << RESET;
          cout << BCYAN;
          Player *player = new Player();
          cout << RESET;
          cout << MAGENTA;
          cout << "\n" ;
          system("read -p 'Press Enter to continue...' var");
          while(player->getLevel() > 0 && player->getLevel() < 7){
            switch(player->getLevel()){
              case 1:{
                cout<< RESET;
                cout<< BRED;
                newLevelPrint(player->getLevel());
                Minions *minion1 = new Minions();
                battleLoop(player, minion1);
                if(player->getWon() == true){
                  player->restoreStats();
                  player->setLevel(player->getLevel() + 1);
                  cout << RESET;
                  cout << BGREEN;
                  cout << "\n<<< ITEM RECEIVED: MAP >>>" << endl;
                  cout << RESET;
                  cout << MAGENTA;
                  cout << "\nPress 1 to open Map \nPress any other key to continue" << endl;
                  cout << RESET;
                  cout << BRED;
                  cin >> choice;
                  if (choice == '1'){
                    cout<<"\e[2J\e[H";
                    initiateMap();
                  }
                }else{
                  player->setLevel(-1);
                }
                cout << RESET;
                cout << MAGENTA;
                cout << "\n";
                system("read -p 'Press Enter to continue...' var");
                break;
              }
              case 2:{
                cout<< RESET;
                cout<< BRED;
                newLevelPrint(player->getLevel());
                Minions *minion21 = new Minions();
                battleLoop(player, minion21);
                cout<< RESET;
                cout<< BRED;
                Minions *minion22 = new Minions();
                battleLoop(player, minion22);
                if(player->getWon() == true){
                  player->restoreStats();
                  player->setLevel(player->getLevel() + 1);
                  cout << RESET;
                  cout << BGREEN;
                  cout << "\n<<< ITEM RECEIVED: SWORD(melee critical hit increased) >>>" << endl;
                  
                  player->setSword(true);
                }else{
                  player->setLevel(-1);
                }
                cout << RESET;
                cout << MAGENTA;
                cout << "\n";
                system("read -p 'Press Enter to continue...' var");
                break;
              }
              case 3:{
                cout<< RESET;
                cout<< BRED;
                newLevelPrint(player->getLevel());
                Minions *minion31 = new Minions();
                battleLoop(player, minion31);
                cout<< RESET;
                cout<< BRED;
                Minions *minion32 = new Minions();
                battleLoop(player, minion32);
                cout<< RESET;
                cout<< BRED;
                Minions *minion33 = new Minions();
                battleLoop(player, minion33);
                if(player->getWon() == true){
                  player->restoreStats();
                  player->setLevel(player->getLevel() + 1);
                  cout << RESET;
                  cout << BGREEN;
                  cout << "\n<<< ITEM RECEIVED: SHIELD(randomly blocks 50% attacks) >>>" << endl;
                  player->setShield(true);
                }else{
                  player->setLevel(-1);
                }
                cout << RESET;
                cout << MAGENTA;
                cout << "\n";
                system("read -p 'Press Enter to continue...' var");
                break;
              }
              case 4:{
                cout<< RESET;
                cout<< BRED;
                newLevelPrint(player->getLevel());
                Minions *minion41 = new Minions();
                battleLoop(player, minion41);
                cout<< RESET;
                cout<< BRED;
                Minions *minion42 = new Minions();
                battleLoop(player, minion42);
                cout<< RESET;
                cout<< BRED;
                Minions *minion43 = new Minions();
                battleLoop(player, minion43);
                if(player->getWon() == true){
                  player->restoreStats();
                  player->setLevel(player->getLevel() + 1);
                  cout << RESET;
                  cout << BGREEN;
                  cout << "\n<<< ITEM RECEIVED: ARMOUR(additional armour of 100) >>>" << endl;
                  player->setArmour(true);
                }else{
                  player->setLevel(-1);
                }
                cout << RESET;
                cout << MAGENTA;
                cout << "\n";
                system("read -p 'Press Enter to continue...' var");
                break;
              }
              case 5:{
                cout<< RESET;
                cout<< BRED;
                newLevelPrint(player->getLevel());
                Minions *minion51 = new Minions();
                battleLoop(player, minion51);
                cout<< RESET;
                cout<< BRED;
                Minions *minion52 = new Minions();
                battleLoop(player, minion52);
                cout<< RESET;
                cout<< BRED;
                Minions *minion53 = new Minions();
                battleLoop(player, minion53);
                cout<< RESET;
                cout<< BRED;
                Minions *minion54 = new Minions();
                battleLoop(player, minion54);
                if(player->getWon() == true){
                  player->restoreStats();
                  player->setLevel(player->getLevel() + 1);
                  cout << RESET;
                  cout << BGREEN;
                  cout << "\n<<< ITEM RECEIVED: BOW >>>" << endl;
                  player->setBow(true);
                }else{
                  player->setLevel(-1);
                }
                cout << RESET;
                cout << MAGENTA;
                cout << "\n";
                system("read -p 'Press Enter to continue...' var");
                break;
              }
              case 6:{
                cout<< RESET;
                cout<< BRED;
                newLevelPrint(player->getLevel());
                Boss *boss = new Boss();
                battleLoop(player, boss);
                if(player->getWon() == true){
                  player->setLevel(player->getLevel() + 1);
                }else{
                  player->setLevel(-1);
                }
                break;
              }
              default:
                break;
            }
          }
          this->quit = true;
          break;
        }
        default:{
          cout << "No such option in Menu" << endl;
          break;
        }
          
      }
    }
};