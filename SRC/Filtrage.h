/*************************************************************************
                           Filtrage  -  filtrer des objets de type Requete
                             -------------------
    début                : 22/01/2025
    copyright            : (C) 2025 par B3107 - B3110
    e-mail               : mohammed.iich@insa-lyon.fr / hamza.el-karchouni@insa-lyon.fr / 
    			   mohamed.lemseffer@insa-lyon.fr / yliess.bellargui@insa-lyon.fr / youssef.erabhaoui@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Filtrage> (fichier Filtrage.h) ----------------
#if ! defined ( Filtrage_H )
#define Filtrage_H

//--------------------------------------------------- Interfaces utilisées
#include "Filtrage.h"
#include "Requete.h"
#include <vector>
#include <unordered_set>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Filtrage>
//
// Cette classe permet de filtrer des requêtes en fonction de critères définis.
// Elle offre des méthodes pour appliquer des filtres sur les extensions de fichiers 
// et l'heure des requêtes, et décider si une requête doit être ignorée ou non.
//------------------------------------------------------------------------

class Filtrage
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    void Filtrer(vector<Requete> & vecRequetes) const;
    // Mode d'emploi : 
    // Cette méthode parcourt le vecteur de requêtes et applique le filtrage en fonction des attributs de la classe.
    // Contrat : 
    // Aucun.

    bool Skip(const Requete & r) const;
    // Mode d'emploi : 
    // Cette méthode retourne vrai si la requête r doit être ignorée selon les filtres appliqués (heure et extensions).
    // Contrat : 
    // Aucun.

//-------------------------------------------- Constructeurs - destructeur
    
    Filtrage(bool filtrerTemps, int heure, bool filtrerExtensions, unordered_set<string> extensions);
    // Mode d'emploi :
    // Initialise un objet Filtrage avec les critères spécifiés pour filtrer les requêtes.
    // Contrat : 
    // Aucun.

    virtual ~Filtrage ( );
    // Mode d'emploi : 
    // Nettoie les ressources utilisées par l'objet Filtrage lors de sa destruction.
    // Contrat : 
    // Aucun.

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

    bool mFiltrerTemps; // Attribut indiquant si le filtrage par heure est activé

    int mHeure; // Attribut qui stocke l'heure de filtrage

    bool mFiltrerExtensions; // Attribut indiquant si le filtrage par extensions est activé

    unordered_set<string> mExtensions; // Ensemble des extensions à filtrer

};

//-------------------------------- Autres définitions dépendantes de <Filtrage>

#endif // Filtrage_H
