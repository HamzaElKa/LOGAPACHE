/*************************************************************************
							 Classement
								-
	permet de classer les URL des requêtes d'un fichier log par ordre d'importance.
							 -------------------
	début                : 22/01/2025
	copyright            : (C) 2025 par BINOME A COMPLÉTER
	e-mail               :  A COMPLÉTER
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
#include "GenerateGraphe.h"
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

	void LireGraphe(const GenerateGraphe &unGraphe);
	// Mode d'emploi :
	// Parcourt le graphe des passages et calcule le total des hits pour chaque
	// URL de destination. Met à jour le classement en conséquence.
	// Contrat :
	// - Le graphe doit contenir des données valides.

	void AjouterRequete(const string &url, int hits);
	// Mode d'emploi :
	// Ajoute ou met à jour le nombre de hits pour une URL spécifique.
	// Contrat :
	// - L'URL doit être une chaîne valide.

	void Affichage();
	// Mode d'emploi :
	// Affiche les 10 URLs les plus consultées (triées par hits décroissants).
	// Contrat :
	// - Affiche un message si aucune donnée n'est disponible.

	//-------------------------------------------- Constructeurs - destructeur
	Classement() = default;
	// Mode d'emploi :
	// Constructeur par défaut.

	Classement(const Classement &unClassement) = default;
	// Mode d'emploi (constructeur de copie) :
	// Copie un classement existant.

	virtual ~Classement() = default;
	// Mode d'emploi :
	// Destructeur de la classe.

	//----------------------------------------------------------------- PROTÉGÉ
protected:
	//----------------------------------------------------- Attributs protégés
	map<string, int> classement; // URL comme clé, nombre de hits comme valeur
};

#endif // CLASSEMENT_H
