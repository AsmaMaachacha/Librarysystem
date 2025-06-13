#include "reservation.h"

Reservation::Reservation(User* u, Resource* r)
    : user(u), resource(r), reservationDate(QDate::currentDate()) {}

User* Reservation::getUser() const { return user; }
Resource* Reservation::getResource() const { return resource; }
QDate Reservation::getDate() const { return reservationDate; }
