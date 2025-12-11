#include "date.h"
#include <stdexcept>

bool Date::estValide() const {
    if (mois_ < 1 || mois_ > 12) return false;
    if (jour_ < 1 || jour_ > 31) return false;
    if (annee_ < 2000) return false;
    return true;
}

Date::Date(int j, int m, int a) : jour_(j), mois_(m), annee_(a) {
    if (!estValide()) {
        throw std::invalid_argument("Date invalide");
    }
}

std::ostream& operator<<(std::ostream& os, const Date& d) {
    os << d.jour_ << "/" << d.mois_ << "/" << d.annee_;
    return os;
}
