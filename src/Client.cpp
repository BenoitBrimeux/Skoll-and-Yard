#include "Client.hpp"
#include <cstring>

Client::Client(string ip, int port):
_ip(ip), _port(port){}

Client::~Client(){}

int Client::DemandeConnexion(){
	_serveur.connect(_ip, _port);
	cout<<"Connecté au serveur."<<endl;
	char data[10]="dmd-connx";
	size_t received;
	_serveur.send(data, 10);
	_serveur.receive(data, 10, received);
	
	_joueur = 0;
	if(strcmp(data, "connexio1") == 0){
		_joueur = 1;
	}
	if(strcmp(data, "connexio2") == 0){
		_joueur = 2;
	}
	return _joueur;
}

void Client::EnvoyerCoup(Stroke Coup){
	char Donnee[10] = "Envoi----";
	Donnee[5]=48+Coup._i;
	Donnee[6]=48+Coup._j;
	if(Coup._type == Red){
		Donnee[7]=48+2;	
	}else{
		Donnee[7]=48+1;
	}

	_serveur.send(Donnee, 10);
}

void Client::RecevoirCoup(Game &RefGame, char Reception[10]){
	int i = Reception[5] - 48;
	int j = Reception[6] - 48;
	if(_joueur == 2){ // Nous sommes joueur 2
		Stroke Coup(i, j, Red);
		RefGame.playStroke(1,Coup); // On joue joueur 1.
	}
	else{// l'inverse
		Stroke Coup(i, j, Yellow );
		RefGame.playStroke(2,Coup);
	}	
	if(RefGame.checkWin() == 1 ){
		EnvoyerMess((char*) "victoire1");}// victoire joueur 1
	else if(RefGame.checkWin() == 2 ){
		EnvoyerMess((char*) "victoire2");// victoire joueur 2
	}
	else if(RefGame.checkFull()){
		EnvoyerMess((char*) "nul------");// on envoie match nul
	}
	else{
		EnvoyerMess((char*) "ok-------");//on continue a joué le match n'est pas terminé
	}
}

void Client::EnvoyerMess(char donnee[10]){
	_serveur.send(donnee, 10);
}

void Client::RecevoirMess( char tab[10]){
	size_t received;
	if (_serveur.receive(tab, 10, received) != Socket::Done){
		cout<<"Erreur de Reception."<<endl;
		sprintf(tab, "Erreur");
	}
}