#ifndef NOTIFICATION_H
#define NOTIFICATION_H

#include <QString>
#include <QDate>

class Notification {
private:
    QString message;
    QDate date;
    bool read;

public:
    Notification(QString msg);
    QString getMessage() const;
    QDate getDate() const;
    bool isRead() const;
    void markAsRead();
};

#endif // NOTIFICATION_H
