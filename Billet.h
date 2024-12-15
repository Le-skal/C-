#ifndef BILLET_H
#define BILLET_H

#include <string>

using namespace std;

class Billet {
private:
    int numeroBillet;
    string typeClasse;
    float prix;
    int numeroTrain;
    string dateVoyage;

public:
    Billet(int numero, const string& type, float prix, int train, const string& date);

    void afficherDetailsBillet() const;

    float calculerPrix(float distance, bool isPremiereClasse) const;

    int getNumeroBillet() const { return numeroBillet; }
    string getDateVoyage() const { return dateVoyage; }
    string getTypeClasse() const { return typeClasse; }
    float getPrix() const { return prix; }

};

#endif
