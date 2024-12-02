#include "Train.h"
#include <iostream>

Train::Train(const std::string& numero, const std::string& depart, const std::string& arrivee,
    const std::string& horaireDep, const std::string& horaireArr, int cap)
    : numeroTrain(numero), villeDepart(depart), villeArrivee(arrivee),
    horaireDepart(horaireDep), horaireArrivee(horaireArr), capacite(cap), placesLibres(cap) {}

bool Train::verifierDisponibilite() const {
    return placesLibres > 0;
}

bool Train::reserverPlace() {
    if (placesLibres > 0) {
        placesLibres--;
        return true;
    }
    return false;
}

bool Train::annulerReservation() {
    if (placesLibres < capacite) {
        placesLibres++;
        return true;
    }
    return false;
}

void Train::afficherInfosTrain() const {
    std::cout << "Train: " << numeroTrain << " | "
        << villeDepart << " -> " << villeArrivee << "\n"
        << "Horaires: " << horaireDepart << " - " << horaireArrivee << "\n"
        << "Places disponibles: " << placesLibres << "/" << capacite << std::endl;
}
std::string Train::getNumeroTrain() const {
    return numeroTrain;
}
