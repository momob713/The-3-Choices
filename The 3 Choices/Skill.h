#ifndef SKILL_H
#define SKILL_H
#include <iostream>
#include "spec_cond.h"
using namespace std;

class Skill : public spec_cond {
    public:
    Skill(){
        name="NA";
        description="";
        turns=0;
        skill_aff = spec_cond();
        id = 0;
    }
    ~Skill(){}
    //skill book
    Skill(int s) {
        id = s;
        //test skills
        if (s >= -100 && s <= -98) {
            if (s == -100) {
                description = "Summon a spectral blade to slash your enemies.";
                name = "test1";
                turns = 0;
                skill_aff = spec_cond(1, 4, 0); // (Health: 0, Attack: 3, Speed: 0)
            }
            else if (s == -99) {
                description = "Conjure a shield of darkness to protect yourself from damage.";
                name = "test2";
                turns = 2;
                skill_aff = spec_cond(2, 0, 3); // (Health: 0, Attack: 0, Speed: 1)
            }
            else if (s == -98) {
                description = "Release a blast of icy breath, damaging an enemies and reducing their speed.";
                name = "test3";
                turns = 1;
                skill_aff = spec_cond(0, 4, 0); // (Health: 0, Attack: 2, Speed: -1)
            }
        }
        //player themed skills
        if (s >= -12 && s <= -1) {
            if (s == -1) {
                description = "Summon a spectral blade to slash your enemies.";
                name = "Spectral Slash";
                turns = 3;
                skill_aff = spec_cond(0, 3, 0); // (Health: 0, Attack: 3, Speed: 0)
            }
            else if (s == -2) {
                description = "Conjure a shield of darkness to protect yourself from damage.";
                name = "Shadow Shield";
                turns = 3;
                skill_aff = spec_cond(3, 0, 0); // (Health: 0, Attack: 0, Speed: 1)
            }
            else if (s == -3) {
                description = "Release a blast of icy breath, damaging an enemies and reducing their speed.";
                name = "Icy Breath";
                turns = 4;
                skill_aff = spec_cond(0, 2, -2); // (Health: 0, Attack: 2, Speed: -1)
            }
            else if (s == -4) {
                description = "Protect yourself using the power of nature.";
                name = "Nature's protection";
                turns = 2;
                skill_aff = spec_cond(1, 0, 0); // (Health: 3, Attack: 0, Speed: 0)
            }
            else if (s == -5) {
                description = "Channel elemental energy to increase your speed.";
                name = "Elemental Mastery";
                turns = 3;
                skill_aff = spec_cond(0, 0, 2); // (Health: 0, Attack: 0, Speed: 2)
            }
            else if (s == -6) {
                description = "Strike your enemies with a powerful hammer attack.";
                name = "Hammer Strike";
                turns = 2;
                skill_aff = spec_cond(0, 2, 0); // (Health: 0, Attack: 3, Speed: 0)
            }
            else if (s == -7) {
                description = "Summon a storm of lightning, damaging an enemies and reducing their speed.";
                name = "Lightning Storm";
                turns = 6;
                skill_aff = spec_cond(0, 3, -3); // (Health: 0, Attack: 2, Speed: -1)
            }
            else if (s == -8) {
                description = "Throw a bomb at an enemies.";
                name = "Bomb Toss";
                turns = 0;
                skill_aff = spec_cond(0, 1, 0); // (Health: 0, Attack: 1, Speed: -1)
            }
            else if (s == -9) {
                description = "Perform a swift flurry of strikes.";
                name = "Flurry";
                turns = 3;
                skill_aff = spec_cond(0, 2, -1); // (Health: 0, Attack: 2, Speed: -1)
            }
            else if (s == -10) {
                description = "Call upon nature to shield yourself and increase your speed.";
                name = "Nature's Grace";
                turns = 4;
                skill_aff = spec_cond(2, 0, 2); // (Health: 2, Attack: 0, Speed: 2)
            }
            else if (s == -11) {
                description = "Envelop your enemies in darkness, reducing their speed.";
                name = "Darkness Veil";
                turns = 2;
                skill_aff = spec_cond(0, 1, -1); // (Health: 0, Attack: 1, Speed: -1)
            }
            else if (s == -12) {
                description = "Summon a blizzard to damage an enemies and reduce their effecive health.";
                name = "Blizzard";
                turns = 5;
                skill_aff = spec_cond(-2, 3, 0); // (Health: 0, Attack: 3, Speed: 0)
            }
        }
        if (s <= 5 && s >= 0) {
            if (s == 0) {
                description = "Unleash a basic physical attack upon your enemies with precision.";
                name = "Basic Attack";
                turns = 0;
                skill_aff = spec_cond(0, 1, 0); // (Health: 0, Attack: 1, Speed: 0)
            }
            else if (s == 1) {
                description = "Gather mystical energy and release a powerful magical blast.";
                name = "Arcane Bolt";
                turns = 0;
                skill_aff = spec_cond(0, 2, 0); // (Health: 0, Attack: 2, Speed: 0)
            }
            else if (s == 2) {
                description = "Channel your inner strength to deliver a devastating punch, shattering defenses.";
                name = "Titan's Fist";
                turns = 4;
                skill_aff = spec_cond(-1, 3, 0); // (Health: 0, Attack: 3, Speed: -1)
            }
            else if (s == 3) {
                description = "Harness the forces of nature to summon a swirling tempest, striking your foes with lightning and boost yout speed.";
                name = "Storm Surge";
                turns = 3;
                skill_aff = spec_cond(0, 2, 1); // (Health: 0, Attack: 2, Speed: 1)
            }
            else if (s == 4) {
                description = "Envelop yourself in ethereal energy, increasing your speed and protection.";
                name = "Arcane Shield";
                turns = 3;
                skill_aff = spec_cond(1, 0, 2); // (Health: 0, Attack: 0, Speed: 2)
            }
            else if (s == 5) {
                description = "Execute a rapid series of precise strikes, overwhelming your enemies with speed and agility.";
                name = "Blade Dance";
                turns = 4;
                skill_aff = spec_cond(0, 4, 0); // (Health: 0, Attack: 2, Speed: 0)
            }
        }
        // Dreadscale boss-themed skills
        else if (s <= 11 && s >= 6) {
            if (s == 6) {
                description = "Engulf your enemies in searing flames, causing burn damage over time.";
                name = "Inferno";
                turns = 0;
                skill_aff = spec_cond(0, 2, 0); // (Health: 0, Attack: 2, Speed: 0)
            }
            else if (s == 7) {
                description = "Unleash a powerful tail swipe, damaging your enemies, and increasing yout speed.";
                name = "Tail Whip";
                turns = 2;
                skill_aff = spec_cond(0, 1, 1); // (Health: 0, Attack: 1, Speed: 1)
            }
            else if (s == 8) {
                description = "Summon a wall of flames, providing temporary protection from enemy attacks.";
                name = "Fire Shield";
                turns = 1;
                skill_aff = spec_cond(1, 0, 0); // (Health: 0, Attack: 0, Speed: 1)
            }
            else if (s == 9) {
                description = "Call upon the fury of the dragon, increasing your effective health and speed.";
                name = "Dragon's Fury";
                turns = 3;
                skill_aff = spec_cond(3, 0, 2); // (Health: 0, Attack: 3, Speed: 2)
            }
            else if (s == 10) {
                description = "Release a burst of fiery energy, damaging an enemies and reducing their speed.";
                name = "Blazing Burst";
                turns = 3;
                skill_aff = spec_cond(0, 2, -1); // (Health: 0, Attack: 2, Speed: -1)
            }
            else if (s == 11) {
                description = "Unleash a devastating firestorm, engulfing an enemies in flames and reducing their speed.";
                name = "Inferno Storm";
                turns = 6;
                skill_aff = spec_cond(0, 4, -2); // (Health: 0, Attack: 4, Speed: -2)
            }
        }
        // Verdantus boss-themed skills
        else if (s <= 18 && s >= 13) {
            if (s == 13) {
                description = "Summon a swarm of insects, dealing damage and reducing enemy speed.";
                name = "Insect Swarm";
                turns = 0;
                skill_aff = spec_cond(0, 1, -1); // (Health: 0, Attack: 1, Speed: -1)
            }
            else if (s == 14) {
                description = "Unleash a barrage of thorns, damaging an enemies and reducing their speed.";
                name = "Thorn Barrage";
                turns = 4;
                skill_aff = spec_cond(0, 2, -2); // (Health: 0, Attack: 2, Speed: 0)
            }
            else if (s == 15) {
                description = "Fortify your defenses with a protective barrier.";
                name = "Nature's Shield";
                turns = 3;
                skill_aff = spec_cond(3, 0, 0); // (Health: 1, Attack: 0, Speed: 0)
            }
            else if (s == 16) {
                description = "Summon a powerful gust of wind, damaging an enemies and reducing their speed.";
                name = "Gale Force";
                turns = 4;
                skill_aff = spec_cond(0, 3, -1); // (Health: 0, Attack: 3, Speed: -1)
            }
            else if (s == 17) {
                description = "Tap into the essence of the forest, increasing your speed and decreasing the target's attack.";
                name = "Forest's Blessing";
                turns = 3;
                skill_aff = spec_cond(0, -1, 2); // (Health: 0, Attack: 0, Speed: 2)
            }
            else if (s == 18) {
                description = "Summon a colossal tree to crush your enemies, dealing massive damage and reducing their effective health.";
                name = "Giant's Grasp";
                turns = 0;
                skill_aff = spec_cond(-2, 5, 0); // (Health: 0, Attack: 4, Speed: -2)
            }
        }
        // Swamp King Mortis boss-themed skills (continued)
        else if (s <= 23 && s >= 18) {
            if (s == 18) {
                description = "Summon a swarm of poisonous snakes, poisoning your enemies and reducing their speed.";
                name = "Snake Bite";
                turns = 0;
                skill_aff = spec_cond(0, 1, -1); // (Health: 0, Attack: 1, Speed: -1)
            }
            else if (s == 19) {
                description = "Unleash a tidal wave, damaging an enemie and reducing their defense.";
                name = "Toxic Wave";
                turns = 3;
                skill_aff = spec_cond(-1, 2, 0); // (Health: 0, Attack: 2, Speed: 0)
            }
            else if (s == 20) {
                description = "Drain the life force of your enemies, giving yourself a shield.";
                name = "Life Drain";
                turns = 0;
                skill_aff = spec_cond(1, 1, 0); // (Health: 1, Attack: 0, Speed: 0)
            }
            else if (s == 21) {
                description = "Summon a whirlpool, damaging an enemies and reducing their speed.";
                name = "Whirlpool";
                turns = 0;
                skill_aff = spec_cond(0, 3, -1); // (Health: 0, Attack: 3, Speed: -1)
            }
            else if (s == 22) {
                description = "Embrace the power of the swamp, damaging enemies and increasing your speed.";
                name = "Swamp's Blessing";
                turns = 3;
                skill_aff = spec_cond(0, 2, 2); // (Health: 0, Attack: 0, Speed: 2)
            }
            else if (s == 23) {
                description = "Summon a massive tidal wave, damaging all enemies and reducing their defense.";
                name = "Deluge";
                turns = 6;
                skill_aff = spec_cond(-2, 4, 0); // (Health: 0, Attack: 4, Speed: -2)
            }
        }
        // Leviathan boss-themed skills (new)
        else if (s <= 29 && s >= 24) {
            if (s == 23) {
                description = "Summon a torrent of water, damaging all enemies and reducing their speed.";
                name = "Water Torrent";
                turns = 0;
                skill_aff = spec_cond(0, 1, -1); // (Health: 0, Attack: 1, Speed: -1)
            }
            else if (s == 25) {
                description = "Unleash a crushing tidal wave, reducing your target's attack.";
                name = "Tidal Crush";
                turns = 2;
                skill_aff = spec_cond(0, -2, 0); // (Health: 0, Attack: 2, Speed: 0)
            }
            else if (s == 26) {
                description = "Become one with the sea, giving yourself a shield and increasing speed";
                name = "Aquatic Regeneration";
                turns = 2;
                skill_aff = spec_cond(1, 0, 1); // (Health: 1, Attack: 0, Speed: 0)
            }
            else if (s == 27) {
                description = "Summon a massive whirlpool, damaging aan enemie and reducing their speed.";
                name = "Whirlpool Vortex";
                turns = 3;
                skill_aff = spec_cond(0, 2, -1); // (Health: 0, Attack: 3, Speed: -1)
            }
            else if (s == 28) {
                description = "Harness the power of the ocean, increasing your speed.";
                name = "Ocean's Blessing";
                turns = 2;
                skill_aff = spec_cond(0, 0, 2); // (Health: 0, Attack: 0, Speed: 2)
            }
            else if (s == 29) {
                description = "Summon a devastating tidal wave, damaging an enemies and reducing their speed.";
                name = "Tsunami";
                turns = 6;
                skill_aff = spec_cond(0, 4, -2); // (Health: 0, Attack: 4, Speed: -2)
            }
        }
        // Blaze Lord Ignis boss-themed skills (continued)
        else if (s <= 35 && s >= 30) {
            if (s == 30) {
                description = "Unleash a blazing fireball, scorching your enemies and reducing their speed.";
                name = "Fireball";
                turns = 0;
                skill_aff = spec_cond(0, 1, -1); // (Health: 0, Attack: 1, Speed: -1)
            }
            else if (s == 31) {
                description = "Engulf your enemies in a fiery inferno, damaging them and reducing their attack.";
                name = "Inferno";
                turns = 2;
                skill_aff = spec_cond(0, 2, 0); // (Health: 0, Attack: 2, Speed: 0)
            }
            else if (s == 32) {
                description = "Embrace the flames, increasing your and speed and reducing the target's attack for a short duration.";
                name = "Flame Surge";
                turns = 4;
                skill_aff = spec_cond(0, -2, 2); // (Health: 0, Attack: 2, Speed: 2)
            }
            else if (s == 33) {
                description = "Summon a massive firestorm, damaging an enemies and reducing their speed.";
                name = "Firestorm";
                turns = 4;
                skill_aff = spec_cond(0, 3, -1); // (Health: 0, Attack: 3, Speed: -1)
            }
            else if (s == 34) {
                description = "Harness the power of the flames, giving yourself a shield.";
                name = "Flame's Embrace";
                turns = 3;
                skill_aff = spec_cond(3, 0, 0); // (Health: 1, Attack: 0, Speed: 0)
            }
            else if (s == 35) {
                description = "Summon a devastating inferno, damaging an enemies and reducing their defense.";
                name = "Infernal Blast";
                turns = 6;
                skill_aff = spec_cond(0, 4, -2); // (Health: 0, Attack: 4, Speed: -2)
            }
        }
        // Thunderhoof boss-themed skills (new)
        else if (s <= 41 && s >= 36) {
            if (s == 36) {
                description = "Charge at your enemies with thunderous force, damaging them and reducing their speed.";
                name = "Thunder Charge";
                turns = 0;
                skill_aff = spec_cond(0, 1, -1); // (Health: 0, Attack: 1, Speed: -1)
            }
            else if (s == 37) {
                description = "Summon a lightning storm, striking your enemies and reducing their attack.";
                name = "Lightning Storm";
                turns = 3;
                skill_aff = spec_cond(0, 2, -1); // (Health: 0, Attack: 2, Speed: 0)
            }
            else if (s == 38) {
                description = "Channel the power of thunder, increasing your speed and defense for a short duration.";
                name = "Thunderous Might";
                turns = 4;
                skill_aff = spec_cond(2, 0, 2); // (Health: 0, Attack: 2, Speed: 2)
            }
            else if (s == 39) {
                description = "Summon a devastating thunderstorm, damaging an enemies and reducing their speed.";
                name = "Thunderstorm";
                turns = 4;
                skill_aff = spec_cond(0, 3, -1); // (Health: 0, Attack: 3, Speed: -1)
            }
            else if (s == 40) {
                description = "Harness the power of lightning, greatly increasing your  speed.";
                name = "Lightning's Grace";
                turns = 3;
                skill_aff = spec_cond(0, 0, 3); // (Health: 0, Attack: 0, Speed: 2)
            }
            else if (s == 41) {
                description = "Summon a devastating lightning strike, damaging all enemies and reducing their defense.";
                name = "Shocking Bolt";
                turns = 6;
                skill_aff = spec_cond(-2, 4, 0); // (Health: 0, Attack: 4, Speed: -2)
            }
        }
        // Frostbite boss-themed skills (new)
        else if (s <= 47 && s >= 42) {
            if (s == 42) {
                description = "Blast your enemies with icy shards, dealing damage and reducing their speed.";
                name = "Icy Shards";
                turns = 0;
                skill_aff = spec_cond(0, 1, -1); // (Health: 0, Attack: 1, Speed: -1)
            }
            else if (s == 43) {
                description = "Summon a freezing blizzard, damaging your enemies.";
                name = "Freezing Blizzard";
                turns = 2;
                skill_aff = spec_cond(0, 2, 0); // (Health: 0, Attack: 2, Speed: 0)
            }
            else if (s == 44) {
                description = "Embrace the frigid cold, increasing your defense and speed for a short duration.";
                name = "Frozen Fortitude";
                turns = 3;
                skill_aff = spec_cond(1, 0, 2); // (Health: 0, Attack: 0, Speed: 2)
            }
            else if (s == 45) {
                description = "Summon a powerful blizzard, damaging an enemies and reducing their speed.";
                name = "Arctic Blizzard";
                turns = 4;
                skill_aff = spec_cond(0, 3, -1); // (Health: 0, Attack: 3, Speed: -1)
            }
            else if (s == 46) {
                description = "Embrace the icy cold, giving you a large shield.";
                name = "Frostbite's Embrace";
                turns = 3;
                skill_aff = spec_cond(3, 0, 0); // (Health: 1, Attack: 0, Speed: 0)
            }
            else if (s == 47) {
                description = "Summon a bone-chilling blizzard, damaging all enemies and reducing their defense.";
                name = "Frost Nova";
                turns = 6;
                skill_aff = spec_cond(-2, 4, 0); // (Health: 0, Attack: 4, Speed: -2)
            }
        }
        // Rhino trashmob-themed skills
        if (s <= 52 && s >= 48) {
            if (s == 48) {
                description = "Charge at your enemies with brute force, dealing damage and knocking them back.";
                name = "Gore";
                turns = 0;
                skill_aff = spec_cond(0, 2, 0); // (Health: 0, Attack: 2, Speed: 0)
            }
            else if (s == 49) {
                description = "Trample over your enemies, causing damage and reducing their speed.";
                name = "Trample";
                turns = 2;
                skill_aff = spec_cond(0, 1, -1); // (Health: 0, Attack: 1, Speed: -1)
            }
            else if (s == 50) {
                description = "Enrage yourself, increasing your attack power at the cost of health.";
                name = "Enrage";
                turns = 3;
                skill_aff = spec_cond(-1, 2, 0); // (Health: -1, Attack: 2, Speed: 0)
            }
            else if (s == 51) {
                description = "Unleash a powerful stomp, damaging an enemiy and reducing their defense.";
                name = "Stomp";
                turns = 3;
                skill_aff = spec_cond(-1, 2, 0); // (Health: 0, Attack: 2, Speed: -1)
            }
            else if (s == 52) {
                description = "Become more resistant to damage, gain a shield.";
                name = "Iron Hide";
                turns = 0;
                skill_aff = spec_cond(1, 0, 0); // (Health: 0, Attack: 0, Speed: 1)
            }
        }

        // Octopus trashmob-themed skills
        if (s <= 57 && s >= 53) {
            if (s == 53) {
                description = "Spray ink at your enemies, reducing their accuracy and lowering their speed.";
                name = "Ink Spray";
                turns = 0;
                skill_aff = spec_cond(0, 1, -1); // (Health: 0, Attack: 1, Speed: -1)
            }
            else if (s == 54) {
                description = "Entangle your enemies with your tentacles, reducing their speed and defense.";
                name = "Tentacle Bind";
                turns = 0;
                skill_aff = spec_cond(0, 1, -1); // (Health: 0, Attack: 1, Speed: -1)
            }
            else if (s == 55) {
                description = "Camouflage yourself in water, increasing your evasion and speed.";
                name = "Water Camouflage";
                turns = 3;
                skill_aff = spec_cond(0, 0, 2); // (Health: 0, Attack: 0, Speed: 2)
            }
            else if (s == 56) {
                description = "Release a cloud of poisonous ink, damaging all enemies and poisoning them.";
                name = "Poisonous Cloud";
                turns = 0;
                skill_aff = spec_cond(0, 2, -1); // (Health: 0, Attack: 2, Speed: -1)
            }
            else if (s == 57) {
                description = "Increase your defense and become more resistant to status effects.";
                name = "Mystic Barrier";
                turns = 3;
                skill_aff = spec_cond(1, 0, 0); // (Health: 1, Attack: 0, Speed: 0)
            }
        }

        // Mammoth trashmob-themed skills
        if (s <= 62 && s >= 58) {
            if (s == 58) {
                description = "Unleash a powerful tusk strike, dealing damage and reducing enemy defense.";
                name = "Tusk Strike";
                turns = 0;
                skill_aff = spec_cond(0, 2, 0); // (Health: 0, Attack: 2, Speed: 0)
            }
            else if (s == 59) {
                description = "Stomp the ground, causing damage and reducing enemy attack power.";
                name = "Ground Pound";
                turns = 0;
                skill_aff = spec_cond(0, 1, -1); // (Health: 0, Attack: 1, Speed: -1)
            }
            else if (s == 60) {
                description = "Increase your resistance to status effects and become immune to some debuffs.";
                name = "Thick Hide";
                turns = 3;
                skill_aff = spec_cond(1, 0, 0); // (Health: 1, Attack: 0, Speed: 0)
            }
            else if (s == 61) {
                description = "Create a freezing gust of wind, reducing enemy speed and freezing them.";
                name = "Arctic Gust";
                turns = 0;
                skill_aff = spec_cond(0, 2, -1); // (Health: 0, Attack: 2, Speed: -1)
            }
            else if (s == 62) {
                description = "Increase your attack power, sacrificing speed for a short duration.";
                name = "Mighty Charge";
                turns = 3;
                skill_aff = spec_cond(0, 2, -1); // (Health: 0, Attack: 2, Speed: -1)
            }
        }
        // Wyvern trashmob-themed skills
        if (s <= 67 && s >= 63) {
            if (s == 63) {
                description = "Slash at your enemies with your claws, dealing damage and reducing their defense.";
                name = "Claw Slash";
                turns = 0;
                skill_aff = spec_cond(0, 2, 0); // (Health: 0, Attack: 2, Speed: 0)
            }
            else if (s == 64) {
                description = "Swoop down from the sky, dealing damage and reducing enemy speed.";
                name = "Swoop Attack";
                turns = 0;
                skill_aff = spec_cond(0, 2, -1); // (Health: 0, Attack: 2, Speed: -1)
            }
            else if (s == 65) {
                description = "Increase your evasion and agility, making it harder for enemies to hit you.";
                name = "Aerial Dodge";
                turns = 3;
                skill_aff = spec_cond(0, 0, 2); // (Health: 0, Attack: 0, Speed: 2)
            }
            else if (s == 66) {
                description = "Breathe a stream of fire, damaging all enemies and reducing their defense.";
                name = "Dragon's Breath";
                turns = 0;
                skill_aff = spec_cond(0, 3, -1); // (Health: 0, Attack: 3, Speed: -1)
            }
            else if (s == 67) {
                description = "Channel your inner power, increasing your attack and defense for a short duration.";
                name = "Dragon's Fury";
                turns = 3;
                skill_aff = spec_cond(0, 2, 1); // (Health: 0, Attack: 2, Speed: 1)
            }
        }

        // Boggy Slime trashmob-themed skills
        if (s <= 72 && s >= 68) {
            if (s == 68) {
                description = "Engulf your enemies in slimy goo, reducing their speed and causing damage over time.";
                name = "Slimy Goo";
                turns = 0;
                skill_aff = spec_cond(0, 1, -1); // (Health: 0, Attack: 1, Speed: -1)
            }
            else if (s == 69) {
                description = "Split into smaller slimes, overwhelming your enemies with multiple attacks.";
                name = "Splitting Assault";
                turns = 0;
                skill_aff = spec_cond(0, 2, 0); // (Health: 0, Attack: 2, Speed: 0)
            }
            else if (s == 70) {
                description = "Regenerate your slimy body, restoring health over time and increasing your defense.";
                name = "Regenerative Slime";
                turns = 3;
                skill_aff = spec_cond(1, 0, 0); // (Health: 1, Attack: 0, Speed: 0)
            }
            else if (s == 71) {
                description = "Release a toxic cloud, damaging all enemies and reducing their attack.";
                name = "Toxic Cloud";
                turns = 0;
                skill_aff = spec_cond(0, 2, -1); // (Health: 0, Attack: 2, Speed: -1)
            }
            else if (s == 72) {
                description = "Absorb energy from your enemies, increasing your attack and speed for a short duration.";
                name = "Energy Drain";
                turns = 3;
                skill_aff = spec_cond(0, 2, 2); // (Health: 0, Attack: 2, Speed: 2)
            }
        }
        // Ebon Fiend trashmob-themed skills
        if (s <= 77 && s >= 73) {
            if (s == 73) {
                description = "Slash your enemies with razor-sharp claws, causing damage and reducing their defense.";
                name = "Razor Slash";
                turns = 0;
                skill_aff = spec_cond(0, 2, 0); // (Health: 0, Attack: 2, Speed: 0)
            }
            else if (s == 74) {
                description = "Summon a dark mist, reducing enemy accuracy and causing damage over time.";
                name = "Shadow Mist";
                turns = 0;
                skill_aff = spec_cond(0, 1, -1); // (Health: 0, Attack: 1, Speed: -1)
            }
            else if (s == 75) {
                description = "Embrace the darkness, increasing your attack and defense for a short duration.";
                name = "Dark Embrace";
                turns = 3;
                skill_aff = spec_cond(0, 2, 2); // (Health: 0, Attack: 2, Speed: 2)
            }
            else if (s == 76) {
                description = "Drain the life force of your enemies, healing yourself and reducing their speed.";
                name = "Life Drain";
                turns = 0;
                skill_aff = spec_cond(1, 0, -1); // (Health: 1, Attack: 0, Speed: -1)
            }
            else if (s == 77) {
                description = "Unleash a barrage of dark energy, damaging all enemies and reducing their speed.";
                name = "Dark Barrage";
                turns = 0;
                skill_aff = spec_cond(0, 3, -1); // (Health: 0, Attack: 3, Speed: -1)
            }
        }

        // Green Goliath trashmob-themed skills
        if (s <= 82 && s >= 78) {
            if (s == 78) {
                description = "Deliver a powerful slam attack, damaging your enemies and reducing their speed.";
                name = "Ground Slam";
                turns = 0;
                skill_aff = spec_cond(0, 2, -1); // (Health: 0, Attack: 2, Speed: -1)
            }
            else if (s == 79) {
                description = "Release a toxic cloud, poisoning enemies and reducing their attack.";
                name = "Toxic Cloud";
                turns = 0;
                skill_aff = spec_cond(0, 1, 0); // (Health: 0, Attack: 1, Speed: 0)
            }
            else if (s == 80) {
                description = "Boost your strength with earth's energy, increasing your attack and defense.";
                name = "Earth's Blessing";
                turns = 3;
                skill_aff = spec_cond(0, 2, 1); // (Health: 0, Attack: 2, Speed: 1)
            }
            else if (s == 81) {
                description = "Unleash a seismic shockwave, damaging all enemies and reducing their defense.";
                name = "Seismic Shock";
                turns = 0;
                skill_aff = spec_cond(0, 3, 0); // (Health: 0, Attack: 3, Speed: 0)
            }
            else if (s == 82) {
                description = "Embrace the power of nature, increasing your magical power and speed.";
                name = "Nature's Embrace";
                turns = 3;
                skill_aff = spec_cond(0, 0, 2); // (Health: 0, Attack: 0, Speed: 2)
            }
        }
        //razorback the rhino skills
        if (s <= 88 && s >= 83) {
            // Skill 1: Horn Charge
            if (s == 83) {
                description = "Charge forward with your mighty horn, dealing massive damage to a single enemy.";
                name = "Horn Charge";
                turns = 0;
                skill_aff = spec_cond(0, 4, -2); // (Health: 0, Attack: 4, Speed: -2)
            }

            // Skill 2: Trample
            else if (s == 84) {
                description = "Run wild and trample all enemies in your path, causing damage and reducing their defense.";
                name = "Trample";
                turns = 0;
                skill_aff = spec_cond(0, 3, -1); // (Health: 0, Attack: 3, Speed: -1)
            }

            // Skill 3: Rhino's Endurance
            else if (s == 85) {
                description = "Tap into the endurance of a rhino, increasing your defense significantly for a short duration.";
                name = "Rhino's Endurance";
                turns = 3;
                skill_aff = spec_cond(0, 0, 2); // (Health: 0, Attack: 0, Speed: 2)
            }

            // Skill 4: Stampede
            else if (s == 86) {
                description = "Summon a stampede of rhinos to crush your foes, dealing damage to all enemies.";
                name = "Stampede";
                turns = 0;
                skill_aff = spec_cond(0, 2, 0); // (Health: 0, Attack: 2, Speed: 0)
            }

            // Skill 5: Rhino's Fortitude
            else if (s == 87) {
                description = "Toughen up like a rhino, increasing your health and defense moderately.";
                name = "Rhino's Fortitude";
                turns = 3;
                skill_aff = spec_cond(2, 0, 1); // (Health: 2, Attack: 0, Speed: 1)
            }

            // Skill 6: Ground Pound
            else if (s == 88) {
                description = "Pound the ground with immense force, damaging all enemies and reducing their speed.";
                name = "Ground Pound";
                turns = 0;
                skill_aff = spec_cond(0, 2, -2); // (Health: 0, Attack: 2, Speed: -2)
            }
        }
        //tentaculus the octopus skills
        if (s <= 94 && s >= 89) {
            // Skill 1: Tentacle Slap
            if (s == 89) {
                description = "Slap a single enemy with a powerful tentacle strike, causing damage and reducing their attack.";
                name = "Tentacle Slap";
                turns = 0;
                skill_aff = spec_cond(0, 3, -1); // (Health: 0, Attack: 3, Speed: -1)
            }

            // Skill 2: Ink Spray
            else if (s == 90) {
                description = "Spray ink at your enemies, reducing their accuracy and causing damage over time.";
                name = "Ink Spray";
                turns = 0;
                skill_aff = spec_cond(0, 1, 0); // (Health: 0, Attack: 1, Speed: 0)
            }

            // Skill 3: Aquatic Regeneration
            else if (s == 91) {
                description = "Tap into the power of the ocean, regenerating health over several turns.";
                name = "Aquatic Regeneration";
                turns = 3;
                skill_aff = spec_cond(3, 0, 0); // (Health: 3, Attack: 0, Speed: 0)
            }

            // Skill 4: Whirlpool
            else if (s == 92) {
                description = "Summon a powerful whirlpool, damaging all enemies and reducing their speed.";
                name = "Whirlpool";
                turns = 0;
                skill_aff = spec_cond(0, 2, -2); // (Health: 0, Attack: 2, Speed: -2)
            }

            // Skill 5: Camouflage
            else if (s == 93) {
                description = "Blend into your surroundings, increasing your evasion and defense significantly.";
                name = "Camouflage";
                turns = 3;
                skill_aff = spec_cond(0, 0, 3); // (Health: 0, Attack: 0, Speed: 3)
            }

            // Skill 6: Tentacle Barrage
            else if (s == 94) {
                description = "Unleash a barrage of tentacle strikes, hitting all enemies and reducing their defense.";
                name = "Tentacle Barrage";
                turns = 0;
                skill_aff = spec_cond(0, 2, -1); // (Health: 0, Attack: 2, Speed: -1)
            }
        }
        //frostclaw the mammoth skills
        if (s <= 100 && s >= 95) {
            // Skill 1: Arctic Charge
            if (s == 95) {
                description = "Charge forward with immense force, damaging a single enemy and reducing their speed.";
                name = "Arctic Charge";
                turns = 0;
                skill_aff = spec_cond(0, 3, -1); // (Health: 0, Attack: 3, Speed: -1)
            }

            // Skill 2: Ice Breath
            else if (s == 96) {
                description = "Exhale a freezing breath, damaging all enemies and reducing their attack.";
                name = "Ice Breath";
                turns = 0;
                skill_aff = spec_cond(0, 2, 0); // (Health: 0, Attack: 2, Speed: 0)
            }

            // Skill 3: Frost Armor
            else if (s == 97) {
                description = "Encase yourself in icy armor, reducing incoming damage and increasing defense.";
                name = "Frost Armor";
                turns = 3;
                skill_aff = spec_cond(0, 0, 3); // (Health: 0, Attack: 0, Speed: 3)
            }

            // Skill 4: Icy Slam
            else if (s == 98) {
                description = "Slam the ground with your icy tusks, damaging all enemies and reducing their defense.";
                name = "Icy Slam";
                turns = 0;
                skill_aff = spec_cond(0, 2, -1); // (Health: 0, Attack: 2, Speed: -1)
            }

            // Skill 5: Frost Nova
            else if (s == 99) {
                description = "Unleash a frigid shockwave, damaging all enemies and reducing their speed.";
                name = "Frost Nova";
                turns = 0;
                skill_aff = spec_cond(0, 1, -2); // (Health: 0, Attack: 1, Speed: -2)
            }

            // Skill 6: Glacial Roar
            else if (s == 100) {
                description = "Let out a mighty roar, increasing your attack and speed significantly.";
                name = "Glacial Roar";
                turns = 3;
                skill_aff = spec_cond(0, 3, 3); // (Health: 0, Attack: 3, Speed: 3)
            }
        }
        //stormwing the wyvern
        if (s <= 106 && s >= 101) {
            if (s == 101) {
                description = "Summon a bolt of lightning to strike a single enemy, causing damage and reducing their speed.";
                name = "Thunderstrike";
                turns = 0;
                skill_aff = spec_cond(0, 3, -1); // (Health: 0, Attack: 3, Speed: -1)
            }
            else if (s == 102) {
                description = "Stir up powerful winds, damaging all enemies and reducing their accuracy.";
                name = "Gale Winds";
                turns = 0;
                skill_aff = spec_cond(0, 2, 0); // (Health: 0, Attack: 2, Speed: 0)
            }
            else if (s == 103) {
                description = "Take to the skies, increasing your speed and evasiveness significantly.";
                name = "Aerial Superiority";
                turns = 3;
                skill_aff = spec_cond(0, 1, 3); // (Health: 0, Attack: 1, Speed: 3)
            }
            else if (s == 104) {
                description = "Exhale a toxic breath, poisoning enemies and reducing their defense.";
                name = "Poisonous Breath";
                turns = 0;
                skill_aff = spec_cond(0, 1, -2); // (Health: 0, Attack: 1, Speed: -2)
            }
            else if (s == 105) {
                description = "Spin rapidly, slashing all enemies with your wings, causing damage and reducing their attack.";
                name = "Cyclone Slash";
                turns = 0;
                skill_aff = spec_cond(0, 2, -1); // (Health: 0, Attack: 2, Speed: -1)
            }
            else if (s == 106) {
                description = "Enter the calm center of the storm, restoring health and increasing defense significantly.";
                name = "Eye of the Storm";
                turns = 3;
                skill_aff = spec_cond(3, 0, 2); // (Health: 3, Attack: 0, Speed: 2)
            }
        }
        //bogchomp the mirebeast
        if (s >= 107 && s <= 112) {
            if (s == 107) {
                description = "Engulf the enemy in toxic mire, causing damage over time and reducing their attack.";
                name = "Mire Vortex";
                turns = 0;
                skill_aff = spec_cond(0, 1, 0); // (Health: 0, Attack: 1, Speed: 0)
            }
            else if (s == 108) {
                description = "Summon bog creatures to aid in battle, slightly healing yourself and reducing enemy speed.";
                name = "Bog Summoning";
                turns = 0;
                skill_aff = spec_cond(1, 0, -1); // (Health: 1, Attack: 0, Speed: -1)
            }
            else if (s == 109) {
                description = "Unleash a devastating stomp, damaging all enemies and reducing their defense.";
                name = "Earthquake Stomp";
                turns = 0;
                skill_aff = spec_cond(0, 2, -1); // (Health: 0, Attack: 2, Speed: -1)
            }
            else if (s == 110) {
                description = "Embrace the power of the mire, increasing your defense and magical power.";
                name = "Mire Enchantment";
                turns = 3;
                skill_aff = spec_cond(0, 0, 2); // (Health: 0, Attack: 0, Speed: 2)
            }
            else if (s == 111) {
                description = "Launch a barrage of poisonous spikes, damaging all enemies and reducing their accuracy.";
                name = "Toxic Barrage";
                turns = 0;
                skill_aff = spec_cond(0, 2, 0); // (Health: 0, Attack: 2, Speed: 0)
            }
            else if (s == 112) {
                description = "Transform into a swamp giant, greatly increasing your attack and defense.";
                name = "Swamp Transformation";
                turns = 3;
                skill_aff = spec_cond(0, 3, 1); // (Health: 0, Attack: 3, Speed: 1)
            }
        }
        //emberclaw the salamander
        if (s >= 113 && s <= 118) {
            if (s == 113) {
                description = "Unleash a scorching fireball, causing damage to all enemies and reducing their defense.";
                name = "Fireball Barrage";
                turns = 0;
                skill_aff = spec_cond(0, 3, -1); // (Health: 0, Attack: 3, Speed: -1)
            }
            else if (s == 114) {
                description = "Ignite the battlefield, causing damage over time and reducing enemy attack.";
                name = "Inferno Blaze";
                turns = 0;
                skill_aff = spec_cond(0, 1, 0); // (Health: 0, Attack: 1, Speed: 0)
            }
            else if (s == 115) {
                description = "Embrace the power of the volcano, increasing your attack and speed.";
                name = "Volcanic Fury";
                turns = 3;
                skill_aff = spec_cond(0, 2, 2); // (Health: 0, Attack: 2, Speed: 2)
            }
            else if (s == 116) {
                description = "Channel intense heat, healing yourself and slightly increasing your defense.";
                name = "Heat Absorption";
                turns = 0;
                skill_aff = spec_cond(1, 0, 1); // (Health: 1, Attack: 0, Speed: 1)
            }
            else if (s == 117) {
                description = "Create a scalding steam cloud, reducing enemy accuracy and causing damage over time.";
                name = "Scalding Steam";
                turns = 0;
                skill_aff = spec_cond(0, 1, -1); // (Health: 0, Attack: 1, Speed: -1)
            }
            else if (s == 118) {
                description = "Unleash an explosion of fire, damaging all enemies and reducing their speed.";
                name = "Inferno Explosion";
                turns = 0;
                skill_aff = spec_cond(0, 2, 0); // (Health: 0, Attack: 2, Speed: 0)
            }
        }
        //thornscale the vine lasher
        if (s >= 119 && s <= 124) {
            if (s == 107) {
                description = "Lash out with thorny vines, causing damage and reducing enemy defense.";
                name = "Vine Lash";
                turns = 0;
                skill_aff = spec_cond(0, 2, 0); // (Health: 0, Attack: 2, Speed: 0)
            }
            else if (s == 108) {
                description = "Entangle enemies in vines, reducing their speed and causing damage over time.";
                name = "Vine Entanglement";
                turns = 0;
                skill_aff = spec_cond(0, 1, -1); // (Health: 0, Attack: 1, Speed: -1)
            }
            else if (s == 109) {
                description = "Embrace the power of nature, increasing your attack and defense for a short duration.";
                name = "Nature's Blessing";
                turns = 3;
                skill_aff = spec_cond(0, 2, 2); // (Health: 0, Attack: 2, Speed: 2)
            }
            else if (s == 110) {
                description = "Heal yourself by draining the life force of your enemies and reducing their attack.";
                name = "Life Drain";
                turns = 0;
                skill_aff = spec_cond(1, 0, -1); // (Health: 1, Attack: 0, Speed: -1)
            }
            else if (s == 111) {
                description = "Summon a barrage of thorns, damaging all enemies and reducing their accuracy.";
                name = "Thorn Barrage";
                turns = 0;
                skill_aff = spec_cond(0, 3, -1); // (Health: 0, Attack: 3, Speed: -1)
            }
            else if (s == 112) {
                description = "Unleash a devastating root slam, damaging all enemies and reducing their defense.";
                name = "Root Slam";
                turns = 0;
                skill_aff = spec_cond(0, 3, 0); // (Health: 0, Attack: 3, Speed: 0)
            }
        }
        //princess skills
        if (s >= 125 && s <= 130) {
            if (s == 125) {
                description = "Hit combo with daggers from crown";
                name = "Crown stab";
                turns = 0;
                skill_aff = spec_cond(0, 2, 0); // (Health: 0, Attack: 2, Speed: 0)
            }
            else if (s == 126) {
                description = "Hit combo with daggers from crown";
                name = "Crown stab";
                turns = 0;
                skill_aff = spec_cond(0, 2, 0); // (Health: 0, Attack: 2, Speed: 0)
            }
            else if (s == 127) {
                description = "Hit combo with daggers from crown";
                name = "Crown stab";
                turns = 0;
                skill_aff = spec_cond(0, 2, 0); // (Health: 0, Attack: 2, Speed: 0)
            }
            else if (s == 128) {
                description = "Hit combo with daggers from crown";
                name = "Crown stab";
                turns = 0;
                skill_aff = spec_cond(0, 2, 0); // (Health: 0, Attack: 2, Speed: 0)
            }
            else if (s == 129) {
                description = "Hit combo with daggers from crown";
                name = "Crown stab";
                turns = 0;
                skill_aff = spec_cond(0, 2, 0); // (Health: 0, Attack: 2, Speed: 0)
            }
            else if (s == 130) {
                description = "Hit combo with daggers from crown";
                name = "Crown stab";
                turns = 0;
                skill_aff = spec_cond(0, 2, 0); // (Health: 0, Attack: 2, Speed: 0)
            }
        };
    }

    string getname(){
        return name;
    }
    string getdescription(){
        return description;
    }
    //skill cooldown
    int  getturns(){
        return turns;
    };
    //current cooldown of skill
    int getcturns() {
        return cturns;
    }
    spec_cond getskill_aff(){
        return skill_aff;
    };
    bool operator==(Skill const& other) {
        return name == other.name;
    }
    void useskill() {
        cturns = 0;
    }
    bool SKILLcooldown() {
        cturns++;
        if (cturns >= turns) {
            cturns = -1;
            return true;
        }
        return false;
    }
    void printskill() {
            cout << name << endl << description << endl;
            if (turns == 0||turns==1) {
                cout << "no cooldown" << endl;
            }
            else {
                cout << turns-1 << " turn(s) cooldown" << endl;
            }
            if (skill_aff.get_aff_health()>0) {
                cout << "Health buff " << skill_aff.get_aff_health();
            }
            else {
                cout << "Health debuff " << skill_aff.get_aff_health();
            }
            if (skill_aff.get_aff_attack() > 0) {
                cout<<" Attack multipluier " << skill_aff.get_aff_attack();
            }
            else {
                cout<<" Attack debuff " << skill_aff.get_aff_attack();
            }
            if (skill_aff.get_aff_speed()>0) {
                cout << " Speed buff " << skill_aff.get_aff_speed();
            }
            else {
                cout << " Speed debuff " << skill_aff.get_aff_speed();
            }
    }
    int get_skillid() {
        return id;
    }
    private:
        string name;
        string description;
        int turns=0;
        int cturns = -1;
        spec_cond skill_aff;
        int id = 0;
};

#endif
