//
//  main.cpp
//  Warrior Duel
//
//  Created by Kori Vernon on 6/10/19.
//  Copyright © 2019 Kori Vernon. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <numeric>
#include <math.h>

class Warrior {
private:
    int attack;
    int block;
    
public:
    int GetAttack(){return attack;}
    int GetBlock(){return block;}
    int health;
    std::string name;
    
    Warrior(std::string name,int health, int attack, int block){
        this -> name = name;
        this -> attack = attack;
        this -> block = block;
        this -> health = health;
    } //constructor
    
    int Attack(){ //this attacks people
        return std::rand() % this -> attack;
    }
    int Block() { //this blocks people
        return std::rand() % this -> block;
    }
    
};

class Battle {
public:
    static void StartFight(Warrior& warrior1, Warrior& warrior2){
        while(true){
            if((Battle::GetAttackResult(warrior1,warrior2).compare("Game Over")) == 0) {
                std::cout << "Game Over\n";
                break;
            }
            if((Battle::GetAttackResult(warrior2,warrior1).compare("Game Over")) == 0) {
                std::cout << "Game Over\n";
                break;
                
            }
            
        }
        
    }
    
    static std::string GetAttackResult(Warrior& warriorA, Warrior& warriorB){
        int warriorAAtk = warriorA.Attack();
        int warriorBBloc = warriorB.Block();
        int damageToWarriorB = ceil(warriorAAtk - warriorBBloc);
        damageToWarriorB = (damageToWarriorB <=0)? 0: damageToWarriorB; //ensures that there won't be a negative.
        warriorB.health = warriorB.health - damageToWarriorB;
        
        printf("%s attacks %s and deals %d damage\n", warriorA.name.c_str(), warriorB.name.c_str(), damageToWarriorB);
        
        printf("%s is down to %d health \n", warriorB.name.c_str(),warriorB.health);
        
        if (warriorB.health <= 0){
            printf("%s has died and %s is Victorious\n",warriorB.name.c_str(),warriorB.name.c_str());
            return "Game Over";
        } else {
            return "Fight Again";
        }
    
    }
};
int main() {
    
    Warrior thor("Thor",100,20,15);
    Warrior hulk("Hulk",135,25,10);
    
    Battle::StartFight(thor,hulk);
    
    return 0;
}
