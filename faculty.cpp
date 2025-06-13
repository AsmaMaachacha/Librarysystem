#include "faculty.h"

Faculty::Faculty(QString id, QString name, QString dep)
    : User(id, name), department(dep) {}

QString Faculty::getRole() const {
    return "Faculty";
}

QString Faculty::getDepartment() const {
    return department;
}
