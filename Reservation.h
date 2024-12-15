#ifndef RESERVATION_H
#define RESERVATION_H

#include "Passager.h"
#include "Billet.h"

class Reservation {
private:
    int numeroReservation;
    Passager passager;
    Billet billet;

public:
    Reservation(int num, const Passager& passager, const Billet& billet);

    void confirmerReservation();
    void annulerReservation();
    void afficherDetailsReservation() const;
};

#endif
