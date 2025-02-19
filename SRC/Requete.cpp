/*************************************************************************
                           Requete  -  représente une requête HTTP extraite d'un fichier de logs
                             -------------------
    début                : 22/01/2025
    copyright            : (C) 2025 par B3107 - B3110
    e-mail               : mohammed.iich@insa-lyon.fr / hamza.el-karchouni@insa-lyon.fr / 
    			   mohamed.lemseffer@insa-lyon.fr / yliess.bellargui@insa-lyon.fr / youssef.erabhaoui@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Requete> (fichier Requete.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <sstream>

//------------------------------------------------------ Include personnel
#include "Requete.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

// Retourne l'extension de l'URL (ex: .html, .jpg) à partir de la dernière occurrence du '.'
string Requete::GetExtension() const
{
    size_t pos = mRHTTP.url.find_last_of('.');
    if (pos != string::npos) // Vérifie si un '.' a été trouvé
    {
        return mRHTTP.url.substr(pos + 1); // Retourne l'extension après le '.'
    }
    return ""; 
} //----- Fin de GetExtension

// Retourne l'URL complète de la requête
string Requete::GetDestination() const
{
    return mRHTTP.url; 
} //----- Fin de GetDestination

// Retourne le referer (URL précédente) de la requête
string Requete::GetReferer() const
{
    return mReferer; 
} //----- Fin de GetReferer

// Retourne l'heure de la requête
int Requete::GetHeure() const
{
    return mDate.heure;
} //----- Fin de GetHeure

//------------------------------------------------- Surcharge d'opérateurs

// Surcharge de l'opérateur d'affectation (=) pour la classe Requete
Requete & Requete::operator = (const Requete &unRequete)
{
    if (this != &unRequete) // Vérifie que l'objet n'est pas assigné à lui-même
    {
        // Copie des attributs de l'objet source dans l'objet courant
        mAdresseIP = unRequete.mAdresseIP;
        mLogName = unRequete.mLogName;
        mUserName = unRequete.mUserName;
        mDate = unRequete.mDate;
        mRHTTP = unRequete.mRHTTP;
        mStatus = unRequete.mStatus;
        mQte = unRequete.mQte;
        mReferer = unRequete.mReferer;
        mClientID = unRequete.mClientID;
    }
    return *this; 
} //----- Fin de operator =

//-------------------------------------------- Constructeurs - destructeur

// Constructeur de copie
Requete::Requete(const Requete &unRequete)
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Requete>" << endl;
#endif
    *this = unRequete;
} //----- Fin de Requete (constructeur de copie)

// Constructeur par défaut
Requete::Requete()
{
#ifdef MAP
    cout << "Appel au constructeur de <Requete>" << endl;
#endif
} //----- Fin de Requete

// Constructeur avec paramètres, initialise tous les attributs
Requete::Requete(string AdresseIP, string LogName, string UserName, Date Date, requeteHTTP RHTTP, int Status, int Qte, string Referer, string ClientID)
{
    mAdresseIP = AdresseIP;
    mLogName = LogName;
    mUserName = UserName;
    mDate = Date;
    mRHTTP = RHTTP;
    mStatus = Status;
    mQte = Qte;
    mReferer = Referer;
    mClientID = ClientID;
} //----- Fin de Requete (constructeur avec paramètres)

// Destructeur de la classe
Requete::~Requete()
{
#ifdef MAP
    cout << "Appel au destructeur de <Requete>" << endl;
#endif
} //----- Fin de ~Requete


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
