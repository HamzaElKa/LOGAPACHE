#include <iostream>
using namespace std;

#include "Classement.h"

void Classement::Ajouter(const vector<Requete> & unVecRequetes)
{
	if (unVecRequetes.empty())
	{
		cerr << "Erreur : Vous n'avez aucune requete" << endl;
		return;
	}

	vector<Requete>::const_iterator it;
	for (it = unVecRequetes.begin(); it != unVecRequetes.end(); ++it)
    {
        string dest = it->GetDestination();
        map<string, int>::iterator classementIt = classement.find(dest);
        if (classementIt == classement.end())
        {
            classement.insert(make_pair(dest, 1));
        }
        else
        {
            classementIt->second++;
        }
    }
}

void Classement::Affichage()
{
	if (classement.empty())
	{
		cout << "Aucune donnée à afficher." << endl;
		return;
	}

	vector<pair<string, int>> vec(classement.begin(), classement.end());

	sort(vec.begin(), vec.end(),
		 [](const pair<string, int> &a, const pair<string, int> &b) {
			 return b.second < a.second;
		 });

	cout << "Top URLs consultées :" << endl;
	for (size_t i = 0; i < 10 && i < vec.size(); ++i)
	{
		cout << vec[i].first << " (" << vec[i].second << " hits)" << endl;
	}
}

Classement::Classement()
{
	#ifdef MAP
    	cout << "Appel au constructeur de <Classement>" << endl;
	#endif
}

Classement::Classement(const Classement & unClassement)
{
	#ifdef MAP
    	cout << "Appel au constructeur de copie de <Classement>" << endl;
	#endif
	classement = unClassement.classement;
}

Classement::~Classement()
{
	#ifdef MAP
    	cout << "Appel au destructeur de <Classement>" << endl;
	#endif
}
