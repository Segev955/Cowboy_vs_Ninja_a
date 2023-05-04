//
// Created by segev95 on 04/05/2023.
//

#ifndef COWBOY_VS_NINJA_A_TEAM_HPP
#define COWBOY_VS_NINJA_A_TEAM_HPP

#include <stdio.h>
#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>


namespace ariel {}
using namespace std;


class Point {
private:
    double x;
    double y;

public:
    Point(double x, double y);
    double distance(Point p);
    void print();
    Point moveTowards(Point src, Point des, double dis);
};

class Character {
private:
    Point pos;
    int hitPoint;
    string name;

public:
    bool isAlive();
    double distance(Character *c);
    void hit(int num);
    string getName();
    Point getLocation();
    void print();
};
//Cowboy:
class Cowboy: public Character {
private:
    int bullets;

public:
    void shoot(Character *enemy);
    bool hasboolets();
    void reload();
};
    //ninja:
class ninja: public Character {
public:
    void move(Character *enemy);
    void slash(Character *enemy);
};


class Team {

};


#endif //COWBOY_VS_NINJA_A_TEAM_HPP
