#include "Serveur.hpp"

Serveur::Serveur(int port):_port(port){
	_ip=IpAddress::getLocalAddress(); //on recupere l'adresse local de la machine qui heberge le serveur
}


int Serveur::run(){

	// on tente de connecter les deux clients
	while( !connexion(_joueur1, _joueur2)){
		cout<<"Erreur lors de la connexion ... recommencer"<<endl; 
		return -1;
	}
	cout<<"Vous êtes désormais connecter au Serveur"<<endl; 	


	int nbPartie = 0; 
	int nbVictoire1 = 0;
	int nbVictoire2 = 0;
	int gagnant;
	size_t received; // Vérification.

	while( (nbVictoire2 <= 2 && nbVictoire1 <= 2) ){ // Tant qu'il reste au moins une partie a joué et qu'un joueur n'a pas 2 victoires. ou que les deux joueurs veulent rejouer une partie

		//on envoie aux clients que la partie va débuté
		char data[]="go-------";
		char data1[]="---------";
		char data2[]="---------";

		_joueur1.send(data,10);
		_joueur2.send(data,10);
		cout<<"La partie va commencer"<<endl; 

		//on lance le jeu
		runGame(_joueur1, _joueur2, &gagnant);
 			
		// On sauvegarde une victoire au gagnant
		if(gagnant == 1){
			nbVictoire1 ++;
		}
	 	if(gagnant == 2){
			nbVictoire2 ++;
		}

		std::cout<<"La partie est finie !"<<std::endl;
		nbPartie++; // On note qu'une partie a été jouée. 

		if(nbPartie >=2 or nbVictoire2 == 2 or nbVictoire1 == 2 ){ // Si on détecte la fin du jeu, on arrete. 
			if(nbVictoire1==1 and nbVictoire2==1 and nbPartie==2){
				sprintf(data,"continue-"); // Sinon on continue.
				_joueur2.send(data,10);
				_joueur1.send(data,10);
			}else{
				sprintf(data,"fin------");// la partie est finit 
				_joueur2.send(data,10);
				_joueur1.send(data,10);// on envoie un signal aux joueur et on attend leur reponse

				_joueur2.receive(data1, 10, received); //on reçoit leurs réponses
				_joueur1.receive(data2, 10, received);

				if( strcmp(data1, "rejouer--") == 0 and strcmp(data2, "rejouer--") == 0){//si les deux joueurs veulent rejouer
					nbPartie = 0; 
					nbVictoire1 = 0;
					nbVictoire2 = 0;
					sprintf(data,"rejouer--"); // on rejoue
					_joueur2.send(data,10);
					_joueur1.send(data,10);
				}else if(strcmp(data1, "quitter--")==0){// 1 a quitter la partie
					_joueur2.send(data1,10); // on envoie a 2 de faire pareil
					break;
				}else if(strcmp(data2, "quitter--")==0){// 2 a quitter la partie
					_joueur1.send(data2,10); // on envoie a 1 de faire pareil
					break;
				}
			}
		}
		else{
			sprintf(data,"continue-"); // Sinon on continue.
			_joueur2.send(data,10);
			_joueur1.send(data,10);
		}

	}
	return 0;
}


bool Serveur::connexion(TcpSocket &j1, TcpSocket &j2){

	size_t received; // Vérification.
	
	char data[10];// La donnée qui va transiter. 

	// lie l'écouteur à un port
	if (_listener.listen(_port) != Socket::Done){cout<<"Erreur du listener"<<endl;return false;}

	cout<<"le Serveur est acctuellement en ligne :"<<endl;
	cout<<"ip :"<<_ip.toString()<<endl;
	cout<<"port :"<<_port<<endl;

	int check = 1;
	while(check <= 2){ // Tant qu'on a pas deux joueurs
		if( check == 1){ // Premier joueur a etre accepté.
			if (_listener.accept(j1) != Socket::Done){
				cout<<"Erreur de connexion 11"<<endl;
				return false;
			}else{
				check = 2;
				if (j1.receive(data, 10, received) != Socket::Done){
	   				cout<<"Erreur de reception client 12"<<endl;
					return false;
				}
				else{
					if(strcmp(data, "dmd-connx") == 0){
						sprintf(data, "connexio1");
						j1.send(data, 10);
						cout<<"Client accepté"<<endl;
					}
					else{
						// Erreur
						cout<<"Erreur de demande client 13"<<endl;
						return false;
					}
				}
			}
		}
		else{ // Second joueur accepté
			if (_listener.accept(j2) != Socket::Done){
					cout<<"Erreur de connexion 2"<<endl;
					return false;
			}else{
				check = 3;
				if (j2.receive(data, 10, received) != Socket::Done){
	    			cout<<"Erreur de reception client 2"<<endl;
	    			return false;
				}
				else{
					if(strcmp(data, "dmd-connx") == 0){
						sprintf(data, "connexio2");
						j2.send(data, 10);
						cout<<"Client accepté"<<endl;
					}
					else{
						// Erreur
						cout<<"Erreur de demande client 2"<<endl;
						return false;
					}
				}
			}
		}
	}				
	return true;
}


void Serveur::runGame(TcpSocket &j1,TcpSocket &j2, int *gagnant){

	char* data = (char *) malloc(10*sizeof(char)); 
	int tour =1;
	size_t received; // Vérification.

	while(1){ // On continue jusqu'au break
		if(tour == 1){ // SI c'est un tour pair.

			// On demande au joueur1 de jouer
			sprintf(data,"dmd-jeu--");
			j1.send(data,10);

			// On reçoit la réponse ( de la forme "envoiIJJ") 
			if (j1.receive(data, 10, received) != Socket::Done){
			    cout<<"Erreur de reception client 1789"<<endl;
			}
			else{ // Pas d'erreur

				cout<<" Recu 1 :"<<data<<endl;
				
				data[0]='r'; 
				data[1]='e';
				data[2]='c'; 
				data[3]='e';
				data[4]='p';

				j2.send(data, 10);
				cout<<" Envoi 2 :"<<data<<endl;

				if (j2.receive(data, 10, received) != Socket::Done){
			   	 	cout<<"Erreur de reception client 2"<<endl;
				}
				else{
					cout<<"Recu Conf 2 :"<<data<<endl;
					// Si c'est match nul
					if(strcmp(data, "nul------") == 0){
						j1.send(data, 10);
						j2.send(data, 10);
						*gagnant = 0;
						break;
					}

					// Si 1 à gagné
					if(strcmp(data, "victoire1") == 0){
						j1.send(data, 10);
						char defaite[10]="defaite--";
						j2.send(defaite, 10);
						*gagnant=1;
						break;
					}
					//si 1 à perdu
					if(strcmp(data, "victoire2") == 0){
						j2.send(data, 10);
						char defaite[10]="defaite--";
						j1.send(defaite, 10);
						*gagnant=2;
						break;
					}

				}
				tour = 2;
	
			}
			
		}
		else{ // Tour impair

			// On demande au joueur2 de jouer
			sprintf(data,"dmd-jeu--");
			j2.send(data,10);

			// On reçoit la réponse ( de la forme "envoiIJJ") 
			if (j2.receive(data, 10, received) != Socket::Done){
			    cout<<"Erreur de reception client 2"<<endl;
			}
			else{// Pas d'erreur

				cout<<" Recu 2 :"<<data<<endl;

				data[0]='r'; 
				data[1]='e';
				data[2]='c'; 
				data[3]='e';
				data[4]='p';

				j1.send(data, 10);
				cout<<" Envoi 2 :"<<data<<endl;

				if (j1.receive(data, 10, received) != Socket::Done){
			   	 	cout<<"Erreur de reception client 2"<<endl;
				}
				else{
					cout<<"Recu Conf 2 :"<<data<<endl;
					// Si c'est match nul, on quitte
					if(strcmp(data, "nul------") == 0){
						j2.send(data, 10);
						j1.send(data, 10);
						*gagnant = 0;
						break;
					}

					// Si 1 à gagné, on quitte
					if(strcmp(data, "victoire1") == 0){
						j1.send(data, 10);
						char defaite[10]="defaite--";
						j2.send(defaite, 10);
						*gagnant = 1;
						break;
					}
					if(strcmp(data, "victoire2") == 0){
						j2.send(data, 10);
						char defaite[10]="defaite--";
						j1.send(defaite, 10);
						*gagnant =2;
						break;
					}

				}

				tour = 1;
	
			}		
		}
	}//fin de la boucle while
}

IpAddress Serveur::getServerIP(){return _ip;}

int Serveur::getServerPort(){return _port;}