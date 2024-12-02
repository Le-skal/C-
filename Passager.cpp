#include "Passager.h"
#include <iostream>
#include <algorithm>

Passager::Passager(const std::string& nom, const std::string& prenom, const std::string& id)
    : nom(nom), prenom(prenom), identifiant(id) {}

void Passager::ajouterReservation(const Billet& billet) {
    reservations.push_back(billet);
}

void Passager::annulerReservation(const std::string& numeroBillet) {
    reservations.erase(std::remove_if(reservations.begin(), reservations.end(),
        [&numeroBillet](const Billet& billet) {
            return billet.getNumeroBillet() == numeroBillet;
        }), reservations.end());
}

void Passager::afficherReservations() const {
    for (const auto& billet : reservations) {
        billet.afficherDetailsBillet();
    }
}
