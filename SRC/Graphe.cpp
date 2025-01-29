/*************************************************************************
                           Graphe  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Graphe> (fichier Graphe.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Graphe.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void Graphe::GenererFichier(const string & nomFichier) const
// Algorithme :
//
{
    ofstream ficGraphe(nomFichier);
    ficGraphe << "digraph {" << endl;

    //Ajout des noeuds
    map<string, int>::const_iterator it;
	for (it = mNoeuds.begin(); it != mNoeuds.end(); it++)
	{
		ficGraphe << "node" << it->second << " [label=\"" << it->first << "\"];" << endl;
	}

    //Ajout des Arêtes
    map<string, map<string, int>>::const_iterator it2;
    for (it2 = mAretes.begin(); it2 != mAretes.end(); it2++)
	{
		map<string, int>::const_iterator inoeuds_dest =mNoeuds.find(it2->first); // récupération du rang du noeud dest
		int dest = inoeuds_dest->second;
        map<string, int>::const_iterator it3;
		for (it3 = it2->second.begin(); it3 != it2->second.end(); it3++)
		{
			map<string, int>::const_iterator inoeuds_src = mNoeuds.find(it3->first); // récupération du rang du noeud src
			int src = inoeuds_src->second;
			ficGraphe << "node" << src << " -> " << "node" << dest << "[label=\"" << it3->second << "\"];" << endl;
		}
	}

    ficGraphe << "}" << endl;
	ficGraphe.close();

} //----- Fin de Méthode

void Graphe::Ajouter(const vector<Requete> & vecRequetes)
// Algorithme :
//
{

    vector<Requete>::const_iterator r;
    for (r = vecRequetes.begin(); r!=vecRequetes.end(); ++r)
    {
        string dest=r->GetDestination();
	    string src=r->GetReferer();

        map<string, map<string, int>>::iterator it=mAretes.find(dest);
	    if(it==mAretes.end())
        {
		    //premiere apparition d'une destination
		    map<string,int> m={{src,1}};
		    mAretes.insert(make_pair(dest,m));
	    }
        else
        {
		    (it->second)[src]++;
	    }
	    if(mNoeuds.emplace(make_pair(src,mNbNoeuds)).second)
        {
		    ++mNbNoeuds;
	    }
	    if(mNoeuds.emplace(make_pair(dest,mNbNoeuds)).second)
        {
		    ++mNbNoeuds;
	    }   
    }
} //----- Fin de Méthode

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
Graphe::Graphe ( const Graphe & unGraphe )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Graphe>" << endl;
#endif

    mAretes = unGraphe.mAretes;
    mNbNoeuds = unGraphe.mNbNoeuds;
    mNoeuds = unGraphe.mNoeuds;

} //----- Fin de Graphe (constructeur de copie)


Graphe::Graphe ( ) : mNbNoeuds(0)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Graphe>" << endl;
#endif
} //----- Fin de Graphe


Graphe::~Graphe()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Graphe>" << endl;
#endif
} //----- Fin de ~Graphe


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

