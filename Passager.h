#ifndef PASSAGER_H
#define PASSAGER_H

#include <string>
#include <vector>
#include "Billet.h"

using namespace std;

class Passager {
private:
    string nom;
    string prenom;
    int identifiant;
    vector<Billet> reservations;
    vector<Billet> historiqueReservations;

public:
    Passager(const string& nom, const string& prenom, int id);

    void ajouterReservation(const Billet& billet);
    void annulerReservation(int numeroBillet);
    void afficherReservations() const;

    void ajouterHistorique(const Billet& billet);
    void afficherHistorique() const;
    void filtrerHistorique(const string& date) const;

    string getNom() const { return nom; }
    string getPrenom() const { return prenom; }
    int getIdentifiant() const { return identifiant; }
};

#endif
