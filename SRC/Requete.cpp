/*************************************************************************
                           Requete  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Requete> (fichier Requete.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include<fstream>
//------------------------------------------------------ Include personnel
#include "Requete.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Requete::Méthode ( liste des paramètres )
// Algorithme :
//
string Requete::GetExtension() const
{
	istringstream ss;
	ss.str(URLdest);
	string extension;
	string line;
	getline(ss,line,'.');
	getline(ss,extension);
	return extension;
}
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
Requete & Requete::operator = ( const Requete & unRequete )
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Requete::Requete ( const Requete & unRequete )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Requete>" << endl;
#endif
} //----- Fin de Requete (constructeur de copie)


Requete::Requete (string un_IP_Client, string un_User_Id, string un_User_Name, Date une_Date, Temps un_Temps,
string une_Time_Zone, string un_Type_Query, string un_URL, int un_Status, int une_Qte, string un_Referer )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Requete>" << endl;
#endif
IP_Client=un_IP_Client;
User_Id=un_User_Id;
User_Name=un_User_Name;
Date=une_Date;
Temps=un_Temps;
Time_Zone=une_Time_Zone;
Type_Query=un_Type_Query;
URL=un_URL;
Status=un_Status;
Qte=une_Qte;
Referer=un_Referer;
} //----- Fin de Requete

Requete::~Requete ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Requete>" << endl;
#endif
} //----- Fin de ~Requete
//------------------------------------------------------------------ PRIVE
//----------------------------------------------------- Méthodes protégées