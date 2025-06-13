#ifndef RESERVATION_H
#define RESERVATION_H

#include "user.h"
#include "resource.h"
#include <QDate>

class Reservation {
private:
    User* user;
    Resource* resource;
    QDate reservationDate;

public:
    Reservation(User* u, Resource* r);
    User* getUser() const;
    Resource* getResource() const;
    QDate getDate() const;
};

#endif // RESERVATION_H
