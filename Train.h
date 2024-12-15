#ifndef TRAIN_H
#define TRAIN_H

#include <string>

class Train {
public:
    int numeroTrain;
    std::string villeDepart;
    std::string villeArrivee;
    std::string horaireDepart;
    std::string horaireArrivee;
    int capacite;
    int placesLibres;

    Train(int numero, const std::string& depart, const std::string& arrivee,
        const std::string& hDepart, const std::string& hArrivee, int capacite);

    bool verifierDisponibilite() const;
    bool reserverPlace();
    void annulerReservation();
    void afficherInfosTrain() const;
    void setPlacesLibres(int places);

};

#endif