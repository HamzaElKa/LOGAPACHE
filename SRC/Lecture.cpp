#include "Lecture.h"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

Lecture::Lecture(const string &fluxFichier, const string &baseLocale) : mBaseLocale(baseLocale)
{
	mFluxFichier.open(fluxFichier);
	if (!mFluxFichier)
	{
		cerr << "Erreur, impossible d'ouvrir le fichier !" << endl;
		exit(EXIT_FAILURE);
	}
}

Lecture::~Lecture()
{
	if (mFluxFichier.is_open())
	{
		mFluxFichier.close();
	}
}

vector<Requete> Lecture::Lire()
{
	vector<Requete> requetes;
	string ligne;

	while (getline(mFluxFichier, ligne))
	{
		stringstream ss(ligne);
		string temp;

		string adresseIP;
		getline(ss, adresseIP, ' ');

		string logName;
		getline(ss, logName, ' ');

		string userName;
		getline(ss, userName, ' ');

		Date date;
		getline(ss, temp, '[');
		getline(ss, temp, '/');
		date.jour = stoi(temp);
		getline(ss, date.mois, '/');
		getline(ss, temp, ':');
		date.annee = stoi(temp);
		getline(ss, temp, ':');
		date.heure = stoi(temp);
		getline(ss, temp, ':');
		date.minute = stoi(temp);
		getline(ss, temp, ' ');
		date.seconde = stoi(temp);
		getline(ss, date.diffGMT, ']');

		getline(ss, temp, ' ');
		getline(ss, temp, '"');

		requeteHTTP rHTTP;
		getline(ss, rHTTP.action, ' ');
		getline(ss, rHTTP.url, ' ');
		getline(ss, rHTTP.http_version, '"');

		getline(ss, temp, ' ');

		int status;
		getline(ss, temp, ' ');
		status = stoi(temp);

		int qte;
		getline(ss, temp, ' ');
		
		//Cas particulier : "-"
		if (temp == "-") qte = 0;
		else qte = stoi(temp);
		
		string referer;
		getline(ss, temp, '"');
		getline(ss, referer, '"');

		size_t position = referer.find(mBaseLocale);
		if (position != string::npos)
		{
			referer.erase(position, mBaseLocale.length());
		}

		string clientID;
		getline(ss, temp, '"');
		getline(ss, clientID, '"');

		Requete r(adresseIP, logName, userName, date, rHTTP, status, qte, referer, clientID);
		requetes.push_back(r);
	}

	if (requetes.empty())
	{
		cerr << "Erreur, aucune ligne valide n'a été trouvée !" << endl;
		exit(EXIT_FAILURE);
	}

	return requetes;
}
