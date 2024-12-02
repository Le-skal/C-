#ifndef PASSAGER_H
#define PASSAGER_H

#include <string>
#include <vector>
#include "Billet.h"

class Passager {
private:
    std::string nom;
    std::string prenom;
    std::string identifiant;
    std::vector<Billet> reservations;

public:
    Passager(const std::string& nom, const std::string& prenom, const std::string& id);

    void ajouterReservation(const Billet& billet);
    void annulerReservation(const std::string& numeroBillet);
    void afficherReservations() const;
};

#endif
#pragma once
