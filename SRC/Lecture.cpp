/*************************************************************************
                           Lecture -  lire un fichier de logs ligne par ligne
                             -------------------
    début                : 22/01/2025
    copyright            : (C) 2025 par B3107 - B3110
    e-mail               : mohammed.iich@insa-lyon.fr / hamza.el-karchouni@insa-lyon.fr / 
    			   mohamed.lemseffer@insa-lyon.fr / yliess.bellargui@insa-lyon.fr / youssef.erabhaoui@insa-lyon.fr
*************************************************************************/

#include "Lecture.h"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

// Constructeur : ouvre le fichier et initialise la base locale
Lecture::Lecture(const string &fluxFichier, const string &baseLocale) : mBaseLocale(baseLocale)
{
    mFluxFichier.open(fluxFichier); 
    if (!mFluxFichier) 
    {
        cerr << "Erreur, impossible d'ouvrir le fichier !" << endl;
        exit(EXIT_FAILURE); 
    }
}

// Destructeur : ferme le fichier s'il est ouvert
Lecture::~Lecture()
{
    if (mFluxFichier.is_open()) 
    {
        mFluxFichier.close(); 
    }
}

// Méthode pour lire et filtrer les requêtes
vector<Requete> Lecture::Lire(const Filtrage & filtre)
{
    vector<Requete> requetes; // On a choisi un vecteur pour stocker les requêtes lues
    string ligne;

    // Lecture ligne par ligne du fichier
    while (getline(mFluxFichier, ligne)) 
    {
        stringstream ss(ligne); // Flux pour traiter la ligne

        // Extraction des informations de la requête
        string adresseIP, logName, userName, temp, referer, clientID;
        Date date;
        requeteHTTP rHTTP;
        int status, qte;

        // Extraction des données depuis la ligne
        getline(ss, adresseIP, ' '); 
        getline(ss, logName, ' '); 
        getline(ss, userName, ' '); 
        getline(ss, temp, '['); getline(ss, temp, '/'); date.jour = stoi(temp);
        getline(ss, date.mois, '/'); getline(ss, temp, ':'); date.annee = stoi(temp);
        getline(ss, temp, ':'); date.heure = stoi(temp); getline(ss, temp, ':'); date.minute = stoi(temp);
        getline(ss, temp, ' '); date.seconde = stoi(temp); getline(ss, date.diffGMT, ']');

        // Extraction de l'action HTTP et de l'URL
        getline(ss, temp, ' '); getline(ss, temp, '"'); 
        getline(ss, rHTTP.action, ' '); getline(ss, rHTTP.url, ' '); getline(ss, rHTTP.http_version, '"');

        // Extraction du statut et des données transférées
        getline(ss, temp, ' '); getline(ss, temp, ' '); status = stoi(temp);
        getline(ss, temp, ' '); qte = (temp == "-") ? 0 : stoi(temp);

        // Extraction du referer et suppression de la base locale si présente
        getline(ss, temp, '"'); getline(ss, referer, '"');
        size_t position = referer.find(mBaseLocale); 
        if (position != string::npos) 
        {
            referer.erase(position, mBaseLocale.length()); 
        }

        // Extraction de l'identifiant client
        getline(ss, temp, '"'); getline(ss, clientID, '"');

        // Création et filtrage de la requête
        Requete r(adresseIP, logName, userName, date, rHTTP, status, qte, referer, clientID);
        bool skip = filtre.Skip(r); 
        if (!skip) 
        {
            requetes.push_back(r); 
        }
    }

    // Vérification qu'il y a des requêtes valides
    if (requetes.empty()) 
    {
        cerr << "Erreur, aucune ligne valide n'a été trouvée !" << endl;
        exit(EXIT_FAILURE); 
    }

    return requetes; 
}
