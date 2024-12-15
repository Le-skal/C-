#include "Passager.h"
#include <iostream>
#include <algorithm>

Passager::Passager(const std::string& nom, const std::string& prenom, int id)
    : nom(nom), prenom(prenom), identifiant(id) {}
Passager::~Passager() {
    for (Billet* billet : reservations) {
        delete billet;
    }
    for (Billet* billet : historiqueReservations) {
        delete billet;
    }
}

void Passager::ajouterReservation(Billet* billet) {
    reservations.push_back(billet);
}

void Passager::annulerReservation(int numeroBillet) {
    for (size_t i = 0; i < reservations.size(); ++i) {
        if (reservations[i]->numeroBillet == numeroBillet) {
            historiqueReservations.push_back(reservations[i]);
            reservations.erase(reservations.begin() + i);
            std::cout << "Réservation annulée avec succès." << std::endl;
            return;
        }
    }
    std::cout << "Aucune réservation trouvée avec ce numéro." << std::endl;
}


void Passager::afficherReservations() const {
    if (reservations.empty()) {
        std::cout << "Aucune réservation actuelle." << std::endl;
        return;
    }
    std::cout << "Reservations actuelles de " << prenom << " " << nom << ":" << std::endl;
    for (const auto& billet : reservations) {
        billet->afficherDetailsBillet();
    }
}

void Passager::ajouterHistorique(Billet* billet) {
    historiqueReservations.push_back(billet);
}

void Passager::afficherHistorique() const {
    if (historiqueReservations.empty()) {
        std::cout << "Aucun historique de réservation." << std::endl;
        return;
    }
    std::cout << "Historique des réservations de " << prenom << " " << nom << ":" << std::endl;
    for (const auto& billet : historiqueReservations) {
        billet->afficherDetailsBillet();
    }
}

void Passager::filtrerHistorique(const std::string& critere, const std::string& valeur) const {
    std::cout << "Historique filtré par " << critere << " avec la valeur : " << valeur << ":" << std::endl;
    for (const auto& billet : historiqueReservations) {
        if (critere == "date" && billet->dateVoyage == valeur) {
            billet->afficherDetailsBillet();
        }
        else if (critere == "typeClasse" && billet->typeClasse == valeur) {
            billet->afficherDetailsBillet();
        }
        else if (critere == "numeroTrain" && std::to_string(billet->numeroTrain) == valeur) {
            billet->afficherDetailsBillet();
        }
    }

}
bool Passager::findReservation(int numeroBillet) const {
    for (const auto& billet : reservations) {
        if (billet->numeroBillet == numeroBillet) {
            return true;
        }
    }
    return false;
}
void Passager::removeReservation(int numeroBillet) {
    for (size_t i = 0; i < reservations.size(); ++i) {
        if (reservations[i]->numeroBillet == numeroBillet) {
            reservations.erase(reservations.begin() + i);
            return;
        }
    }
    std::cout << "Aucune réservation trouvée avec ce numéro." << std::endl;
}