#include "GestionFichiers.h"
#include <sstream>
#include <fstream>
#include <iostream>

// Fonctions pour les Trains
std::vector<Train> chargerDonneesTrains(const std::string& nomFichier) {
    std::vector<Train> trains;
    std::ifstream fichier(nomFichier);
    if (!fichier.is_open()) {
        std::cerr << "Impossible d'ouvrir le fichier : " << nomFichier << std::endl;
        return trains;
    }

    std::string ligne;
    while (getline(fichier, ligne)) {
        std::istringstream iss(ligne);
        int numeroTrain, capacite, placesLibres;
        std::string villeDepart, villeArrivee, horaireDepart, horaireArrivee;

        if (iss >> numeroTrain >> villeDepart >> villeArrivee >> horaireDepart >> horaireArrivee >> capacite >> placesLibres) {
            Train train(numeroTrain, villeDepart, villeArrivee, horaireDepart, horaireArrivee, capacite);
            train.setPlacesLibres(placesLibres);
            trains.push_back(train);
        }
        else {
            std::cerr << "Erreur de lecture de la ligne, verifier le format " << ligne << std::endl;
        }
    }

    fichier.close();
    return trains;
}

void sauvegarderDonneesTrains(const std::string& nomFichier, const std::vector<Train>& trains) {
    std::ofstream fichier(nomFichier);
    if (!fichier.is_open()) {
        std::cerr << "Impossible d'ouvrir le fichier pour enregistrer: " << nomFichier << std::endl;
        return;
    }

    for (const auto& train : trains) {
        fichier << train.numeroTrain << " " << train.villeDepart << " " << train.villeArrivee << " "
            << train.horaireDepart << " " << train.horaireArrivee << " " << train.capacite << " " << train.placesLibres << std::endl;
    }

    fichier.close();
}


// Fonctions pour les Passagers
std::vector<Passager> chargerDonneesPassagers(const std::string& nomFichier) {
    std::vector<Passager> passagers;
    std::ifstream fichier(nomFichier);
    if (!fichier.is_open()) {
        std::cerr << "Impossible d'ouvrir le fichier pour charger: " << nomFichier << std::endl;
        return passagers;
    }
    std::string ligne;
    while (getline(fichier, ligne)) {
        std::istringstream iss(ligne);
        std::string nom, prenom;
        int identifiant;
        if (iss >> nom >> prenom >> identifiant) {
            passagers.emplace_back(nom, prenom, identifiant);
        }
        else {
            std::cerr << "Erreur de lecture de la ligne, verifier le format " << ligne << std::endl;
        }
    }
    fichier.close();
    return passagers;
}

void sauvegarderDonneesPassagers(const std::string& nomFichier, const std::vector<Passager>& passagers) {
    std::ofstream fichier(nomFichier);
    if (!fichier.is_open()) {
        std::cerr << "Impossible d'ouvrir le fichier pour enregistrer: " << nomFichier << std::endl;
        return;
    }
    for (const auto& passager : passagers) {
        fichier << passager.nom << " " << passager.prenom << " " << passager.identifiant << std::endl;
    }
    fichier.close();
}


// Fonctions pour les Billets
std::vector<Billet> chargerDonneesBillets(const std::string& nomFichier, const std::vector<Train>& trains) {
    std::vector<Billet> billets;
    std::ifstream fichier(nomFichier);
    if (!fichier.is_open()) {
        std::cerr << "Impossible d'ouvrir le fichier pour charger : " << nomFichier << std::endl;
        return billets;
    }
    std::string ligne;
    while (getline(fichier, ligne)) {
        std::istringstream iss(ligne);
        int numeroBillet, numeroTrain;
        std::string typeClasse, dateVoyage;
        if (iss >> numeroBillet >> typeClasse >> numeroTrain >> dateVoyage) {

            Billet billet(numeroBillet, typeClasse, numeroTrain, dateVoyage);
            for (const auto& train : trains) {
                if (train.numeroTrain == numeroTrain) {
                    billet.calculerPrix(train.villeDepart, train.villeArrivee);
                    billets.push_back(billet);
                    break;
                }
            }
        }
        else {
            std::cerr << "Erreur de lecture de la ligne, verifier le format " << ligne << std::endl;
        }
    }
    fichier.close();
    return billets;
}

void sauvegarderDonneesBillets(const std::string& nomFichier, const std::vector<Billet>& billets) {
    std::ofstream fichier(nomFichier);
    if (!fichier.is_open()) {
        std::cerr << "Impossible d'ouvrir le fichier pour enregistrer : " << nomFichier << std::endl;
        return;
    }
    for (const auto& billet : billets) {
        fichier << billet.numeroBillet << " " << billet.typeClasse << " " << billet.numeroTrain << " " << billet.dateVoyage << std::endl;
    }
    fichier.close();
}

// Fonctions pour les Reservations
std::vector<Reservation> chargerDonneesReservations(const std::string& nomFichier, const std::vector<Passager*>& passagers, const std::vector<Billet*>& billets, const std::vector<Train*>& trains) {
    std::vector<Reservation> reservations;
    std::ifstream fichier(nomFichier);
    if (!fichier.is_open()) {
        std::cerr << "Impossible d'ouvrir le fichier pour charger: " << nomFichier << std::endl;
        return reservations;
    }
    std::string ligne;
    while (getline(fichier, ligne)) {
        std::istringstream iss(ligne);
        int numeroReservation, idPassager, numeroBillet, numeroTrain;
        if (iss >> numeroReservation >> idPassager >> numeroBillet >> numeroTrain) {
            Passager* passagerPtr = nullptr;
            for (size_t i = 0; i < passagers.size(); ++i) {
                if (passagers[i]->identifiant == idPassager) {
                    passagerPtr = passagers[i];
                    break;
                }
            }
            Billet* billetPtr = nullptr;
            for (size_t i = 0; i < billets.size(); ++i) {
                if (billets[i]->numeroBillet == numeroBillet) {
                    billetPtr = billets[i];
                    break;
                }
            }

            Train* trainPtr = nullptr;
            for (size_t i = 0; i < trains.size(); ++i) {
                if (trains[i]->numeroTrain == numeroTrain) {
                    trainPtr = trains[i];
                    break;
                }
            }


            if (passagerPtr != nullptr && billetPtr != nullptr && trainPtr != nullptr) {
                reservations.emplace_back(numeroReservation, passagerPtr, billetPtr, trainPtr);
            }
            else {
                std::cerr << "Passager , billet ou train non trouvé pour cette reservation : " << ligne << std::endl;
            }
        }
        else {
            std::cerr << "Erreur de lecture de la ligne, verifier le format: " << ligne << std::endl;
        }
    }
    fichier.close();
    return reservations;
}

void sauvegarderDonneesReservations(const std::string& nomFichier, const std::vector<Reservation>& reservations) {
    std::ofstream fichier(nomFichier);
    if (!fichier.is_open()) {
        std::cerr << "Impossible d'ouvrir le fichier pour enregistrer: " << nomFichier << std::endl;
        return;
    }
    for (const auto& reservation : reservations) {
        fichier << reservation.numeroReservation << " "
            << reservation.passager->identifiant << " "
            << reservation.billet->numeroBillet << " " << reservation.train->numeroTrain << std::endl;
    }
    fichier.close();
}

void exporterHistorique(const std::string& nomFichier, const Passager& passager) {
    std::ofstream fichier(nomFichier);
    if (!fichier.is_open()) {
        std::cerr << "Impossible d'ouvrir le fichier pour l'exportation: " << nomFichier << std::endl;
        return;
    }
    fichier << "Historique des reservations pour " << passager.prenom << " " << passager.nom << std::endl;
    for (const auto& billet : passager.historiqueReservations) {
        fichier << "Billet #" << billet->numeroBillet << ", Classe: " << billet->typeClasse
            << ", Prix: " << billet->prix << " €, Train #" << billet->numeroTrain
            << ", Date: " << billet->dateVoyage << std::endl;
    }
    fichier.close();
}