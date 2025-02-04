/*************************************************************************
                           Graphe  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
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
	// g�n�re le fichier au format GraphViz avec l'extension ".dot"
	// Contrat :
	// rien.

    void Ajouter(const vector<Requete> & vecRequetes);
	// Mode d'emploi :
	// ajoute dans la map "mAretes" est dans la map "nodes" les URL contenues 
	// dans une requ�te ainsi que les filtres � appliquer.
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
