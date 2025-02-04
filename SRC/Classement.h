/*************************************************************************
                           Classement -  description
                             -------------------
    début                : 22/01/2025
    copyright            : (C) 2025 par B3107 - B3110
    e-mail               : mohammed.iich@insa-lyon.fr / hamza.el-karchouni@insa-lyon.fr / 
    			   mohamed.lemseffer@insa-lyon.fr / yliess.bellargui@insa-lyon.fr / youssef.erabhaoui@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Classement> (fichier Classement.h) ----------------
#ifndef CLASSEMENT_H
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
// permet de classer les URL des requêtes selon le nombre de fois qu'elles ont été
// adressées par une autre URL (nombre de "hits").
//------------------------------------------------------------------------

class Classement
{
	//----------------------------------------------------------------- PUBLIC
public:
	//----------------------------------------------------- Méthodes publiques

	void Ajouter(const vector<Requete> &unVecRequetes);
	// Mode d'emploi :
	// Parcourt le graphe des passages et calcule le total des hits pour chaque
	// URL de destination. Met à jour le classement en conséquence.
	// Contrat :
	// - Le graphe doit contenir des données valides.

	void Affichage();
	// Mode d'emploi :
	// Affiche les 10 URLs les plus consultées (triées par hits décroissants).
	// Contrat :
	// - Affiche un message si aucune donnée n'est disponible.

	//-------------------------------------------- Constructeurs - destructeur
	Classement();
	// Mode d'emploi :
	// Constructeur par défaut.

	Classement(const Classement &unClassement);
	// Mode d'emploi (constructeur de copie) :
	// Copie un classement existant.

	virtual ~Classement();
	// Mode d'emploi :
	// Destructeur de la classe.

	//----------------------------------------------------------------- PROTÉGÉ
protected:
	//----------------------------------------------------- Attributs protégés
	map<string, int> classement; // URL comme clé, nombre de hits comme valeur
};

#endif // CLASSEMENT_H
