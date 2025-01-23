/*************************************************************************
						   Classement
								-
	permet de classer les URL des requêtes d'un fichier log par ordre d'importance.
							 -------------------
	début                : 22/01/2025
	copyright            : (C) 2025 par BINOME A COMPLÉTER
	e-mail               : A COMPLÉTER
*************************************************************************/

//---------- Réalisation de la classe <Classement> (fichier Classement.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Classement.h"

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void Classement::LireGraphe(const GenerateGraphe &unGraphe)
// Algorithme :
// - Parcourt la structure "passage" du graphe pour calculer le total des hits
//   pour chaque URL destination.
// - Ajoute ou met à jour les hits dans la map "classement".
{
	if (unGraphe.passage.empty())
	{
		cerr << "Erreur : Le graphe est vide." << endl;
		return;
	}

	for (const auto & [dest, sources] : unGraphe.passage)
	{
		int somme = 0;
		for (const auto & [src, hits] : sources)
		{
			somme += hits; // Accumuler les hits pour chaque URL destination
		}
		classement[dest] += somme; // Ajouter ou mettre à jour l'URL
	}
} //----- Fin de LireGraphe

void Classement::AjouterRequete(const string &url, int hits)
// Algorithme :
// - Ajoute ou incrémente le nombre de hits pour une URL donnée.
{
	classement[url] += hits;
} //----- Fin de AjouterRequete

void Classement::Affichage()
// Algorithme :
// - Copie les données de la map dans un vecteur pour permettre le tri.
// - Trie les entrées par hits décroissants.
// - Affiche les 10 premières URLs ou toutes si moins de 10.
{
	if (classement.empty())
	{
		cout << "Aucune donnée à afficher." << endl;
		return;
	}

	// Copier les données dans un vecteur pour trier par valeur
	vector<pair<string, int>> vec(classement.begin(), classement.end());

	// Trier par nombre de hits décroissant
	sort(vec.begin(), vec.end(),
		 [](const pair<string, int> &a, const pair<string, int> &b) {
			 return b.second > a.second; // Tri décroissant
		 });

	// Afficher les 10 premières URLs
	cout << "Top URLs consultées :" << endl;
	for (size_t i = 0; i < 10 && i < vec.size(); ++i)
	{
		cout << vec[i].first << " (" << vec[i].second << " hits)" << endl;
	}
} //----- Fin de Affichage
