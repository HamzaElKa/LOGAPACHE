/*************************************************************************
                           Requete  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/
//---------- Interface de la classe <Requete> (fichier Requete.h) ----------------
#if !defined(Requete_H)
#define Requete_H

//--------------------------------------------------- Interfaces utilisées
#include <cstring>
#include <fstream>
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
//
//
//------------------------------------------------------------------------
class Requete
{
    //----------------------------------------------------------------- PUBLIC
    friend class Lecture;

public:
    //----------------------------------------------------- Méthodes publiques
    string GetExtension() const;
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
    //------------------------------------------------- Surcharge d'opérateurs
    Requete &operator=(const Requete &unRequete);
    // Mode d'emploi :
    //
    // Contrat :
    //
    //-------------------------------------------- Constructeurs - destructeur
    Requete(const Requete &unRequete);
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //
    Requete(string mAdresseIP, string mLogName, string mUserName, Date mDate, requeteHTTP mRHTTP, int mStatus, int mQte, string mReferer, string mClientID);
    // Mode d'emploi :
    //
    // Contrat :
    //
    virtual ~Requete();
    // Mode d'emploi :
    //
    // Contrat :
    //
    //------------------------------------------------------------------ PRIVE
protected:
    //----------------------------------------------------- Méthodes protégées
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
#endif // Requete_H
