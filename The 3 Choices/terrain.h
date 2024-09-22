#ifndef __TERRAIN_H_
#define __TERRAIN_H_
#include "spec_cond.h"
class terrain: public spec_cond{
    private:
   string n_environ;
   spec_cond environment;
   int difficulty=1;
    public:
    terrain(){}
    ~terrain(){}
    terrain(string nam, int h_a, int a_a, int s_a){
    n_environ=nam;
    environment.set_environ(h_a,a_a,s_a);
}
string get_n_environ(){
    return n_environ;
};
spec_cond get_environment(){
    return environment;
};
};
#endif
