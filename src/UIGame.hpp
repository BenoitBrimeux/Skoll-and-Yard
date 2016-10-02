#ifndef UIGAME
#define UIGAME
 
/*!
 * \file UIGame.hpp
 * \brief Gestion de l'interface graphique du jeu pour l'utilisateur affichage du plateau, des differents messages (quitter,gagné,perdu,egalité)
 * \author Clement Prevot, Benjamin Maes
 */

#include "Game.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
using namespace sf;

/*! \class UIGame
 * \brief classe contenant les fonctions d'interface graphique partie jeu.
 *  La classe contient les fonctions utile pour la partie.  
 */
class UIGame{
    public:
        /*!
         *  \brief Constructeur
         *  Permet de crée un objet UIGame. 
         */
        UIGame();
 
        /*!
         *  \brief Destructeur
         *  Permet de détruire un objet UIGame. 
         */
        ~UIGame();
 
        /*!
         *  \brief fonction qui retourne le numero de la colonne selon la position de la souris sur la fenêtre
         *  On récupère la position de la souris, et on renvoie 0,1,2... en fonction de la colonne où l'utilisateur a cliqué
         *  \param mousePosition : Position de la souris sur la fenêtre.
         *  \return la colonne choisie par l'utilisateur.
         */
        int placeInColumn(Vector2i mousePosition);

        /*!
         *  \brief met à jour le joueur courant
         *  Permet de mettre à jour le prochain joueur. 
         *  \param t : le prochain joueur.
         */
        void setNextPlayer(Token t);

        /*!
         *\brief retourne le prochain joueur qui doit joué
         *  Permet de retourne le joueur qui doit jouer le prochaine coup
         *  \return le Token representant le joueur.
         */
        Token getNextPlayer();

        /*!
         *  \brief transforme le numero de colonne en position sur l'axe y de la fenêtre
         *  \param i : la coordonnée a transformer
         *  \return la valeur calculée
         */
        int i_to_y(int i) const;
       
        /*!
         *  \brief transforme le numero de colonne en position sur l'axe x de la fenêtre
         *  \param j : la coordonnée a transformer
         *  \return la valeur calculée
         */      
        int j_to_x(int j) const;
       
        /*!
         *  \brief Affiche le plateau avec les pions
         *  Permet d'afficher le plateau et les pions joués correctement.
         *  \param refWindow : La fenetre où l'on affiche les éléments.
         *  \param g : le jeu où est stocké le coups joués.
         *  \return 0 si il y a des problèmes au chargement des textures , des sons ou des fonts
         */
        int displayBoard( RenderWindow &refWindow,Game g);
            
        /*!
         *  \brief Fenêtre en cas d'égalité
         *  affiche un message pop-up lors d'un égalité et propose au joueur de rejouer ou de quitter
         *  \param signal : la valeur choisie par le joueur ( 1: rejouer , 2: quitter)
         */
        void DrawMessage(int &signal);
       
        /*!
         *  \brief Fenêtre en cas de victoire
         *  affiche un message pop-up lors d'un victoire et propose au joueur de rejouer ou de quitter
         *  \param signal : la valeur choisie par le joueur ( 1: rejouer , 2: quitter)
         */
        void WinMessage(int &signal); 
       
        /*!
         *  \brief Fenêtre en cas de défaite
         *  affiche un message pop-up lors d'une défaite et propose au joueur de rejouer ou de quitter
         *  \param signal : la valeur choisie par le joueur ( 1: rejouer , 2: quitter)
         */
        void LoseMessage(int &signal);
       
        /*!
         *  \brief Fenêtre quand le joueur veut quitter
         *  affiche un message pop-up lors d'un évènement SFML Event::Quit et propose au joueur de rejouer ou de quitter
         *  \param signal : la valeur choisie par le joueur ( 1: annuler , 2: quitter)
         */
        void QuitMessage(int &signal);

    private:
        int _column; /*!< le numero de la Colonne cliquée.*/
 
        Token _nextPlayer; /*!< Token representant le prochain joueur. ( Red ou Yellow ) */
 
        ConvexShape _boardShape; /*!< la face avant de la texture du plateau on la dessine par dessus les pions presents sur le plateau*/
        
        ConvexShape _boardShape3D; /*!< le fond de la texture du plateau on dessine les pions par dessus cette texture*/
};
 
#endif
