#include "Player.hpp"
#include "Board.hpp"
#include "Game.hpp"

using namespace std;

Player::Player() : _pseudo("Joueur Inconnu"), _id(0){}

Player::Player(string pseudo, int id) : _pseudo(pseudo), _id(id){}

Player::~Player(){}

string Player::getPseudo(){return _pseudo;}

int Player::getId(){return _id;}

void Player::setPseudo(string pseudo){_pseudo = pseudo;}

void Player::setId(int id){	_id = id; }

void Player::displayPlayer(ostream &os){os << "Identifiant : " << _id << " Pseudo : " << _pseudo;}

ostream& operator<<(std::ostream &os, Player joueur){
	joueur.displayPlayer(os);
	return os;
}