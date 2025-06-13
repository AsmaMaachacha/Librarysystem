#ifndef THESIS_H
#define THESIS_H

#include "resource.h"

class Thesis : public Resource {
private:
    QString supervisor;

public:
    Thesis(QString t, QString a, int y, QString s);
    QString getType() const override;
    QString getDetails() const override;
};

#endif // THESIS_H
