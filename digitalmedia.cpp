#include "digitalmedia.h"
#include <iostream>

DigitalMedia::DigitalMedia(QString t, QString a, int y, QString ftype, double size)
    : Resource(t, a, y), fileType(ftype), sizeMB(size) {}

QString DigitalMedia::getType() const {
    return "Digital Media";
}

QString DigitalMedia::getDetails() const {
    return "Digital Media: " + title + " by " + author + " (" + QString::number(year) + ")";
}
