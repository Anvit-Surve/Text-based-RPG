#include <iostream>
using namespace std;

class Enemy
{
  protected:
    int health;
    int attackDamage;
    int additionalDamage;
    virtual void generateRandomAdditionalDamage()= 0;
    virtual int giveDamage()= 0;
    virtual void takeDamage(int damageRecieved) = 0;
  public:
    int getHealth(){return this->health;}
    Enemy(){}
};
class Minions:public Enemy{
  private:
    void generateRandomAdditionalDamage(){
      int additionalDamageMin = 1;
      int additionalDamageMax = 10;
     
      srand(time(0));
      
      additionalDamage = (rand() % (additionalDamageMax - additionalDamageMin)+additionalDamageMin);
    }
  public:
    Minions(){
      health = 50;
      attackDamage = 20;
      additionalDamage = 0;
    }
    int giveDamage(){
      generateRandomAdditionalDamage();
      int totalDamage = attackDamage + additionalDamage;
      cout.width(93);
      cout << right;
      cout<<"Baby Dragon Delt "<<attackDamage<<" Base Damage and"<<endl;
      cout.width(77);
      cout << right;
      cout<<additionalDamage<<" additional Damage to Arthur!"<<endl;
      cout.width(95);
      cout << right;
      cout<<"Total Damage Delt: "<<totalDamage; 
      return totalDamage;
    }
    void takeDamage(int damageRecieved){
      health = health - damageRecieved;
      if(health >0)
      {
        cout<<"\nBaby Dragon's Health after recieveing Damage:"<<health<<endl; 
      }
      else
      {
        cout<<"\n\nDefeated him... Lets Rush Ahead!"<<endl;
      }
    }
};
class Boss:public Enemy{
  private:
    void generateRandomAdditionalDamage(){
      int additionalDamageMin = 15;
      int additionalDamageMax = 30;
     
      srand(time(0));
      
      additionalDamage = (rand() % (additionalDamageMax - additionalDamageMin)+additionalDamageMin);
    }
  public:
    Boss(){
      health = 200;
      attackDamage = 30;
      additionalDamage = 0;
    }
    int giveDamage(){
      generateRandomAdditionalDamage();
      int totalDamage = attackDamage + additionalDamage;
      cout.width(93);
      cout << right;
      cout<<"Murlock did "<<attackDamage<<" Damage and "<<endl;
      cout.width(77);
      cout << right;
      cout << additionalDamage<<" additional Damage to Arthur!"<<endl;
      cout.width(95);
      cout << right;
      cout<<"Total Damage Delt: "<<totalDamage; 
      return totalDamage;
    }
    void takeDamage(int damageRecieved){
      health = health - damageRecieved;
      if(health >0)
      {
        cout<<"\nMurlock's Health after recieveing Damage:"<<health<<endl; 
      }
      else
      {
        cout<<"\n\nArthur has finally won the battle!"<<endl;
        cout<<"The Kingdom is taken back and safe in our hero's Hands!"<<endl;
        cout<<"Thanks for playing."<<endl;
      }
    }
};