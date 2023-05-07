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
#include <vector>
#include <cfloat>


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
    friend Point moveTowards(Point src, Point des, double dis);

    friend ostream &operator <<(ostream &output, const Point &point);
    friend istream &operator >>(std::istream &input, Point &point);

};

class Character {
protected:
    Point pos;
    int hitPoint;
    string name;

public:
    Character(const string &name, const Point &pos, const int hitPoint);
    bool isAlive();
    double distance(Character *c);
    void hit(int num);
    string getName();
    Point getLocation();
    void print();

    friend ostream &operator <<(ostream &output, const Character &character);

};
//Cowboy:
class Cowboy: public Character {
private:
    int bullets;

public:
    Cowboy(const string &name, const Point &pos); //6 bullets, 110 hitPoints.
    void shoot(Character *enemy);
    bool hasboolets();
    void reload();
};
//ninja:
class Ninja: public Character {
private:
    int speed;
public:
    Ninja (const string &name, const Point &pos, int hitPoint, int speed);
    void move(Character *enemy);
    void slash(Character *enemy);
};

class YoungNinja: public Ninja {
public:
    YoungNinja(const string &name, const Point &pos) : Ninja(name,pos,100, 14){}
};

class TrainedNinja : public Ninja {
public:
    TrainedNinja(const string &name, const Point &pos) : Ninja(name,pos,120, 12){}
};

class OldNinja: public Ninja {
public:
    OldNinja(const string &name, const Point &pos) : Ninja(name,pos,150, 8){}
};


class Team {
private:
    vector<Character*> teamMates;
    Character leader;
public:
    void add(Character *c);
    void attack();
    int stillAlive();
    void print();
    void nextLeader();

    friend ostream &operator <<(ostream &output, const Team &team);

};


#endif //COWBOY_VS_NINJA_A_TEAM_HPP

