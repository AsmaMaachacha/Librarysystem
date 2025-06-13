#include "thesis.h"
#include <iostream>

Thesis::Thesis(QString t, QString a, int y, QString s)
    : Resource(t, a, y), supervisor(s) {}

QString Thesis::getType() const {
    return "Thesis";
}

QString Thesis::getDetails() const {
    return "Thesis: " + title + " by " + author + " (" + QString::number(year) + ")";
}
