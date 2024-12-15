#include <iostream>
#include <vector>
#include <limits>
#include "Train.h"
#include "Billet.h"
#include "Passager.h"
#include "Reservation.h"
#include "Calendrier.h"
#include "GestionFichiers.h"
#include "Utils.h"
#include <fstream>
#include <sstream>

//Variables Globales
std::vector<Train*> trains;
std::vector<Passager*> passagers;
std::vector<Billet*> billets;
std::vector<Reservation> reservations;
Calendrier calendrier;
int dernierNumeroBillet = 0;
int dernierNumeroReservation = 0;
int dernierNumeroTrain = 0;
int dernierIdPassager = 0;

// Fonctions utilitaires
int getNextBilletNumber() {
    return ++dernierNumeroBillet;
}
int getNextReservationNumber() {
    return ++dernierNumeroReservation;
}
int getNextTrainNumber() {
    return ++dernierNumeroTrain;
}
int getNextPassagerId() {
    return ++dernierIdPassager;
}
//Fonctions de chargement et de sauvegarde
void chargerDonnees() {

    std::vector<Train> tempTrains = chargerDonneesTrains("trains.txt");
    for (auto& train : tempTrains) {
        trains.push_back(new Train(train));
    }
    std::vector<Passager> tempPassagers = chargerDonneesPassagers("passagers.txt");
    for (auto& passager : tempPassagers) {
        passagers.push_back(new Passager(passager));
    }


    std::vector<Billet> tempBillets = chargerDonneesBillets("billets.txt", tempTrains);
    for (auto& billet : tempBillets) {
        billets.push_back(new Billet(billet));
    }

    reservations = chargerDonneesReservations("reservations.txt", passagers, billets, trains);

    for (const auto& train : trains) {
        if (train->numeroTrain > dernierNumeroTrain) {
            dernierNumeroTrain = train->numeroTrain;
        }
    }
    for (const auto& billet : billets) {
        if (billet->numeroBillet > dernierNumeroBillet) {
            dernierNumeroBillet = billet->numeroBillet;
        }
    }
    for (const auto& reservation : reservations) {
        if (reservation.numeroReservation > dernierNumeroReservation) {
            dernierNumeroReservation = reservation.numeroReservation;
        }
    }
    for (const auto& passager : passagers) {
        if (passager->identifiant > dernierIdPassager) {
            dernierIdPassager = passager->identifiant;
        }
    }


    for (const auto& train : trains) {
        std::string date = "01/01/2024";
        calendrier.ajouterHoraire(date, *train);
    }

    std::cout << "Données chargées avec succès." << std::endl;
}
void sauvegarderDonnees() {
    std::vector<Train> tempTrains;
    for (const auto& train : trains) {
        tempTrains.push_back(*train);
    }
    std::vector<Passager> tempPassagers;
    for (const auto& passager : passagers) {
        tempPassagers.push_back(*passager);
    }
    std::vector<Billet> tempBillets;
    for (const auto& billet : billets) {
        tempBillets.push_back(*billet);
    }
    
    sauvegarderDonneesTrains("trains.txt", tempTrains);
    sauvegarderDonneesPassagers("passagers.txt", tempPassagers);
    sauvegarderDonneesBillets("billets.txt", tempBillets);
    sauvegarderDonneesReservations("reservations.txt", reservations);
    std::cout << "Données sauvegardées avec succès." << std::endl;
}

// Fonctions d'interaction utilisateur
void afficherMenu() {
    std::cout << "\n=== Menu Principal ===" << std::endl;
    std::cout << "1. Reserver un billet" << std::endl;
    std::cout << "2. Annuler une reservation" << std::endl;
    std::cout << "3. Afficher les reservations" << std::endl;
    std::cout << "4. Afficher le calendrier des trains" << std::endl;
    std::cout << "5. Afficher l'historique des tickets" << std::endl;
    std::cout << "6. Ajouter un nouveau train" << std::endl;
    std::cout << "7. Quitter" << std::endl;
    std::cout << "Choisissez une option: ";
}

void reserverBillet() {
    int choixTrain;
    std::string typeClasse;
    std::string dateVoyage;
    std::string nomPassager, prenomPassager;
    int idPassager;

    if (trains.empty()) {
        std::cout << "Aucun train disponible pour le moment." << std::endl;
        return;
    }

    std::cout << "=== Liste des trains disponibles ===" << std::endl;
    for (size_t i = 0; i < trains.size(); ++i) {
        std::cout << i + 1 << ". ";
        trains[i]->afficherInfosTrain();
    }

    while (true) {
        std::cout << "Choisissez un train (numéro): ";
        std::string input;
        std::cin >> input;

        if (estNombreValide(input)) {
            choixTrain = std::stoi(input);
            if (choixTrain > 0 && choixTrain <= trains.size()) {
                break;
            }
        }
        std::cout << "Choix invalide. Veuillez entrer un nombre valide." << std::endl;
        viderBuffer();
    }
    viderBuffer();


    while (true) {
        std::cout << "Choisissez le type de billet (premiere/deuxieme): ";
        std::cin >> typeClasse;
        if (typeClasse == "premiere" || typeClasse == "deuxieme") {
            break;
        }
        std::cout << "Type de billet invalide. Veuillez choisir premiere ou deuxieme." << std::endl;
    }

    while (true) {
        std::cout << "Entrez la date du voyage (JJ/MM/AAAA): ";
        std::cin >> dateVoyage;
        if (estDateValide(dateVoyage)) {
            break;
        }
        std::cout << "Format de date invalide. Veuillez entrer une date valide (JJ/MM/AAAA)." << std::endl;
        viderBuffer();
    }


    std::cout << "=== Informations du passager ===" << std::endl;

    while (true) {
        std::cout << "Nom: ";
        std::cin >> nomPassager;
        if (!nomPassager.empty()) {
            break;
        }
        std::cout << "Nom invalide. Veuillez entrer un nom valide." << std::endl;
    }

    while (true) {
        std::cout << "Prenom: ";
        std::cin >> prenomPassager;
        if (!prenomPassager.empty()) {
            break;
        }
        std::cout << "Prenom invalide. Veuillez entrer un prenom valide." << std::endl;
    }

    idPassager = getNextPassagerId();


    Train* trainChoisi = trains[choixTrain - 1];

    if (!trainChoisi->verifierDisponibilite()) {
        std::cout << "Desole, ce train est complet." << std::endl;
        return;
    }

    Passager* passager = new Passager(nomPassager, prenomPassager, idPassager);

    bool passagerExiste = false;
    for (auto& existingPassager : passagers) {
        if (existingPassager->identifiant == passager->identifiant) {
            passagerExiste = true;
            delete passager;
            passager = existingPassager;
            break;
        }
    }
    if (!passagerExiste) {
        passagers.push_back(passager);
    }


    int numeroBillet = getNextBilletNumber();
    Billet* billet = new Billet(numeroBillet, typeClasse, trainChoisi->numeroTrain, dateVoyage);
    billet->calculerPrix(trainChoisi->villeDepart, trainChoisi->villeArrivee);



    int numeroReservation = getNextReservationNumber();
    Reservation reservation(numeroReservation, passager, billet, trainChoisi);

    reservations.push_back(reservation);

    passager->ajouterReservation(billet);
    trainChoisi->reserverPlace();
    reservation.confirmerReservation();

    std::cout << "Réservation effectuée avec succès." << std::endl;

}

void annulerReservation() {
    int numeroReservation;

    if (reservations.empty()) {
        std::cout << "Aucune réservation trouvée." << std::endl;
        return;
    }

    while (true) {
        std::cout << "Entrez le numero de reservation à annuler : ";
        std::string input;
        std::cin >> input;

        if (estNombreValide(input)) {
            numeroReservation = std::stoi(input);
            bool reservationFound = false;
            for (size_t i = 0; i < reservations.size(); ++i) {
                if (reservations[i].numeroReservation == numeroReservation) {
                    if (reservations[i].annulerReservation()) {
                        reservations.erase(reservations.begin() + i);
                        std::cout << "Réservation #" << numeroReservation << " annulée avec succès." << std::endl;
                    }
                    else {
                        std::cout << "Impossible d'annuler cette réservation." << std::endl;
                    }

                    reservationFound = true;
                    break;
                }
            }
            if (reservationFound) {
                break;
            }
        }
        std::cout << "Numero de reservation invalide ou non existant." << std::endl;
        viderBuffer();
    }
}

void afficherReservations() {
    int idPassager;
    if (passagers.empty()) {
        std::cout << "Aucun passager enregistré." << std::endl;
        return;
    }

    while (true) {
        std::cout << "Entrez votre ID passager : ";
        std::string input;
        std::cin >> input;
        if (estNombreValide(input)) {
            idPassager = std::stoi(input);
            bool passagerFound = false;
            for (const auto& passager : passagers) {
                if (passager->identifiant == idPassager) {
                    passager->afficherReservations();
                    passagerFound = true;
                    break;
                }
            }
            if (passagerFound) {
                break;
            }
        }
        std::cout << "ID passager invalide ou non existant." << std::endl;
        viderBuffer();
    }
}


void afficherCalendrierTrains() {
    calendrier.afficherCalendrier();
    std::string date, villeDepart, villeArrivee;

    while (true) {
        std::cout << "Entrez la date (JJ/MM/AAAA) pour filtrer: ";
        std::cin >> date;
        if (estDateValide(date)) {
            break;
        }
        std::cout << "Format de date invalide. Veuillez entrer une date valide (JJ/MM/AAAA)." << std::endl;
        viderBuffer();
    }
    while (true) {
        std::cout << "Ville de depart: ";
        std::cin >> villeDepart;
        if (!villeDepart.empty()) {
            break;
        }
        std::cout << "Ville de depart invalide." << std::endl;
    }
    while (true) {
        std::cout << "Ville d'arrivee: ";
        std::cin >> villeArrivee;
        if (!villeArrivee.empty()) {
            break;
        }
        std::cout << "Ville d'arrivee invalide." << std::endl;
    }

    calendrier.rechercherTrainsParDate(date, villeDepart, villeArrivee);
}

void afficherHistoriqueTickets() {
    int idPassager;
    std::string critere, valeur;
    if (passagers.empty()) {
        std::cout << "Aucun passager enregistré." << std::endl;
        return;
    }

    while (true) {
        std::cout << "Entrez votre ID passager : ";
        std::string input;
        std::cin >> input;
        if (estNombreValide(input)) {
            idPassager = std::stoi(input);
            bool passagerFound = false;
            for (const auto& passager : passagers) {
                if (passager->identifiant == idPassager) {
                    std::cout << "1. Afficher tout l'historique" << std::endl;
                    std::cout << "2. Filtrer l'historique" << std::endl;
                    std::cout << "Choisissez une option: ";
                    int choix;
                    std::cin >> choix;
                    switch (choix) {
                    case 1:
                        passager->afficherHistorique();
                        break;
                    case 2:
                        std::cout << "Critère de filtrage (date, typeClasse, numeroTrain): ";
                        std::cin >> critere;
                        std::cout << "Valeur pour le filtrage: ";
                        std::cin >> valeur;
                        passager->filtrerHistorique(critere, valeur);
                        break;
                    default:
                        std::cout << "Option invalide" << std::endl;
                        break;
                    }
                    passagerFound = true;
                    break;
                }
            }
            if (passagerFound) {
                break;
            }

        }
        std::cout << "ID passager invalide ou non existant." << std::endl;
        viderBuffer();
    }

}
void ajouterNouveauTrain() {
    int numeroTrain, capacite;
    std::string villeDepart, villeArrivee, horaireDepart, horaireArrivee;

    numeroTrain = getNextTrainNumber();

    while (true) {
        std::cout << "Ville de départ: ";
        std::cin >> villeDepart;
        if (!villeDepart.empty()) {
            break;
        }
        std::cout << "Ville de depart invalide." << std::endl;
    }

    while (true) {
        std::cout << "Ville d'arrivée: ";
        std::cin >> villeArrivee;
        if (!villeArrivee.empty()) {
            break;
        }
        std::cout << "Ville d'arrivee invalide." << std::endl;
    }
    while (true) {
        std::cout << "Horaire de depart (HH:MM): ";
        std::cin >> horaireDepart;
        if (estHeureValide(horaireDepart)) {
            break;
        }
        std::cout << "Format d'heure invalide. Veuillez entrer une heure valide (HH:MM)." << std::endl;
        viderBuffer();
    }
    while (true) {
        std::cout << "Horaire d'arrivee (HH:MM): ";
        std::cin >> horaireArrivee;
        if (estHeureValide(horaireArrivee)) {
            break;
        }
        std::cout << "Format d'heure invalide. Veuillez entrer une heure valide (HH:MM)." << std::endl;
        viderBuffer();
    }

    while (true) {
        std::cout << "Capacite du train: ";
        std::string input;
        std::cin >> input;
        if (estNombreValide(input)) {
            capacite = std::stoi(input);
            if (capacite > 0) {
                break;
            }
        }
        std::cout << "Capacite du train invalide." << std::endl;
        viderBuffer();
    }

    Train* nouveauTrain = new Train(numeroTrain, villeDepart, villeArrivee, horaireDepart, horaireArrivee, capacite);
    trains.push_back(nouveauTrain);
    calendrier.ajouterHoraire("01/01/2024", *nouveauTrain);
    std::cout << "Nouveau train ajouté avec succès." << std::endl;
}

int main() {
    chargerDonnees();
    int choix;
    do {
        afficherMenu();
        std::cin >> choix;

        switch (choix) {
        case 1:
            reserverBillet();
            break;
        case 2:
            annulerReservation();
            break;
        case 3:
            afficherReservations();
            break;
        case 4:
            afficherCalendrierTrains();
            break;
        case 5:
            afficherHistoriqueTickets();
            break;
        case 6:
            ajouterNouveauTrain();
            break;
        case 7:
            std::cout << "Merci d'avoir utilisé l'application. Au revoir!" << std::endl;
            break;
        default:
            std::cout << "Option invalide. Veuillez réessayer." << std::endl;
            break;
        }
        pauseConsole();
        sauvegarderDonnees();
    } while (choix != 7);
    for (auto train : trains) {
        delete train;
    }
    for (auto passager : passagers) {
        delete passager;
    }
    for (auto billet : billets) {
        delete billet;
    }
    return 0;
}