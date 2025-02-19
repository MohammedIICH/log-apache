/*************************************************************************
                           Requete -  représente une requête HTTP extraite d'un fichier de logs
                             -------------------
    début                : 22/01/2025
    copyright            : (C) 2025 par B3107 - B3110
    e-mail               : mohammed.iich@insa-lyon.fr / hamza.el-karchouni@insa-lyon.fr / 
                           mohamed.lemseffer@insa-lyon.fr / yliess.bellargui@insa-lyon.fr / 
                           youssef.erabhaoui@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Requete> (fichier Requete.h) ----------------
#if ! defined ( REQUETE_H )
#define REQUETE_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
using namespace std;

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

// Structure représentant la date et l'heure de la requête
struct Date
{
    int jour;        
    string mois;     
    int annee;       
    int heure;       
    int minute;      
    int seconde;     
    string diffGMT;  
};

// Structure représentant une requête HTTP
struct requeteHTTP
{
    string action;       // Action HTTP (GET, POST, etc.)
    string url;          // URL demandée
    string http_version; // Version du protocole HTTP
};

//------------------------------------------------------------------------
// Rôle de la classe <Requete>
//
// Cette classe représente une requête HTTP avec ses différentes informations :
// adresse IP, identifiants, date, requête HTTP, statut, quantité, référant et ID client.
//------------------------------------------------------------------------

class Requete
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    string GetExtension() const;
    // Mode d'emploi : Retourne l'extension du fichier demandé dans la requête.
    // Contrat : Aucun.

    string GetDestination() const;
    // Mode d'emploi : Retourne la destination de la requête HTTP, c'est-à-dire l'URL demandée.
    // Contrat : Aucun.

    string GetReferer() const;
    // Mode d'emploi : Retourne le référant de la requête HTTP (l'URL de la page précédente).
    // Contrat : Aucun.

    int GetHeure() const;
    // Mode d'emploi : Retourne l'heure à laquelle la requête a été effectuée.
    // Contrat : Aucun.

//------------------------------------------------- Surcharge d'opérateurs

    Requete & operator = ( const Requete & unRequete );
    // Mode d'emploi : Opérateur d'affectation qui permet de copier les attributs d'une requête dans une autre.
    // Contrat : Aucun.

//-------------------------------------------- Constructeurs - destructeur

    Requete();
    // Mode d'emploi : Constructeur par défaut. Initialise une requête vide.
    // Contrat : Aucun.

    Requete(const Requete &unRequete);
    // Mode d'emploi (constructeur de copie) : Crée une copie d'une requête existante.
    // Contrat : Aucun.

    Requete(string AdresseIP, string LogName, string UserName, Date Date, requeteHTTP RHTTP, int Status, int Qte, string Referer, string ClientID);
    // Mode d'emploi : Constructeur avec paramètres permettant d'initialiser la requête avec toutes ses données.
    // Contrat : Aucun.

    virtual ~Requete();
    // Mode d'emploi : Destructeur de la classe. Libère les ressources associées à la requête.
    // Contrat : Aucun.

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Attributs protégés
    string mAdresseIP;  
    string mLogName;    
    string mUserName;   
    Date mDate;         
    requeteHTTP mRHTTP; 
    int mStatus;       
    int mQte;          
    string mReferer;   
    string mClientID;  

//-------------------------------- Autres définitions dépendantes de <Requete>
};

#endif // REQUETE_H
