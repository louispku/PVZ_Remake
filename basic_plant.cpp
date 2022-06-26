#include "basic_plant.h"

Basic_Plant::Basic_Plant() : movie(nullptr)
{
}

Basic_Plant::~Basic_Plant()
{
    delete movie;
}

int Basic_Plant::type() const
{
    return Type;
}

void Basic_Plant::setMovie(const QString &path)
{
    if (movie)
    {
        delete movie;
    }
    movie = new QMovie(path);
    movie->start();
}
