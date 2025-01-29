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
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Filtrage>
//
//
//------------------------------------------------------------------------

class Filtrage : public Ancetre
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    
    bool Skip(requete & r) const;
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
    bool mFiltrerImages;
    vector<string> mExtensions;

};

//-------------------------------- Autres définitions dépendantes de <Filtrage>

#endif // Filtrage_H

