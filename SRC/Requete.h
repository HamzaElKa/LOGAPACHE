#ifndef REQUETE_H
#define REQUETE_H

#include <string>
using namespace std;

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

class Requete
{
public:
    Requete();
    Requete(const Requete &unRequete);
    Requete(string AdresseIP, string LogName, string UserName, Date Date, requeteHTTP RHTTP, int Status, int Qte, string Referer, string ClientID);
    ~Requete();

    string GetExtension() const;

    Requete &operator=(const Requete &unRequete);

protected:
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

#endif // REQUETE_H
