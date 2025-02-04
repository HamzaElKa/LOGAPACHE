/*************************************************************************
                           Lecture -  lire un fichier de logs ligne par ligne
                             -------------------
    début                : 22/01/2025
    copyright            : (C) 2025 par B3107 - B3110
    e-mail               : mohammed.iich@insa-lyon.fr / hamza.el-karchouni@insa-lyon.fr / 
    			   mohamed.lemseffer@insa-lyon.fr / yliess.bellargui@insa-lyon.fr / youssef.erabhaoui@insa-lyon.fr
*************************************************************************/

#include "Lecture.h"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

// Constructeur : ouvre le fichier et initialise la base locale
Lecture::Lecture(const string &fluxFichier, const string &baseLocale) : mBaseLocale(baseLocale)
{
    mFluxFichier.open(fluxFichier);
    if (!mFluxFichier)
    {
        cerr << "Erreur, impossible d'ouvrir le fichier !" << endl;
        exit(EXIT_FAILURE);
    }
}

// Destructeur : ferme le fichier s'il est encore ouvert
Lecture::~Lecture()
{
    if (mFluxFichier.is_open())
    {
        mFluxFichier.close();
    }
}

// Méthode permettant de lire et filtrer les requêtes
vector<Requete> Lecture::Lire(const Filtrage & filtre)
{
    vector<Requete> requetes;
    string ligne;

    // Lecture ligne par ligne du fichier
    while (getline(mFluxFichier, ligne))
    {
        stringstream ss(ligne);
        string temp;

        // Extraction des différentes informations de la requête
        string adresseIP;
        getline(ss, adresseIP, ' ');

        string logName;
        getline(ss, logName, ' ');

        string userName;
        getline(ss, userName, ' ');

        // Extraction de la date et de l'heure
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

        // Extraction de l'action HTTP et de l'URL
        getline(ss, temp, ' ');
        getline(ss, temp, '"');
        requeteHTTP rHTTP;
        getline(ss, rHTTP.action, ' ');
        getline(ss, rHTTP.url, ' ');
        getline(ss, rHTTP.http_version, '"');

        // Extraction du statut et de la quantité de données transférées
        getline(ss, temp, ' ');
        int status;
        getline(ss, temp, ' ');
        status = stoi(temp);

        int qte;
        getline(ss, temp, ' ');
        qte = (temp == "-") ? 0 : stoi(temp);

        // Extraction du referer et suppression de la base locale si présente
        string referer;
        getline(ss, temp, '"');
        getline(ss, referer, '"');
        size_t position = referer.find(mBaseLocale);
        if (position != string::npos)
        {
            referer.erase(position, mBaseLocale.length());
        }

        // Extraction de l'identifiant client
        string clientID;
        getline(ss, temp, '"');
        getline(ss, clientID, '"');

        // Création d'un objet Requete et application du filtre
        Requete r(adresseIP, logName, userName, date, rHTTP, status, qte, referer, clientID);
        bool skip = filtre.Skip(r);
        if (!skip)
        {
            requetes.push_back(r);
        }
    }

    // Vérification que des requêtes valides ont été trouvées
    if (requetes.empty())
    {
        cerr << "Erreur, aucune ligne valide n'a été trouvée !" << endl;
        exit(EXIT_FAILURE);
    }

    return requetes;
}
// Fin Lecture.cpp
