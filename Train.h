#ifndef TRAIN_H
#define TRAIN_H

#include <string>

class Train {
private:
    std::string numeroTrain;
    std::string villeDepart;
    std::string villeArrivee;
    std::string horaireDepart;
    std::string horaireArrivee;
    int capacite;
    int placesLibres;

public:
    Train(const std::string& numero, const std::string& depart, const std::string& arrivee,
        const std::string& horaireDep, const std::string& horaireArr, int cap);

    bool verifierDisponibilite() const;
    bool reserverPlace();
    bool annulerReservation();
    void afficherInfosTrain() const;
    std::string getNumeroTrain() const;
};

#endif
