#ifndef LIBRARYEVENT_H
#define LIBRARYEVENT_H

#include <QString>
#include <QDate>

class LibraryEvent {
private:
    QString title;
    QString description;
    QDate date;

public:
    LibraryEvent(QString t, QString d, QDate dt);
    QString getTitle() const;
    QString getDescription() const;
    QDate getDate() const;
    QString display() const;
};

#endif // LIBRARYEVENT_H
