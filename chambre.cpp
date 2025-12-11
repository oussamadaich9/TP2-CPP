#include "chambre.h"
#include <stdexcept>

Chambre::Chambre(int num, std::string type, double prix)
    : numero_(num), type_(type), prix_(prix) {
    if (num <= 0 || type.empty() || prix < 0) {
        throw std::invalid_argument("Info chambre invalide");
    }
}

void Chambre::setPrix(double p) {
    if (p < 0) throw std::invalid_argument("Prix negatif");
    prix_ = p;
}

std::ostream& operator<<(std::ostream& os, const Chambre& c) {
    os << "Chambre " << c.numero_ << " (" << c.type_ << ") : " << c.prix_ << " eur";
    return os;
}
