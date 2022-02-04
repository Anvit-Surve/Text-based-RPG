#include <iostream>
using namespace std;

void newLevelPrint(int level){
  cout<<"\e[2J\e[H";
  cout<<"Level "<< level << " Begins" << endl;
}
