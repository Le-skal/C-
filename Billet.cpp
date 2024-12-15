#include "Billet.h"
#include <iostream>
#include <iomanip>

using namespace std;

Billet::Billet(int numBillet, const string& classe, float prix, int numTrain, const string& date)
    : numeroBillet(numBillet), typeClasse(classe), prix(prix), numeroTrain(numTrain), dateVoyage(date) {}

void Billet::afficherDetailsBillet() const {
    cout << "Billet #" << numeroBillet << " - Classe: " << typeClasse << ", Prix: " << fixed
        << setprecision(2) << prix << " EUR, Train #" << numeroTrain << ", Date: " << dateVoyage
        << endl;
}

float Billet::calculerPrix(float distance, bool isPremiereClasse) const {
    return distance * (isPremiereClasse ? 0.2f : 0.1f);
}
