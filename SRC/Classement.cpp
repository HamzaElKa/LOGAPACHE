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

void Classement::AjouterVecRequetes(const vector<Requete> & unVecRequetes);
// Algorithme :
// - Parcourt la structure "passage" du graphe pour calculer le total des hits
//   pour chaque URL destination.
// - Ajoute ou met à jour les hits dans la map "classement".
{

	if (unVecRequetes.empty())
	{
		cerr << "Erreur : Vous n'avez aucune requete" << endl;
		return;
	}

	vector<Requete>::iterator it;
	for (it = unVecRequetes.begin(); it != unVecRequetes.end(); ++it)
	{
		

	}
} //----- Fin de LireGraphe

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

Classement::Classement()
// Algorithme :
//
{
	#ifdef MAP
    	cout << "Appel au constructeur de <Classement>" << endl;
	#endif
} //----- Fin de Classement

Classement::Classement(const & unClassement)
// Algorithme :
//
{
	#ifdef MAP
    	cout << "Appel au constructeur de copie de <Classement>" << endl;
	#endif

	classement = unClassement.classement;

} //----- Fin de Classement

Classement::~Classement()
// Algorithme :
//
{
	#ifdef MAP
    	cout << "Appel au destructeur de <Classement>" << endl;
	#endif
} //----- Fin de ~Classement


} //----- Fin de Affichage
