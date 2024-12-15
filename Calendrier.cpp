#include "Calendrier.h"
#include <iostream>

void Calendrier::ajouterHoraire(const std::string& date, const Train& train) {
    horaireTrain[date].push_back(train);
}

void Calendrier::afficherCalendrier() const {
    if (horaireTrain.empty()) {
        std::cout << "Le calendrier est vide." << std::endl;
        return;
    }
    std::cout << "Calendrier des trains :" << std::endl;
    for (const auto& pair : horaireTrain) {
        std::cout << "Date: " << pair.first << std::endl;
        for (const auto& train : pair.second) {
            train.afficherInfosTrain();
        }
        std::cout << std::endl;
    }
}

void Calendrier::rechercherTrainsParDate(const std::string& date, const std::string& villeDepart, const std::string& villeArrivee) const {
    auto it = horaireTrain.find(date);
    if (it != horaireTrain.end()) {
        bool found = false;
        std::cout << "Trains disponibles pour le " << date << " entre " << villeDepart << " et " << villeArrivee << ":" << std::endl;
        for (const auto& train : it->second) {
            if (train.villeDepart == villeDepart && train.villeArrivee == villeArrivee) {
                train.afficherInfosTrain();
                found = true;
            }
        }
        if (!found) {
            std::cout << "Aucun train trouvé pour ces critères" << std::endl;
        }
    }
    else {
        std::cout << "Aucun train trouvé pour cette date" << std::endl;
    }
}