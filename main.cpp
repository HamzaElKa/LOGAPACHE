/*************************************************************************
                           main -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

using namespace std;
#include <iostream>
#include <vector>
#include <cstring>
#include "Filtrage.h"
#include "Lecture.h"
#include "Requete.h"
#include "Classement.h"

void Demarrage(bool &, int &, bool &, bool &, string &, string &, const int &, const char * [], bool &, const string &);

int main(int argc, char * argv[])
{

    vector<string> extensions = {"jpg", "jpeg", "png", "bmp", "gif", "tiff", "tif", "webp", "ico", 
                                    "svg", "eps", "ai", "raw", "cr2", "nef", "arw", "dng", "psd", "heic", 
                                    "heif", "xcf", "css", "js", "mjs"};
    string baseURL = "intranet-if.insa-lyon.fr";

    bool filtrerTemps = false;
    int heure = -1;
    bool filtrerImages = false;
	bool genererGraphe = false;
	string nomGraphe;
	string nomFic;
    bool erreur = false;

    Demarrage(requeteComplete, filtrerTemps, heure, filtrerImages, genererGraphe, nomFic, nomGraphe, argc, argv, erreur, baseURL);
    if (erreur) return 1;

    Filtrage filtre(filtrerTemps, heure, filtrerExtensions, Extensions);
    Lecture lecture(nomFic, baseURL);
    Graphe graphe;
    Classement classement;
    while (!lecture.finie())
    {
        requete r = lecture.lire();
        if (genereGraphe) graphe.Ajouter(r);
        classement.Ajouter(r);
    }

    if (genereGraphe) graphe.GenerateFichier(nomGraphe);
    classement.Affichage();

}


void Demarrage(bool & filtrerTemps, int & heure, bool & filtrerImages, bool &genererGraphe, string & nomGraphe, 
                string & nomFic, const int & argv, const char * argv[], bool & erreur, const string & baseURL)
{

    if (argc == 1)
    {
        cerr << "Aucun nom de fichier n'a ete renseigne" << endl;
        erreur = true;
        return;
    }

    erreur = false;
    nomFic = argv[argc-1];

    unsigned i=1;

    while (i<argc-1)
    {
        if(!strcmp(argv[i],"-e"))
        {
			if(filtreImage)
            { 
                cerr << "Vous avez utilise plusieurs fois l'option de compilation -e" << endl;
				erreur=true;
			}
            else
            {
				filtrerImages=true;
				i++;
			}
		}
        else if(!strcmp(argv[optionCounter],"-g"))
        {
			if(genererGraphe)
            {
				erreur=true;
                cerr << "Vous avez utilise plusieurs fois l'option de compilation -g" << endl;
                return;
			}
            else
            {
				genererGraphe=true;
				++i;
				if(i<argc-1)
                {
					nomGraphe=argv[i];
					i++;
				}
                else
                {
					error=true;
                    cerr << "Il manque le nom de fichier du graphe" << endl;
                    return;
				}
			}
		}

        else if(!strcmp(argv[optionCounter],"-t"))
        {
			if(filtrerTemps)
            {
				erreur=true;
                cerr << "Vous avez utilise plusieurs fois l'option de compilation -t" << endl;
                return;
			}
            else
            {
				filtrerTemps=true;
				++i;
				if(i<argc-1)
                {
					string heure_str = argv[i];
                    heure = stoi(heure_str);
                    if (heure<0||heure>24)
                    {
                        erreur = true;
                        cerr << "L'heure doit etre comprise entre 0 et 24" << endl;
                        return;
                    }
                    ++i;
				}
                else
                {
					erreur=true;
                    cerr << "Vous n'avez pas indique d'heure" << endl;
                    return;
				}
			}
		}
    }
}