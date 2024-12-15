#include "Reservation.h"
#include <iostream>

using namespace std;

Reservation::Reservation(int num, const Passager& p, const Billet& b)
    : numeroReservation(num), passager(p), billet(b) {}

void Reservation::confirmerReservation() {
    cout << "R�servation #" << numeroReservation << " confirm�e pour " << passager.getNom() << endl;
}

void Reservation::annulerReservation() {
    cout << "R�servation #" << numeroReservation << " annul�e." << endl;
}

void Reservation::afficherDetailsReservation() const {
    cout << "R�servation #" << numeroReservation << ":\n"
        << "Passager: " << passager.getNom() << " " << passager.getPrenom() << "\n"
        << "Billet:\n";
    billet.afficherDetailsBillet();
}
