#ifndef DATE_H
#define DATE_H
#include <iostream>

class Date {
private:
    int jour_;
    int mois_;
    int annee_;
    bool estValide() const;

public:
    Date(int j, int m, int a);
    int jour() const { return jour_; }
    int mois() const { return mois_; }
    int annee() const { return annee_; }
    friend std::ostream& operator<<(std::ostream& os, const Date& d);
};

#endif
