/*************************************************************************
                           Graphe  -  gérer le graphe orienté
                             -------------------
    début                : 22/01/2025
    copyright            : (C) 2025 par B3107 - B3110
    e-mail               : mohammed.iich@insa-lyon.fr / hamza.el-karchouni@insa-lyon.fr / 
                           mohamed.lemseffer@insa-lyon.fr / yliess.bellargui@insa-lyon.fr / 
                           youssef.erabhaoui@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Graphe> (fichier Graphe.h) ----------------
#if ! defined ( Graphe_H )
#define Graphe_H

//--------------------------------------------------- Interfaces utilisées
#include "Requete.h"
#include <vector>
#include <map>
#include <fstream>
using namespace std;

//------------------------------------------------------------- Constantes
//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Graphe>
//
// Cette classe gère un graphe orienté représentant les relations entre les URL d'un ensemble de requêtes. 
//------------------------------------------------------------------------

class Graphe
{
//----------------------------------------------------------------- PUBLIC
public:
//----------------------------------------------------- Méthodes publiques

    void GenererFichier(const string & nomFichier) const;
    // Mode d'emploi :
    // Cette méthode écrit un fichier ".dot" qui représente le graphe sous forme d'un format compréhensible par GraphViz 
    // pour une visualisation graphique.
    // Contrat :
    // Aucun.

    void Ajouter(const vector<Requete> & vecRequetes);
    // Mode d'emploi :
    // Cette méthode parcourt un vecteur de requêtes et ajoute les URL ainsi que les filtres à appliquer dans 
    // les maps associées aux arêtes et noeuds du graphe.
    // Les arêtes correspondent aux relations entre les URLs, et les noeuds sont les URLs elles-mêmes.
    // Contrat :
    // Les requêtes doivent contenir des informations valides pour le graphe (destination, référent).

//-------------------------------------------- Constructeurs - destructeur

    Graphe ( const Graphe & unGraphe );
    // Mode d'emploi :
    // Crée une nouvelle instance de Graphe en copiant les attributs de l'objet Graphe fourni.
    // Contrat : 
    // Aucun.

    Graphe ( );
    // Mode d'emploi :
    // Crée une instance vide de Graphe.
    // Contrat : 
    // Aucun.

    virtual ~Graphe ( );
    // Mode d'emploi :
    // Libère les ressources utilisées par l'objet Graphe.
    // Contrat :
    // Aucun.

//------------------------------------------------------------------ PRIVE
protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

    map<string,map<string,int>> mAretes; // map des arêtes du graphe 

    map <string, int> mNoeuds; // Noeuds du graphe sous forme d'une map

    int mNbNoeuds;   // Nombre total de noeuds dans le graphe

};

//-------------------------------- Autres définitions dépendantes de <Graphe>

#endif // Graphe_H
