#ifndef RESOURCE_H
#define RESOURCE_H

#include <QString>

class Resource {
protected:
    QString title;
    QString author;
    int year;
    bool available;

public:
    Resource(QString t, QString a, int y);
    virtual ~Resource() = default;

    QString getTitle() const;
    QString getAuthor() const;
    int getYear() const;
    bool isAvailable() const;
    void setAvailable(bool);

    virtual QString getType() const = 0;
    virtual QString getDetails() const = 0;
};

#endif // RESOURCE_H
