
#ifndef BOARD_HPP_
#define BOARD_HPP_

class Game;
class Player;

/*!
 * \file Board.hpp
 * \brief Gestion du plateau. 
 * \author Clement Prevot, Benjamin Maes, Nadir Trabelsi, Benoit Brimeux
 */

#include <iostream>

 /*! Liste des Token */
enum Token
{
    Empty, /*!<  Coup Vide */
    Red, /*!< Coup Rouge ( Joueur 2) */
    Yellow, /*!< Coup Jaune ( Joueur 1) */
};


/**
 * \struct Stroke
 * \brief structure contenant un coup.
 * Coup contient un coup qui est représenté par ses coordonées (i et j) et par une couleur (Token) qui peut être Red ou Yellow.
 */
typedef struct Stroke {
	int _i;/*!< entre 0 et la taille du plateau, coordonnée verticale*/
	int _j;/*!< entre 0 et la taille du plateau, coordonnée horizontale*/
	Token _type;/*!< Type du coup, vide, rouge ou jaune. */
	Stroke();
	Stroke(int i, int j, Token type);
} Stroke;


/*! \class Board
 * \brief classe contenant les fonctions de gestion du plateau.
 *  La classe contient le plateau, les listes de coups, et les fonctions de jeu.
 */
class Board{

private: 
	Stroke _tab[6][7];/*! Plateau du jeu qui contient des structures Stroke*/
	Game* _refgame; /*!< Reference sur le jeu en cours. */

public: 
	/*!
	 *	\brief Constructeur
	 *	Construit l'objet Board
	 */
	Board();

	/*!
	 *	\brief Constructeur
	 *	Construit l'objet Board
	 *	\param pointeur de Game : refgame , qui est une réference sur le jeu en cours.
	 */
	Board(Game *refgame);

	/*!
	 *	\brief Jouer Coup
	 *	Joue et sauvegarde le coup passé en paramètre.
	 *	\param Coup : Le coup à jouer  
	 */
	void playStroke(Stroke Coup);

	/*!
	 *	\brief Initialise le Plateau
	 *	Remplie le tableau de cases vide.
	 */
	void initBoard();


	/*!
	 *	\brief Vérifie s'il y a match nul.
	 *	La fonction vérifie si le plateau n'est pas plein sans pour autant avoir eu de victoire.
	 *	\return true s'il y a match nul
	 */
	bool checkFull();

	/*!
	 *	\brief Compte le nombre de coups alignés sur le plateau.
	 *	La fonction vérifie le nombre de coups alignés
	 *	\param colonne,ligne qui sont les coordonées de départ et incrementColonne,incrementLigne correspondent au sens de parcours du plateau
	 *	\return On renvoie le nombre de pions alignés par un joueur
	 */
	int nbAdjacents(int colonne, int ligne, int incrementColonne, int incrementLigne);

	/*!
	 *	\brief Vérifie si quelqu'un a gagné.
	 *	La fonction vérifie si un des joueurs a gagné et renvoie le numéro du vainqueur.
	 *	\return On renvoie le joueur vainqueur, ou -1 si personne n'a gagné.
	 */
	int checkWin();

	/*!
	 *	\brief Vérifie si une colonne du plateau est vide.
	 *	la fonction vérifie si la colonne est jouable
	 *	\param int num correspond au numero de la colonne
	 *	\return on return true si la colonne est jouable
	 */
	bool columnEmpty(int num);

	/*!
	 *	\brief retourne le coup correspondant aux coordonées i et j
	 *	La fonction retourne un coup
	 *	\param coordonées i et j du coup à retourner
	 *	\return Stroke Coup correspondant au coordonnée i et j du plateau
	 */
	Stroke getStroke(int i, int j); 


	std::string toAsciiArt();
};

#endif
