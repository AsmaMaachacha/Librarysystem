#ifndef FACULTY_H
#define FACULTY_H

#include "user.h"

class Faculty : public User {
private:
    QString department;
public:
    Faculty(QString id, QString name, QString dep);
    QString getRole() const override;
    QString getDepartment() const;
};

#endif // FACULTY_H
