#include "Train.h"
#include <iostream>

using namespace std;

Train::Train(int num, const string& depart, const string& arrivee, const string& hDepart,
    const string& hArrivee, int cap)
    : numeroTrain(num), villeDepart(depart), villeArrivee(arrivee), horaireDepart(hDepart),
    horaireArrivee(hArrivee), capacite(cap), placesLibres(cap) {}

bool Train::verifierDisponibilite() const {
    return placesLibres > 0;
}

void Train::reserverPlace() {
    if (verifierDisponibilite()) {
        placesLibres--;
    }
    else {
        cerr << "Aucune place disponible." << endl;
    }
}

void Train::annulerReservation() {
    if (placesLibres < capacite) {
        placesLibres++;
    }
}

void Train::afficherInfosTrain() const {
    cout << "Train #" << numeroTrain << ": " << villeDepart << " -> " << villeArrivee << endl;
    cout << "Départ: " << horaireDepart << ", Arrivée: " << horaireArrivee << endl;
    cout << "Places disponibles: " << placesLibres << "/" << capacite << endl;
}
