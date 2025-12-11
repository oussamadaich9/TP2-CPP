#include "hotel.h"
#include <stdexcept>

Hotel::Hotel(std::string id, std::string nom, std::string ville)
    : id_(id), nom_(nom), ville_(ville) {
    if (id.empty()) throw std::invalid_argument("ID hotel vide");
}

void Hotel::ajouterChambre(const Chambre& c) {
    chambres_.push_back(c);
}

std::ostream& operator<<(std::ostream& os, const Hotel& h) {
    os << "Hotel " << h.nom_ << " (" << h.ville_ << ")\n";
    for (const auto& c : h.chambres_) {
        os << c << "\n";
    }
    return os;
}
