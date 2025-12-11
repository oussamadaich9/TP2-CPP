#ifndef RESERVATION_H
#define RESERVATION_H
#include <iostream>
#include <string>
#include "date.h"

class Reservation {
private:
    Date dateDebut_;
    int nbrNuits_;
    std::string hotelId_;
    int chambreNum_;
    std::string clientId_;
    double montant_;

public:
    Reservation(Date d, int n, std::string h, int ch, std::string cl, double prix);
    double montant() const { return montant_; }
    friend std::ostream& operator<<(std::ostream& os, const Reservation& r);
};

#endif
