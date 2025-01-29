/*************************************************************************
                           Filtrage  -  description
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

void Filtrage::Filtrer(vector<Requete> & vecRequetes) const
// Algorithme :
//
{
    vector<Requete>::iterator it = vecRequetes.begin();
    while (it != vecRequetes.end())
    {
        if (Skip(*it))
        {
            it = vecRequetes.erase(it); // erase renvoie l'itérateur suivant après suppression
        }
        else
        {
            ++it;
        }
    }
}
//----- Fin de Méthode

bool Filtrage::Skip(const Requete & r) const
// Algorithme :
//
{
    if (!mFiltrerExtensions||!mFiltrerTemps) return false;
    
    if (mFiltrerTemps)
    {
        if (r.GetHeure()==mHeure) return true;
    }
    if (mFiltrerExtensions)
    {
        vector<string>::const_iterator it = mExtensions.begin();
        while (it != mExtensions.end()) 
        {
            if (*it == r.GetExtension()) 
            {
                break;  // Trouvé, sortir de la boucle
            }
            ++it;
        }
        if (it != mExtensions.end()) return true;
    }
    return false;
}
//----- Fin de Méthode


//-------------------------------------------- Constructeurs - destructeur
Filtrage::Filtrage(bool filtrerTemps, int heure, bool filtrerExtensions, vector<string> Extensions) : mFiltrerTemps(filtrerTemps), 
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

