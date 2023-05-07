//
// Created by segev95 on 04/05/2023.
//

#include "Team.hpp"

void Team::add(Character *c) {
    if (this->teamMates.size() < 10)
        this->teamMates.push_back(c);
}

void Team::nextLeader() {
    double minDis = DBL_MAX;
    for (int i = 0; i < teamMates.size(); ++i) {
        if (teamMates[i]->distance(leader) <= 0)
            continue;
        if (teamMates[i]->distance(leader) < minDis) {
            minDis = teamMates[i]->distance(leader);
            leader = teamMates[i];
        }
    }
}
void Team::attack() {
    if (!this->leader.isAlive()) {
        nextLeader();
    }

}

int Team::stillAlive() {
    return teamMates.size();
}

void Team::print() {
    for (int i = 0; i < teamMates.size(); ++i) {
        cout << teamMates[i] << endl;
    }
}

ostream &operator <<(ostream &output, const Team &team) {
    if(team.stillAlive())
        output << "Leader: " << team.leader ->getName();
    else
        output << "All Dead";
    output << '\n'<<"Participants: ";
    for (auto item : team.characters) {
        output << *item << ", ";
    }
    return output;
}
