#ifndef CLIENT
#define CLIENT

/*!
 * \file Client.hpp
 * \brief Gestion du reseau partie client.. 
 * \author Benjamin Maes, Nadir Trabelsi, Benoit Brimeux
 */

#include <SFML/Network.hpp>
#include <iostream>
#include "Game.hpp"

using namespace sf; 
using namespace std;

/*! \class Client
 * \brief classe contenant les fonctions de gestion du réseau partie Client.
 *  La classe contient la socket de liaison serveur, les fonctions d'envoi et de 
 *	reception des données/messages.
 */
class Client{

	TcpSocket _serveur; /*!< Socket de liaison avec le serveur.*/
	string _ip; /*!< adresse Ipv4 du serveur */
	int _port; /*!< port du serveur*/
	int _joueur; /*!< Joueur courant.*/

public:
	/*!
     *  \brief Constructeur
     *  Permet de créer un objet Client. 
     *  \param _ip : ip du serveur
     *  \param port : Le port du serveur
     */
	Client(string _ip, int port);
	
	/*!
     *  \brief Destructeur
     *  Permet de supprimer un objet Client. 
     */
	~Client();
	
	/*!
     *  \brief Demande la connexion au serveur
     *  Se connecte au serveur et renvoie le numéro du joueur.
     *  \return le numéro du joueur.
     */
	int DemandeConnexion();
	
	/*!
     *  \brief Envoie le coup qui vient d'etre joué. 
     *  Permet de transmettre au serveur le coup qui vient d'être joué.
     *  \param Coup : le coup a envoyer au serveur.
     */
	void EnvoyerCoup(Stroke Coup);

	/*!
     *  \brief Reçoit le coup joué par l'adversaire.
     *  Permet de recevoir via le serveur le coup joué par l'adversaire. 
     *  \param RefGame : réference sur le jeu en cours pour jouer le coup.
     *	\param Reception : les données reçus.
     */
	void RecevoirCoup(Game &RefGame, char Reception[10]);

	/*!
     *  \brief Envoi un message au serveur.
     *  Permet d'envoyer un message au serveur. "ok-------"
     *  \param donnee : Les données à  envoyer.
     */		
	void EnvoyerMess(char donnee[10]);

	/*!
     *  \brief Réceptionne un message du serveur.
     *  Permet de recevoir un message du serveur.
     *  \param tab : Le message reçu.
     */
	void RecevoirMess(char tab[10]);
};

#endif