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
#include "Filtrage.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

bool & Filtrage::Skip(const requete & r) const
// Algorithme :
//
{
    if (!m_filtrer_images||!m_filtrer_temps) return false;
    
    if (m_filtrer_temps)
    {
        if (r.time.heure==m_heure) return true;
    }
    if (m_filtrer_images)
    {
        vector<string>::iterator it = m_extensions_image.find(r.GetExtension());
        if (it != m_extensions_image.end()) return true;
    }
    return false;
}
//----- Fin de Méthode


//-------------------------------------------- Constructeurs - destructeur
Filtrage::Filtrage(bool filtrer_temps, int heure, bool filtrer_images, vector<string> extensions_image) : m_filtrer_temps(filtrer_temps), 
                                                                                                        m_heure(heure), m_filtrer_images(filtrer_images), 
                                                                                                        m_extensions_image(extensions_image)
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

