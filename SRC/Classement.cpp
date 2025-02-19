/*************************************************************************
                           Classement  -  Classement des requêtes
                             -------------------
    début                : 22/01/2025
    copyright            : (C) 2025 par B3107 - B3110
    e-mail               : mohammed.iich@insa-lyon.fr / hamza.el-karchouni@insa-lyon.fr / 
    			   mohamed.lemseffer@insa-lyon.fr / yliess.bellargui@insa-lyon.fr / youssef.erabhaoui@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Classement> (fichier Classement.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Classement.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

// Ajoute les requêtes au classement en incrémentant les comptages
void Classement::Ajouter(const vector<Requete> & unVecRequetes)
{
    if (unVecRequetes.empty())
    {
        cerr << "Erreur : Vous n'avez aucune requete" << endl;
        return;
    }

    // Parcours des requêtes pour compter les destinations
    vector<Requete>::const_iterator it;
    for (it = unVecRequetes.begin(); it != unVecRequetes.end(); ++it)
    {
        string dest = it->GetDestination();
        map<string, int>::iterator classementIt = classement.find(dest);
        
        // Si la destination n'est pas encore dans le classement, l'ajouter avec une occurrence initiale
        if (classementIt == classement.end())
        {
            classement.insert(make_pair(dest, 1));
        }
        else
        {
            // Sinon, incrémenter le comptage pour cette destination
            classementIt->second++;
        }
    }
}

// Affiche le classement des requêtes par nombre de hits, trié par ordre décroissant
void Classement::Affichage()
{
    if (classement.empty())
    {
        cout << "Aucune donnée à afficher." << endl;
        return;
    }

    // Conversion du classement en vecteur pour faciliter le tri
    vector<pair<string, int>> vec(classement.begin(), classement.end());

    // Tri des résultats par nombre de hits, de manière décroissante
    sort(vec.begin(), vec.end(),
         [](const pair<string, int> &a, const pair<string, int> &b) {
             return b.second < a.second;
         });

    cout << "Top URLs consultées :" << endl;
    // Affichage des 10 premières URLs du classement
    for (size_t i = 0; i < 10 && i < vec.size(); ++i)
    {
        cout << vec[i].first << " (" << vec[i].second << " hits)" << endl;
    }
}

//-------------------------------------------- Constructeurs - destructeur

// Constructeur par défaut
Classement::Classement()
{
#ifdef MAP
    cout << "Appel au constructeur de <Classement>" << endl;
#endif
}

// Constructeur de copie : copie du classement existant
Classement::Classement(const Classement & unClassement)
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Classement>" << endl;
#endif
    classement = unClassement.classement;
}

// Destructeur
Classement::~Classement()
{
#ifdef MAP
    cout << "Appel au destructeur de <Classement>" << endl;
#endif
}
