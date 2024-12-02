#ifndef BILLET_H
#define BILLET_H

#include <string>

class Billet {
private:
    std::string numeroBillet;
    std::string typeClasse;
    double prix;
    std::string numeroTrain;
    std::string dateVoyage;

public:
    Billet(const std::string& numero, const std::string& type, double prix,
        const std::string& train, const std::string& date);

    void afficherDetailsBillet() const;

    // Getter pour numeroBillet
    std::string getNumeroBillet() const;
};

#endif
