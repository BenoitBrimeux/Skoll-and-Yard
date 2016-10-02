#ifndef SERVEUR
#define SERVEUR

/*!
 * \file Serveur.hpp
 * \brief Gestion du reseau partie serveur.. 
 * \author Benjamin Maes, Nadir Trabelsi, Benoit Brimeux
 */

#include <SFML/Network.hpp>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>

using namespace sf; 
using namespace std;

/*! \class Serveur
 * \brief classe contenant les fonctions de gestion du réseau partie Serveur.
 *  La classe contient les sockets connectant les deux joueurs, ainsi que toutes les fonctions permettant une partie en réseau.
 */
class Serveur{
private:
		IpAddress _ip; /*!< L'adresse IP du serveur*/
		int _port; /*!< Le port du serveur*/
		
		TcpListener _listener;  /*!< socket d'ecoute du serveur permettant la connexion.*/

		TcpSocket _joueur1; /*!< Socket de liaison avec le joueur 1*/
		TcpSocket _joueur2; /*!< Socket de liaison avec le joueur 2*/
		
public:
	/*!
     *  \brief Constructeur
     *  Permet de crée un objet Serveur. 
     *	\param port : Le port du serveur
     */
	Serveur(int port);
	
	/*!
     *  \brief La fonction qui lance le serveur et fait joué trois parties
     *  Lance la partie, gére les tours, et transmet les données.
	*  \return 0 quand le serveur est stopé
     */
	int run();
	
	/*!
     *  \brief on établie la connexion des deux joueurs au serveur
     *  Permet de connecter les deux joueurs au serveur.
     *  \param j1 : socket liant le serveur et le joueur 1 
     *  \param j2 : socket liant le serveur et le joueur 2 
     *  \return true si la connexion est établie entre les deux joueurs et le serveur
     */
	bool connexion(TcpSocket &j1, TcpSocket &j2);//on connecte deux clients au serveru
	
	/*!
     *  \brief Lance une et une seule partie entre deux joueur. 
     *  Lance la partie et demande aux joueurs de jouer l'un après l'autre.
     *  \param j1 : socket liant le serveur et le joueur 1 
     *  \param j2 : socket liant le serveur et le joueur 2 
     *	\param gagnant : le gagnant entre les deux joueurs sur une partie
     */
	void runGame(TcpSocket &j1, TcpSocket &j2, int *gagnant);//on fait jouer les 2 clients
	
	/*!
     *  \brief retourne l'adresse ip du serveur
     *  Permet de Récuperer l'adresse du serveur. 
     *	\return L'adresse ip.
     */
	IpAddress getServerIP();
	
	/*!
     *  \brief retourne le port utilisé par le serveur
     *  Permet de Récuperer le port du serveur. 
     *	\return Le port du serveur.
     */
	int getServerPort();
};

#endif