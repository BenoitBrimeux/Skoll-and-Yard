#ifndef UINTERFACE
#define UINTERFACE
 
 /*!
 * \file UInterface.hpp
 * \brief Gestion de l'interface utilisateur du jeu
 * \author Clement Prevot, Benjamin Maes, Nadir Trabelsi
 */

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Game.hpp"
#include "UIGame.hpp"
#include "Client.hpp"

using namespace sf; 
using namespace std;


/*! \class UInterface
 * \brief La classe de tout les modes de jeu et differents menu.
 *	Les différentes fonctions de jeu. ( Joueur vs IA, Joueur vs Joueur, Jeu en réseau , crédits etc...)
 */
class UInterface{

public:
    /*!
     *  \brief Constructeur
     *  Permet de crée un objet UInterface. 
     */	
	UInterface();

	 /*!
     *  \brief Destructeur
     *  Permet de détruire un objet UInterface. 
     */	
	~UInterface();

	/*!
     *  \brief La fenêtre de départ
     *  Permet d'afficher une fenêtre de début. 
     */
	void Start();

	/*!
     *  \brief La fenêtre de Menu
     *  Permet d'afficher une fenêtre de Menu avec différents choix.
     */
     void MainMenu();//menu principal

	/*!
     *  \brief La fenêtre de Multi
     *  Permet d'afficher un menu multijoueur et de lancer un jeu en réseau ou localement sur la même machine
     */
	void PlayMulti();

	/*!
     *  \brief La fenêtre de Crédit.
     *  Permet d'afficher un menu de crédit. 
     */
    void Credits();

    /*!
     *  \brief La fenêtre de jeu solo.
     *  Permet d'afficher une fenêtre de jeu solo face à une ia. 
     */
	int runSingle();
	
	/*!
     *  \brief La fenetre de Jeu multi sur la même machine
     *  Permet d'afficher une fenêtre de jeu multi, et de jouer à deux sur la même machine.
     */
	int runPVP();
	
	/*!
     *  \brief menu qui demande à l'utilisateur l'ip et le port du serveur
     *  lance une fenêtre ou l'on demande à l'utilisateur de taper l'adresse ip et le port du serveur
     *  lors du clic sur le bouton Connexion par l'utilisateur on lance la connection au serveur et le jeu
     */
	void runClient();
	
	/*!
     *  \brief La fonction
     *  la connexion au serveur est établi et on lance l'interface graphique du jeu
     */
	int runUIClient(string ip_port); 
};

#endif