/*************************************************************************
                           Graphe  -  gérer le graphe orienté
                             -------------------
    début                : 22/01/2025
    copyright            : (C) 2025 par B3107 - B3110
    e-mail               : mohammed.iich@insa-lyon.fr / hamza.el-karchouni@insa-lyon.fr / 
                           mohamed.lemseffer@insa-lyon.fr / yliess.bellargui@insa-lyon.fr / 
                           youssef.erabhaoui@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Graphe> (fichier Graphe.h) ----------------
#if ! defined ( Graphe_H )
#define Graphe_H

//--------------------------------------------------- Interfaces utilisées
#include "Requete.h"
#include <vector>
#include <map>
#include <fstream>
using namespace std;

//------------------------------------------------------------- Constantes
//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Graphe>
//
//
//------------------------------------------------------------------------

class Graphe
{
//----------------------------------------------------------------- PUBLIC
public:
//----------------------------------------------------- Méthodes publiques
    void GenererFichier(const string & nomFichier) const;
    // Mode d'emploi :
    // génère le fichier au format GraphViz avec l'extension ".dot"
    // Contrat :
    // rien.

    void Ajouter(const vector<Requete> & vecRequetes);
    // Mode d'emploi :
    // ajoute dans la map "mAretes" et dans la map "nodes" les URL contenues 
    // dans une requête ainsi que les filtres à appliquer.
    // Contrat :
    // rien.

//-------------------------------------------- Constructeurs - destructeur
    Graphe ( const Graphe & unGraphe );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Graphe ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Graphe ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE
protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

    map<string,map<string,int>> mAretes;
    map <string, int> mNoeuds;
    int mNbNoeuds;  

};

//-------------------------------- Autres définitions dépendantes de <Graphe>

#endif // Graphe_H
