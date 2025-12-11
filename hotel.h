#ifndef HOTEL_H
#define HOTEL_H
#include <iostream>
#include <string>
#include <vector>
#include "chambre.h"

class Hotel {
private:
    std::string id_;
    std::string nom_;
    std::string ville_;
    std::vector<Chambre> chambres_;

public:
    Hotel(std::string id, std::string nom, std::string ville);
    std::string id() const { return id_; }
    std::vector<Chambre>& chambres() { return chambres_; }
    void ajouterChambre(const Chambre& c);
    friend std::ostream& operator<<(std::ostream& os, const Hotel& h);
};

#endif
