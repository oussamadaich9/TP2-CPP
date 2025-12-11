#include "client.h"
#include <stdexcept>

Client::Client(std::string id, std::string nom, std::string prenom)
    : id_(id), nom_(nom), prenom_(prenom) {
    if (id.empty() || nom.empty() || prenom.empty()) {
        throw std::invalid_argument("Info client invalide");
    }
}

std::ostream& operator<<(std::ostream& os, const Client& c) {
    os << c.prenom_ << " " << c.nom_ << " (" << c.id_ << ")";
    return os;
}
