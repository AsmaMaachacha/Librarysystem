#ifndef ARTICLE_H
#define ARTICLE_H

#include "resource.h"

class Article : public Resource {
private:
    QString journal;
    int volume;

public:
    Article(QString t, QString a, int y, QString j, int v);
    QString getType() const override;
    QString getDetails() const override;
};

#endif // ARTICLE_H
