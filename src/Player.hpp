#ifndef PLAYER_HPP_
#define PLAYER_HPP_

/*!
 * \file Player.hpp
 * \brief Gestion d'un Joueur
 * \author Prévot Clément, Maes Benjamin, Nadir Trabelsi , Brimeux Benoit
 */

#include <iostream>
#include "Board.hpp"

/*! \class Player
 * \brief classe contenant les fonctions de gestion d'un joueur
 */

class Player{
public:

     /*!
     *  \brief Constructeur de la classe Player
     */
     Player();

     /*!
     *  \brief Constructeur de la classe Player
     *  \param pseudo : Le nom du joueur.
     *  \param id : L'identifiant du joueur.
     */
     Player(std::string pseudo, int i);

     /*!
     *  \brief Destructeur de la classe Player
     */
     ~Player();

     /*!
     *  \brief retourne le pseudo d'un joueur
     *  Methode qui retourne le pseudo du joueur
     * \return std::string , chaine de caractère qui contient le nom du joueur
     */
     std::string getPseudo();

     /*!
     *  \brief retourne le numero d'un joueur
     *  Methode qui retourne l'identifiant du joueur
     * \return le numero du joueur 1 ou 2
     */
     int getId();

     /*!
     *  \brief met à jour le pseudo d'un joueur
     *  Methode qui modifie le pseudo du joueur
     * \param std:string le nom du joueur
     */
     void setPseudo(std::string pseudo);

     /*!
     *  \brief met à jour l'identifiant d'un joueur
     *  Methode qui modifie l'identifiant du joueur
     * \param int contenant l'identifiant d'un joueur
     */
     void setId(int id);

     /*!
     *  \brief Methode qui permet de jouer un coup
     *  \param Stroke : le coup qui sera joué 
     */
     void playStroke(Stroke coup);

     /*!
     *  \brief afficher joueur
     *  Methode qui permet d'afficher l'identifiant et le pseudo du joueur
     *  \param os : flux de sortie
     */
     void displayPlayer(std::ostream &os);

private:
     std::string _pseudo; /*!< Pseudo du joueur*/
     int _id;             /*!< Identifiant du joueur*/
};


     /*!
     *  \brief surchage d'operateur <<
     *  Surcharge de l'operateur de flux de sortie pour l'objet Player
     *  \param os : Flux de sortie
     *  \param joueur : Joueur à afficher
     *  \return le flux de sortie
     */
     std::ostream& operator<<(std::ostream &os, Player joueur);

#endif