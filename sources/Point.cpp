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

void Point::print() const{
    cout << '(' << this->x << ", " << this->y << ')' << endl;
}

Point moveTowards(Point src, Point des, double dis) {
    double srcToDes = src.distance(des);
    if (dis >= srcToDes) {
        return des;
    }
    //not finish
    return Point(1,1);
}

ostream &operator <<(ostream &output, const Point &point) {
    output << '(' << point.x << ", " << point.y << ')';
    return output;
}

//Input
std::istream &operator>>(std::istream &input, Point &point) {
    int x, y;
    char delimiter;

    if (!(input >> x)) {
        throw runtime_error("Error: Invalid input for x.");
    }

    input >> ws; // Skip leading whitespace

    // Check if there is a delimiter
    if (!input.eof() && (input.peek() == ',' || input.peek() == ' '))
        input >> delimiter;

    if (!(input >> y)) {
        throw runtime_error("Error: Invalid input for y.");
    }
    point = Point(x, y);
    return input;
}



