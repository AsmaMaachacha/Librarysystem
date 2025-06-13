#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include <QString>
#include "resource.h"
#include "user.h"
#include "loan.h"
#include "reservation.h"
#include "libraryevent.h"

class Library {
private:
    std::vector<Resource*> resources;
    std::vector<User*> users;
    std::vector<Loan*> loans;
    std::vector<Reservation*> reservations;
    std::vector<LibraryEvent> events;

public:
    ~Library();

    void addResource(Resource* r);
    void removeResource(QString title);
    void listResources() const;
    Resource* searchResource(QString title);

    void addUser(User* u);
    User* getUserByID(QString id);
    void listUsers() const;

    void borrowResource(QString userID, QString title);
    void returnResource(QString userID, QString title);
    void reserveResource(QString userID, QString title);

    void removeLoan(User* u, Resource* r);
    void checkReservation(Resource* r);

    void addEvent(const LibraryEvent& event);
    void showEvents() const;
    void borrowResource(User* user, Resource* resource);
    void returnResource(User* user, Resource* resource);
    std::vector<Resource*> getAllResources();
};

#endif // LIBRARY_H
