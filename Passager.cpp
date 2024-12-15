#include "Passager.h"
#include <iostream>
#include <algorithm>

using namespace std;

Passager::Passager(const string& nom, const string& prenom, int id)
    : nom(nom), prenom(prenom), identifiant(id) {}

void Passager::ajouterReservation(const Billet& billet) {
    reservations.push_back(billet);
}

void Passager::annulerReservation(int numeroBillet) {
    auto it = remove_if(reservations.begin(), reservations.end(), [numeroBillet](const Billet& b) {
        return b.getNumeroBillet() == numeroBillet;
        });
    if (it != reservations.end()) {
        historiqueReservations.push_back(*it);
        reservations.erase(it, reservations.end());
    }
}

void Passager::afficherReservations() const {
    cout << "Réservations en cours pour " << nom << " " << prenom << ":" << endl;
    for (const auto& billet : reservations) {
        billet.afficherDetailsBillet();
    }
}

void Passager::ajouterHistorique(const Billet& billet) {
    historiqueReservations.push_back(billet);
}

void Passager::afficherHistorique() const {
    cout << "Historique des billets pour " << nom << " " << prenom << ":" << endl;
    for (const auto& billet : historiqueReservations) {
        billet.afficherDetailsBillet();
    }
}

void Passager::filtrerHistorique(const string& date) const {
    cout << "Filtrage de l'historique pour la date: " << date << endl;
    for (const auto& billet : historiqueReservations) {
        if (billet.getDateVoyage() == date) {
            billet.afficherDetailsBillet();
        }
    }
}
