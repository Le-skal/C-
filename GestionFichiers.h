#ifndef GESTIONFICHIERS_H
#define GESTIONFICHIERS_H

#include <vector>
#include "Train.h"
#include "Passager.h"
#include "Billet.h"
#include "Reservation.h"
#include <fstream>
#include <iostream>

std::vector<Train> chargerDonneesTrains(const std::string& nomFichier);
void sauvegarderDonneesTrains(const std::string& nomFichier, const std::vector<Train>& trains);

std::vector<Passager> chargerDonneesPassagers(const std::string& nomFichier);
void sauvegarderDonneesPassagers(const std::string& nomFichier, const std::vector<Passager>& passagers);

std::vector<Billet> chargerDonneesBillets(const std::string& nomFichier, const std::vector<Train>& trains);
void sauvegarderDonneesBillets(const std::string& nomFichier, const std::vector<Billet>& billets);

std::vector<Reservation> chargerDonneesReservations(const std::string& nomFichier, const std::vector<Passager*>& passagers, const std::vector<Billet*>& billets, const std::vector<Train*>& trains);
void sauvegarderDonneesReservations(const std::string& nomFichier, const std::vector<Reservation>& reservations);

void exporterHistorique(const std::string& nomFichier, const Passager& passager);

#endif


