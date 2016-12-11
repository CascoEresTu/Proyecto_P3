#include "Boss.h"

using namespace std;

Boss::Boss(){

}

Boss::~Boss(){
    cout << "Boss ded, lol." <<endl;
}

Boss::Boss(string nombre, int hp){
  name = nombre;
  HP = hp;
}

void Boss::setHP(double hp){
  HP=hp;
}

double Boss::getHP(){
  return HP;
}
