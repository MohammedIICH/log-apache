# Analyse de Logs Apache

## Table des matières
- [À propos](#à-propos)
- [Fonctionnalités](#fonctionnalités)
- [Installation](#installation)
- [Configuration requise](#configuration-requise)
- [Ce que vous devriez savoir](#ce-que-vous-devriez-savoir)
- [Utilisation](#utilisation)
- [Tests](#tests)
- [Contributeurs](#contributeurs)

## À propos
Ce projet est un outil en ligne de commande permettant d’analyser un fichier de log Apache. Il permet d’extraire des statistiques sur les pages web les plus consultées et de générer une représentation graphique des parcours des utilisateurs sous forme de graphe à l’aide de GraphViz.

## Fonctionnalités
- Lecture et analyse des logs Apache.
- Affichage des 10 documents les plus consultés.
- Génération d’un fichier `.dot` pour une visualisation GraphViz des parcours utilisateurs.
- Exclusion des fichiers statiques (images, CSS, JS) de l’analyse.
- Filtrage des requêtes par plage horaire.
- Gestion des erreurs et logs de diagnostic.
- Tests automatisés avec un framework fourni.

## Installation
Vous pouvez obtenir ce projet de deux manières :

### Clonage avec Git
```sh
git clone <URL-du-référentiel>
cd <nom-du-projet>
```

### Téléchargement en format ZIP
1. Cliquez sur le bouton "Code" sur la page du dépôt GitHub.
2. Sélectionnez "Download ZIP".
3. Extrayez le fichier dans un répertoire de votre choix.

### Compilation
Ce projet utilise un `Makefile` pour faciliter la compilation. Exécutez la commande suivante dans le répertoire du projet :
```sh
make
```
Cela générera un exécutable `analog`.

## Configuration requise
- Système d’exploitation : Linux ou Windows avec un environnement compatible.
- Un compilateur C++ compatible avec la norme C++11 ou supérieure (g++ recommandé).
- L’outil GraphViz pour la génération des graphes (si l’option -g est utilisée).

## Ce que vous devriez savoir
- Le programme est conçu pour fonctionner avec des fichiers de logs Apache au format standard.
- Un framework de test est fourni pour valider les résultats.
- L’outil GraphViz doit être installé pour permettre la génération des fichiers `.dot`.
- Les droits d'accès pour pouvoir effectuer les tests sont déjà gérés par le make, vous ne devriez effectuer aucun chmod. 

## Utilisation
L'exécutable `analog` prend en argument un fichier de log et peut être utilisé avec différentes options.

### Commande de base
```sh
./analog [options] nomfichier.log
```

### Options disponibles
- `-g nomfichier.dot` : Génère un fichier `.dot` représentant le graphe des parcours utilisateurs.
- `-e` : Exclut les fichiers de type image, CSS et JavaScript des statistiques.
- `-t heure` : Ne prend en compte que les requêtes effectuées dans l'intervalle [heure, heure+1[.

## Tests
Un framework de test est fourni pour valider le fonctionnement du programme. Les tests doivent être passés avec succès avant toute soumission du projet.

### Exécution des tests dans le répértoire Tests de FrameWorkdeTests et droits d'accès 

Puis rentrer dans le répértoire situé dans FrameWorkdeTests puis Tests et effectuer la commande suivante : 
```sh
./mktest.sh
```
Les résultats des tests seront affichés directement dans la console.

## Contributeurs
-B3107 : EL KARCHOUNI & BELLARGUI
-B3110 : LEMSEFFER, IICH & ERRABHAOUI
