#include "loan.h"

Loan::Loan(User* u, Resource* r, int durationDays)
    : user(u), resource(r), loanDate(QDate::currentDate()),
      dueDate(loanDate.addDays(durationDays)) {}

User* Loan::getUser() const { return user; }
Resource* Loan::getResource() const { return resource; }
QDate Loan::getLoanDate() const { return loanDate; }
QDate Loan::getDueDate() const { return dueDate; }

bool Loan::isOverdue() const {
    return QDate::currentDate() > dueDate;
}
