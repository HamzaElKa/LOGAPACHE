/*************************************************************************
                           Requete  -  Gestion des requêtes HTTP
                             -------------------
    début                : 04/02/2025
    copyright            : (C) 2025 par Mohammed IICH
    e-mail               : mohammed.iich@outlook.fr
*************************************************************************/

//---------- Réalisation de la classe <Requete> (fichier Requete.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Requete.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
string Requete::GetExtension() const
// Algorithme :
// Retourne l'extension du fichier demandé
{
} //----- Fin de GetExtension

string Requete::GetDestination() const
// Algorithme :
// Retourne la destination de la requête
{
} //----- Fin de GetDestination

string Requete::GetReferer() const
// Algorithme :
// Retourne le referer de la requête
{
} //----- Fin de GetReferer

int Requete::GetHeure() const
// Algorithme :
// Retourne l'heure de la requête
{
} //----- Fin de GetHeure

//------------------------------------------------- Surcharge d'opérateurs
Requete & Requete::operator=(const Requete &unRequete)
// Algorithme :
// Affectation d'une requête à une autre
{
} //----- Fin de operator=

//-------------------------------------------- Constructeurs - destructeur
Requete::Requete(const Requete &unRequete)
// Algorithme :
// Constructeur par copie
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Requete>" << endl;
#endif
} //----- Fin de Requete (constructeur de copie)

Requete::Requete()
// Algorithme :
// Constructeur par défaut
{
#ifdef MAP
    cout << "Appel au constructeur de <Requete>" << endl;
#endif
} //----- Fin de Requete

Requete::Requete(string AdresseIP, string LogName, string UserName, Date Date, requeteHTTP RHTTP, int Status, int Qte, string Referer, string ClientID)
// Algorithme :
// Constructeur avec paramètres
{
#ifdef MAP
    cout << "Appel au constructeur avec paramètres de <Requete>" << endl;
#endif
} //----- Fin de Requete

Requete::~Requete()
// Algorithme :
// Destructeur de la classe
{
#ifdef MAP
    cout << "Appel au destructeur de <Requete>" << endl;
#endif
} //----- Fin de ~Requete

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
