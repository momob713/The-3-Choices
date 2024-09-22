#ifndef __MAP_H_
#define __MAP_H_
#include "terrain.h"
class map: public terrain{
    public:
    map(){
        for (int i=0;i<3;i++){
        for (int j=0;j<9;j++){
            ///does this work
            Map[i][j]=terrain("grasslands", 0,0,0);
        }
    }
    }
    ~map(){}
    map(terrain m[3][9]){
        for (int i=0;i<3;i++){
        for (int j=0;j<9;j++){
            Map[i][j]=m[i][j];
        }
    }
    }
   terrain get_mapp(int i, int j){
    return Map[i][j];
       };
   string get_nterrain(terrain terrain){
   return terrain.get_n_environ();
   };
   private:
   terrain Map[3][9];
};
#endif
