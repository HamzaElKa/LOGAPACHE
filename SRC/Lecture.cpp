#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <fstream>
#include "Lecture.h"

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

vector<Requete> Lecture::Lire(void) const
{
	vector<Requete> requetes;
	string ligne;
	while (getline(m_fluxFichier, ligne))
	{
		stringstream ss(ligne);

		string adresseIP;
		getline(ss, adresseIP, ' ');

		string temp;
		getline(ss, temp, ' ');
		getline(ss, temp, ' ');

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
		qte = stoi(temp);

		string referer;
		getline(ss, temp, '"');
		getline(ss, referer, '"');

		size_t position = referer.find(m_baseLocale);
		if (position != string::npos)
		{
			referer.erase(position, m_baseLocale.length());
		}

		string clientID;
		getline(ss, temp, '"');
		getline(ss, clientID, '"');

		Requete r(adresseIP, temp, temp, date, rHTTP, status, qte, referer, clientID);

		requetes.push_back(r);
	}

	if (requetes.empty())
	{
		cerr << "Erreur, aucune ligne valide n'a été trouvée !" << endl;
		exit(EXIT_FAILURE);
	}

	return requetes;
}

Lecture::Lecture(const string &fluxFichier, const string &baseLocale) : m_baseLocale(baseLocale)
{
	m_fluxFichier.open(fluxFichier);
	if (!m_fluxFichier)
	{
		cerr << "Erreur, impossible d'ouvrir le fichier !" << endl;
		exit(EXIT_FAILURE);
	}
}

Lecture::~Lecture()
{
	if (m_fluxFichier.is_open())
	{
		m_fluxFichier.close();
	}
}
