#ifndef STUDENT_H
#define STUDENT_H

#include "user.h"

class Student : public User {
private:
    QString major;
public:
    Student(QString id, QString name, QString major);
    QString getRole() const override;
    QString getMajor() const;
};

#endif // STUDENT_H
