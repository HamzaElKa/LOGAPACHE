/*************************************************************************
                           Filtrage  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Filtrage> (fichier Filtrage.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

vector<Requete> Filtrage::Filtrer(const vector<requete> & r) const
// Algorithme :
//
{
    vector<Requete> vecFiltre;
    vector<Requete>::iterator it;
	for (it = unVecRequetes.begin(); it != unVecRequetes.end(); ++it)
	{
		if (!Skip(it)) vecFiltre.push_back(it);
	}
    return vecFiltre;
}
//----- Fin de Méthode

bool Filtrage::Skip(const requete & r) const
// Algorithme :
//
{
    if (!mFiltrerExtensions||!mFiltrerTemps) return false;
    
    if (mFiltrerTemps)
    {
        if (r.time.heure==mHeure) return true;
    }
    if (mFiltrerExtensions)
    {
        vector<string>::iterator it = mExtensions.find(r.GetExtension());
        if (it != mExtensions.end()) return true;
    }
    return false;
}
//----- Fin de Méthode


//-------------------------------------------- Constructeurs - destructeur
Filtrage::Filtrage(bool filtrerTemps, int heure, bool filtrerExtensions, vector<string> Extensions) : mFiltrerTemps(filtrerTemps), 
                                                                                                        mHeure(heure), mFiltrerExtensions(filtrerExtensions), 
                                                                                                        mExtensions(Extensions)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Filtrage>" << endl;
#endif
} //----- Fin de Filtrage


Filtrage::~Filtrage ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Filtrage>" << endl;
#endif
} //----- Fin de ~Filtrage


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

