/*************************************************************************
                           Filtrage  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Filtrage> (fichier Filtrage.h) ----------------
#if ! defined ( Filtrage_H )
#define Filtrage_H

//--------------------------------------------------- Interfaces utilisées
#include "Filtrage.h"
#include "Requete.h"
#include <vector>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Filtrage>
//
//
//------------------------------------------------------------------------

class Filtrage
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    void Filtrer(vector<Requete> & vecRequetes) const;

    bool Skip(const Requete & r) const;
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

//-------------------------------------------- Constructeurs - destructeur
    Filtrage(bool, int, bool, vector<string>);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Filtrage ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

    bool mFiltrerTemps;
    int mHeure;
    bool mFiltrerExtensions;
    vector<string> mExtensions;

};

//-------------------------------- Autres définitions dépendantes de <Filtrage>

#endif // Filtrage_H

