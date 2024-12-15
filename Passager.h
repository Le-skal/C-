#ifndef PASSAGER_H
#define PASSAGER_H

#include <string>
#include <vector>
#include "Billet.h"

class Passager {
public:
    std::string nom;
    std::string prenom;
    int identifiant;
    std::vector<Billet*> reservations;
    std::vector<Billet*> historiqueReservations;

    Passager(const std::string& nom, const std::string& prenom, int id);
    ~Passager();

    void ajouterReservation(Billet* billet);
    void annulerReservation(int numeroBillet);
    void afficherReservations() const;
    void ajouterHistorique(Billet* billet);
    void afficherHistorique() const;
    void filtrerHistorique(const std::string& critere, const std::string& valeur) const;
    bool findReservation(int numeroBillet) const;
    void removeReservation(int numeroBillet);

};

#endif