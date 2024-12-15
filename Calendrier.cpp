#include "Calendrier.h"
#include <iostream>

using namespace std;

void Calendrier::ajouterHoraire(const string& date, const Train& train) {
    horaireTrain[date].push_back(train);
}

void Calendrier::afficherCalendrier() const {
    for (const auto& entry : horaireTrain) {
        cout << "Date: " << entry.first << endl;
        for (const auto& train : entry.second) {
            train.afficherInfosTrain();
        }
    }
}

void Calendrier::rechercherTrainsParDate(const string& date, const string& depart, const string& arrivee) const {
    if (horaireTrain.find(date) != horaireTrain.end()) {
        for (const auto& train : horaireTrain.at(date)) {
            if (train.getVilleDepart() == depart && train.getVilleArrivee() == arrivee) {
                train.afficherInfosTrain();
            }
        }
    }
    else {
        cout << "Aucun train trouvé pour la date: " << date << endl;
    }
}
