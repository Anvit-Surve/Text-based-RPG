#pragma once
#include <iostream>
#include <vector>
#include <string>
#define RESET "\u001b[0m"
#define MAGENTA "\u001b[35m"
#define RED "\u001b[31;9m"
using namespace std;

class Player{
  private:
  //Variables
  int health = 100;
  int maxHealth;
  int meleeDamage = 20;
  int level = 1;
  int rangedDamage = 25;
  int defence = 100;
  int maxDefence;
  int additionalDamage = 0;
  int heal;
  bool sword = false;
  bool bow = false;
  bool won = false;
  bool shield = false;
  bool armour = false;
  public:
  //Constructors and Destructors
  Player(){
    maxHealth = health;
    maxDefence = defence;
    displayPlayerInfo();
  }
  ~Player(){}
  //Accessors
  int getHealth(){
    return health;
  }
  int getLevel(){
    return level;
  }
  int getWon(){
    return won;
  }
  //Modifiers
  void setLevel(int level){
    this->level = level;
  }
  void setWon(bool won){
    this->won = won;
  }
  void setSword(bool sword){
    this->sword = sword;
  }
  void setBow(bool bow){
    this->bow = bow;
  }
  void setShield(bool shield){
    this->shield = shield;
  }
  void setArmour(bool armour){
    this->armour = armour;
  }
  //Functions
  int generateRandomNumber(int min, int max){
    srand(time(0));
    return rand() % (max - min + 1) + min;
  }
  void generateRandomAdditionalDamage(){
    int additionalDamageMin;
    int additionalDamageMax;
    if(sword == true){
      additionalDamageMin = 15 ;
      additionalDamageMax = 30;
    }
    else{
      additionalDamageMin = 5 ;
      additionalDamageMax = 15;
    }
    srand(time(0));
    additionalDamage = (rand() % (additionalDamageMax - additionalDamageMin + 1) + additionalDamageMin);
  }
  void displayPlayerInfo(){
    if(this->level < 3){
      cout<<"\e[2J\e[H";
      cout<<"\nHi I am Arthur! We need to defeat Murlock and get back our Kingdom"<<endl;
      cout<<"Here are some of my stats"<<endl;
      cout<<"\nHealth: "<<health<<endl;
      cout<<"\nMelee Damage: "<<meleeDamage<<endl;
      cout<<"\nLevel: "<<level<<endl;
      cout<<"\nRanged Damage: "<<rangedDamage<<endl;
      cout<<"\nAddtional Damage: 5 to 15"<<endl;
      cout<<"\nHealing : 15 to 30"<<endl;
    }
    else{
      cout<<"\e[2J\e[H";
      cout<<"\nHi I am Arthur! We need to defeat Murlock and get back our Kingdom"<<endl;
      cout<<"Here are some of my stats"<<endl;
      cout<<"\nHealth: "<<health<<endl;
      cout<<"\nMelee Damage: "<<meleeDamage<<endl;
      cout<<"\nLevel: "<<level<<endl;
      cout<<"\nRanged Damage: "<<rangedDamage<<endl;
      cout<<"\nAddtional Damage: 5 to 15"<<endl;
      cout<<"\nSheild: "<<defence<<endl;
      cout<<"\nHealing : 15 to 30"<<endl;
    }
  }
  int giveDamage(){
    int totalDamage;
    generateRandomAdditionalDamage();
    if(bow == true){
      totalDamage = rangedDamage + additionalDamage; 
      cout<<"\nArthur hit "<<rangedDamage<<" Ranged Damage and "<<additionalDamage<<" additional Damage to Dragon!"<<endl;
    }
    else{
      totalDamage = meleeDamage + additionalDamage; 
      cout<<"\nArthur hit "<<meleeDamage<<" Melee Damage and "<<additionalDamage<<" additional Damage to Dragon!"<<endl;
    }
    cout<<"Total Damage Delt: "<<totalDamage;
    return totalDamage;
  }
  void takeDamage(int damageRecieved){
    if(shield == true){
      switch(generateRandomNumber(1,4)){
        case 1: {
          if(armour == true && defence > 0){
            defence -= damageRecieved;
          }else{
            health -= damageRecieved;
          }
          break;
        }
        case 2: {
          cout << "\n<<< Attack Blocked >>>" << endl;
          break;
        }
        case 3: {
          cout << "\n<<< Attack Blocked >>>" << endl;
          break;
        }
        // case 3: {
        //   if(armour == true && defence > 0){
        //     defence -= damageRecieved;
        //   }else{
        //     health -= damageRecieved;
        //   }
        //   break;
        // }
        default: {
          if(armour == true && defence > 0){
            defence -= damageRecieved;
          }else{
            health -= damageRecieved;
          }
          break;
        }
      }
    }
    else{
      if(armour == true && defence > 0){
        defence -= damageRecieved;
      }else{
        health -= damageRecieved;
      }
    }
    if(armour == true && defence > 0){
      this->won = true;
      cout<< RESET;
      cout<< BCYAN;
      cout<<"\nArthur's Armour After recieving Damage: "<<this->defence<<endl;
      cout.width(100);
      cout << right;
      cout<<"\nArthur's Health After recieving Damage: "<<this->health<<endl;
      cout<< RESET;
      cout<< RED;
    }
    else if(health > 0){
      this->won = true;
      cout<< RESET;
      cout<< BCYAN;
      cout<<"\nArthur's Health After recieving Damage: "<<this->health<<endl;
      cout<< RESET;
      cout<< RED;
    }else{
      this->won = false;
      cout<< RESET;
      cout<< BCYAN;
      cout<<"\nHere i Come....................!"<<endl;
      cout<<RESET;
      cout<<RED;
      cout.width(100);
      cout << right;
      cout<<"Last words of our Hero :("<<endl;
      cout.width(100);
      cout << right;
      cout<<"Damage Given: "<<damageRecieved<<endl;
      cout.width(100);
      cout << right;
      cout<<"Arthur's Health after recieving Damage: 00"<<endl;
      cout.width(100);
      cout << right;
      cout<<"Our great warrior sacrificed himself for the kingdom"<<endl;
      cout<<"Game Over.....:( \nThanks for playing!";
    }
  }
  void healSpell(){
    int minHealCapacity = 10;
    int maxHealCapacity = 20; 

    srand(time(0));
    int randomHeal = (rand()% (maxHealCapacity - minHealCapacity + 1 ) + minHealCapacity);

    health = health + randomHeal;

    cout<<"Arthur Healed by:"<<randomHeal<<endl;
    cout<<"Health after healing:"<<health<<endl;
  }
  void restoreStats(){
    this->health = maxHealth;
    this->defence = maxDefence;
  }
};