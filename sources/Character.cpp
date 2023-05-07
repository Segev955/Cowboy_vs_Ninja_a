//
// Created by segev95 on 04/05/2023.
//

#include "Team.hpp"
using namespace ariel;

//constructor
Character::Character(const string &name, const Point &pos, const int hitPoint) : name(name), pos(pos),
                                                                                 hitPoint(hitPoint) {}

bool Character::isAlive() {
    if (hitPoint > 0)
        return true;
    return false;
}

double Character::distance(Character *c) {
    return this->pos.distance(c);
}

void Character::hit(int num) {
    this->hitPoint -= num;
}

string Character::getName() {
    return this->name;
}

Point Character::getLocation() {
    return this->pos;
}

void Character::print() {
    if (!isAlive()) {
        cout << '(' << name << ')' << endl;
    } else {
        cout << name << endl;
        cout << hitPoint << endl;
        cout << pos << endl;
    }
}

ostream &operator <<(ostream &output, const Character &character) {
    output << character.print();
    return output;
}

//Cowboy ----------------------------------------------------
Cowboy::Cowboy(const string &name, const Point &pos) : Character(name,pos,110) , bullets(6) {}

void Cowboy::shoot(Character *enemy) {
    if (isAlive() && hasboolets()) {
        enemy->hit(10);
        bullets --;
    }
}

bool Cowboy::hasboolets() {
    if (this->bullets > 0)
        return true;
    return false;
}

void Cowboy::reload() {
    this->bullets = 6;
}

//Cowboy ----------------------------------------------------

//Ninja -----------------------------------------------------
Ninja::Ninja(const string &name, const Point &pos, int hitPoint, int speed) : Character(name,pos,hitPoint), speed(speed) {}

void Ninja::move(Character *enemy) {
    this->pos = moveTowards(this->getLocation(), enemy->getLocation(), this->speed);
}

void Ninja::slash(Character *enemy) {
    if(isAlive() && this->getLocation().distance(enemy) < 1) {
        enemy->hit(31);
    }
}

//Ninja -----------------------------------------------------
