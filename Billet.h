#ifndef BILLET_H
#define BILLET_H

#include <string>

class Billet {
public:
    int numeroBillet;
    std::string typeClasse;
    double prix;
    int numeroTrain;
    std::string dateVoyage;

    Billet(int numero, const std::string& classe, int train, const std::string& date);

    void afficherDetailsBillet() const;
    double calculerPrix(const std::string& villeDepart, const std::string& villeArrivee);
};

#endif