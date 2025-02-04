/*************************************************************************
                           Requete  -  Gestion des requêtes HTTP
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par Mohammed IICH
    e-mail               : mohammed.iich@outlook.fr
*************************************************************************/

//---------- Interface de la classe <Requete> (fichier Requete.h) ----------------
#if ! defined ( REQUETE_H )
#define REQUETE_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
using namespace std;

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types
struct Date
{
    int jour;
    string mois;
    int annee;
    int heure;
    int minute;
    int seconde;
    string diffGMT;
};

struct requeteHTTP
{
    string action;
    string url;
    string http_version;
};

//------------------------------------------------------------------------
// Rôle de la classe <Requete>
// Cette classe représente une requête HTTP avec ses différentes informations :
// adresse IP, identifiants, date, requête HTTP, statut, quantité, référant et ID client.
//------------------------------------------------------------------------

class Requete
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    string GetExtension() const;
    // Mode d'emploi : Retourne l'extension du fichier demandé dans la requête
    // Contrat : Aucun

    string GetDestination() const;
    // Mode d'emploi : Retourne la destination de la requête HTTP
    // Contrat : Aucun

    string GetReferer() const;
    // Mode d'emploi : Retourne le référant de la requête HTTP
    // Contrat : Aucun

    int GetHeure() const;
    // Mode d'emploi : Retourne l'heure à laquelle la requête a été effectuée
    // Contrat : Aucun

//------------------------------------------------- Surcharge d'opérateurs
    Requete & operator = ( const Requete & unRequete );
    // Mode d'emploi : Opérateur d'affectation
    // Contrat : Aucun

//-------------------------------------------- Constructeurs - destructeur
    Requete();
    // Mode d'emploi : Constructeur par défaut
    // Contrat : Aucun

    Requete(const Requete &unRequete);
    // Mode d'emploi (constructeur de copie) : Crée une copie d'une requête existante
    // Contrat : Aucun

    Requete(string AdresseIP, string LogName, string UserName, Date Date, requeteHTTP RHTTP, int Status, int Qte, string Referer, string ClientID);
    // Mode d'emploi : Constructeur avec paramètres
    // Contrat : Aucun

    virtual ~Requete();
    // Mode d'emploi : Destructeur de la classe
    // Contrat : Aucun

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Attributs protégés
    string mAdresseIP;
    string mLogName;
    string mUserName;
    Date mDate;
    requeteHTTP mRHTTP;
    int mStatus;
    int mQte;
    string mReferer;
    string mClientID;
};

//-------------------------------- Autres définitions dépendantes de <Requete>

#endif // REQUETE_H
