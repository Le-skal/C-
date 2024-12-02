#include "Billet.h"
#include <iostream>

Billet::Billet(const std::string& numero, const std::string& type, double prix,
    const std::string& train, const std::string& date)
    : numeroBillet(numero), typeClasse(type), prix(prix), numeroTrain(train), dateVoyage(date) {}

void Billet::afficherDetailsBillet() const {
    std::cout << "Billet No: " << numeroBillet << "\nClasse: " << typeClasse
        << "\nPrix: " << prix << " EUR\nTrain: " << numeroTrain
        << "\nDate: " << dateVoyage << std::endl;
}

std::string Billet::getNumeroBillet() const {
    return numeroBillet;
}
