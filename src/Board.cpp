#include "Board.hpp"
#include "Game.hpp"
#include "Player.hpp"

Stroke::Stroke():_i(0), _j(0), _type(Empty){}

Stroke::Stroke(int i, int j, Token type):
_i(i), _j(j), _type(type){}

Board::Board():
_refgame(NULL){
	initBoard();
}

Board::Board(Game* refgame):
_refgame(refgame){
	initBoard();
}

void Board::playStroke(Stroke Coup){
	if(columnEmpty(Coup._j)){
		for(int i = 5; i>=0; i-- ){
			if(_tab[i][Coup._j]._type == Empty){
				Coup._i = i;
				break;
			}
		}

		_tab[Coup._i][Coup._j] = Coup;
	}
}

void Board::initBoard(){
	for(int i=0; i<6; i++){
		for(int j=0; j<7; j++){
			_tab[i][j]._type = Empty;
		}
	}
}

bool Board::checkFull(){
	for(int i=0; i<6; i++){
		for(int j=0; j<7; j++){
			if(_tab[i][j]._type == Empty)
				return false;
		}
	}
	return true;

}

int Board::nbAdjacents(int colonne, int ligne, int incrementColonne, int incrementLigne){
    int compteur = 1;
    while(colonne+incrementColonne>-1 && colonne+incrementColonne<7 && ligne+incrementLigne>-1 && ligne+incrementLigne<6 
    && _tab[ligne][colonne]._type==_tab[ligne+incrementLigne][colonne+incrementColonne]._type 
    && _tab[ligne][colonne]._type != Empty){
        compteur++;
        ligne=ligne+incrementLigne;
        colonne=colonne+incrementColonne;
    }
    return compteur;
}



int Board::checkWin(){
	int valeur;
    for(int ligne = 0; ligne <6; ligne ++){
    	for(int colonne =0; colonne <7; colonne ++){

    		if(_tab[ligne][colonne]._type != Empty){
    			
    			if(_tab[ligne][colonne]._type == Yellow)
    				valeur = 1;
    			else
    				valeur = 2;

			    //Verification verticale
			    if(nbAdjacents(colonne,ligne,0,-1)+nbAdjacents(colonne,ligne,0,1)-1>=4){      
			        return valeur;
			    }
			    //Verification horizontale
			    if(nbAdjacents(colonne,ligne,-1,0)+nbAdjacents(colonne,ligne,1,0)-1>=4){
			        return valeur;
			    }
			    //Verification Diagonale
			    if(nbAdjacents(colonne,ligne,-1,-1)+nbAdjacents(colonne,ligne,1,1)-1>=4){
			        return valeur;
			    }
			    //Verification Diagonale "inversée"
			    if(nbAdjacents(colonne,ligne,1,-1)+nbAdjacents(colonne,ligne,-1,1)-1>=4){
			        return valeur;
			    }
			}
		}
	}
    return -1;
}

Stroke Board::getStroke(int i, int j){
	return _tab[i][j];
}

bool Board::columnEmpty(int num){
	if(_tab[0][num]._type != Empty){
		return false;
	}else{
		return true;
	}
	return false;
}

std::string Board::toAsciiArt(){
	std::string out =""; 
	for(int ligne = 0; ligne <6; ligne ++){
    	for(int colonne =0; colonne <7; colonne ++){
    		if(_tab[ligne][colonne]._type == Empty) out += "  ";
    		else if(_tab[ligne][colonne]._type == Red) out += " R";
    		else if(_tab[ligne][colonne]._type == Yellow) out += " Y";
    	}
    	out += "\n";
    }
    return out;
}