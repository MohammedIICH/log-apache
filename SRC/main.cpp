/*************************************************************************
                           main -  description
                             -------------------
    début                : 22/01/2025
    copyright            : (C) 2025 par B3107 - B3110
    e-mail               : mohammed.iich@insa-lyon.fr / hamza.el-karchouni@insa-lyon.fr /
                   mohamed.lemseffer@insa-lyon.fr / yliess.bellargui@insa-lyon.fr / youssef.erabhaoui@insa-lyon.fr
*************************************************************************/

using namespace std;
#include <iostream>
#include <vector>
#include <unordered_set>
#include <cstring>
#include "Filtrage.h"
#include "Lecture.h"
#include "Requete.h"
#include "Classement.h"
#include "Graphe.h"

// Fonction permettant d'analyser les arguments en ligne de commande
void Demarrage(bool &, int &, bool &, bool &, string &, string &, const int &, char *[], bool &, const string &);

int main(int argc, char *argv[])
{
    // Ensemble d'extensions de fichiers à filtrer
    unordered_set<string> extensions = {
        "jpg", "jpeg", "png", "bmp", "gif", "tiff", "tif", "webp", "ico",
        "svg", "eps", "ai", "raw", "cr2", "nef", "arw", "dng", "psd", "heic",
        "heif", "xcf", "css", "js", "mjs"};

    string baseURL = "http://intranet-if.insa-lyon.fr";

    // Initialisation des variables de filtrage et d'options
    bool filtrerTemps = false;
    int heure = -1;
    bool filtrerExtensions = false;
    bool genererGraphe = false;
    string nomGraphe = "";
    string nomFic = "";
    bool erreur = false;

    // Analyse des arguments en ligne de commande
    Demarrage(filtrerTemps, heure, filtrerExtensions, genererGraphe, nomFic, nomGraphe, argc, argv, erreur, baseURL);
    if (erreur)
        return 1; // Arrêt en cas d'erreur

    // Création des objets de traitement
    Filtrage filtre(filtrerTemps, heure, filtrerExtensions, extensions);
    Lecture lecture(nomFic, baseURL);
    Graphe graphe;
    Classement classement;

    // Lecture et filtrage des requêtes
    vector<Requete> vecRequetes = lecture.Lire(filtre);

    // Génération du graphe si demandé
    if (genererGraphe)
        graphe.Ajouter(vecRequetes);
    classement.Ajouter(vecRequetes);

    if (genererGraphe)
        graphe.GenererFichier(nomGraphe);
    classement.Affichage();

    // Fin du programme principal
    return 0;
}

// Fonction pour analyser les arguments de la ligne de commande
void Demarrage(bool &filtrerTemps, int &heure, bool &filtrerExtensions, bool &genererGraphe, string &nomFic,
               string &nomGraphe, const int &argc, char *argv[], bool &erreur, const string &baseURL)
{
    if (argc == 1)
    {
        cerr << "Aucun nom de fichier n'a ete renseigne" << endl;
        erreur = true;
        return;
    }

    erreur = false;
    nomFic = argv[argc - 1]; // Récupération du dernier argument comme fichier d'entrée
    int i = 1;

    while (i < argc - 1)
    {
        if (!strcmp(argv[i], "-e")) // Option -e pour activer le filtrage des extensions
        {
            if (filtrerExtensions)
            {
                cerr << "Vous avez utilise plusieurs fois l'option de compilation -e" << endl;
                erreur = true;
                return;
            }
            else
            {
                filtrerExtensions = true;
                i++;
            }
        }
        else if (!strcmp(argv[i], "-g")) // Option -g pour générer un graphe
        {
            if (genererGraphe)
            {
                erreur = true;
                cerr << "Vous avez utilise plusieurs fois l'option de compilation -g" << endl;
                return;
            }
            else
            {
                genererGraphe = true;
                ++i;
                if (i < argc - 1)
                {
                    if (!strcmp(argv[i], "-g"))
                    {
                        erreur = true;
                        cerr << "Vous avez utilise plusieurs fois l'option de compilation -g" << endl;
                        return;
                    }

                    nomGraphe = argv[i];

                    size_t pos = nomGraphe.find_last_of('.');
                    if (pos != string::npos)
                    {
                        if (nomGraphe.substr(pos + 1) != "dot")
                        {
                            erreur = 1;
                            cerr << "Le fichier pour creer le graphe doit etre un .dot" << endl;
                            return;
                        }
                    }
                    i++;
                }
                else
                {
                    erreur = true;
                    cerr << "Il manque le nom de fichier du graphe" << endl;
                    return;
                }
            }
        }
        else if (!strcmp(argv[i], "-t")) // Option -t pour filtrer par heure
        {
            if (filtrerTemps)
            {
                erreur = true;
                cerr << "Vous avez utilise plusieurs fois l'option de compilation -t" << endl;
                return;
            }
            else
            {
                filtrerTemps = true;
                ++i;
                if (i < argc - 1)
                {
                    string heure_str = argv[i];
                    heure = stoi(heure_str);
                    if (heure < 0 || heure > 24)
                    {
                        erreur = true;
                        cerr << "L'heure doit etre comprise entre 0 et 24" << endl;
                        return;
                    }
                    ++i;
                }
                else
                {
                    erreur = true;
                    cerr << "Vous n'avez pas indique d'heure" << endl;
                    return;
                }
            }
        }
        else
        {
            erreur = 1;
            cerr << "Une option de compilation inconnue a été entrée" << endl;
            return;
        }
    }
    // Fin de la fonction Demarrage
}
