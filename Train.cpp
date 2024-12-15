#include "Train.h"
#include <iostream>

Train::Train(int numero, const std::string& depart, const std::string& arrivee,
    const std::string& hDepart, const std::string& hArrivee, int capacite)
    : numeroTrain(numero), villeDepart(depart), villeArrivee(arrivee),
    horaireDepart(hDepart), horaireArrivee(hArrivee), capacite(capacite),
    placesLibres(capacite) {}

bool Train::verifierDisponibilite() const {
    return placesLibres > 0;
}

bool Train::reserverPlace() {
    if (verifierDisponibilite()) {
        placesLibres--;
        return true;
    }
    return false;
}

void Train::annulerReservation() {
    if (placesLibres < capacite) {
        placesLibres++;
    }
}

void Train::afficherInfosTrain() const {
    std::cout << "Train #" << numeroTrain << ": " << villeDepart << " -> " << villeArrivee
        << ", Depart: " << horaireDepart << ", Arrivee: " << horaireArrivee
        << ", Places disponibles: " << placesLibres << "/" << capacite << std::endl;
}
void Train::setPlacesLibres(int places) {
    placesLibres = places;
}