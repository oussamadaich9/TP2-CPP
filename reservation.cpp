#include "reservation.h"
#include <stdexcept>

Reservation::Reservation(Date d, int n, std::string h, int ch, std::string cl, double prix)
    : dateDebut_(d), nbrNuits_(n), hotelId_(h), chambreNum_(ch), clientId_(cl) {
    if (n <= 0) throw std::invalid_argument("Nuits <= 0");
    montant_ = n * prix;
}

std::ostream& operator<<(std::ostream& os, const Reservation& r) {
    os << "Resa: Client " << r.clientId_ << ", Hotel " << r.hotelId_ 
       << ", Ch " << r.chambreNum_ << ", Debut " << r.dateDebut_ 
       << ", Total " << r.montant_;
    return os;
}
