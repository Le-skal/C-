#ifndef CALENDRIER_H
#define CALENDRIER_H

#include <map>
#include <vector>
#include <string>
#include "Train.h"

using namespace std;

class Calendrier {
private:
    map<string, vector<Train>> horaireTrain;

public:
    void ajouterHoraire(const string& date, const Train& train);
    void afficherCalendrier() const;
    void rechercherTrainsParDate(const string& date, const string& depart, const string& arrivee) const;
};

#endif
