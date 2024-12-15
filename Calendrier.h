#ifndef CALENDRIER_H
#define CALENDRIER_H

#include <map>
#include <vector>
#include <string>
#include "Train.h"

class Calendrier {
public:
    std::map<std::string, std::vector<Train>> horaireTrain;

    void ajouterHoraire(const std::string& date, const Train& train);
    void afficherCalendrier() const;
    void rechercherTrainsParDate(const std::string& date, const std::string& villeDepart, const std::string& villeArrivee) const;
};

#endif