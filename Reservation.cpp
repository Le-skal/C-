#include "Reservation.h"
#include <iostream>

using namespace std;

Reservation::Reservation(int num, const Passager& p, const Billet& b)
    : numeroReservation(num), passager(p), billet(b) {}

void Reservation::confirmerReservation() {
    cout << "Réservation #" << numeroReservation << " confirmée pour " << passager.getNom() << endl;
}

void Reservation::annulerReservation() {
    cout << "Réservation #" << numeroReservation << " annulée." << endl;
}

void Reservation::afficherDetailsReservation() const {
    cout << "Réservation #" << numeroReservation << ":\n"
        << "Passager: " << passager.getNom() << " " << passager.getPrenom() << "\n"
        << "Billet:\n";
    billet.afficherDetailsBillet();
}
