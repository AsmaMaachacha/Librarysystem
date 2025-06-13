#include "user.h"

User::User(QString id, QString n) : userID(id), name(n) {}

QString User::getID() const { return userID; }
QString User::getName() const { return name; }
