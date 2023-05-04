//
// Created by segev95 on 04/05/2023.
//


#include "Team.hpp"

using namespace ariel;

Point::Point(double x, double y): x(x), y(y) {}

double Point::distance(Point p) {
    double a = pow(p.x - this->x, 2);
    double b = pow(p.y - this->y, 2);
    return sqrt(a + b);
}

void Point::print() {
    cout << '(' << this->x << ", " << this->y << ')' << endl;
}

Point Point::moveTowards(Point src, Point des, double dis) {
    double srcToDes = src.distance(des);
    if (dis >= srcToDes) {
        return des;
    }
    //not finish
    return Point(1,1);
}
