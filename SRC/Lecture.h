/*************************************************************************
                           main -  description
                             -------------------
    début                : 22/01/2025
    copyright            : (C) 2025 par B3107 - B3110
    e-mail               : mohammed.iich@insa-lyon.fr / hamza.el-karchouni@insa-lyon.fr / 
    			   mohamed.lemseffer@insa-lyon.fr / yliess.bellargui@insa-lyon.fr / youssef.erabhaoui@insa-lyon.fr
*************************************************************************/

#ifndef LECTURE_H
#define LECTURE_H

#include <fstream>
#include <vector>
#include "Requete.h"
#include "Filtrage.h"

// Classe permettant la lecture des requêtes depuis un fichier
class Lecture
{
public:
    // Constructeur prenant en paramètre le nom du fichier à lire et l'URL de base
    Lecture(const string &fluxFichier, const string &baseLocale);
    
    // Destructeur libérant les ressources associées
    ~Lecture();

    // Méthode permettant de lire les requêtes et de les filtrer selon un objet Filtrage
    vector<Requete> Lire(const Filtrage & filtre);

protected:
    ifstream mFluxFichier; // Flux de fichier pour la lecture
    string mBaseLocale; // URL de base utilisée pour la lecture et le traitement des requêtes
};

#endif // LECTURE_H

