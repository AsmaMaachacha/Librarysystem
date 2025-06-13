#ifndef LOAN_H
#define LOAN_H

#include "user.h"
#include "resource.h"
#include <QDate>

class Loan {
private:
    User* user;
    Resource* resource;
    QDate loanDate;
    QDate dueDate;

public:
    Loan(User* u, Resource* r, int durationDays = 14);
    User* getUser() const;
    Resource* getResource() const;
    QDate getLoanDate() const;
    QDate getDueDate() const;
    bool isOverdue() const;
};

#endif // LOAN_H
