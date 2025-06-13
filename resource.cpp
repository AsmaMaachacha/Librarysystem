#include "resource.h"

Resource::Resource(QString t, QString a, int y)
    : title(t), author(a), year(y), available(true) {}

QString Resource::getTitle() const { return title; }
QString Resource::getAuthor() const { return author; }
int Resource::getYear() const { return year; }
bool Resource::isAvailable() const { return available; }
void Resource::setAvailable(bool a) { available = a; }
