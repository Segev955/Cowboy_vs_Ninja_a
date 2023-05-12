#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cassert>
#include "doctest.h"
using namespace std;

#include "sources/Team.hpp"

using namespace ariel;

TEST_CASE("Point") {
    Point a(1.1,2.5), b(23.1,34);
    CHECK_EQ(a.getX(),1.1);
    CHECK_EQ(a.getY(),2.5);
    CHECK_EQ(a.print(),"(1.1,2.5)");
    CHECK_EQ(a.distance(b), 38.422);
//    CHECK_EQ(moveTowards(a,b,1), Point(1,1));
}

TEST_CASE("Character") {
    CHECK_NOTHROW(Character());
    Point p(1.1,2.5), p2(1.5,2.1);
    Character a("Segev", p,10) , b("Tzabar", p2, 15);
    CHECK(a.isAlive());
    CHECK(b.isAlive());
    CHECK_EQ(b.distance(&a), a.distance(&b));
    CHECK_EQ(a.distance(&b), 0.565685);
    CHECK_EQ(b.getHitPoint(), 15);
    CHECK_NOTHROW(b.hit(5)); //hitPoint -5
    CHECK_EQ(b.getHitPoint(), 10);
    CHECK_EQ(a.getName(), "Segev");
    CHECK_EQ(b.getLocation(), p2);
    CHECK_NOTHROW(a.attack(&b));
}

TEST_CASE("Cowboy") {
    Point p(1.1,2.5), p2(1.5,2.1);
    Character b("Tzabar", p2, 15);
    Cowboy c("Segev", p);
    CHECK_EQ(c.getHitPoint(), 110);
    CHECK_EQ(c.getBullets(), 6);
    CHECK(c.hasboolets());
    CHECK(c.isAlive());
    CHECK_NOTHROW(c.attack(&b));
    CHECK_EQ(c.getBullets(), 5);
    CHECK_NOTHROW(c.reload());
    CHECK_EQ(c.getBullets(), 6);
    CHECK_NOTHROW(c.shoot(&b));
    CHECK_FALSE(b.isAlive());
}

TEST_CASE("Ninja") {
    Point p(1.1,2.5), p2(1.5,2.1);
    Character b("Tzabar", p2, 15);
    Ninja n("Segev", p, 20, 17);
    CHECK_NOTHROW(n.move(&b));
    CHECK_NOTHROW(n.slash(&b));
    CHECK_NOTHROW(n.attack(&b));
    CHECK_FALSE(b.isAlive());

    YoungNinja y("Young", p);
    CHECK_EQ(y.getHitPoint(), 100);
    CHECK_EQ(y.getSpeed(), 14);

    TrainedNinja t("Trained", p);
    CHECK_EQ(t.getHitPoint(), 120);
    CHECK_EQ(t.getSpeed(), 12);

    OldNinja o("Old", p);
    CHECK_EQ(o.getHitPoint(), 150);
    CHECK_EQ(o.getSpeed(), 8);
}

TEST_CASE("Team") {
    Point p(1.1, 2.5), p2(1.5, 2.1);
    Ninja n("Segev", p, 20, 17);
    YoungNinja y("Young", p);
    Cowboy c("Tzabar", p2);
    Team team(&n);
    Team team2(&c);
    CHECK_NOTHROW(team.add(&y));
    CHECK_EQ(team.stillAlive(), 2);
    CHECK_NOTHROW(team.print());
//    CHECK_NOTHROW(team.attack(&team2));
}


