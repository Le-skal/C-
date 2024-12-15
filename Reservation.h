#ifndef RESERVATION_H
#define RESERVATION_H

#include "Passager.h"
#include "Billet.h"
#include "Train.h"

class Reservation {
public:
    int numeroReservation;
    Passager* passager;
    Billet* billet;
    Train* train;

    Reservation(int numero, Passager* passager, Billet* billet, Train* train);

    void confirmerReservation();
    bool annulerReservation();
    void afficherDetailsReservation() const;


};

#endif