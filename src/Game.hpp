
#ifndef GAME_HPP_
#define GAME_HPP_

#include <iostream>
#include "Board.hpp"
#include "Player.hpp"

/*!
 * \file Game.hpp
 * \brief Gestion du jeu. 
 * \author Clement Prevot, Benjamin Maes, Nadir Trabelsi, Benoit Brimeux
 */


/*! \class Game
* \brief classe contenant les fonctions de gestion du jeu.
*  La classe contient le plateau, les joueurs, et les manipules pour la partie
*/
class Game{

private:
	Board _plateau; /*!< Plateau du jeu courant */
	Player _Joueur1; /*!< Joueur 1 du jeu */
	Player _Joueur2; /*!< Joueur 2 du jeu */

public:

	/*!
	 *	\brief Constructeur Base.
 	 *	Construit le Jeu courant.
 	 */
	Game();

	/*!
	 *	\brief Constructeur Base.
 	 *
 	 *	Construit le Jeu courant.
 	 * \param std::string pseudo1 : contient le nom jeu joueur 1
 	 * \param std::string pseudo2 : contient le nom jeu joueur 2
 	 */
	Game(std::string pseudo1, std::string pseudo2);
	
	/*!
     *  \brief Recupération d'un Joueur
     *  Renvoie le joueur choisi.
     *  \param num : le numéro du joueur à récuperer.
     *  \return Une copie du joueur choisi.
     */
	Player getPlayer(int player); 

    /*!
	 *	\brief Récupération du plateau
	 *	Renvoie le plateau.
	 *	\return Le plateau courant. 
	 */
	Board getBoard();

	/*!
	 *	\brief Joue le coup passé en paramêtre, sur le joueur num
	 *	C'est à dire que si le joueur est un joueur classique et on fait les vérifications necessaires.
	 *
	 *	\param num : Le numéro du joueur.
	 * 	\param Coup : Le coup à jouer.	
	 */
	void playStroke(int player, Stroke Coup);

	/*!
	 *	\brief verifie le coup passé en paramètre.
	 *	La fonction sert à vérifié le coup passé en paramètre.
	 * \param Coup : Le coup à jouer.	
	 * \return : true si le coup passé en parmamètre est valide
	 */
	bool canPlayStroke(Stroke Coup);

	/*!
	 *	\brief Vérifier si quelqu'un a gagné.
	 *	La fonction vérifie si un des joueurs a gagner et renvoie le numéro du vainqueur.
	 *	\return On renvoie le joueur vainqueur, ou -1 si personne n'a gagné.
	 */
	int checkWin();

	/*!
	 *	\brief Vérifier s'il y a match nul.
	 *	La fonction vérifie si le plateau n'est pas plein sans pour autant avoir eu de victoire.
	 *	\return true s'il y a match nul
	 */
	bool checkFull();

	/*!
	 *	\brief Initialise le jeu.
	 */
	void initGame();

	/*!
	 *	\brief lance l'IA
	 *	La fonction joue un coup valide aléatoirement
	 */
	void runAI();
};

 #endif
