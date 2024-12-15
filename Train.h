#ifndef TRAIN_H
#define TRAIN_H

#include <string>

using namespace std;

class Train {
private:
    int numeroTrain;
    string villeDepart;
    string villeArrivee;
    string horaireDepart;
    string horaireArrivee;
    int capacite;
    int placesLibres;

public:
    Train(int numero, const string& depart, const string& arrivee,
        const string& horaireDep, const string& horaireArr, int capacite);

    void reserverPlace();
    void annulerReservation();
    bool verifierDisponibilite() const;
    void afficherInfosTrain() const;

    string getVilleDepart() const { return villeDepart; }
    string getVilleArrivee() const { return villeArrivee; }
    int getNumeroTrain() const { return numeroTrain; }
    int getPlacesLibres() const { return placesLibres; }
};

#endif
