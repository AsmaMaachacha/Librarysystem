#include "notification.h"

Notification::Notification(QString msg)
    : message(msg), date(QDate::currentDate()), read(false) {}

QString Notification::getMessage() const { return message; }
QDate Notification::getDate() const { return date; }
bool Notification::isRead() const { return read; }
void Notification::markAsRead() { read = true; }
