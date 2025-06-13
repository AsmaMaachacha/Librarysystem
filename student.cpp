#include "student.h"

Student::Student(QString id, QString name, QString m)
    : User(id, name), major(m) {}

QString Student::getRole() const {
    return "Student";
}

QString Student::getMajor() const {
    return major;
}
