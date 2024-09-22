#ifndef __SPEC_COND_H_
#define __SPEC_COND_H_
#include <iostream>
using namespace std;
//special conditions for skills and terrain
class spec_cond{
    public:
    spec_cond(){
    aff_health=0;
    aff_attack=0;
    aff_speed=0;
    }
   ~spec_cond(){}
   spec_cond(int h, int a, int s) {
    aff_health=h;
    aff_attack=a;
    aff_speed=s;
   }
   spec_cond(int h, int a, int s, int d) {

   }
int get_aff_health(){
    return aff_health;
   };
int get_aff_attack(){
    return aff_attack;
   };
int get_aff_speed(){
    return aff_speed;
   };
void set_environ(int h, int a, int s){
    aff_health=h;
    aff_attack=a;
    aff_speed=h;
}
void set_aff_health(int a){
    aff_health=a;
}
void set_aff_attack(int a){
    aff_attack=a;
}
void set_aff_speed(int a){
    aff_speed=a;
}
    private:
    int aff_health;
    int aff_attack;
    int aff_speed;
    int duration = -1;
};
#endif
