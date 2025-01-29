/*************************************************************************
                           GenerateGraphe
    Permet de générer un fichier synthétique au format GraphViz.
*************************************************************************/

//---------- Réalisation de la classe <GenerateGraphe> (fichier GenerateGraphe.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
using namespace std;

//------------------------------------------------------ Include personnel
#include "GenerateGraphe.h"
#include "Requete.h"
#include "Filtrage.h"

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void GenerateGraphe::GenerateFichier(const string &nomFichier)
// Algorithme :
// On parcourt la map nodes pour générer les nœuds et la map passage
// pour générer les arcs entre ces nœuds.
{
    ofstream fichierGraphe(nomFichier);
    fichierGraphe << "digraph {" << endl;

    // Création des nœuds
    for (const auto &it : nodes)
    {
        fichierGraphe << "node" << it.second << " [label=\"" << it.first << "\"];" << endl;
    }

    // Construction des arcs
    for (const auto &it : passage)
    {
        auto inodes_dest = nodes.find(it.first);
        if (inodes_dest != nodes.end()) // Vérification de l'existence
        {
            int dest = inodes_dest->second;
            for (const auto &ij : it.second)
            {
                auto inodes_src = nodes.find(ij.first);
                if (inodes_src != nodes.end()) // Vérification de l'existence
                {
                    int src = inodes_src->second;
                    fichierGraphe << "node" << src << " -> " << "node" << dest
                                  << " [label=\"" << ij.second << "\"];" << endl;
                }
            }
        }
    }

    fichierGraphe << "}" << endl;
    fichierGraphe.close();
} //----- Fin de GenerateFichier

void GenerateGraphe::Ajouter(const Requete &r, const vector<Filtrage *> &filtres)
// Algorithme : Vérifie si une requête passe tous les filtres et met à jour le graphe
{
    for (const auto &filtre : filtres)
    {
        if (filtre->Skip(r)) // On utilise Skip() à la place de ResultatFiltrage()
        {
            return; // La requête est filtrée, on l'ignore
        }
    }

    string dest = r.mRHTTP.url; // Utilisation correcte de l'URL
    string src = r.mReferer;    // Utilisation correcte du referer

    // Mise à jour de passage
    auto it = passage.find(dest);
    if (it == passage.end())
    {
        // Première apparition d'une destination
        passage[dest] = {{src, 1}};
    }
    else
    {
        // Destination déjà vue, on incrémente
        it->second[src]++;
    }

    // Mise à jour de nodes
    if (nodes.find(src) == nodes.end())
    {
        nodes[src] = nodeNum++;
    }
    if (nodes.find(dest) == nodes.end())
    {
        nodes[dest] = nodeNum++;
    }

} //----- Fin de Ajouter

//-------------------------------------------- Constructeurs - destructeur

GenerateGraphe::GenerateGraphe(const GenerateGraphe &unGenerateGraphe)
    : nodes(unGenerateGraphe.nodes), passage(unGenerateGraphe.passage), nodeNum(unGenerateGraphe.nodeNum)
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <GenerateGraphe>" << endl;
#endif
} //----- Fin de GenerateGraphe (constructeur de copie)

GenerateGraphe::~GenerateGraphe()
{
#ifdef MAP
    cout << "Appel au destructeur de <GenerateGraphe>" << endl;
#endif
} //----- Fin de ~GenerateGraphe
