#include "character.h"

string Character::get_name() {
    return name;
}
int Character::get_health() {
    return health;
}
int Character::get_speed() {
    return speed;
}
int Character::get_attack() {
    return attack;
}
void Character::set_health(int h) {
    health=h;
}
void Character::set_speed(int s) {
    speed = s;
}
void Character::set_attack(int a) {
    attack=a;
}
int Character::get_floor() {
    return current_floor;
}
void Character::set_floor(int t)
{
    current_floor = t;
}
void  Character::printskillset(){
    cout << "\n";
for (int i=0;i<3;i++){
    if (skill_set[i].getname() != "NA") {
        cout << endl << i + 1 << ". " << skill_set[i].getname() << endl << skill_set[i].getdescription() << endl;
        if (skill_set[i].getturns() == 0|| skill_set[i].getturns() == 1) {
            cout << "no cooldown" << endl;
        }
        else {
            cout<<skill_set[i].getturns()-1 << " turn(s) cooldown" << endl;
        }
        if (skill_set[i].getskill_aff().get_aff_attack() > 0)
            cout << skill_set[i].getname() << " deals " << skill_set[i].getskill_aff().get_aff_attack() * attack << " damage.";
        if (skill_set[i].getskill_aff().get_aff_attack() < 0)
            cout << skill_set[i].getname() << " applies attack " << skill_set[i].getskill_aff().get_aff_attack()<<" debuff to target. ";
        if (skill_set[i].getskill_aff().get_aff_health() > 0)
            cout << skill_set[i].getname() << " applies health " << skill_set[i].getskill_aff().get_aff_health()<<" buff to target. ";
        if (skill_set[i].getskill_aff().get_aff_health() < 0)
            cout << skill_set[i].getname() << " applies health " << skill_set[i].getskill_aff().get_aff_health() << " debuff to target. ";
        if (skill_set[i].getskill_aff().get_aff_speed() > 0)
            cout << skill_set[i].getname() << " applies speed " << skill_set[i].getskill_aff().get_aff_speed() << " buff to target. ";
        if (skill_set[i].getskill_aff().get_aff_speed() < 0)
            cout << skill_set[i].getname() << " applies speed " << skill_set[i].getskill_aff().get_aff_speed() << " debuff to target. ";

        if (skill_set[i].getcturns() == -1) {
            cout << " Skill usable!" << endl;
        }
        else {
            cout << " Skill usable in " << skill_set[i].getturns() - skill_set[i].getcturns() << " turn(s)."<<endl;
        }
    }
            }
        }
Skill& Character::get_skill(int w) {
    return skill_set[w];
};
//take damage
void Character::tdamage(int t) {
    health=health - t;
};
//deal damage
int Character::ddamage(int t) {
    return (skill_set[t].getskill_aff().get_aff_attack())*attack;
};
bool Character::operator==(Character const& Char) {
    return (health == Char.health) && (speed == Char.speed) && (attack == Char.attack)&&(name==Char.name);
};

Skill Character::randomskillgen(string t) {
    int skillType = 0;

    // Check the desired monster type and set the skill type accordingly
    if (t == "player") {
        // Randomly choose a skill type for the player-themed skills
        skillType = std::rand() % 6;  // Generates a random number between 0 and 5
    }
    // Boss skills
    else if (t == "Dreadscale") {
        // Randomly choose a skill type for the Dreadscale boss-themed skills
        skillType = (std::rand() % 6) + 6;  // Generates a random number between 6 and 11
    }
    else if (t == "Verdantus") {
        // Randomly choose a skill type for the Verdantus boss-themed skills
        skillType = (std::rand() % 6) + 12;  // Generates a random number between 13 and 18
    }
    else if (t == "Swamp King Mortis") {
        // Randomly choose a skill type for the Swamp King Mortis boss-themed skills
        skillType = (std::rand() % 6) + 18;  // Generates a random number between 19 and 24
    }
    else if (t == "Leviathan") {
        // Randomly choose a skill type for the Leviathan boss-themed skills
        skillType = (std::rand() % 6) + 24;  // Generates a random number between 25 and 30
    }
    else if (t == "Blaze Lord Ignis") {
        // Randomly choose a skill type for the Blaze Lord Ignis boss-themed skills
        skillType = (std::rand() % 6) + 30;  // Generates a random number between 31 and 36
    }
    else if (t == "Thunderhoof") {
        // Randomly choose a skill type for the Thunderhoof boss-themed skills
        skillType = (std::rand() % 6) + 36;  // Generates a random number between 37 and 42
    }
    else if (t == "Frostbite") {
        // Randomly choose a skill type for the Frostbite boss-themed skills
        skillType = (std::rand() % 6) + 42;  // Generates a random number between 43 and 48
    }
    else if (t == "Rhino") {
        // Randomly choose a skill type for the Rhino trashmob-themed skills
        skillType = (std::rand() % 5) + 48;  // Generates a random number between 49 and 54
    }
    else if (t == "Octopus") {
        // Randomly choose a skill type for the Octopus trashmob-themed skills
        skillType = (std::rand() % 5) + 53;  // Generates a random number between 55 and 60
    }
    else if (t == "Mammoth") {
        // Randomly choose a skill type for the Mammoth trashmob-themed skills
        skillType = (std::rand() % 5) + 58;  // Generates a random number between 60 and 65
    }
    else if (t == "Wyvern") {
        // Randomly choose a skill type for the Wyvern trashmob-themed skills
        skillType = (std::rand() % 5) + 63;  // Generates a random number between 65 and 70
    }
    else if (t == "Boggy Slime") {
        // Randomly choose a skill type for the Boggy Slime trashmob-themed skills
        skillType = (std::rand() % 5) + 68;  // Generates a random number between 70 and 75
    }
    else if (t == "Ebon Fiend") {
        // Randomly choose a skill type for the Ebon Fiend trashmob-themed skills
        skillType = (std::rand() % 5) + 73;  // Generates a random number between 75 and 89
    }
    else if (t == "Green Goliath") {
        // Randomly choose a skill type for the Green Goliath trashmob-themed skills
        skillType = (std::rand() % 5) + 78;  // Generates a random number between 90 and 94
    }
    else if (t == "Razorback") {
        skillType = (rand() % 6) + 83;
    }
    else if (t == "Tentaculus") {
        skillType = (rand() % 6) + 89;
    }
    else if (t == "Frostclaw") {
        skillType = (rand() % 6) + 95;
    }
    else if (t == "Stormwing") {
        skillType = (rand() % 6) + 101;
    }
    else if (t == "Bogchomp") {
        skillType = (rand() % 6) + 107;
    }
    else if (t == "Emberclaw") {
        skillType = (rand() % 6) + 113;
    }
    else if (t == "Thornscale") {
        skillType = (rand() % 6) + 119;
    }
    else if (t == "Princess") {
        skillType = (rand() % 6) + 125;
    }
    // Create the skill based on the selected type
    return Skill(skillType);
};
void Character::effects_reset() {
    for (int i = 0; i < 15; i++) {
        temp_effects[i] = 0;
    }
}
//pow 1 for buff 2 for debuffs      -1 for decrease
void Character::turn_effect(int atr, int pow) {
        double multiplier = 0;
        if (abs(pow) == 1) {
            multiplier = (1+ (((atr % 3)+1) * .1));
        }
        else if (abs(pow) == 2) {
            multiplier = (1 - (((atr % 3)+1) * .1));
        }
        if (pow > 0) {
            apply_effect(atr);
            if (0 <= atr && atr < 6) {
                set_health(round(health * multiplier));
            }
            if (6 <= atr && atr < 9) {
                set_attack(round(attack * multiplier));
            }
            if (9 <= atr && atr < 15) {
                set_speed(round(speed * multiplier));
            }
        }
        else if (pow < 0) {
            if (0 <= atr && atr < 6) {
                set_health(round(health / multiplier));
            }
            if (6 <= atr && atr < 9) {
                set_attack(round(attack / multiplier));
            }
            if (9 <= atr && atr < 15) {
                set_speed(round(speed / multiplier));
            }
        }
}
int Character::getCharacterTurn() {
    return turn;
}
void Character::incCharacterTurn() {
    turn++;
}
void Character::apply_effect(int n) {
    temp_effects[n] += 4;
    if (temp_effects[n] > 4) {
        temp_effects[n] = 4;
    }
}
void Character::deapply_effect(){
    for (int m = 0; m < 15; m++) {
        if (temp_effects[m] > 0) {
            if (temp_effects[m] - 1 == 0) {
                //need to change if more effects added
                if (m % 9 == 0 || m % 9 == 1 || m % 9 == 2) {
                    turn_effect(m, -1);
                }
                else {
                    turn_effect(m, -2);
                }
            }
            temp_effects[m]--;
        }
    }
}
void Character::remove_effect(){}
int Character::get_effect(int s) {
    return temp_effects[s];
}
void Character::set_skill(int a, Skill skill) {
    skill_set[a] = skill;
}
void Character::skill_oc(int ability) {
    get_skill(ability).useskill();
    abilitycooldown[ability] = true;
}
void Character::skill_cooldown() {
    for (int i = 0; i < (sizeof(abilitycooldown) / sizeof(bool)); i++) {
        if (abilitycooldown[i]==true) {
            if (get_skill(i).SKILLcooldown()) {
                abilitycooldown[i] = false;
            }
        }
    }
}
int Character::getskillloot() {
    int skillnum=rand() % 3;
    return get_skill(skillnum).get_skillid();
}
