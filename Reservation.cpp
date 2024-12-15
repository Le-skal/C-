#include "Reservation.h"
#include <iostream>

Reservation::Reservation(int numero, Passager* passager, Billet* billet, Train* train)
    : numeroReservation(numero), passager(passager), billet(billet), train(train) {}

void Reservation::confirmerReservation() {
    std::cout << "Reservation #" << numeroReservation << " confirmée pour "
        << passager->prenom << " " << passager->nom << "." << std::endl;
}

bool Reservation::annulerReservation() {
    if (train != nullptr && billet != nullptr && passager != nullptr) {
        train->annulerReservation();
        passager->annulerReservation(billet->numeroBillet);
        return true;
    }
    else {
        return false;
    }

}

void Reservation::afficherDetailsReservation() const {
    std::cout << "Details de la reservation #" << numeroReservation << ":" << std::endl;
    std::cout << "  Passager: " << passager->prenom << " " << passager->nom << std::endl;
    std::cout << "  "; billet->afficherDetailsBillet();
    std::cout << "  Train #" << train->numeroTrain << " : " << train->villeDepart << " -> " << train->villeArrivee << std::endl;
}