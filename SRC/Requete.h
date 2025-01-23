/*************************************************************************
                           Requete  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/
//---------- Interface de la classe <Requete> (fichier Requete.h) ----------------
#if ! defined ( Requete_H )
#define Requete_H

//--------------------------------------------------- Interfaces utilisées
#include<cstring>
#include<fstream>
using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types
typedef struct {
    int jour;
    string mois;
    int annee;
}Date;
typedef struct {
    int heure;
    int minute;
    int seconde;
}Temps;
//------------------------------------------------------------------------
// Rôle de la classe <Requete>
//
//
//------------------------------------------------------------------------
class Requete
{
//----------------------------------------------------------------- PUBLIC
friend class Lecture;
public:
//----------------------------------------------------- Méthodes publiques
    string GetExtension()const;
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
//------------------------------------------------- Surcharge d'opérateurs
    Requete & operator = ( const Requete & unRequete );
    // Mode d'emploi :
    //
    // Contrat :
    //
//-------------------------------------------- Constructeurs - destructeur
    Requete ( const Requete & unRequete );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //
    Requete (string un_IP_Client, string un_User_Id, string un_User_Name, Date une_Date,Temps un_Temps,
    string une_Time_Zone, string un_Type_Query, string un_URL, int un_Status, int une_Qte, string un_Referer );
    // Mode d'emploi :
    //
    // Contrat :
    //
    virtual ~Requete ( );
    // Mode d'emploi :
    //
    // Contrat :
    //
//------------------------------------------------------------------ PRIVE
protected:
//----------------------------------------------------- Méthodes protégées
//----------------------------------------------------- Attributs protégés
string IP_Client;
string User_Id;
string User_Name;
Date Date;
Temps Time;
string Time_Zone;
string Type_Query;
string URL;
int Status;
int Qte;
string Referer;
};
//-------------------------------- Autres définitions dépendantes de <Requete>
#endif // Requete_H