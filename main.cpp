#include <iostream>
#include "Train.h"
#include "Billet.h"
#include "Passager.h"

#include <iostream>
#include "Train.h"
#include "Billet.h"
#include "Passager.h"

void main() {
    // Cr�ation d'un train
    Train train1("TGV123", "Paris", "Lyon", "08:00", "10:00", 100);

    // Affichage des informations du train
    std::cout << "\n--- Informations Train ---\n";
    train1.afficherInfosTrain();

    // V�rification de disponibilit�
    std::cout << "\n--- V�rification de disponibilit� ---\n";
    if (train1.verifierDisponibilite()) {
        std::cout << "Des places sont disponibles.\n";
    }
    else {
        std::cout << "Aucune place disponible.\n";
    }

    // Cr�ation d'un passager
    Passager passager1("Dupont", "Jean", "P001");

    // R�servation d'une place
    std::cout << "\n--- R�servation d'une place ---\n";
    if (train1.reserverPlace()) {
        Billet billet1("B001", "2eme Classe", 50.0, train1.getNumeroTrain(), "2024-12-25");
        passager1.ajouterReservation(billet1);
        std::cout << "R�servation r�ussie.\n";
    }
    else {
        std::cout << "R�servation �chou�e. Plus de places disponibles.\n";
    }

    // Affichage des r�servations du passager
    std::cout << "\n--- R�servations du passager ---\n";
    passager1.afficherReservations();

    // Annulation de la r�servation
    std::cout << "\n--- Annulation d'une r�servation ---\n";
    passager1.annulerReservation("B001");
    train1.annulerReservation();  // Mettre � jour les places disponibles dans le train

    std::cout << "R�servation annul�e.\n";

    // Affichage des r�servations apr�s annulation
    std::cout << "\n--- R�servations du passager apr�s annulation ---\n";
    passager1.afficherReservations();

    // Affichage des informations mises � jour du train
    std::cout << "\n--- Informations Train apr�s annulation ---\n";
    train1.afficherInfosTrain();

}


