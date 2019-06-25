//
//  main.cpp
//  Workspace
//
//  Created by Kori Vernon on 6/6/19.
//  Copyright © 2019 Kori Vernon. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <numeric>
#include <math.h>

class Animal{
private:
    std::string name;
    double height;
    double weight;
    
    //a static variable is shared amongst everything in the class
    //things are often static because the real world capability would likely not have the ability to do it
    static int numOfAnimals;
public:
    //accessible outside of our blueprint or class
    std::string GetName(){return name;}
    void SetName(std:: string name){
        this->name = name;}
    // this name needs to be set to the [name] passed in.
    double GetHeight(){return height;}
    void SetHeight(double height) {
        this->height = height;}
    double GetWeight(){return weight;}
    void SetWeight(double weight) {
        this->weight = weight;
    }
    
    void SetAll(std::string, double, double);
    
    Animal(std::string,double, double);
    
    Animal(); // overloader constructor
    
    ~Animal(); // deconstructor
    
    static int GetNumOfAnimals(){
        return numOfAnimals;
    }
    void ToString();
};

int Animal::numOfAnimals =0;
void Animal::SetAll(std::string name, double height, double weight){
    this->name = name;
    this->height = height;
    this->weight = weight;
    Animal::numOfAnimals++; //increment
    
}

Animal::Animal(std::string name, double height, double weight){
    this->name = name;
    this->height = height;
    this->weight = weight;
    Animal::numOfAnimals++; //increment
}

Animal::Animal(){
    this->name = "";
    this->height = 0;
    this->weight = 0;
    Animal::numOfAnimals++; //increment
}

Animal::~Animal(){
    if (this -> name == "" ) {
        std::cout << "Unknown animal destroyed! " << std::endl;
    } else {
    std::cout << "Animal " << this-> name << " destroyed! " << std::endl;
}
}

void Animal::ToString(){
    if (this -> name ==""){
        std::cout << "Unknown animal is " << this -> height << " cm tall, and weighs " << this -> weight << " kilograms. "<< std::endl;
    } else {
        std::cout << this -> name << " is " << this -> height << " centimeters tall, and weighs " << this -> weight << " kilograms. "<< std::endl;
    }
}
class Dog: public Animal {
private:
    std::string sound = "Woof";
public:
    void MakeSound(){
        std:: cout << "The dog " << this->GetName() << " says " << this -> sound << std::endl;
    }
    Dog(std::string,double,double, std::string);
    Dog(): Animal(){};
    void ToString();
};

Dog::Dog(std::string name, double height, double weight, std::string sound) : Animal(name, height, weight) {
    this -> sound = sound;
}

void Dog::ToString(){
    //you can change from private to protected
    if (this -> GetName() ==""){
        std::cout << "Unknown animal is " << this -> GetHeight() << " cm tall, and weighs " << this -> GetWeight() << " kilograms. "<< std::endl;
    } else {
        std::cout << this -> GetName() << " is " << this -> GetHeight() << " centimeters tall, weighs " << this -> GetWeight() << " kilograms, and says " << this->sound << std::endl;
    }}
/*
}
int main() {
    Animal fred;
    
    fred.ToString();
    fred.SetHeight(33);
    fred.SetName("Fred");
    fred.SetWeight(10);
    fred.ToString();
    
    Animal tom("Tom",36,15);
    tom.ToString();
    
    Dog spot("Spot", 38, 16, "Wooooof");
    spot.ToString();
    
    std::cout << "Number of animals in the Kingdom " << Animal::GetNumOfAnimals() << "!" << std::endl;
    
    return 0;
}
*/
