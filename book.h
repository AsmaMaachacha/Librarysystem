#ifndef BOOK_H
#define BOOK_H

#include "resource.h"

class Book : public Resource {
private:
    QString isbn;
public:
    Book(QString t, QString a, int y, QString i);
    QString getType() const override;
    QString getDetails() const override;

};

#endif // BOOK_H
