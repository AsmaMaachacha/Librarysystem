#include "article.h"
#include <iostream>

Article::Article(QString t, QString a, int y, QString j, int v)
    : Resource(t, a, y), journal(j), volume(v) {}

QString Article::getType() const {
    return "Article";
}

QString Article::getDetails() const {
    return "Article: " + title + " by " + author + " (" + QString::number(year) + ")";
}
