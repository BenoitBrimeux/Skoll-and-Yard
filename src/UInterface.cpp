
#include "UInterface.hpp"
#include <SFML/Network.hpp>
#include <cstring>

UInterface::UInterface(){}
UInterface::~UInterface(){}

void UInterface::Start(){//quand on lance le jeu 
	// Create main window
    ContextSettings settings;
    settings.antialiasingLevel = 8;
    RenderWindow LaunchScreen(VideoMode(800, 600, 32), "Skoll and Yard Puissance 4", Style::Close | Style::Titlebar, settings);
    
   	LaunchScreen.setVerticalSyncEnabled(true);
    LaunchScreen.setPosition(Vector2i( (VideoMode::getDesktopMode().width/2)-400, (VideoMode::getDesktopMode().height/2)-300) );// center the window on screen


    //set the background wallpaper
    Texture textureWallpaper;
    if (!textureWallpaper.loadFromFile("./UIcomponents/img/LaunchScreen.jpg")){cout<<"Erreur chargement"<<endl;}    
    RectangleShape Wallpaper(Vector2f(800,600));
    Wallpaper.setTexture(&textureWallpaper);


    Font font;
	if (!font.loadFromFile("./UIcomponents/font/Freshman.ttf")){cout<<"Erreur chargement"<<endl;}// erreur...
	
	Text text;
	// choix de la police à utiliser
	text.setFont(font); // font est un Font
	// choix de la chaîne de caractères à afficher
	text.setString("Appuyer sur une touche pour continuer");
	text.setCharacterSize(29); // exprimée en pixels, pas en points !
	text.setPosition(100,500); 


	Music music;
	if (!music.openFromFile("./UIcomponents/music/Skoll.ogg")){cout<<"Erreur chargement"<<endl;}// erreur..
	music.play();


     // This is the main loop
    // It will loop until you exit the program
    while (LaunchScreen.isOpen()){
        // Here we process the events list
        Event event;
        while (LaunchScreen.pollEvent(event)){
        	if(event.type == Event::KeyPressed ){LaunchScreen.close();music.stop();MainMenu();}
            if (event.type == Event::Closed){LaunchScreen.close();}
        }
        LaunchScreen.clear();
        LaunchScreen.draw(Wallpaper);
        LaunchScreen.draw(text);
        LaunchScreen.display();
    }
}

void UInterface::MainMenu(){
	// Create main window
    ContextSettings settings;
    settings.antialiasingLevel = 8;
    RenderWindow mainMenu(VideoMode(800, 600, 32), "Skoll and Yard Puissance 4", Style::Close | Style::Titlebar, settings);
    
   	mainMenu.setVerticalSyncEnabled(true);
    mainMenu.setPosition(Vector2i( (VideoMode::getDesktopMode().width/2)-400, (VideoMode::getDesktopMode().height/2)-300) );// center the window on screen


    //set the background wallpaper
    Texture textureWallpaper;
    if (!textureWallpaper.loadFromFile("./UIcomponents/img/MainMenu.png")){cout<<"Erreur chargement"<<endl;}    
    RectangleShape Wallpaper(Vector2f(800,600));
    Wallpaper.setTexture(&textureWallpaper);

	Music music;
	if (!music.openFromFile("./UIcomponents/music/MainTheme.ogg")){cout<<"Erreur chargement"<<endl;}// erreur.
	music.play();


	Texture button;

	Sprite solo;
	Sprite multi;
	Sprite credits;
	Sprite quit;

	if (!button.loadFromFile("./UIcomponents/img/Buttons.png")){cout<<"Erreur chargement"<<endl;}// erreur.

    solo.setTexture(button); 
	multi.setTexture(button);
	credits.setTexture(button); 
	quit.setTexture(button);

	solo.setTextureRect(IntRect(1623, 0, 3207/2, 2382/9));
	solo.setScale(Vector2f(0.15f, 0.15f));
	solo.setPosition(20, 340);

	multi.setTextureRect(IntRect(1623, 528, 3207/2, 2382/9));
	multi.setScale(Vector2f(0.15f, 0.15f));
	multi.setPosition(20,400);

	credits.setTextureRect(IntRect(1623, 1584, 3207/2, 2382/9));
	credits.setScale(Vector2f(0.15f, 0.15f));
	credits.setPosition(20, 460);

	quit.setTextureRect(IntRect(1623, 2112, 3207/2, 2382/9));
	quit.setScale(Vector2f(0.15f, 0.15f));
	quit.setPosition(20, 520);


     // This is the main loop
    // It will loop until you exit the program
    while (mainMenu.isOpen()){
        // Here we process the events list
        Event event;
        while (mainMenu.pollEvent(event)){
            if (event.type == Event::Closed){mainMenu.close();}
          	 if (event.type == Event::MouseMoved or event.type == Event::MouseButtonPressed){
               Vector2i p = Mouse::getPosition(mainMenu);
                if(p.x>=20 and p.x<=400){
					if(p.y>=340 and p.y<=399){
						solo.setTextureRect(IntRect(0, 0, 3207/2, 2382/9));//on met a jour la texture
                		multi.setTextureRect(IntRect(1623, 528, 3207/2, 2382/9));
						
						credits.setTextureRect(IntRect(1623, 1584, 3207/2, 2382/9));
						quit.setTextureRect(IntRect(1623, 2112, 3207/2, 2382/9));
               			if (event.mouseButton.button == Mouse::Left){
               				mainMenu.close();
               				music.stop();
               				runSingle();
               			}
						
					}
					if(p.y>=400 and p.y<=459){
						solo.setTextureRect(IntRect(1623, 0, 3207/2, 2382/9));
						multi.setTextureRect(IntRect(0,528,3207/2, 2382/9));//on met a jour la texture
						credits.setTextureRect(IntRect(1623, 1584, 3207/2, 2382/9));
						quit.setTextureRect(IntRect(1623, 2112, 3207/2, 2382/9));
						if (event.mouseButton.button == Mouse::Left){
							mainMenu.close();
                            music.stop();
							PlayMulti();
						}
					}
					if(p.y>=460 and p.y<=519){
						solo.setTextureRect(IntRect(1623, 0, 3207/2, 2382/9));
						multi.setTextureRect(IntRect(1623, 528, 3207/2, 2382/9));
						credits.setTextureRect(IntRect(0, 1584, 3207/2, 2382/9));//on met a jour la texture
						quit.setTextureRect(IntRect(1623, 2112, 3207/2, 2382/9));
						if (event.mouseButton.button == Mouse::Left){
                            mainMenu.close();
                            music.stop();
                            Credits();
						}
					}
					if(p.y>=520 and p.y<=560){
						solo.setTextureRect(IntRect(1623, 0, 3207/2, 2382/9));
						multi.setTextureRect(IntRect(1623, 528, 3207/2, 2382/9));
						credits.setTextureRect(IntRect(1623, 1584, 3207/2, 2382/9));
						quit.setTextureRect(IntRect(0, 2112, 3207/2, 2382/9));//on met a jour la texture
						if (event.mouseButton.button == Mouse::Left){
							mainMenu.close();
							music.stop();
						}
					}
				}
            }
        }
        mainMenu.clear();
        mainMenu.draw(Wallpaper);
    
        mainMenu.draw(solo);
    	mainMenu.draw(multi);
		mainMenu.draw(credits);
		mainMenu.draw(quit);
    
        mainMenu.display();
    }
}

void UInterface::PlayMulti(){
	// Create main window
    ContextSettings settings;
    settings.antialiasingLevel = 8;
    RenderWindow multi(VideoMode(600, 600, 32), "Multijoueur", Style::Close | Style::Titlebar, settings);
    
   	multi.setVerticalSyncEnabled(true);
    //skoll.setFramerateLimit(30);
    multi.setPosition(Vector2i( (VideoMode::getDesktopMode().width/2)-300, (VideoMode::getDesktopMode().height/2)-300) );// center the window on screen

    //set the background wallpaper
    Texture textureWallpaper;

    if (!textureWallpaper.loadFromFile("./UIcomponents/img/Multi.jpg")){cout<<"Erreur chargement"<<endl;}
    
    RectangleShape Wallpaper(Vector2f(600,600));

    Wallpaper.setTexture(&textureWallpaper);
    
    Texture button;

	Sprite creePartie;
	Sprite rejoindrePartie;
	Sprite retour;
	
	if (!button.loadFromFile("./UIcomponents/img/boutons.gif")){cout<<"Erreur chargement"<<endl;}// erreur.
 	
 	creePartie.setTexture(button); 
	rejoindrePartie.setTexture(button); 
	retour.setTexture(button); 

			//setTextureRect(IntRect(X, Y, x, y);
			// X,Y origine de la texture ,  x,y taille de la texture selectionné sur l'image
	creePartie.setTextureRect(IntRect(0, 0, 1842, 890/5));
	creePartie.setScale(Vector2f(0.2f, 0.2f));
	creePartie.setPosition(120, 280);

	rejoindrePartie.setTextureRect(IntRect(0, 177.5, 1842, 890/5));
	rejoindrePartie.setScale(Vector2f(0.2f, 0.2f));
	rejoindrePartie.setPosition(120, 340);

	retour.setTextureRect(IntRect(0, 355.3, 1842, 890/5));
    retour.setScale(Vector2f(0.2f, 0.2f));
	retour.setPosition(120, 400);

 	Music multiwait;
	if (!multiwait.openFromFile("./UIcomponents/music/multiplayerTheme.ogg")){cout<<"Erreur chargement"<<endl;}// erreur.
	multiwait.setLoop(true);
	multiwait.play();

    Font font;
    if (!font.loadFromFile("./UIcomponents/font/Rock.ttf")){cout<<"Erreur chargement"<<endl;}// erreur...
    Text text;
    text.setFont(font);
    text.setString("Multijoueur");
    text.setCharacterSize(35);
    text.setPosition(200,10);



     // This is the main loop
    // It will loop until you exit the program
    while (multi.isOpen()){
        // Here we process the events list
        Event event;
        while (multi.pollEvent(event)){

            // Close window : exit
            if (event.type == Event::Closed){multi.close();multiwait.stop();MainMenu();}
            if (event.type == Event::MouseButtonPressed){
                if (event.mouseButton.button == Mouse::Left){
              		Vector2i p = Mouse::getPosition(multi);
                	if(p.x>=120 and p.x<=480){
	                	if( p.y>=280 and p.y<=320){       //creation d'une partie multijoueur
                            multi.close();
                            multiwait.stop();
                            runPVP();
                        }
	                	if( p.y>=340 and p.y<=380){  //rejoindre une partie => devenir client 
	                    	multi.close();
	                    	multiwait.stop();
    	                	runClient();
                    	}
	                	if( p.y>=400 and p.y<=440){
	                    	multi.close();
	                    	multiwait.stop();
    	                	MainMenu();
                    	}
                	}
                }
            }
         }

         multi.clear(Color::Black);
         multi.draw(Wallpaper);
         multi.draw(text);
         multi.draw(creePartie);
         multi.draw(rejoindrePartie);
         multi.draw(retour);
         multi.display();
     }
}

void UInterface::Credits(){
    // Create main window
    ContextSettings settings;
    settings.antialiasingLevel = 8;
    
    Clock timer;
	float pos=0;
 
    RenderWindow creditsMenu(VideoMode(800, 600, 32), "Credits", Style::Close | Style::Titlebar, settings);
    
    creditsMenu.setVerticalSyncEnabled(true);
    creditsMenu.setPosition(Vector2i( (VideoMode::getDesktopMode().width/2)-400, (VideoMode::getDesktopMode().height/2)-300) );// center the window on screen


    Texture textureWallpaper;
    if (!textureWallpaper.loadFromFile("./UIcomponents/img/Credits.jpg")){cout<<"Erreur chargement"<<endl;}    
    RectangleShape Wallpaper(Vector2f(800,600));
    Wallpaper.setTexture(&textureWallpaper);

    Texture button;
    Sprite retour;
    if (!button.loadFromFile("./UIcomponents/img/boutons.gif")){cout<<"Erreur chargement"<<endl;}// erreur.
    retour.setTexture(button); 
    retour.setTextureRect(IntRect(0, 355.3, 1842, 890/5));
    retour.setScale(Vector2f(0.2f, 0.2f));
    retour.setPosition(215, 500);


    Texture credits_t;
    Sprite credits;
    if (!credits_t.loadFromFile("./UIcomponents/img/credits.gif")){cout<<"Erreur chargement"<<endl;}// erreur.
    credits.setTexture(credits_t); 
    credits.setTextureRect(IntRect(0, 0, 800, 430));
    credits.setPosition(0, 50);

    Font fontTitle;
    if (!fontTitle.loadFromFile("./UIcomponents/font/Rock.ttf") ){ cout<<"Erreur chargement"<<endl;}
    Text title;
    title.setFont(fontTitle);
    title.setCharacterSize(28);
    title.setString("Skoll And Yard");
    title.setColor(Color::White);
    title.setPosition(300, 10);

    Music music;
	if (!music.openFromFile("./UIcomponents/music/credits.ogg")){cout<<"Erreur chargement"<<endl;}// erreur.
	music.play();

     // This is the main loop
    // It will loop until you exit the program
    while (creditsMenu.isOpen()){
        // Here we process the events list
        Event event;
        while (creditsMenu.pollEvent(event)){
            if (event.type == Event::Closed){creditsMenu.close();}
            if (event.type == Event::MouseMoved or event.type == Event::MouseButtonPressed){
                Vector2i p = Mouse::getPosition(creditsMenu);
                if(p.x>=200 and p.x<=550 and p.y>=500 and p.y<=550){
                    if (event.mouseButton.button == Mouse::Left){
                        creditsMenu.close();
                        music.stop();
                        MainMenu();
                    }
                }
            }
        }

        creditsMenu.clear(Color::Black);
        creditsMenu.draw(Wallpaper);
        creditsMenu.draw(title);
        creditsMenu.draw(retour);
		

		if(timer.getElapsedTime().asMilliseconds() >= 1)
		{
			credits.setTextureRect(IntRect(0, pos, 800, 430));
			pos += 0.5;
			timer.restart();
			
			if(pos==1672){pos=0;}//pos = 2072 -> hauteur total de l'image des credits 
		}
		creditsMenu.draw(credits);
        creditsMenu.display();
    }
}

int UInterface::runSingle(){ 
    // Create main window
    ContextSettings settings;
    settings.antialiasingLevel = 8;
    RenderWindow skoll(VideoMode(800, 800, 32), "Mode Solo", Style::Default, settings);
    
   	skoll.setVerticalSyncEnabled(true);
    //skoll.setFramerateLimit(30);
    skoll.setPosition(Vector2i( (VideoMode::getDesktopMode().width/2)-400, (VideoMode::getDesktopMode().height/2)-400) );// center the window on screen

    //set the background wallpaper
    Texture textureWallpaper;

    if (!textureWallpaper.loadFromFile("./UIcomponents/img/bar.jpg")){cout<<"Erreur chargement"<<endl;return 0;}
    
    RectangleShape Wallpaper(Vector2f(800,800));

    Wallpaper.setTexture(&textureWallpaper);
 
    // Create a 4 SkØll in a row board
    Game game("Player 1","Player 2");
 	

    // Create the user interface
    UIGame ui;

    Stroke lastStroke;

    int nbpartie=0;
    int YellowWin=0;
    int RedWin=0;
    string _0("[0]");
    string _1("[1]");
    string _2("[2]");
    string _3("[3]");

    Music ambiant;
	if (!ambiant.openFromFile("./UIcomponents/music/Ambiant.ogg")){cout<<"Erreur chargement"<<endl;}// erreur.
	ambiant.setLoop(true);
	ambiant.play();

	SoundBuffer capsbuffer;
    if (!capsbuffer.loadFromFile("./UIcomponents/music/caps.ogg")){cout<<"Erreur chargement"<<endl;}// erreur.
    Sound caps_sound;
	caps_sound.setBuffer(capsbuffer);

	Font font1;
	if (!font1.loadFromFile("./UIcomponents/font/chiffre.ttf")){}
	
	Font font2;
	if (!font2.loadFromFile("./UIcomponents/font/Viking.ttf")){}

	Text text;
	Text scoreY;	
	Text scoreR;

	scoreY.setFont(font1);
	scoreR.setFont(font1);
	text.setFont(font2); // font est un Font
	text.setString("Round 1");

	string sY=_0;
	string sR=_0;

	scoreY.setString(sY);
	scoreR.setString(sR);

	// choix de la taille des caractères
	text.setCharacterSize(50); // exprimée en pixels, pas en points !
	text.setPosition(580,20);

	scoreY.setCharacterSize(38); // exprimée en pixels, pas en points !
	scoreY.setPosition(280,18);

	scoreR.setCharacterSize(38); // exprimée en pixels, pas en points !
	scoreR.setPosition(280,98);
    bool PlayerTurn=true;
    // This is the main loop
    // It will loop until you exit the program
    while (skoll.isOpen()){
        // Here we process the events list
        Event event;
        while (skoll.pollEvent(event)){
            
            int column;
            
            // Close window : exit
            if(event.type == Event::KeyPressed && event.key.code== Keyboard::Escape){ 
                int signal;   
                ui.QuitMessage(signal);
                if(signal==2){    
                    ambiant.stop();
                    skoll.close();
                    MainMenu();
                }else{}
            }
            if (event.type == Event::Closed){
                int signal;   
                ui.QuitMessage(signal);
                if(signal==2){    
                    ambiant.stop();
                    skoll.close();
                    MainMenu();
                }else{}
            }
            if (event.type == Event::MouseMoved){
                Vector2i localPosition = Mouse::getPosition(skoll);
                column=ui.placeInColumn(localPosition);
            }
            if (PlayerTurn==true and event.type == Event::MouseButtonPressed){
                if (event.mouseButton.button == Mouse::Left){
                    Vector2i localPosition = Mouse::getPosition(skoll);
                    column=ui.placeInColumn(localPosition);
                    Token nextPlayer=ui.getNextPlayer();
                    Stroke s(0,column,nextPlayer);

                    if(game.canPlayStroke(s)){
                        if(nextPlayer==Yellow){
                            game.playStroke(1,s);
                            caps_sound.play();
                            ui.setNextPlayer(Red);
                            PlayerTurn=false;
                        }
                    }
                }
            }else if(PlayerTurn==false){// AI turn
                Token nextPlayer=ui.getNextPlayer();
                if(nextPlayer==Red){
                    game.runAI(); 
                    caps_sound.play();
                    ui.setNextPlayer(Yellow);
                    PlayerTurn=true;
                }
            }
        }

        // Clear the screen with a color
        skoll.clear(Color::Black);
        
        //Display wallpaper
        skoll.draw(Wallpaper);

        // Draw the board
        ui.displayBoard(skoll,game);
        
        //affichage du score
        if(YellowWin==0){sY=_0;}
        if(YellowWin==1){sY=_1;}
        if(YellowWin==2){sY=_2;}
        if(YellowWin==3){sY=_3;}
        
        if(RedWin==0){sR=_0;}
        if(RedWin==1){sR=_1;}
        if(RedWin==2){sR=_2;}
        if(RedWin==3){sR=_3;}

        scoreY.setString(sY);
        scoreR.setString(sR);
        
        skoll.draw(scoreY);
        skoll.draw(scoreR);

        if(nbpartie==0){text.setString("Round 1");}
        if(nbpartie==1){text.setString("Round 2");}
        if(nbpartie==2){text.setPosition(548,20);text.setString("Final Round");}
        skoll.draw(text);


        //Verification de l'etat du jeu
        if(nbpartie>2 or YellowWin==2 or RedWin==2){ //si on a fait 3 partie    ou si Jaune a gagné 2 fois   ou si rouge a gagné 2 fois
            ambiant.stop();
            int signal=0;
 //affichage du score
             // Clear the screen with a color
            skoll.clear(Color::Black);
        
            //Display wallpaper
            skoll.draw(Wallpaper);
            // Draw the board
            ui.displayBoard(skoll,game);

            if(YellowWin==0){sY=_0; scoreY.setString(sY);}
            if(YellowWin==1){sY=_1; scoreY.setString(sY); }
            if(YellowWin==2){sY=_2; scoreY.setString(sY); }
            if(YellowWin==3){sY=_3; scoreY.setString(sY); }
            if(RedWin==0){sR=_0;scoreR.setString(sR); }
            if(RedWin==1){sR=_1;scoreR.setString(sR); }
            if(RedWin==2){sR=_2;scoreR.setString(sR); }
            if(RedWin==3){sR=_3;scoreR.setString(sR); }
            if(nbpartie==0){text.setString("Round 1"); }
            if(nbpartie==1){text.setString("Round 2");  }
            if(nbpartie==2){text.setPosition(548,20);text.setString("Final Round"); }
            skoll.draw(scoreY);
            skoll.draw(scoreR);
            skoll.draw(text);

            // Render the frame on screen
            skoll.display();
          
            if(YellowWin>RedWin){
                
                ui.WinMessage(signal);
            }
            if(RedWin>YellowWin){
                ui.LoseMessage(signal);
            }
            if(YellowWin==RedWin){
                ui.DrawMessage(signal);
            }
            if(signal==1){
                game.initGame();
                nbpartie=0;
                YellowWin=0;
                RedWin=0;
            }
            if(signal==2){skoll.close();MainMenu();}
        }else{
            if(game.checkFull()){
                nbpartie++;
                game.initGame();
            }
            if(game.checkWin()==1 or game.checkWin()==2 ){
                if(game.checkWin()==1){YellowWin++;}
                if(game.checkWin()==2){RedWin++;}
                nbpartie++;
                game.initGame();
            }

        }

        skoll.display();
    }
 
    return 0;
}

int UInterface::runPVP(){ 
    // Create main window
    ContextSettings settings;
    settings.antialiasingLevel = 8;
    RenderWindow skoll(VideoMode(800, 800, 32), "Multijoueur Local", Style::Default, settings);
    
    skoll.setVerticalSyncEnabled(true);
    //skoll.setFramerateLimit(30);
    skoll.setPosition(Vector2i( (VideoMode::getDesktopMode().width/2)-400, (VideoMode::getDesktopMode().height/2)-400) );// center the window on screen

    //set the background wallpaper
    Texture textureWallpaper;

    if (!textureWallpaper.loadFromFile("./UIcomponents/img/bar.jpg")){cout<<"Erreur chargement"<<endl;return 0;}
    
    RectangleShape Wallpaper(Vector2f(800,800));

    Wallpaper.setTexture(&textureWallpaper);
 
    // Create a 4 SkØll in a row board
    Game game("Player 1","Player 2");
    

    // Create the user interface
    UIGame ui;

    Stroke lastStroke;

    int nbpartie=0;
    int YellowWin=0;
    int RedWin=0;
    string _0("[0]");
    string _1("[1]");
    string _2("[2]");
    string _3("[3]");

    Music ambiant;
    if (!ambiant.openFromFile("./UIcomponents/music/Ambiant.ogg")){cout<<"Erreur chargement"<<endl;}// erreur.
    ambiant.setLoop(true);
    ambiant.play();

    SoundBuffer capsbuffer;
    if (!capsbuffer.loadFromFile("./UIcomponents/music/caps.ogg")){cout<<"Erreur chargement"<<endl;}// erreur.
    Sound caps_sound;
    caps_sound.setBuffer(capsbuffer);

    Font font1;
    if (!font1.loadFromFile("./UIcomponents/font/chiffre.ttf")){}
    
    Font font2;
    if (!font2.loadFromFile("./UIcomponents/font/Viking.ttf")){}

    Text text;
    Text scoreY;    
    Text scoreR;

    scoreY.setFont(font1);
    scoreR.setFont(font1);
    text.setFont(font2); // font est un Font
    text.setString("Round 1");

    string sY=_0;
    string sR=_0;

    scoreY.setString(sY);
    scoreR.setString(sR);

    // choix de la taille des caractères
    text.setCharacterSize(50); // exprimée en pixels, pas en points !
    text.setPosition(580,20);

    scoreY.setCharacterSize(38); // exprimée en pixels, pas en points !
    scoreY.setPosition(280,18);

    scoreR.setCharacterSize(38); // exprimée en pixels, pas en points !
    scoreR.setPosition(280,98);
  

    // This is the main loop
    // It will loop until you exit the program
    while (skoll.isOpen()){
        // Here we process the events list
        Event event;
        while (skoll.pollEvent(event)){
            
            int column;
            
            // Close window : exit
            if(event.type == Event::KeyPressed && event.key.code== Keyboard::Escape){ 
                int signal;   
                ui.QuitMessage(signal);
                if(signal==2){    
                    ambiant.stop();
                    skoll.close();
                    MainMenu();
                }else{}
            }
            if (event.type == Event::Closed){
                int signal;   
                ui.QuitMessage(signal);
                if(signal==2){    
                    ambiant.stop();
                    skoll.close();
                    MainMenu();
                }else{}
            }
            if (event.type == Event::MouseMoved){
                Vector2i localPosition = Mouse::getPosition(skoll);
                column=ui.placeInColumn(localPosition);
            }
            if (event.type == Event::MouseButtonPressed){
                if (event.mouseButton.button == Mouse::Left){
                    Vector2i localPosition = Mouse::getPosition(skoll);
                    column=ui.placeInColumn(localPosition);
                    Token nextPlayer=ui.getNextPlayer();
                    Stroke s(0,column,nextPlayer);

                    if(game.canPlayStroke(s)){
                        if(nextPlayer==Yellow){
                            game.playStroke(1,s);
                            caps_sound.play();
                            ui.setNextPlayer(Red);
                        }
                        if(nextPlayer==Red){
                            game.playStroke(2,s);
                            caps_sound.play();
                            ui.setNextPlayer(Yellow);
                        }
                    }
                }
            }
        }

        // Clear the screen with a color
        skoll.clear(Color::Black);
        
        //Display wallpaper
        skoll.draw(Wallpaper);

        // Draw the board
        ui.displayBoard(skoll,game);
        
        //affichage du score
        if(YellowWin==0){sY=_0;}
        if(YellowWin==1){sY=_1;}
        if(YellowWin==2){sY=_2;}
        if(YellowWin==3){sY=_3;}
        
        if(RedWin==0){sR=_0;}
        if(RedWin==1){sR=_1;}
        if(RedWin==2){sR=_2;}
        if(RedWin==3){sR=_3;}

        scoreY.setString(sY);
        scoreR.setString(sR);
        
        skoll.draw(scoreY);
        skoll.draw(scoreR);

        if(nbpartie==0){text.setString("Round 1");}
        if(nbpartie==1){text.setString("Round 2");}
        if(nbpartie==2){text.setPosition(548,20);text.setString("Final Round");}
        skoll.draw(text);


        //Verification de l'etat du jeu
        if(nbpartie>2 or YellowWin==2 or RedWin==2){ //si on a fait 3 partie    ou si Jaune a gagné 2 fois   ou si rouge a gagné 2 fois
            ambiant.stop();
            int signal=0;
 //affichage du score
             // Clear the screen with a color
            skoll.clear(Color::Black);
        
            //Display wallpaper
            skoll.draw(Wallpaper);
            // Draw the board
            ui.displayBoard(skoll,game);

            if(YellowWin==0){sY=_0; scoreY.setString(sY);}
            if(YellowWin==1){sY=_1; scoreY.setString(sY); }
            if(YellowWin==2){sY=_2; scoreY.setString(sY); }
            if(YellowWin==3){sY=_3; scoreY.setString(sY); }
            if(RedWin==0){sR=_0;scoreR.setString(sR); }
            if(RedWin==1){sR=_1;scoreR.setString(sR); }
            if(RedWin==2){sR=_2;scoreR.setString(sR); }
            if(RedWin==3){sR=_3;scoreR.setString(sR); }
            if(nbpartie==0){text.setString("Round 1"); }
            if(nbpartie==1){text.setString("Round 2");  }
            if(nbpartie==2){text.setPosition(548,20);text.setString("Final Round"); }
            skoll.draw(scoreY);
            skoll.draw(scoreR);
            skoll.draw(text);

            // Render the frame on screen
            skoll.display();
          
            if(YellowWin>RedWin){
                
                ui.WinMessage(signal);
            }
            if(RedWin>YellowWin){
                ui.LoseMessage(signal);
            }
            if(YellowWin==RedWin){
                ui.DrawMessage(signal);
            }
            if(signal==1){
                game.initGame();
                nbpartie=0;
                YellowWin=0;
                RedWin=0;
            }
            if(signal==2){skoll.close();ambiant.stop();MainMenu();}
        }else{
            if(game.checkFull()){
                nbpartie++;
                game.initGame();
            }
            if(game.checkWin()==1 or game.checkWin()==2 ){
                if(game.checkWin()==1){YellowWin++;}
                if(game.checkWin()==2){RedWin++;}
                nbpartie++;
                game.initGame();
            }

        }

        skoll.display();
    }
 
    return 0;
}

void UInterface::runClient(){// on lance l'interface du second client   //TODO
    ContextSettings settings;
    settings.antialiasingLevel = 8;
    RenderWindow client_log(VideoMode(400, 200, 32), "Client", Style::Close | Style::Titlebar, settings);
    
    client_log.setVerticalSyncEnabled(true);
    client_log.setPosition(Vector2i( (VideoMode::getDesktopMode().width/2)-400, (VideoMode::getDesktopMode().height/2)-250) );// center the window on screen
 	

 	Font font2;
   	if (!font2.loadFromFile("./UIcomponents/font/arial.ttf")){}

	Text text;
	text.setFont(font2); // font est un Font
	text.setColor(Color::White);
	text.setCharacterSize(20);
    text.setString("Entrer l'adresse ip et le port du serveur :\n(exemple: 127.0.0.1/5000)");
    text.setPosition(5,20);
    
    Text iptext;
	iptext.setFont(font2); // font est un Font
	iptext.setColor(Color::White);
	iptext.setCharacterSize(20);
    iptext.setPosition(22,74);
    
    string ip_port;


	Texture button;
    Sprite text_zone;
    Sprite connexion;

    if (!button.loadFromFile("./UIcomponents/img/boutons.gif")){cout<<"Erreur chargement"<<endl;}// erreur.

    text_zone.setTexture(button);
    text_zone.setTextureRect(IntRect(0, 716, 1842, 890/5));
    text_zone.setScale(Vector2f(0.2f, 0.2f));
    text_zone.setPosition(15, 70);

    connexion.setTexture(button);
    connexion.setTextureRect(IntRect(0, 532, 1842, 890/5));
    connexion.setScale(Vector2f(0.2f, 0.2f));
    connexion.setPosition(15, 120);


    // This is the main loop
    // It will loop until the 2 clients are connected
    while (client_log.isOpen()){
    	
 		Event event;
		while(client_log.pollEvent(event)){
			if(event.type == Event::Closed){client_log.close();}

			if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape){client_log.close();}
			if(event.type == Event::KeyPressed && event.key.code == Keyboard::BackSpace){
				ip_port="";
				iptext.setString(ip_port);;
			}
			if(event.type==Event::TextEntered){
				char code=static_cast<char>(event.text.unicode);
				if( (event.text.unicode>=46 and event.text.unicode<=57) ){// 0~9 ou '.' , ou '/''
                    ip_port=ip_port+code;
					iptext.setString(ip_port);	
				}
			}
			if (event.type == Event::MouseButtonPressed){
                Vector2i p = Mouse::getPosition(client_log);
                if(p.x>=15 and p.x<=395 and p.y>=120 and p.y<=160){
                    if (event.mouseButton.button == Mouse::Left){
                        client_log.close();
                        runUIClient(ip_port);
                    }
                }
            }
		}

		client_log.clear();
		client_log.draw(text);
		client_log.draw(text_zone);
		client_log.draw(connexion);
		client_log.draw(iptext);
		client_log.display();
    }
} 

int UInterface::runUIClient(string ip_port){
    /****************************************************************************/
    //on recupere l'ip et le port de la chaine entrée par l'utilisateur
    string ip;
    string port;
    int slash_pos=0;
    int size=ip_port.size();
    for (int i=0; i<size; i++){
        if(ip_port[i]!='/'){
            ip=ip+ip_port[i];
            slash_pos=i+1;
        }else{
            break;
        }
    }
    for(int i=slash_pos+1;i<size;i++){
        port=port+ip_port[i];
    }
    int server_port=stoi(port);//on convertit la chaine en int 
    /********************************************************************/

    ContextSettings settings;
    settings.antialiasingLevel = 8;
    RenderWindow skoll(VideoMode(800, 800, 32), "Multijoueur", Style::Default, settings);
    
    skoll.setVerticalSyncEnabled(true);
    //skoll.setFramerateLimit(30);
    skoll.setPosition(Vector2i( (VideoMode::getDesktopMode().width/2)-400, (VideoMode::getDesktopMode().height/2)-400) );// center the window on screen

    //set the background wallpaper
    Texture textureWallpaper;
    if (!textureWallpaper.loadFromFile("./UIcomponents/img/bar.jpg")){cout<<"Erreur chargement"<<endl;return 0;}
    RectangleShape Wallpaper(Vector2f(800,800));
    Wallpaper.setTexture(&textureWallpaper);

    Music ambiant;
    if (!ambiant.openFromFile("./UIcomponents/music/Ambiant.ogg")){cout<<"Erreur chargement"<<endl;}// erreur.
    ambiant.setLoop(true);
    ambiant.play();

    SoundBuffer capsbuffer;
    if (!capsbuffer.loadFromFile("./UIcomponents/music/caps.ogg")){cout<<"Erreur chargement"<<endl;}// erreur.
    Sound caps_sound;
    caps_sound.setBuffer(capsbuffer);

    //variables du jeu
    int nbpartie=0;// nombre totale de partie
    int YellowWin=0; // partie gagné par jaune
    int RedWin=0; // partie gagné par rouge
    /*****************/

    string _0("[0]");
    string _1("[1]");
    string _2("[2]");
    string _3("[3]");

    Font font1;
    if (!font1.loadFromFile("./UIcomponents/font/chiffre.ttf")){}
    
    Font font2;
    if (!font2.loadFromFile("./UIcomponents/font/Viking.ttf")){}

    Text text;
    Text scoreY;    
    Text scoreR;

    scoreY.setFont(font1);
    scoreR.setFont(font1);
    text.setFont(font2); // font est un Font
    text.setString("Round 1");

    string sY=_0;
    string sR=_0;

    scoreY.setString(sY);
    scoreR.setString(sR);

    // choix de la taille des caractères
    text.setCharacterSize(50); // exprimée en pixels, pas en points !
    text.setPosition(580,20);

    scoreY.setCharacterSize(38); // exprimée en pixels, pas en points !
    scoreY.setPosition(280,18);

    scoreR.setCharacterSize(38); // exprimée en pixels, pas en points !
    scoreR.setPosition(280,98);


    /*INITIALISATION DU JEU , DE LA CONNECTION AU SERVEUR ET DE L'INTERFACE CLIENT */
    Game game("Player 1", "Player 2");
    Client C(ip,server_port);
    UIGame ui;


    skoll.clear(Color::Black);    
    //Display wallpaper
    skoll.draw(Wallpaper);
    ui.displayBoard(skoll,game);
    skoll.draw(text);
    skoll.draw(scoreY);
    skoll.draw(scoreR);
    skoll.display();


    int val = C.DemandeConnexion(); // connexion serveur, val = le num du joueur. 
    
    while(1){ // Tant qu'on a pas eu le signal de fin au bout des 2 ou 3 parties.

        char data[10];
        C.RecevoirMess(data); // Début de la partie. "go--------"

        char victoire[10];
        if(val==1){
            sprintf(victoire, "victoire1");
        }
        else{
            sprintf(victoire, "victoire2");
        }

        Stroke tmp;
        // On reçoit le premier message
        C.RecevoirMess(data);


        // On démare la boucle
        while(skoll.isOpen()){
       // while(skoll.isOpen()and  strcmp(data, victoire) != 0 && strcmp(data, "nul------") != 0 && strcmp(data, "defaite--")){

            skoll.clear(Color::Black);    
            //Display wallpaper
            skoll.draw(Wallpaper);
            ui.displayBoard(skoll,game);

            if(YellowWin==0){sY=_0; scoreY.setString(sY);}
            if(YellowWin==1){sY=_1; scoreY.setString(sY); }
            if(YellowWin==2){sY=_2; scoreY.setString(sY); }
            if(YellowWin==3){sY=_3; scoreY.setString(sY); }
            if(RedWin==0){sR=_0;scoreR.setString(sR); }
            if(RedWin==1){sR=_1;scoreR.setString(sR); }
            if(RedWin==2){sR=_2;scoreR.setString(sR); }
            if(RedWin==3){sR=_3;scoreR.setString(sR); }
            if(nbpartie==0){text.setString("Round 1"); }
            if(nbpartie==1){text.setString("Round 2");  }
            if(nbpartie==2){text.setPosition(548,20);text.setString("Final Round"); }
          
            skoll.draw(scoreY);
            skoll.draw(scoreR);
            skoll.draw(text);

            // Render the frame on screen
            skoll.display();

            if(strcmp(data, "dmd-jeu--") == 0){ // le serveur demande au client de jouer
                // Here we process the events list
                Event event;
                while (skoll.waitEvent(event)){
                    int column;
                    // Close window : exit
                    if(event.type == Event::KeyPressed && event.key.code== Keyboard::Escape){ 
                        int signal;   
                        ui.QuitMessage(signal);
                        if(signal==2){
                            //on envoie au serveur qu'on veut arreter de jouer
                            // C.EnvoyerMess((char*)"quitter--");  
                            ambiant.stop();
                            skoll.close();
                            MainMenu();
                        }else{}
                    }
                    if (event.type == Event::Closed){
                        int signal;   
                        ui.QuitMessage(signal);
                        if(signal==2){ 
                            //on envoie au serveur qu'on veut arreter de jouer
                            //C.EnvoyerMess((char*)"quitter--");  
                            ambiant.stop();
                            skoll.close();
                            MainMenu();
                        }else{}
                    }
                    if (event.type == Event::MouseButtonPressed){
                        if (event.mouseButton.button == Mouse::Left){
                            Vector2i localPosition = Mouse::getPosition(skoll);
                            column=ui.placeInColumn(localPosition);
                            Token nextPlayer=ui.getNextPlayer();
                                tmp._i=0;
                                tmp._j=column;
                                tmp._type=nextPlayer;                                    
                            if(nextPlayer==Yellow and val == 1){
                                if(game.canPlayStroke(tmp)){
                                    game.playStroke(val, tmp);
                                    caps_sound.play();
                                    ui.setNextPlayer(Red);
                                    C.EnvoyerCoup(tmp);
                                    break;
                                }
                            }
                            if(nextPlayer==Red and val==2){
                                if(game.canPlayStroke(tmp)){
                                    game.playStroke(val, tmp);
                                    caps_sound.play();
                                    ui.setNextPlayer(Yellow);
                                    C.EnvoyerCoup(tmp);
                                    break;
                                }
                            }
                        }  
                    }
                }
            }
            else if(data[0] == 'r' && data[1] == 'e' && data[2]== 'c' && data[3]== 'e' && data[4]== 'p'){
                tmp._i = 48 - data[5];
                tmp._j = 48 - data[6];
                if(data[7]=='1'){
                    tmp._type = Yellow;
                    ui.setNextPlayer(Red);
                }else{
                    tmp._type = Red;
                    ui.setNextPlayer(Yellow);
                }
            
                C.RecevoirCoup(game, data);
            }
            skoll.clear(Color::Black);    
            //Display wallpaper
            skoll.draw(Wallpaper);
            ui.displayBoard(skoll,game);
            skoll.draw(text);
            skoll.draw(scoreY);
            skoll.draw(scoreR);
            skoll.display();


            C.RecevoirMess(data);

            //on a terminé une partie
            if(strcmp(data, victoire) == 0){
                if(val==1){
                    YellowWin++;
                    if(YellowWin==0){sY=_0; scoreY.setString(sY);}
                    if(YellowWin==1){sY=_1; scoreY.setString(sY);}
                    if(YellowWin==2){sY=_2; scoreY.setString(sY);}
                    if(YellowWin==3){sY=_3; scoreY.setString(sY);}
                    ui.setNextPlayer(Yellow);
                }
                if(val==2){
                    RedWin++;
                    if(RedWin==0){sR=_0; scoreR.setString(sR);}
                    if(RedWin==1){sR=_1; scoreR.setString(sR);}
                    if(RedWin==2){sR=_2; scoreR.setString(sR);}
                    if(RedWin==3){sR=_3; scoreR.setString(sR);}
                    ui.setNextPlayer(Yellow); 
                }
                nbpartie++;
                game.initGame();
            }else if(strcmp(data, "nul------") == 0){        
                nbpartie++;
                game.initGame();
                ui.setNextPlayer(Yellow);
            }else if(strcmp(data, "defaite--") == 0){
                if(val==1){
                    RedWin++;
                    if(RedWin==0){sR=_0; scoreR.setString(sR);}
                    if(RedWin==1){sR=_1; scoreR.setString(sR);}
                    if(RedWin==2){sR=_2; scoreR.setString(sR);}
                    if(RedWin==3){sR=_3; scoreR.setString(sR);} 
                    ui.setNextPlayer(Yellow);
                }
                if(val==2){
                    YellowWin++;
                    if(YellowWin==0){sY=_0; scoreY.setString(sY);}
                    if(YellowWin==1){sY=_1; scoreY.setString(sY);}
                    if(YellowWin==2){sY=_2; scoreY.setString(sY);}
                    if(YellowWin==3){sY=_3; scoreY.setString(sY);}
                    ui.setNextPlayer(Yellow);
                }
                nbpartie++;
                game.initGame();
            }

            int signal=0;
            if(strcmp(data,"fin------") == 0){//si c'est la fin 
                if(val==1){
                    if(YellowWin>RedWin){
                        ui.WinMessage(signal);
                    }else if(YellowWin==RedWin){
                        ui.DrawMessage(signal);
                    }else if(YellowWin<RedWin){
                        ui.LoseMessage(signal);
                    }
                }
                if(val==2){
                    if(RedWin>YellowWin){
                        ui.WinMessage(signal);
                    }else if(YellowWin==RedWin){
                        ui.DrawMessage(signal);
                    }else if(RedWin<YellowWin){
                        ui.LoseMessage(signal);
                    }
                }

                if(signal==1){
                    C.EnvoyerMess((char*) "rejouer--");
                    nbpartie=0;// nombre totale de partie
                    YellowWin=0; // partie gagné par jaune
                    RedWin=0; // partie gagné par rouge
                    
                }
                if(signal==2){
                    C.EnvoyerMess((char*) "quitter--");
                    ambiant.stop();
                    skoll.close();
                    return 0;
                }
            }
        }
    }
    return 0;
}