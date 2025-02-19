/*************************************************************************
                           Lecture  -  lire un fichier de logs ligne par ligne
                             -------------------
    début                : 22/01/2025
    copyright            : (C) 2025 par B3107 - B3110
    e-mail               : mohammed.iich@insa-lyon.fr / hamza.el-karchouni@insa-lyon.fr / 
                           mohamed.lemseffer@insa-lyon.fr / yliess.bellargui@insa-lyon.fr / 
                           youssef.erabhaoui@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Lecture> (fichier Lecture.h) ----------------
#if ! defined ( LECTURE_H )
#define LECTURE_H

//--------------------------------------------------- Interfaces utilisées
#include <fstream>
#include <vector>
#include "Requete.h"
#include "Filtrage.h"

//------------------------------------------------------------------------
// Rôle de la classe <Lecture>
//
// Cette classe permet de lire un fichier de logs ligne par ligne.
//
//------------------------------------------------------------------------

class Lecture
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    vector<Requete> Lire(const Filtrage & filtre);
    // Lire : Lit un fichier de logs ligne par ligne et retourne un vecteur de requêtes filtrées
    // Mode d'emploi :
    // Cette méthode ouvre le fichier spécifié, lit chaque ligne et crée des objets Requete en filtrant 
    // selon l'objet Filtrage passé en paramètre.
    // Contrat :
    // Le fichier doit être ouvert correctement et l'objet Filtrage valide.

    Lecture(const string &fluxFichier, const string &baseLocale);
    // Mode d'emploi :
    // Le constructeur initialise un objet Lecture en associant un fichier de logs et une base URL pour traiter les requêtes.
    // Contrat :
    // Le fichier doit exister et être lisible.

//-------------------------------------------- Constructeurs - destructeur
    Lecture ( const Lecture & unLecture );
    // Mode d'emploi (constructeur de copie) :
    // Initialise un objet Lecture à partir d'un autre.
    // Contrat :
    // Aucun.

    virtual ~Lecture ( );
    // Mode d'emploi :
    // Nettoie les ressources de l'objet Lecture.
    // Contrat :
    // Aucun.

//----------------------------------------------------------------- PRIVE

protected:
//----------------------------------------------------- Attributs protégés
    ifstream mFluxFichier; // Flux de fichier pour la lecture
    string mBaseLocale; // URL de base utilisée pour la lecture et le traitement des requêtes

};

#endif // LECTURE_H
