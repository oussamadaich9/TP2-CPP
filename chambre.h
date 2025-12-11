#ifndef CHAMBRE_H
#define CHAMBRE_H
#include <iostream>
#include <string>

class Chambre {
private:
    int numero_;
    std::string type_;
    double prix_;

public:
    Chambre(int num, std::string type, double prix);
    int numero() const { return numero_; }
    std::string type() const { return type_; }
    double prix() const { return prix_; }
    void setPrix(double p);
    friend std::ostream& operator<<(std::ostream& os, const Chambre& c);
};

#endif