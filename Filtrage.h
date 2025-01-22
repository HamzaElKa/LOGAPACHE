/*************************************************************************
                           Filtrage  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Filtrage> (fichier Filtrage.h) ----------------
#if ! defined ( Filtrage_H )
#define Filtrage_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Filtrage>
//
//
//------------------------------------------------------------------------

class Filtrage : public Ancetre
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    
    bool & Skip(const requete & r) const;
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

//-------------------------------------------- Constructeurs - destructeur
    Filtrage(bool filtrer_temps, int heure, bool filtrer_images, vector<string> extensions_image);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Filtrage ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

    bool m_filtrer_temps;
    int m_heure;
    bool m_filtrer_images;
    vector<string> m_extensions_image;

};

//-------------------------------- Autres définitions dépendantes de <Filtrage>

#endif // Filtrage_H

