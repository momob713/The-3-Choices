#ifndef __CHARACTER_H_
#define __CHARACTER_H_
#include <iostream>
#include "Skill.h"
using namespace std;

/// charatcer class

class Character {
private:
    //tracks current floor for entities
    int current_floor = 0;
    string name;
    int health = 100;
    int attack = 30;
    int speed = 20;
    Skill skill_set[3];
    bool abilitycooldown[3] = { false,false,false };
    int loot = 0;
    //number of turns the character has taken in a battle
    int turn = 1;
    //hold temporary effefts in battle
    ///h1,h2,h3,-h1,-h2,-h3,-a1,-a2,-a3,s1,s2,s3,-s1,-s2,-s3
    int temp_effects[15] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
public:
    //dead character constructor
    Character() {
        name = "#dead";
        skill_set[0] = Skill(0);
    }
    ~Character() {}
    //(name, health, attack, speed, skill 1, skill 2, skill3)
    Character(string n, int h, int a, int s, int q, int w, int e) {
        name = n;
        health = h;
        attack = a;
        speed = s;
        skill_set[0] = Skill(q);
        skill_set[1] = Skill(w);
        skill_set[2] = Skill(e);
    }
    Character(string n, int h, int a, int s) {
        name = n;
        health = h;
        attack = a;
        speed = s;
    }
    //monster gen t variable used to determine types of skills monster should get
    Character(int type, int floor) {
        //used to calculate extra attributes for mobs based off of difficulty
        int attr = 0;
        string t = "";
        if (floor % 6 == 5|| floor % 6 == 4|| floor % 6 == 3 && floor != 0) {
            attr = floor * 2;
        }
        else {
            attr = floor / 2;
        }
        int extraspeed = 0;
        int extrahealth = 0;
        int extraattack = 0;
        if (attr > 0) {
            double percent = 0;
            percent = rand();
            extraspeed = attr * percent;
            attr -= extraspeed;
            percent = rand();
            extrahealth = attr * percent;
            attr -= extrahealth;
            extraattack = attr;
        }
        //boss
        if (type == 0) {
            int bossType = rand() % 7;
            health = 180 + extrahealth;
            attack = 15 + extraattack;
            speed = 5 + extraspeed;
            if (bossType == 0) {
                name = "Dreadscale the Terrible";
                t = "Dreadscale";
            }
            else if (bossType == 1) {
                name = "Verdantus the Overgrowth";
                t = "Verdantus";
            }
            else if (bossType == 2) {
                name ="Swamp King Mortis";
                t = "Swamp King Mortis";
            }
            else if (bossType == 3) {
                name = "Leviathan, the Abyssal Horror";
                t = "Leviathan";
            }
            else if (bossType == 4) {
                name = "Inferno Lord Ignatius";
                t = "Ignatius";
            }
            else if (bossType == 5) {
                name = "Thunderhoof the Rampant";
                t = "Thunderhoof";
            }
            else if (bossType == 6) {
                name = "Frostbite, the Frozen Tyrant";
                t = "Frostbite";
            }
            else if (bossType == 7) {
                name = "Princess";
                t = "Princess";
            }
        }

        // Miniboss
        else if (type == 1) {
            int minibossType = rand() % 7;
            health = 120 + extrahealth;
            attack = 10 + extraattack;
            extraspeed = 15 + extraspeed;
            if (minibossType == 0) {
                name = "Razorback the Rhino";
                t = "Razorback";
            }
            else if (minibossType == 1) {
                name = "Tentaculus the Octopus";
                t = "Tentaculus";
            }
            else if (minibossType == 2) {
                name = "Frostclaw the Mammoth";
                t = "Frostclaw";
            }
            else if (minibossType == 3) {
                name ="Stormwing the Wyvern" ;
                t = "Stormwing";
            }
            else if (minibossType == 4) {
                name ="Bogchomp the Mirebeast" ;
                t = "Bogchomp";
            }
            else if (minibossType == 5) {
                name ="Emberclaw the Salamander" ;
                t ="Emberclaw" ;
            }
            else if (minibossType == 6) {
                name ="Thornscale the Vine Lasher" ;
                t = "Thornscale";
            }
        }

        // Trashmob
        else if (type == 2) {
            int trashmobType = rand() % 7;
            health = 60 + extrahealth;
            attack = 5 + extraattack;
            extraspeed = 10 + extraspeed;
            if (trashmobType == 0) {
                name= "Rhino";
                t = "Rhino";
            }
            else if (trashmobType == 1) {
                name ="Octopus" ;
                t = "Octopus";
            }
            else if (trashmobType == 2) {
                name = "Mammoth";
                t ="Mammoth" ;
            }
            else if (trashmobType == 3) {
                name ="Wyvern" ;
                t ="Wyvern" ;
            }
            else if (trashmobType == 4) {
                name ="Boggy Slime" ;
                t ="Boggy Slime" ;
            }
            else if (trashmobType == 5) {
                name ="Ebon Fiend" ;
                t ="Ebon Fiend" ;
            }
            else if (trashmobType == 6) {
                name = "Green Goliath";
                t = "Green Goliath";
            }
        }
        for (int i = 0; i < 3; i++) {
            Skill p = randomskillgen(t);
            for (int m = 0; m < i; m++) {
                while (p == skill_set[m]) {
                    p = randomskillgen(t);
                }
            }
            skill_set[i] = p;
        }
    }
        void  printskillset();
        Skill& get_skill(int w);
        string get_name();
        int get_health();
        int get_speed();
        int get_attack();
        void set_attack(int a);
        void set_health(int h);
        void set_speed(int s);
        int get_floor();
        void set_floor(int t);
        //take damage
        void tdamage(int d);
        //deal damage
        int ddamage(int d);
        bool operator==(Character const& Char);
        Skill randomskillgen(string t);
        void effects_reset();
        void turn_effect(int atr, int pow);
        int getCharacterTurn();
        void incCharacterTurn();
        void apply_effect (int n);
        void deapply_effect();
        void remove_effect();
        int get_effect(int n);
        void set_skill(int a, Skill skill);
        void skill_oc(int ability);
        void skill_cooldown();
        int getskillloot();
};

#endif
