#include <iostream>
#include <vector>
#include <string>
#include "date.h"
#include "client.h"
#include "chambre.h"
#include "hotel.h"
#include "reservation.h"

using namespace std;

// Fonction pour vider le buffer clavier (éviter les bugs de getline)
void viderBuffer() {
    cin.ignore(1000, '\n');
}

int main() {
    try {
        // 1. Initialisation de l'hôtel
        Hotel hotel("H01", "Le Bellagio", "Las Vegas");
        hotel.ajouterChambre(Chambre(101, "Single", 100));
        hotel.ajouterChambre(Chambre(102, "Single", 100));
        hotel.ajouterChambre(Chambre(201, "Double", 125));
        hotel.ajouterChambre(Chambre(202, "Double", 125));
        hotel.ajouterChambre(Chambre(301, "Suite", 210));

        // 2. Liste des clients
        vector<Client> clients;
        clients.push_back(Client("C1", "Dupont", "Jean"));
        clients.push_back(Client("C2", "Martin", "Alice"));

        vector<Reservation> reservations;
        int choix = 0;

        while (choix != 3) {
            cout << "\n=== MENU ===" << endl;
            cout << "1. Voir l'état de l'hôtel" << endl;
            cout << "2. Faire une réservation" << endl;
            cout << "3. Quitter" << endl;
            cout << "Choix : ";
            cin >> choix;

            if (choix == 1) {
                cout << hotel << endl;
                cout << "--- Reservations actuelles ---" << endl;
                if (reservations.empty()) cout << "Aucune réservation." << endl;
                for (const auto& r : reservations) cout << r << endl;
            }
            else if (choix == 2) {
                // --- A. GESTION CLIENT ---
                string nom, prenom, id;
                cout << "\n--- Nouveau Client ---" << endl;
                cout << "Nom : "; cin >> nom;
                
                // Recherche si client existe
                bool trouve = false;
                string clientId;
                for (const auto& c : clients) {
                    if (c.nom() == nom) {
                        cout << "Client existant trouvé : " << c << endl;
                        clientId = c.id();
                        trouve = true;
                        break;
                    }
                }

                if (!trouve) {
                    cout << "Client inconnu. Prénom : "; cin >> prenom;
                    cout << "ID Client (ex: C3) : "; cin >> id;
                    Client nouveau(id, nom, prenom);
                    clients.push_back(nouveau);
                    clientId = id;
                    cout << "Client ajouté !" << endl;
                }

                // --- B. GESTION DATES ---
                int j, m, a, nuits;
                cout << "\n--- Dates ---" << endl;
                cout << "Jour : "; cin >> j;
                cout << "Mois : "; cin >> m;
                cout << "Année : "; cin >> a;
                cout << "Nb Nuits : "; cin >> nuits;
                Date dateDebut(j, m, a);

                // --- C. CHOIX CHAMBRE ---
                string type;
                cout << "\n--- Chambre ---" << endl;
                cout << "Type souhaité (Single/Double/Suite) : ";
                cin >> type;

                int numChambre = -1;
                double prix = 0;
                
                // Cherche une chambre de ce type
                // Note: Dans un vrai système, il faudrait vérifier si elle est libre aux dates données
                for (const auto& c : hotel.chambres()) {
                    if (c.type() == type) {
                        numChambre = c.numero();
                        prix = c.prix();
                        break; // On prend la première trouvée
                    }
                }

                if (numChambre != -1) {
                    Reservation res(dateDebut, nuits, hotel.id(), numChambre, clientId, prix);
                    reservations.push_back(res);
                    cout << "\n✅ RÉSERVATION CONFIRMÉE !" << endl;
                    cout << res << endl;
                } else {
                    cout << "\n❌ Désolé, aucune chambre de type " << type << " trouvée." << endl;
                }
            }
        }

    } catch (const exception& e) {
        cerr << "Erreur : " << e.what() << endl;
    }

    return 0;
}
