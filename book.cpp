#include "book.h"
#include <iostream>

Book::Book(QString t, QString a, int y, QString i)
    : Resource(t, a, y), isbn(i) {}

QString Book::getType() const {
    return "Book";
}

QString Book::getDetails() const {
    return "Book: " + title + " by " + author + " (" + QString::number(year) + "), ISBN: " + isbn;
}

