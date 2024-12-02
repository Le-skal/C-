#include <iostream>
#include "Train.h"
#include "Billet.h"
#include "Passager.h"

#include <iostream>
#include "Train.h"
#include "Billet.h"
#include "Passager.h"

void main() {
    // Création d'un train
    Train train1("TGV123", "Paris", "Lyon", "08:00", "10:00", 100);

    // Affichage des informations du train
    std::cout << "\n--- Informations Train ---\n";
    train1.afficherInfosTrain();

    // Vérification de disponibilité
    std::cout << "\n--- Vérification de disponibilité ---\n";
    if (train1.verifierDisponibilite()) {
        std::cout << "Des places sont disponibles.\n";
    }
    else {
        std::cout << "Aucune place disponible.\n";
    }

    // Création d'un passager
    Passager passager1("Dupont", "Jean", "P001");

    // Réservation d'une place
    std::cout << "\n--- Réservation d'une place ---\n";
    if (train1.reserverPlace()) {
        Billet billet1("B001", "2eme Classe", 50.0, train1.getNumeroTrain(), "2024-12-25");
        passager1.ajouterReservation(billet1);
        std::cout << "Réservation réussie.\n";
    }
    else {
        std::cout << "Réservation échouée. Plus de places disponibles.\n";
    }

    // Affichage des réservations du passager
    std::cout << "\n--- Réservations du passager ---\n";
    passager1.afficherReservations();

    // Annulation de la réservation
    std::cout << "\n--- Annulation d'une réservation ---\n";
    passager1.annulerReservation("B001");
    train1.annulerReservation();  // Mettre à jour les places disponibles dans le train

    std::cout << "Réservation annulée.\n";

    // Affichage des réservations après annulation
    std::cout << "\n--- Réservations du passager après annulation ---\n";
    passager1.afficherReservations();

    // Affichage des informations mises à jour du train
    std::cout << "\n--- Informations Train après annulation ---\n";
    train1.afficherInfosTrain();

}


