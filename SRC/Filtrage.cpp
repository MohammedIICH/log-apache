/*************************************************************************
                           Filtrage  -  filtrer des objets de type Requete
                             -------------------
    début                : 22/01/2025
    copyright            : (C) 2025 par B3107 - B3110
    e-mail               : mohammed.iich@insa-lyon.fr / hamza.el-karchouni@insa-lyon.fr / 
    			   mohamed.lemseffer@insa-lyon.fr / yliess.bellargui@insa-lyon.fr / youssef.erabhaoui@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Filtrage> (fichier Filtrage.cpp) ------------

//---------------------------------------------------------------- INCLUDE
#include "Filtrage.h"
//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <vector>

//------------------------------------------------------ Include personnel

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

// Vérifie si la requête doit être filtrée selon les critères définis
bool Filtrage::Skip(const Requete & r) const
{
    // Si aucun filtrage n'est appliqué, la requête n'est pas filtrée
    if (!mFiltrerExtensions && !mFiltrerTemps) return false;

    // Si le filtrage par heure est activé et correspond à l'heure de la requête, on la filtre
    if (mFiltrerTemps && r.GetHeure() != mHeure) 
    {
        return true;
    }

    // Si le filtrage par extensions est activé et l'extension de la requête est dans la liste à filtrer
    if (mFiltrerExtensions) 
    {
        if (mExtensions.find(r.GetExtension()) != mExtensions.end()) 
        {
            return true;
        }
    }

    // La requête ne correspond à aucun critère de filtrage
    return false;
}
//----- Fin de Méthode


//-------------------------------------------- Constructeurs - destructeur

// Constructeur : initialise les critères de filtrage selon les paramètres
Filtrage::Filtrage(bool filtrerTemps, int heure, bool filtrerExtensions, unordered_set<string> Extensions) 
: mFiltrerTemps(filtrerTemps), mHeure(heure), mFiltrerExtensions(filtrerExtensions), mExtensions(Extensions)
{
#ifdef MAP
    cout << "Appel au constructeur de <Filtrage>" << endl;
#endif
} //----- Fin de Filtrage


// Destructeur
Filtrage::~Filtrage ( )
// Nettoyage lors de la destruction de l'objet Filtrage
{
#ifdef MAP
    cout << "Appel au destructeur de <Filtrage>" << endl;
#endif
} //----- Fin de ~Filtrage
