#include "terrain.h"
#include "map.h"
#include "Skill.h"
#include "character.h"
#include "spec_cond.h"
#include <iostream>
using namespace std;
void wait() {
    string pause = "";
    cout << "\nPress a key and enter to contine\n";
    cin>>pause;
}
///used to make sure attribute values are within limits
int ch_attr(int attr, const int limit){       ///checks if over or below max
        //if limit is 0 check
        if (limit <= 0) {
            if (attr < limit) {
                return limit;
            }
            if (attr > 0) {
                return attr;
            }
            return attr;
        }
        //if limit is not 0
        if (attr>limit){
            return limit;
        }
        if(attr<0){
            return 0;
        }
        return attr;
    }
///need to find solution for input control
int num_input_check(){
    bool good = false;
    string input="";
    int n_input = 0;
    while (!good) {
        good = true;
        cin >> input;
        for (int c = 0; c < input.length(); c++) {
            if (!isdigit(input[c])) {
                good=false;
                cout << "Invalid Input\n";
                break;
            }
        }
    }
    int b = input.length() - 1;
    for (int a = 0; a < input.length(); a++) {
        n_input += (int(input[a]) - '0') * pow(10, b);
        b--;
    }
    return n_input;
}
bool playercheck(Character* current_player, Character real_player) {
    if (*current_player == real_player) {
        return true;
    }
    return false;
}
//allocating attributes
void allocate_attributes(Character& player, int available) {
    int h_health = player.get_health();
    int h_attack = player.get_attack();
    int h_speed = player.get_speed();
    int t_num = available;
    int num_attribute = 0;
    string input = "";
    while (input != "confirm" && input != "Confirm") {
        std::cout << "Name: " << player.get_name() << endl << "Health: " << h_health << endl << "Attack: " << h_attack << endl << "Speed: " << h_speed << endl;
        std::cout << "available attributes: " << t_num << endl;
        std::cout << "Which attribute do you want to allocate points in? type confirm to confirm attributes and skills. Or reset attributes. must spend all attributes" << endl;
        cin >> input;
        if ((t_num == 0) && (input == "confirm" || input == "Confirm")) {
            std::cout << endl << endl << endl << "Name: " << player.get_name() << endl << "Health: " << h_health << endl << "Attack: " << h_attack << endl << "Speed: " << h_speed << endl;
            player.set_health(h_health);
            player.set_attack(h_attack);
            player.set_speed(h_speed);
            return;
        }
        if (input == "health" || input == "Health") {
            std::cout << "number of points in health?" << endl;
            num_attribute = num_input_check();
            num_attribute = ch_attr(num_attribute, t_num);    ///calls check
            h_health += num_attribute;
            t_num = t_num - num_attribute;
        }
        if (input == "attack" || input == "Attack") {
            std::cout << "number of points in attack?" << endl;
            num_attribute = num_input_check();
            num_attribute = ch_attr(num_attribute, t_num);
            h_attack += num_attribute;
            t_num = t_num - num_attribute;
        }
        if (input == "speed" || input == "Speed") {
            std::cout << "number of points in speed?" << endl;
            num_attribute = num_input_check();
            num_attribute = ch_attr(num_attribute, t_num);
            h_speed += num_attribute;
            t_num = t_num - num_attribute;
        }
        if (input == "reset" || input == "Reset") {
            std::cout << endl;
            h_health = player.get_health();
            h_attack = player.get_attack();
            h_speed = player.get_speed();
            t_num = available;
        }
        if (input != "reset" && input != "Reset" && input != "Speed" && input != "speed" && input != "attack" && input != "Attack" && input != "health" && input != "Health" && input != "confirm") {
            std::cout << "invalid input" << endl;
        }
    }
}
//initial skills
void allocate_skills(Character& player) {
    string input = "";
    bool go = false;
        cout << endl << endl << endl << "Your character will have 3 abilities at all times. Choose your 3 starting abilities by number." << endl;
        Skill one = Skill(0);
        Skill two = Skill(0);
        Skill three = Skill(0);
        while (!go) {
            string choice = "";
            for (int w = 0; w < 3; w++) {
                bool reset = false;
                int a = rand() % 18 - 12;
                int b = rand() % 18 - 12;
                int c = rand() % 18 - 12;
                cout << endl << endl << endl << "1:  ";
                Skill(a).printskill();
                cout << endl << "2:  ";
                Skill(b).printskill();
                cout << endl << "3:  ";
                Skill(c).printskill();
                cout << "\n";
                choice = "";
                int chosen = 0;
                while (choice != "1" && choice != "2" && choice != "3") {
                    cin >> choice;
                }
                if (choice == "1") {
                    chosen = a;
                }
                else if (choice == "2") {
                    chosen = b;
                }
                else if (choice == "3") {
                    chosen = c;
                }
                if (w == 0) {
                    one = Skill(chosen);
                }
                if (w == 1) {
                    two = Skill(chosen);
                }
                if (w == 2) {
                    three = Skill(chosen);
                }
            }
            std::cout << endl<<"do you want to start with these skills? yes or no"<<endl;
            one.printskill();
            two.printskill();
            three.printskill();
            //possible issue with acII count
            while (choice != "yes" && choice != "no") {
                cin >> choice;
            }
            if (choice == "yes") {
                go = true;
            }
        }
        player.set_skill(0, one);
        player.set_skill(1, two);
        player.set_skill(2, three);
    }
///character creation
Character create_character(){
    ///ask for character name

        string name="character";
        std::cout<<"\n\nWhat is your character's name?"<<endl;
        cin>> name;
        if(name=="test"){
            Character player= Character("Test", 100, 30, 30, -100, -99, -98);
            return player;
        }

///create player
        std::cout<<endl<<"Health determines how many damage points you can take before death."<<endl<<"Attack determines the damage you can do with attacks."<<endl<<"Speed determines when you can take a turn in battle"<<endl;
        std::cout<<"You have 20 attribute points to spend. Where do you want to allocate them? State the desired attribute, enter, and then the desired number of points you want to go into that attribute."<<endl;
        Character player = Character(name, 100, 10, 10,0,0,0);
        allocate_attributes(player,30);
        allocate_skills(player);
        return player;
}
///location generator
terrain randomterrain(){
    int i=rand()%10+1;
        if(i==1) {terrain v("Dessert",-1, 0,0);
        return v;}
        if(i==2) {terrain v("grasslands",1,0,0);
        return v;}
        if(i==3) {terrain v("Marsh",0,0,-1);
        return v;}
        if(i==4) {terrain v("Underwater",0,-2,-2);
        return v;}
        if(i==5) {terrain v("Underwold",0,-3,-1);
        return v;}
        if(i==6) {terrain v("Savannah",0,0,2);
        return v;}
        if(i==7) {terrain v("Snowy plains",-3,0,-3);
        return v;}
        if(i==8){terrain v("grasslands",1,0,0);
        return v;}
        if(i==9){terrain v("grasslands",1,0,0);
        return v;}
        if(i==10){terrain v("grasslands",1,0,0);
        return v;}
        ///cases
        terrain v("grasslands",1,0,0);
        return v;
}
//world creation
map world_create(){
///map creation first part
    terrain t_map[3][9];
    for (int i=0;i<3;i++){
        for (int j=0;j<9;j++){
            t_map[i][j]=randomterrain();
        }
    }
    map tmap= map(t_map);
    return tmap;
}
void battlestate(Character arena[], int asize) {
    cout << endl << "Battle state:" << endl;
    for (int q = 0; q < asize; q++) {
        cout << endl << "Name: " << arena[q].get_name();
        cout << endl << "Health: " << arena[q].get_health() << "     Attack: " << arena[q].get_attack() << "       Speed: " << arena[q].get_speed();
        //current buffs
        cout << endl << "Buffs: ";
        for (int t = 0; t < 3; t++) {
            if (arena[q].get_effect(t) > 0) {
                cout << "  Health " << t % 3 + 1 << " lasts for " << arena[q].get_effect(t) << " turn(s)";
            }
        }
        for (int t = 9; t < 12; t++) {
            if (arena[q].get_effect(t) > 0) {
                cout << "  Speed " << t % 3 + 1 << " lasts for " << arena[q].get_effect(t) << " turn(s)";
            }
        }
        //current debuffs
        cout << endl << "Debuffs: ";
        for (int t = 3; t < 6; t++) {
            if (arena[q].get_effect(t) > 0) {
                cout << "  Health " << t % 3 + 1 << " lasts for " << arena[q].get_effect(t) << " turn(s)";
            }
        }
        for (int t = 6; t < 9; t++) {
            if (arena[q].get_effect(t) > 0) {
                cout << "  Attack " << t % 3 + 1 << " lasts for " << arena[q].get_effect(t) << " turn(s)";
            }
        }
        for (int t = 11; t < 14; t++) {
            if (arena[q].get_effect(t) > 0) {
                cout << "  Speed " << t % 3 + 1 << " lasts for " << arena[q].get_effect(t) << " turn(s)";
            }
        }

    }
}
int abilitychoice(Character* current_player) {
    //player chooses ability and target if it is their turn
    int achoice = -1;
        while ((achoice < 1 || achoice >= 4) || current_player->get_skill(achoice - 1).getname() == "NA" || current_player->get_skill(achoice - 1).getcturns() != -1) {
            cout << endl << "\nwhat ability do you want to use? by number, or press 0 to pass.";
            cout << endl;
            achoice=num_input_check();
            //pass check
            if (achoice == 0) {
                break;
            }
        }
        return achoice-1;
}
int targetchoice(Character arena[], int asize) {
    int tchoice = 0;
        while ((tchoice < 1 || tchoice >= asize)) {
            cout << endl << "\npick a target. " << endl;
            for (int o = 1; o < asize; o++) {
                if (arena[o].get_health() != 0) {
                    cout << endl << o << ". " << arena[o].get_name() << endl;
                }
            }
            cin >> tchoice;
    }
    return tchoice;
}
void ability_effects(Character* current_player, int ability, Character& target) {
    ///ability/target effect (Chatgpt implementation some)
    int targetHealthBefore = target.get_health();
    int casterHealthBefore = current_player->get_health();
    int targetAttackBefore = target.get_attack();
    int casterAttackBefore = current_player->get_attack();
    int targetSpeedBefore = target.get_speed();
    int casterSpeedBefore = current_player->get_speed();
    // calculate buffs and debuffs (Chatgpt implement some)
    int attackEffect = current_player->get_skill(ability).getskill_aff().get_aff_attack();
    int healthEffect = current_player->get_skill(ability).getskill_aff().get_aff_health();
    int speedEffect = current_player->get_skill(ability).getskill_aff().get_aff_speed();
    if (healthEffect > 0) {
        current_player->turn_effect(-1 + healthEffect, 1);
    }
    else if (healthEffect < 0) {
        target.turn_effect(2 + abs(healthEffect), 2);
    }
    if (speedEffect > 0) {
        current_player->turn_effect(8 + abs(speedEffect), 1);
    }
    else if (speedEffect < 0) {
        target.turn_effect(11 + abs(speedEffect), 2);
    }
    if (attackEffect > 0) {
        int damage = current_player->get_attack() * attackEffect;
        target.tdamage(damage);
    }
    //apply effects
    else if (attackEffect < 0) {
        target.turn_effect(5 + abs(attackEffect), 2);
    }
    // Print the skill's effect on the target and caster
    cout << endl << endl << current_player->get_name() << " uses " << current_player->get_skill(ability).getname() << " on " << target.get_name() << ".";
    cout << endl << "Skill effect on " << target.get_name() << ":";
    if (targetHealthBefore >> target.get_health()) {
        cout << " Takes " << targetHealthBefore - target.get_health() << " damage.";
    }
    if (target.get_health() < targetHealthBefore && healthEffect > 0) {
        cout << "Max Health reduced by " << targetHealthBefore / target.get_health() << " for 2 turns ";
    }
    else if (target.get_health() > targetHealthBefore) {
        cout << "Max Health increased by " << target.get_health() - targetHealthBefore << " for 2 turns ";
    }

    if (target.get_attack() < targetAttackBefore) {
        cout << " Attack reduced by " << targetAttackBefore - target.get_attack() << " for 2 turns ";
    }
    else if (target.get_attack() > targetAttackBefore) {
        cout << " Attack increased by " << target.get_attack() - targetAttackBefore << " for 2 turns ";
    }

    if (target.get_speed() < targetSpeedBefore) {
        cout << " Speed reduced by " << targetSpeedBefore - target.get_speed() << " for 2 turns ";
    }
    else if (target.get_speed() > targetSpeedBefore) {
        cout << " Speed increased by " << target.get_speed() - targetSpeedBefore << " for 2 turns ";
    }

    cout << endl << "Skill effect on " << current_player->get_name() << ":";
    if (current_player->get_health() < casterHealthBefore) {
        cout << " Health reduced by " << casterHealthBefore - current_player->get_health() << " for 2 turns ";
    }
    else if (current_player->get_health() > casterHealthBefore) {
        cout << " Health increased by " << current_player->get_health() - casterHealthBefore << " for 2 turns ";
    }

    if (current_player->get_attack() < casterAttackBefore) {
        cout << " Attack reduced by " << casterAttackBefore - current_player->get_attack() << " for 2 turns ";
    }
    else if (current_player->get_attack() > casterAttackBefore) {
        cout << " Attack increased by " << current_player->get_attack() - casterAttackBefore << " for 2 turns ";
    }

    if (current_player->get_speed() < casterSpeedBefore) {
        cout << " Speed reduced by " << casterSpeedBefore - current_player->get_speed() << " for 2 turns ";
    }
    else if (current_player->get_speed() > casterSpeedBefore) {
        cout << " Speed increased by " << current_player->get_speed() - casterSpeedBefore << " for 2 turns ";
    }
}
void buff_and_debuffs(Character* current_player) {
    //may add parts later
        current_player->deapply_effect();
}
void turn_cooldowns(Character* current_player) {
    //may add parts later
    current_player->skill_cooldown();
}
bool battle(Character arena[], int asize) {
    //keeps track of which characters have skills on cooldown
    //turn keeps track of the amount of turns taken in the battle
    int turn = 1;
    //a round is 5 total turns
    int round = 1;
    //keep track if the player is alive
    bool alive = true;
    cout << endl <<"BATTLE!!!" << endl << "you are facing: ";
    //prints who is in the arena
    for (int o = 1; o < asize; o++) {
        cout <<"  " << o << "." << arena[o].get_name();
    }
    //each index of turns holds the "pace" of a player
//turns variable is the current turn pace for each player
//oturns variable simulates the pace of each player for different turns
    int turns[4] = { 0,0,0,0 };
    int oturns[4] = { 0,0,0,0 };
    //array to show who the battke order
    Character* order[5];
    //variables help turn have correct value
    int p = 0;
    int sp = 0;
    Character* current_player;
    //main loop of battle
    while (asize > 1 && alive) {
        cout << endl << "Round " << round << endl;
        //gets the current battleorder and pointer to next player
        int ord = 0;
        //updates oturns to be in line with the previous turn
        for (int a = 0; a < 4; a++) {
            oturns[a] = turns[a];
        }
        p = sp;
        //figues out who goes next for the next 4 turns
        while (ord < 5) {
            if (p >= asize) {
                p = 0;
            }
            oturns[p] += arena[p].get_speed();
            if (oturns[p] >= 100) {
                oturns[p] = oturns[p] % 100;
                order[ord] = &arena[p];
                if (ord == 0) {
                    for (int x = 0; x < 4; x++) {
                        turns[x] = oturns[x];
                    }
                    sp = p + 1;
                }
                ord++;
            }
            p++;
        }
        cout << "\nbattle order: \n";
        //prints order
        for (int a = 0; a < 5; a++) {
            cout << a + 1 << ". " << order[a]->get_name() << "\n";
        }
        cout << "\n" << order[0]->get_name() << "'s turn "<<order[0]->getCharacterTurn()<<":\n";
        //mechanic planning to implement later
        order[0]->incCharacterTurn();
        //current_player
        current_player = order[0];
        battlestate(arena, asize);
        wait();
        //ability and target variable
        int ability = -1;
        int target = -1;
        //print skillset of current player
        current_player->printskillset();
        bool confirm = false;
        //player turn
        bool pass = false;
        if (playercheck(current_player, arena[0])) {
            while (!confirm) {
                ability = abilitychoice(current_player);
                string conf = "";
                if (ability != -1) {
                    target = targetchoice(arena, asize);
                    cout << "\nUse " << arena[0].get_skill(ability).getname() << " on " << arena[target].get_name() << ". 1 to confirm, 0 to redo." << endl;
                    while (conf != "1" && conf != "0") {
                        cin >> conf;
                    }
                }
                    if (conf == "1"||ability==-1) {
                        confirm = true;
                    }
            }
        }
        //enemy turn
        else {
            int tries = 0;
            ability = rand() % 3;
            while (current_player->get_skill(ability).getcturns() != -1&&tries<15) {
                ability = rand() % 3;
                tries++;
            }
            target = 0;  // Target the player (arena[0])
            if (tries == 15) {
                ability = -1;
            }
        }
        //ability=-1= pass
        if (ability != -1) {
            ability_effects(current_player, ability, arena[target]);
            ///put ability on cooldown
            current_player->skill_oc(ability);
            ///adjust arena array based off of death
            ///flip the target in arena with the last character in arena then decrese the asize variable by one
            if (arena[target].get_health() <= 0) {
                cout << endl << arena[target].get_name() << " has been defeated" << endl;
                if (target == 0) {
                    alive = false;
                }
                Character hold = arena[target];
                arena[target] = arena[asize - 1];
                arena[asize - 1] = hold;
                asize--;
            }
            else {
                cout << endl << arena[target].get_name() << " now has " << arena[target].get_health() << " health." << endl;
            }
            //end of round effects
                     //buff and debuff effect
            buff_and_debuffs(current_player);
        }
        else {
            cout << current_player->get_name() << " passed.\n";
        }
          //turn cooldowns
        turn_cooldowns(current_player);
        turn++;
        if (turn % 5 == 1) {
            round++;
        }
    }
    //end of battle checks
    bool pass = false;
    if (asize == 1 && alive) {
        cout << endl << "VICTORY!!!" << endl;
        pass = true;
    }
    else if (!alive) {
        cout << endl << "DEFEAT" << endl;
    }
    return pass;
}
void loot(Character player) {
    cout << endl << "LOOT!!!";
}
//used to determine rewards after encounter
void encounterskillrewards(Character& player,int reward) {
    int choice = -1;
    Skill Reward = Skill(reward);
    cout << "\n\nNew Skill:";
    Reward.printskill();
    cout << "\nOld Skills:";
    player.printskillset();
    cout << "Pick a skill by number or press 0 to replace no skill.\n3";
    while (choice != 0 && choice != 1 && choice != 2 && choice != 3) {
        choice = num_input_check();
    }
    if (choice!= 0) {
        player.set_skill(choice-1, Reward.get_skillid());
    }
}
//used to get skill options, and skill choice
int skillrewards(Character arena[]) {
    int choices[3];
    int choice = 4;
    int c = 1;
    //choices not working
    for (int i = 1; i < 4; i++) {
        if (arena[i].get_name() != "#dead" && arena[i].get_name() != "NA") {
            choices[i - 1] = arena[i].getskillloot();
            cout << "\n\nChoice " << i << ": ";
            Skill(choices[i - 1]).printskill();
            c++;
        }
    }

    cout<<"\nPick skill by number\n";
    while (choice != 1 && choice != 2 && choice != 3) {
        choice = num_input_check();
        if (arena[3].get_name() == "#dead" && choice == 3) {
            choice = 0;
        }
    }
        return Skill(choices[choice - 1]).get_skillid();
}
//create battle
int cbattle(Character player){
    int pass = -101;
    int floor = player.get_floor();
    //entities in the battle
    Character arena[4];
    if (floor == 0||floor == 1||floor==2) {
        arena[0] = player;
        arena[1] = Character(2,floor);
        arena[2] = Character(2,floor);
        arena[3] = Character();
        if (battle(arena, 3)) {
            pass = skillrewards(arena);
        }
    }
    //check for boss level
    else if (floor % 9 == 0) {
        arena[0] = player;
        arena[1] = Character(2,floor);
        arena[2] = Character(0,floor);
        arena[3] = Character(2,floor);
        if (battle(arena, 4)) {
            pass = skillrewards(arena);
        }
    }
    //check for miniboss level
    else if (floor % 3==0) {
        arena[0] = player;
        arena[1] = Character(2,floor);
        arena[2] = Character(1,floor);
        arena[3] = Character(2,floor);
        if (battle(arena,4)) {
            pass = skillrewards(arena);
        }
    }
    else {
        //normal fight
        arena[0] = player;
        arena[1] = Character(2, floor);
        arena[2] = Character(2, floor);
        arena[3] = Character(2, floor);
        if (battle(arena, 4)) {
            pass = skillrewards(arena);
        }
    }
    return pass;
}

//encounters
bool encounter(Character& player, terrain location){
    bool pass = false;
    ///type of encounter
    //change rnd 2 to 3 to incorporate loot
    int encounter_roll = rand() % 3 + 1;
    ///loot
    if (encounter_roll == 3) {
        loot(player);
        pass = true;
        return pass;
    }
    ///battle
    if (encounter_roll ==1 || encounter_roll == 2) {
        int reward=cbattle(player);
        if (reward!=-101) {
            pass = true;
            encounterskillrewards(player, reward);
            if (player.get_floor() % 3 == 0) {
                allocate_attributes(player, 2 * (player.get_floor()+1));
            }
        }
        return pass;
    }
    return pass;

}

terrain move_to_terrain(map& world, int floor) {
    if (floor > 8 && (floor) % 9 == 0) {
        world = (world_create());
    }
    cout << endl << "You have 3 choices: " << endl << world.get_nterrain(world.get_mapp(0, floor % 9)) << "(1)    " << world.get_nterrain(world.get_mapp(1, floor % 9)) << "(2)   " << world.get_nterrain(world.get_mapp(2, floor % 9)) << "(3)";
    cout << endl << "Where do you want to go? 1,2, or 3" << endl;
    bool b = true;
    int c = 1;
    //terrain choices
    string a = "";
    while (b) {
        cin >> a;
        if (a == "1" || a == "2" || a == "3") {
            if (a == "1") c = 0;
            if (a == "2") c = 1;
            if (a == "3") c = 2;
            b = false;
        }
        else { cout << endl << "invalid input" << endl; }
    }
    terrain current_terrain = world.get_mapp(c, floor % 9);
    cout << endl << endl << "Floor " << floor << endl << current_terrain.get_n_environ() << endl;
    return current_terrain;
}

void journey(Character &player, map world) {
    cout << endl << endl << player.get_name() << "'s journey beigins!!!";
    terrain terrain_on = terrain();
    bool alive=true;
    while (alive) {
        move_to_terrain(world, player.get_floor());
        if (!encounter(player, terrain_on)) {
            alive = false;
        }
        else {
            player.set_floor(player.get_floor() + 1);
        }
    }

}

void Tutorial() {
    cout << "This game is a turn-based action rpg game. You create a character and set off into the world of three. At every step you will have 3 choices(for the most part). First, you will make a character. Your character has attributes and skills. At the beginning of the game you will start with a certain number";
    cout << "of attributes. You will also have a certain number of attributes to allocate to your character. The 3 attributes are health attack and speed. Health is your life line. If it reaches 0, you die. Attack is how much power you can out behind your attacks. The more power, the more damage your attacks will do.";
    cout << "Speed influences how how often you can take a turn. The higher the speed, the more often you can take a turn. You use these turns to pick a skill to use on your self or enemies. Where do you take these turn? You take them in battle. How do you get into a battle? You travel the world. How do you travel the world. You pick one of 3 choices when prompted. Once you reach a pick a path you will enter a battle with enemies.";
    cout << "Enemies can be seen as just like you. They have attributes and skills too. Each floor will have at the most 3 opponents, but no opponent is alike. Some are far stronger than others, and two opponents of the same type can have different attributes and skills. If you die during battle, you will be give the choice to restart with your current character or restart entirely. However, if you win the battle, you will be given the option to replace one of your skills with one of the skills of your defeated opponents.";
    cout << "You will thgen be given attributes to allocate based on the difficulty of your victory. This process of choosing a path and the fighting will continue until you lose, leave to do something else, or the game crashes because of an error.";
    cout << "\n\n Skill details: There are over 50 skills to aqquire and each one is unique(for the most part). The skills come with three practical attributes. The first attribute or number represents the skills effect on health. If the number is positive it will give you a temporary shield. This shield does not work like other games. It works more like a damage mitigator. your real health will still take damage when you take damage but it won't be as much damage. If the health attribute is negative, you will apply a vulnrebility debuff on your target, which makes them take more damage. ";
    cout << "The second attribute is the attack power. A positive number will represents a multiplier which is applied to your attack power and then calculated as damage for the skills attack. A negative number is an attack debuff on your target. The last attribute is speed. a positive number gives you a speed buff, and a negative number gives your target a speed debuff. Skills also have cooldowns that decrease when the caster takes a turn.";
    return;
}

int main(){
srand(time(0));
//keep character
bool current_character = true;
//new map
bool current_map = true;
//run game check
bool game=true;
//create initial character and world
bool tutorial = true;
cout << "Welcome to The 3 Choices!!!\nDo you want to play the tutorial? 1 yes, 0 no.\n";
    tutorial = num_input_check();
    if (tutorial) {
        Tutorial();
    }
Character player = create_character();
map world = (world_create());
///run game loop
while (game) {
    if (!current_character) {
        player = create_character();
        current_character = true;
    }
    if (!current_map) {
        world = world_create();
        current_map = true;
    }
    journey(player, world);
    //end game checks
    cout << endl << "1 for exit, 2 for start over with current character, 3 start over completley";
    string wait = "";
    cin >> wait;
    //exit game
    if (wait == "1") {
        game = false;
    }
    //start over with current character
    if (wait == "2") {
        current_character = false;
    }
    //start over completley
    if (wait == "3") {
        current_character = false;
        current_map = false;
    }
}
return 1;
}
