#include "Requete.h"
#include <iostream>
#include <sstream>

using namespace std;

Requete::Requete()
{
}

Requete::Requete(const Requete &unRequete)
{
    *this = unRequete;
}

Requete::Requete(string AdresseIP, string LogName, string UserName, Date Date, requeteHTTP RHTTP, int Status, int Qte, string Referer, string ClientID)
{
    mAdresseIP = AdresseIP;
    mLogName = LogName;
    mUserName = UserName;
    mDate = Date;
    mRHTTP = RHTTP;
    mStatus = Status;
    mQte = Qte;
    mReferer = Referer;
    mClientID = ClientID;
}

Requete::~Requete()
{
}

Requete &Requete::operator=(const Requete &unRequete)
{
    if (this != &unRequete)
    {
        mAdresseIP = unRequete.mAdresseIP;
        mLogName = unRequete.mLogName;
        mUserName = unRequete.mUserName;
        mDate = unRequete.mDate;
        mRHTTP = unRequete.mRHTTP;
        mStatus = unRequete.mStatus;
        mQte = unRequete.mQte;
        mReferer = unRequete.mReferer;
        mClientID = unRequete.mClientID;
    }
    return *this;
}

string Requete::GetExtension() const
{
    size_t pos = mRHTTP.url.find_last_of('.');
    if (pos != string::npos)
    {
        return mRHTTP.url.substr(pos + 1);
    }
    return "";
}
