#include "Serveur.hpp"
#include <SFML/Network.hpp>
#include <stdio.h>

using namespace std;

int main(int argc,char** argv){
	int port;
	
	if ( argc > 1 ){ //si l'utilisateur spécifie un numéro de port
		port=atoi(argv[1]);
		Serveur s(port);
		cout<<"Le Serveur à besoin d'un port libre pour démarrer"<<endl;
		cout<<"Initialisation du serveur..."<<endl;
		cout<<"démarrage du serveur en cours."<<endl;
		cout<<endl;
		s.run();
	}else if ( argc == 1 ){// par default
		cout<<"Le Serveur à besoin d'un port libre pour démarrer"<<endl;
		cout<<"Initialisation d'un port par default..."<<endl;
		cout<<"démarrage du serveur en cours."<<endl;
		cout<<endl;
		port=5000;
		Serveur s(port);
		s.run();
	}

	

	return 0;
}