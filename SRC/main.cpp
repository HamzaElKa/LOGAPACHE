/*************************************************************************
                           main -  fonction principale pour traiter les logs HTTP
                             -------------------
    début                : 22/01/2025
    copyright            : (C) 2025 par B3107 - B3110
    e-mail               : mohammed.iich@insa-lyon.fr / hamza.el-karchouni@insa-lyon.fr / 
                           mohamed.lemseffer@insa-lyon.fr / yliess.bellargui@insa-lyon.fr / 
                           youssef.erabhaoui@insa-lyon.fr
*************************************************************************/

using namespace std;
#include <iostream>
#include <vector>
#include <unordered_set>
#include <cstring>
#include "Filtrage.h"
#include "Lecture.h"
#include "Requete.h"
#include "Classement.h"
#include "Graphe.h"

// Fonction pour analyser les arguments en ligne de commande
void Demarrage(bool &, int &, bool &, bool &, string &, string &, const int &, char * [], bool &, const string &);

int main(int argc, char * argv[])
{
    // Extensions de fichiers à filtrer
    unordered_set<string> extensions = {
        "jpg", "jpeg", "png", "bmp", "gif", "tiff", "tif", "webp", "ico",
        "svg", "eps", "ai", "raw", "cr2", "nef", "arw", "dng", "psd", "heic",
        "heif", "xcf", "css", "js", "mjs"
    };

    string baseURL = "http://intranet-if.insa-lyon.fr"; // URL de base pour les logs

    // Variables pour les options de filtrage et autres paramètres
    bool filtrerTemps = false;
    int heure = -1;
    bool filtrerExtensions = false;
    bool genererGraphe = false;
    string nomGraphe = "";
    string nomFic = "";
    bool erreur = false;

    // Analyse des arguments en ligne de commande
    Demarrage(filtrerTemps, heure, filtrerExtensions, genererGraphe, nomFic, nomGraphe, argc, argv, erreur, baseURL);
    if (erreur) return 1;

    // Création des objets nécessaires au traitement
    Filtrage filtre(filtrerTemps, heure, filtrerExtensions, extensions);
    Lecture lecture(nomFic, baseURL);
    Graphe graphe;
    Classement classement;
    
    // Lecture des requêtes et application du filtrage
    vector<Requete> vecRequetes = lecture.Lire(filtre);

    // Génération du graphe si nécessaire
    if (genererGraphe) graphe.Ajouter(vecRequetes);
    classement.Ajouter(vecRequetes);
    
    // Génération du fichier du graphe
    if (genererGraphe) graphe.GenererFichier(nomGraphe);
    classement.Affichage();

    // Fin du programme principal
    return 0;
}

// Fonction pour analyser les arguments de la ligne de commande
void Demarrage(bool & filtrerTemps, int & heure, bool & filtrerExtensions, bool &genererGraphe, string & nomFic, 
                string & nomGraphe, const int & argc, char * argv[], bool & erreur, const string & baseURL)
{
    if (argc == 1)
    {
        cerr << "Aucun nom de fichier n'a ete renseigne" << endl;
        erreur = true;
        return;
    }

    erreur = false;
    nomFic = argv[argc-1]; // Récupération du fichier d'entrée
    int i = 1;

    while (i < argc - 1)
    {
        if (!strcmp(argv[i], "-e")) // Option pour filtrer les extensions
        {
            if (filtrerExtensions) 
            {
                cerr << "Option -e utilisée plusieurs fois" << endl;
                erreur = true;
                return;
            }
            filtrerExtensions = true;
            i++;
        }
        else if (!strcmp(argv[i], "-g")) // Option pour générer un graphe
        {
            if (genererGraphe)
            {
                erreur = true;
                cerr << "Option -g utilisée plusieurs fois" << endl;
                return;
            }
            genererGraphe = true;
            ++i;
            if(i < argc - 1)
            {
                nomGraphe = argv[i]; // Nom du fichier pour le graphe

                size_t pos = nomGraphe.find_last_of('.');
              
                if (pos != string::npos)
                {
                    if (nomGraphe.substr(pos + 1)!="dot")
                    {
                        erreur = 1;
                        cerr << "Le fichier pour creer le graphe doit etre un .dot" << endl;
                        return;
                    }
                }
              
                i++;
            }
            else
            {
                erreur = true;
                cerr << "Nom du fichier du graphe manquant" << endl;
                return;
            }
        }
        else if (!strcmp(argv[i], "-t")) // Option pour filtrer par heure
        {
            if (filtrerTemps)
            {
                erreur = true;
                cerr << "Option -t utilisée plusieurs fois" << endl;
                return;
            }
            filtrerTemps = true;
            ++i;
            if (i < argc - 1)
            {
                heure = stoi(argv[i]); // Heure de filtrage
                if (heure < 0 || heure > 24)
                {
                    erreur = true;
                    cerr << "L'heure doit être entre 0 et 24" << endl;
                    return;
                }
                ++i;
            }
            else
            {
                erreur = true;
                cerr << "Heure manquante" << endl;
                return;
            }
        }
    }
}
