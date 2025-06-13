#ifndef DIGITALMEDIA_H
#define DIGITALMEDIA_H

#include "resource.h"

class DigitalMedia : public Resource {
private:
    QString fileType;
    double sizeMB;

public:
    DigitalMedia(QString t, QString a, int y, QString ftype, double size);
    QString getType() const override;
    QString getDetails() const override;
};

#endif // DIGITALMEDIA_H
