#ifndef USER_H
#define USER_H

#include <QString>

class User {
protected:
    QString userID;
    QString name;

public:
    User(QString id, QString n);
    virtual ~User() = default;

    QString getID() const;
    QString getName() const;

    virtual QString getRole() const = 0;
};

#endif // USER_H
