#ifndef CLIENT_H
#define CLIENT_H
#include <iostream>
#include <string>

class Client {
private:
    std::string id_;
    std::string nom_;
    std::string prenom_;

public:
    Client(std::string id, std::string nom, std::string prenom);
    std::string id() const { return id_; }
    std::string nom() const { return nom_; }
    std::string prenom() const { return prenom_; }
    friend std::ostream& operator<<(std::ostream& os, const Client& c);
};

#endif
