/*************************************************************************
                           Filtrage  -  filtrer des objets de type Requete
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Filtrage> (fichier Filtrage.cpp) ------------

//---------------------------------------------------------------- INCLUDE
#include "Filtrage.h"
//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <vector>

//------------------------------------------------------ Include personnel

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques


bool Filtrage::Skip(const Requete & r) const
{
    if (!mFiltrerExtensions && !mFiltrerTemps) return false;

    if (mFiltrerTemps && r.GetHeure() == mHeure) 
    {
        return true;
    }

    if (mFiltrerExtensions) 
    {
        if (mExtensions.find(r.GetExtension()) != mExtensions.end()) 
        {
            return true;
        }
    }

    return false;
}
//----- Fin de Méthode


//-------------------------------------------- Constructeurs - destructeur
Filtrage::Filtrage(bool filtrerTemps, int heure, bool filtrerExtensions, unordered_set<string> Extensions) : mFiltrerTemps(filtrerTemps), 
                                                                                                        mHeure(heure), mFiltrerExtensions(filtrerExtensions), 
                                                                                                        mExtensions(Extensions)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Filtrage>" << endl;
#endif
} //----- Fin de Filtrage


Filtrage::~Filtrage ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Filtrage>" << endl;
#endif
} //----- Fin de ~Filtrage


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

