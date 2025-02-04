#ifndef LECTURE_H
#define LECTURE_H

#include <fstream>
#include <vector>
#include "Requete.h"
#include "Filtrage.h"

class Lecture
{
public:
    Lecture(const string &fluxFichier, const string &baseLocale);
    ~Lecture();

    vector<Requete> Lire(const Filtrage & filtre);

protected:
    ifstream mFluxFichier;
    string mBaseLocale;
};

#endif // LECTURE_H
