/*************************************************************************
                           Graphe  -  gérer le graphe orienté
                             -------------------
    début                : 22/01/2025
    copyright            : (C) 2025 par B3107 - B3110
    e-mail               : mohammed.iich@insa-lyon.fr / hamza.el-karchouni@insa-lyon.fr / 
    			   mohamed.lemseffer@insa-lyon.fr / yliess.bellargui@insa-lyon.fr / youssef.erabhaoui@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Graphe> (fichier Graphe.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Graphe.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void Graphe::GenererFichier(const string & nomFichier) const
// Génère un fichier dot pour représenter le graphe orienté
{
    ofstream ficGraphe(nomFichier);
    ficGraphe << "digraph {" << endl;

    // Ajout des noeuds dans le fichier dot
    map<string, int>::const_iterator it;
    for (it = mNoeuds.begin(); it != mNoeuds.end(); it++)
    {
        ficGraphe << "node" << it->second << " [label=\"" << it->first << "\"];" << endl;
    }

    // Ajout des arêtes (relations entre les noeuds) dans le fichier
    map<string, map<string, int>>::const_iterator it2;
    for (it2 = mAretes.begin(); it2 != mAretes.end(); it2++)
    {
        map<string, int>::const_iterator inoeuds_dest = mNoeuds.find(it2->first);
        int dest = inoeuds_dest->second;
        map<string, int>::const_iterator it3;
        for (it3 = it2->second.begin(); it3 != it2->second.end(); it3++)
        {
            map<string, int>::const_iterator inoeuds_src = mNoeuds.find(it3->first);
            int src = inoeuds_src->second;
            ficGraphe << "node" << src << " -> " << "node" << dest << "[label=\"" << it3->second << "\"];" << endl;
        }
    }

    ficGraphe << "}" << endl;
    ficGraphe.close();
} //----- Fin de Méthode

void Graphe::Ajouter(const vector<Requete> & vecRequetes)
// Ajoute des requêtes au graphe (enregistrant les sources et destinations)
{
    vector<Requete>::const_iterator r;
    for (r = vecRequetes.begin(); r != vecRequetes.end(); ++r)
    {
        string dest = r->GetDestination();
        string src = r->GetReferer();

        map<string, map<string, int>>::iterator it = mAretes.find(dest);
        if (it == mAretes.end())
        {
            // Première apparition de la destination
            map<string, int> m = {{src, 1}};
            mAretes.insert(make_pair(dest, m));
        }
        else
        {
            // Mise à jour de la quantité pour la source existante
            (it->second)[src]++;
        }

        // Ajout des noeuds s'ils n'existent pas déjà
        if (mNoeuds.emplace(make_pair(src, mNbNoeuds)).second)
        {
            ++mNbNoeuds;
        }
        if (mNoeuds.emplace(make_pair(dest, mNbNoeuds)).second)
        {
            ++mNbNoeuds;
        }
    }
} //----- Fin de Méthode

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
Graphe::Graphe ( const Graphe & unGraphe )
// Constructeur de copie pour le graphe
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Graphe>" << endl;
#endif

    mAretes = unGraphe.mAretes;
    mNbNoeuds = unGraphe.mNbNoeuds;
    mNoeuds = unGraphe.mNoeuds;
} //----- Fin de Graphe (constructeur de copie)


Graphe::Graphe ( ) : mNbNoeuds(0)
// Constructeur par défaut, initialise le nombre de noeuds à 0
{
#ifdef MAP
    cout << "Appel au constructeur de <Graphe>" << endl;
#endif
} //----- Fin de Graphe


Graphe::~Graphe()
// Destructeur, nettoyage du graphe
{
#ifdef MAP
    cout << "Appel au destructeur de <Graphe>" << endl;
#endif
} //----- Fin de ~Graphe


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
