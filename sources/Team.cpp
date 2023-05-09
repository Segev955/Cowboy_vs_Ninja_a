//
// Created by segev95 on 04/05/2023.
//

#include "Team.hpp"

Team::Team(Character *leader) : leader(leader){
    this->add(leader);
}

void Team::add(Character *c) {
    if (this->teamMates.size() < 10)
        this->teamMates.push_back(c);
}


void Team::nextLeader() {
    double minDis = DBL_MAX;
    for (std::size_t i = 0; i < teamMates.size(); ++i) {
        if (teamMates[i]->distance(leader) <= 0)
            continue;
        if (teamMates[i]->distance(leader) < minDis) {
            minDis = teamMates[i]->distance(leader);
            leader = teamMates[i];
        }
    }
}

Character* Team::closest(Team *team) {
    double minDis = DBL_MAX;
    Character *c = nullptr;
    for (std::size_t i = 0; i < team->teamMates.size(); ++i) {
        if (teamMates[i]->distance(leader) < minDis) {
            minDis = teamMates[i]->distance(leader);
            c = teamMates[i];
        }
    }
    return c;
}

void Team::attack(Team *enemy) {
    cout << stillAlive() << endl;

    if (stillAlive() == 0 || enemy->stillAlive() == 0) {
        return;
    }
    if (!this->leader->isAlive()) {
        nextLeader();
    }
    Character *c = closest(enemy);
    leader->attack(c);
    attack(enemy);
}

int Team::stillAlive() const{
    return teamMates.size();
}

void Team::print() {
    for (std::size_t i = 0; i < teamMates.size(); ++i) {
        cout << teamMates[i] << endl;
    }
}

ostream &operator<<(ostream &output, const Team &team) {
    if (team.stillAlive())
        output << "Leader: " << team.leader->getName();
    else
        output << "All Dead";
    output << '\n' << "Participants: ";
    for (auto item: team.teamMates) {
        output << *item << ", ";
    }
    return output;
}

