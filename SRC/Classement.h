/*************************************************************************
                           Classement  -  Classement des requêtes
                             -------------------
    début                : 22/01/2025
    copyright            : (C) 2025 par B3107 - B3110
    e-mail               : mohammed.iich@insa-lyon.fr / hamza.el-karchouni@insa-lyon.fr / 
    			   mohamed.lemseffer@insa-lyon.fr / yliess.bellargui@insa-lyon.fr / youssef.erabhaoui@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Classement> (fichier Classement.h) ----------------
#if ! defined ( CLASSEMENT_H )
#define CLASSEMENT_H

//--------------------------------------------------- Interfaces utilisées
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include "Graphe.h"
#include "Requete.h"
using namespace std;

//------------------------------------------------------------------------
// Rôle de la classe <Classement>
//
// Cette classe gère le classement des requêtes selon un critère défini.
// Elle permet d'ajouter des requêtes et d'afficher le classement.
//------------------------------------------------------------------------

class Classement
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    
    void Ajouter(const vector<Requete> &unVecRequetes);
    // Ajouter : Ajoute des requêtes dans le classement
    // Mode d'emploi : 
    // La méthode prend un vecteur de requêtes et les ajoute au classement.
    

    void Affichage();
    // Affichage : Affiche le classement actuel
    // Mode d'emploi : 
    // La méthode affiche le classement des requêtes dans la console.
    
    
//------------------------------------------------- Surcharge d'opérateurs
    Classement & operator = ( const Classement &unClassement );
    // Surcharge de l'opérateur d'affectation
    // Mode d'emploi : 
    // Cette méthode permet de copier un autre objet Classement dans le présent objet.
    // Contrat :
    // L'opération est valide si l'objet sur lequel elle est appelée est bien
    // initialisé et qu'il n'y a pas de fuite mémoire.

//-------------------------------------------- Constructeurs - destructeur

    Classement ( const Classement &unClassement );
    // Constructeur de copie
    // Mode d'emploi :
    // Initialise un objet Classement à partir d'un autre.
    

    Classement ( );
    // Constructeur par défaut
    // Mode d'emploi :
    // Initialise un objet Classement vide.
    

    virtual ~Classement ( );
    // Destructeur
    // Mode d'emploi :
    // Nettoie les ressources de l'objet Classement.
    

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    map<string, int> classement; // Stocke le classement des requêtes sous forme d'un map.
};

#endif // CLASSEMENT_H
