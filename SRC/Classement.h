#ifndef CLASSEMENT_H
#define CLASSEMENT_H

#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include "Graphe.h"
#include "Requete.h"
using namespace std;

class Classement
{
public:
    void Ajouter(const vector<Requete> &unVecRequetes);
    void Affichage();
    
    Classement();
    Classement(const Classement &unClassement);
    virtual ~Classement();

protected:
    map<string, int> classement;
};

#endif // CLASSEMENT_H
