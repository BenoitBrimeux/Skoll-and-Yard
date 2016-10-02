#include "Game.hpp"
#include "Board.hpp"

using namespace std;

Game::Game():
_plateau(this), _Joueur1("Joueur 1", 1), _Joueur2("Joueur 2", 2){}

Game::Game(string pseudo1, string pseudo2):
_plateau(this), _Joueur1(pseudo1, 1), _Joueur2(pseudo2, 2){}

Player Game::getPlayer(int num){
	if(num==1){
		return _Joueur1;
	}
	if(num==2){
		return _Joueur2;
	}
	return _Joueur1;
} 

Board Game::getBoard(){
	return _plateau;
}

void Game::playStroke(int num, Stroke Coup){
	if(num==2){
		Coup._type = Red;
		_plateau.playStroke(Coup);
	}
	else{
		Coup._type = Yellow;
		_plateau.playStroke(Coup);
	}
}

bool Game::canPlayStroke(Stroke Coup){
	if(_plateau.columnEmpty(Coup._j)){
		return true;
	}
	return false;
}

int Game::checkWin(){return _plateau.checkWin();}

bool Game::checkFull(){	return _plateau.checkFull();}

void Game::initGame(){_plateau.initBoard();}

//retourne un nombre compris en min et max
int getrand(int min,int max){return (rand()%(max-min))+min;}

void Game::runAI(){
	srand (time(NULL));
	int j=getrand(0,6);
	Stroke coup(0,j,Red);

	if(canPlayStroke(coup)){
		playStroke(2,coup);
	}else{runAI();}
}