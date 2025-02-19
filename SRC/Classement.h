/*************************************************************************
                           Classement  -  Classement des requêtes
                             -------------------
    début                : 22/01/2025
    copyright            : (C) 2025 par B3107 - B3110
    e-mail               : mohammed.iich@insa-lyon.fr / hamza.el-karchouni@insa-lyon.fr / 
    			   mohamed.lemseffer@insa-lyon.fr / yliess.bellargui@insa-lyon.fr / youssef.erabhaoui@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Classement> (fichier Classement.h) ----------------
#if ! defined ( CLASSEMENT_H )
#define CLASSEMENT_H

//--------------------------------------------------- Interfaces utilisées
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include "Graphe.h"
#include "Requete.h"
using namespace std;

//------------------------------------------------------------------------
// Rôle de la classe <Classement>
//
// Cette classe gère le classement des requêtes selon un critère défini.
// Elle permet d'ajouter des requêtes et d'afficher le classement.
//------------------------------------------------------------------------

class Classement
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    
    void Ajouter(const vector<Requete> &unVecRequetes);
    // Mode d'emploi : 
    // La méthode prend un vecteur de requêtes et les ajoute au classement.
    // Contrat : 
    // Aucun.

    void Affichage();
    // Mode d'emploi : 
    // La méthode affiche le classement des requêtes, triées par ordre décroissant du nombre de hits.
    // Contrat : 
    // Aucun.

//-------------------------------------------- Constructeurs - destructeur

    Classement ( const Classement &unClassement );
    // Mode d'emploi : 
    // Initialise un objet Classement à partir d'un autre.
    // Contrat : 
    // Aucun.

    Classement ( );
    // Mode d'emploi : 
    // Initialise un objet Classement vide, sans éléments dans le classement.
    // Contrat : 
    // Aucun.

    virtual ~Classement ( );
    // Mode d'emploi : 
    // Nettoie les ressources utilisées par l'objet Classement lors de sa destruction.    
    // Contrat : 
    // Aucun.

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    map<string, int> classement; // On stocke le classement des requêtes sous forme d'un map, où la clé est l'URL 
                                 // et la valeur est le nombre de hits.
};

#endif // CLASSEMENT_H
