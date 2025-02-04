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
    vector<Requete> requetes; // Vecteur pour stocker les requêtes lues
    string ligne;

    // Lecture ligne par ligne du fichier
    while (getline(mFluxFichier, ligne)) 
    {
        stringstream ss(ligne); // Convertit la ligne en flux de données
        string temp;

        // Extraction des différentes informations de la requête
        string adresseIP;
        getline(ss, adresseIP, ' '); // Récupère l'adresse IP

        string logName;
        getline(ss, logName, ' '); // Récupère le logName

        string userName;
        getline(ss, userName, ' '); // Récupère le userName

        // Extraction de la date et de l'heure
        Date date;
        getline(ss, temp, '['); // Ignore le caractère '['
        getline(ss, temp, '/'); // Récupère le jour
        date.jour = stoi(temp);
        getline(ss, date.mois, '/'); // Récupère le mois
        getline(ss, temp, ':'); // Récupère l'année
        date.annee = stoi(temp);
        getline(ss, temp, ':'); // Récupère l'heure
        date.heure = stoi(temp);
        getline(ss, temp, ':'); // Récupère les minutes
        date.minute = stoi(temp);
        getline(ss, temp, ' '); // Récupère les secondes
        date.seconde = stoi(temp);
        getline(ss, date.diffGMT, ']'); // Récupère le décalage GMT

        // Extraction de l'action HTTP et de l'URL
        getline(ss, temp, ' '); // Ignore le caractère ' '
        getline(ss, temp, '"'); // Ignore le guillemet ouvrant
        requeteHTTP rHTTP;
        getline(ss, rHTTP.action, ' '); // Récupère l'action HTTP (GET, POST, etc.)
        getline(ss, rHTTP.url, ' '); // Récupère l'URL
        getline(ss, rHTTP.http_version, '"'); // Récupère la version HTTP

        // Extraction du statut et de la quantité de données transférées
        getline(ss, temp, ' '); // Ignore un espace
        int status;
        getline(ss, temp, ' '); // Récupère le statut HTTP
        status = stoi(temp);

        int qte;
        getline(ss, temp, ' '); // Récupère la quantité de données
        qte = (temp == "-") ? 0 : stoi(temp); // Si la quantité est "-", la mettre à 0

        // Extraction du referer et suppression de la base locale si présente
        string referer;
        getline(ss, temp, '"'); // Ignore le premier guillemet
        getline(ss, referer, '"'); // Récupère le referer
        size_t position = referer.find(mBaseLocale); // Recherche la base locale dans le referer
        if (position != string::npos) // Si la base locale est trouvée
        {
            referer.erase(position, mBaseLocale.length()); 
        }

        // Extraction de l'identifiant client
        string clientID;
        getline(ss, temp, '"'); // Ignore le guillemet
        getline(ss, clientID, '"'); // Récupère l'identifiant client

        // Création d'un objet Requete et application du filtre
        Requete r(adresseIP, logName, userName, date, rHTTP, status, qte, referer, clientID);
        bool skip = filtre.Skip(r); // Applique le filtre pour savoir si la requête doit être ignorée
        if (!skip) // Si la requête ne doit pas être ignorée
        {
            requetes.push_back(r); // Ajoute la requête au vecteur
        }
    }

    // Vérification que des requêtes valides ont été trouvées
    if (requetes.empty()) // Si le vecteur est vide
    {
        cerr << "Erreur, aucune ligne valide n'a été trouvée !" << endl;
        exit(EXIT_FAILURE); 
    }

    return requetes; 
}
// Fin Lecture.cpp
