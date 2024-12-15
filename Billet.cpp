#include "Billet.h"
#include <iostream>
#include <cmath>
#include <cstdlib>

Billet::Billet(int numero, const std::string& classe, int train, const std::string& date)
    : numeroBillet(numero), typeClasse(classe), numeroTrain(train), dateVoyage(date) {
}

void Billet::afficherDetailsBillet() const {
    std::cout << "Billet #" << numeroBillet << ", Classe: " << typeClasse
        << ", Prix: " << prix << " €, Train #" << numeroTrain
        << ", Date: " << dateVoyage << std::endl;
}

double Billet::calculerPrix(const std::string& villeDepart, const std::string& villeArrivee) {
    // Simule un calcul de prix basé sur la distance
    double distance = std::abs(static_cast<int>(villeDepart[0]) - static_cast<int>(villeArrivee[0]));
    double prixBase = distance * 2.5; // Exemple : 2.5€ par "unité de distance"
    if (typeClasse == "premiere") {
        prix = prixBase * 1.5; // La première classe coûte 50% de plus
    }
    else {
        prix = prixBase;
    }
    return prix;
}