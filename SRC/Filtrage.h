/*************************************************************************
                           Filtrage  -  filtrer des objets de type Requete
                             -------------------
    début                : 22/01/2025
    copyright            : (C) 2025 par B3107 - B3110
    e-mail               : mohammed.iich@insa-lyon.fr / hamza.el-karchouni@insa-lyon.fr / 
    			   mohamed.lemseffer@insa-lyon.fr / yliess.bellargui@insa-lyon.fr / youssef.erabhaoui@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Filtrage> (fichier Filtrage.h) ----------------
#if ! defined ( Filtrage_H )
#define Filtrage_H

//--------------------------------------------------- Interfaces utilisées
#include "Filtrage.h"
#include "Requete.h"
#include <vector>
#include <unordered_set>
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
    Filtrage(bool, int, bool, unordered_set<string>);
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
    unordered_set<string> mExtensions;

};

//-------------------------------- Autres définitions dépendantes de <Filtrage>

#endif // Filtrage_H

