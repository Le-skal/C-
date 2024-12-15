#include <iostream>
#include "Train.h"
#include "Billet.h"
#include "Passager.h"
#include "Reservation.h"
#include "Calendrier.h"

using namespace std;

int main() {
    // Initialisation des trains
    Train t1(1, "Paris", "Lyon", "08:00", "11:00", 100);
    Train t2(2, "Marseille", "Nice", "14:00", "16:00", 80);

    // Initialisation du calendrier
    Calendrier calendrier;
    calendrier.ajouterHoraire("2024-12-20", t1);
    calendrier.ajouterHoraire("2024-12-20", t2);

    cout << "\n--- Calendrier des Trains ---\n";
    calendrier.afficherCalendrier();

    // S�lection d'un passager
    Passager passager("Doe", "John", 1);

    // R�servation de billet
    Billet b1(1001, "Premi�re Classe", 50.0f, 1, "2024-12-20");
    passager.ajouterReservation(b1);
    t1.reserverPlace();

    cout << "\n--- R�servations du Passager ---\n";
    passager.afficherReservations();

    // Annulation de r�servation
    cout << "\n--- Annulation de la R�servation ---\n";
    passager.annulerReservation(1001);
    t1.annulerReservation();

    // Affichage de l'historique
    cout << "\n--- Historique des Tickets ---\n";
    passager.afficherHistorique();

    // Recherche par date et villes
    cout << "\n--- Recherche de Trains ---\n";
    calendrier.rechercherTrainsParDate("2024-12-20", "Paris", "Lyon");

    return 0;
}
