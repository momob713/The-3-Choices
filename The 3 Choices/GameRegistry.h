#pragma once
#include "terrain.h"
#include "character.h"
#include <iostream>
class GameRegistry {
private:
    std::map<std::string, Skill> skills;
    std::vector<Monster> trashMobs;
    std::vector<Monster> miniBosses;
    std::vector<Monster> bosses;

public:
    // Function to add skills
    void addSkill(const std::string& name, const Skill& skill) {
        skills[name] = skill;
    }

    // Function to add characters
    void addCharacter(const std::string& name, const Character& character) {
        characters[name] = character;
    }

    // Functions to add monsters
    void addTrashMob(const Monster& mob) {
        trashMobs.push_back(mob);
    }

    void addMiniBoss(const Monster& boss) {
        miniBosses.push_back(boss);
    }

    void addBoss(const Monster& boss) {
        bosses.push_back(boss);
    }

    // Retrieve entities
    const Skill& getSkill(const std::string& name) {
        return skills[name];
    }

    const Character& getCharacter(const std::string& name) {
        return characters[name];
    }

    // Other retrieval and utility methods...
};

