#include "UIGame.hpp"
#include <iostream>

using namespace std;
using namespace sf;

UIGame::UIGame(){
    _nextPlayer = Yellow;

    //nombre de point definissant la texture du plateau (face avant)
    _boardShape.setPointCount(4);
    //les coordonées des differents points de la texture (face avant)
    _boardShape.setPoint(0, Vector2f(240,250));
    _boardShape.setPoint(1, Vector2f(240,550));
    _boardShape.setPoint(2, Vector2f(540,550));
    _boardShape.setPoint(3, Vector2f(540,250));
   
    //l'echelle de la texture (face avant)
    _boardShape.setScale(1.7f,1.7f);
    //la position a l'ecran de la texture (face avant)
    _boardShape.setPosition(-280,-172);
    
    //nombre de point definissant la texture du plateau (face arriere)
    _boardShape3D.setPointCount(4);
    //les coordonées des differents points de la texture (face arriere)
    _boardShape3D.setPoint(0, Vector2f(238,250));
    _boardShape3D.setPoint(1, Vector2f(240,555));
    _boardShape3D.setPoint(2, Vector2f(545,557));
    _boardShape3D.setPoint(3, Vector2f(545,250));
   
    //l'echelle de la texture (face arriere)
    _boardShape3D.setScale(1.7f,1.7f);
    //la position a l'ecran de la texture (face arriere)
    _boardShape3D.setPosition(-280,-182);
}
 
UIGame::~UIGame(){}

void UIGame::setNextPlayer(Token t){ _nextPlayer=t;}

Token UIGame::getNextPlayer(){return _nextPlayer;}

int UIGame::placeInColumn(Vector2i mousePosition){
    float MouseX=mousePosition.x;
    float MouseY=mousePosition.y;

    if(MouseY >=268 && MouseY <=747){
        if( MouseX>=130 && MouseX<= 200){//col1
            _column=0;

        }else if((MouseX>=201 && MouseX <=270)){ //col2
            _column=1;


        }else if((MouseX>=271 && MouseX <=344)){  //col3
            _column=2;
                  

        }else if((MouseX>=345 && MouseX <=420)){ //col4
            _column=3;

        }else if((MouseX>=421 && MouseX <=495)){ //col5
            _column=4;
            

        }else if((MouseX>=496 && MouseX <=563)){ //col6
            _column=5;
            

        }else if((MouseX>=564 && MouseX <=640)){ //col7
            _column=6;
        }
    }
	return _column;
 }

int UIGame::j_to_x(int j) const{
    //colonne
    switch(j){
    case 0:
        return 131;
    case 1:
        return 200;
    case 2:
        return 273;
    case 3:
        return 345;
    case 4:
        return 419;
    case 5:
        return 490;
    case 6:
        return 562;
    default:
        return 0;
    }
}
 
int UIGame::i_to_y(int i) const{
   //ligne
    switch(i){
    case 0:
        return 258;
    case 1:
        return 344;
    case 2:
        return 428;
    case 3:
        return 512;
    case 4:
        return 596;
    case 5:
        return 680;
    default:
        return 5;
    }  
}

int UIGame::displayBoard( RenderWindow &refWindow, Game g){
    //on charge en memoire la texture (face avant)
    Texture boardTexture;
    if (!boardTexture.loadFromFile("./UIcomponents/img/plateau.gif") ){ cout<<"Erreur chargement"<<endl;return 0;}
     _boardShape.setTexture(&boardTexture);  
     
    //on charge en memoire la texture (face arriere)
    Texture boardTexture3D;
    if (!boardTexture3D.loadFromFile("./UIcomponents/img/plateau3D.gif") ){ cout<<"Erreur chargement"<<endl;return 0;}
     _boardShape3D.setTexture(&boardTexture3D);  

    //on recupere le nom des joueurs
    Player p1=g.getPlayer(1);
    Player p2=g.getPlayer(2);

    //on charge en memoire une font
    Font font;
    if (!font.loadFromFile("./UIcomponents/font/Freshman.ttf") ){ cout<<"Erreur chargement"<<endl;return 0;}

    //get yellow player name and his surname font and his caps
    //player1 name
    Text player1;
    player1.setFont(font);
    player1.setString(p1.getPseudo());
    player1.setColor(Color::Yellow);
    player1.setPosition(90,20);

    //player1 caps
    Texture yellowCapsTexture;
    if (!yellowCapsTexture.loadFromFile("./UIcomponents/img/yellowCaps.gif")){cout<<"Erreur chargement"<<endl;return 0;}
    
    CircleShape yellowCaps(38);
    yellowCaps.setPosition(5,5);
    yellowCaps.setTexture(&yellowCapsTexture);


    //get red player name and his surname font and his stone
    //player2 name
    Text player2;
    player2.setFont(font);
    player2.setString(p2.getPseudo());
    player2.setColor(Color::Red);
    player2.setPosition(90,100);

    //player2 caps
    Texture redCapsTexture;
    if (!redCapsTexture.loadFromFile("./UIcomponents/img/redCaps.gif")){cout<<"Erreur chargement"<<endl;return 0;}

    CircleShape redCaps(38);
    redCaps.setPosition(5,80);
    redCaps.setTexture(&redCapsTexture);

    
    //hide the next player
   	if(_nextPlayer==Yellow){
        yellowCaps.setFillColor(Color(255, 255, 255, 255));  //  no hide
        redCaps.setFillColor(Color(255, 255, 255, 128));  // hide
    }else if(_nextPlayer==Red){
      	redCaps.setFillColor(Color(255, 255, 255, 255));  // no hide
      	yellowCaps.setFillColor(Color(255, 255, 255, 128));  // hide
   	}
   

    //draw the board
    //on recupere le plateau courant
    Stroke s;
    Board b=g.getBoard();
    cout << b.toAsciiArt()<< endl;

    CircleShape yellow=yellowCaps;
    CircleShape red=redCaps;

	//on affiche le fond du plateau
	refWindow.draw(_boardShape3D);
	
	//on affiche les pions
    //on parcours le tableau
    for(int i=0;i<6;i++){
        for(int j=0;j<7;j++){
        	//on recupere le stroke
        	s=b.getStroke(i,j);
            if (s._type==Yellow){
                int x,y;
                y=i_to_y(s._i);
                x=j_to_x(s._j);
                yellow.setPosition(x,y);
                yellow.setFillColor(Color(255, 255, 255, 255));  //  no hide
                refWindow.draw(yellow);
            }
        
            if (s._type==Red){	
                int x,y;
                y=i_to_y(s._i);
                x=j_to_x(s._j);
                red.setPosition(x,y);
                red.setFillColor(Color(255, 255, 255, 255));  //  no hide
                refWindow.draw(red);
            }
        }
    }

    //on affiche le reste
    refWindow.draw(yellowCaps);
    refWindow.draw(redCaps);
    refWindow.draw(player1);
    refWindow.draw(player2);
    refWindow.draw(_boardShape);
    return 0;
 }



void UIGame::QuitMessage(int &signal){
    ContextSettings quitSettings;
    quitSettings.antialiasingLevel = 8;
    RenderWindow quitWindow(VideoMode(500, 300, 32), "Attention !!", Style::None, quitSettings);
    quitWindow.setFramerateLimit(30);
    quitWindow.setPosition(Vector2i( (VideoMode::getDesktopMode().width/2)-250, (VideoMode::getDesktopMode().height/2)-175) );// center the window on screen

    //set the background wallpaper
    Texture textureQuitPopup;

    if(!textureQuitPopup.loadFromFile("./UIcomponents/img/quit.jpg")){cout<<"Erreur chargement"<<endl;}
    
    RectangleShape quitPopup(Vector2f(500,300));
    quitPopup.setTexture(&textureQuitPopup);
    
    Texture buttonPopUp;
    if (!buttonPopUp.loadFromFile("./UIcomponents/img/Message_buttons.gif")){cout<<"Erreur chargement"<<endl;}// erreur.
    
    Texture buttonPopUp2;
    if (!buttonPopUp2.loadFromFile("./UIcomponents/img/MultiSelectionButtons.png")){cout<<"Erreur chargement"<<endl;}// erreur.
    
    Sprite retour;
    Sprite quit;
    
    retour.setTexture(buttonPopUp2);
    retour.setTextureRect(sf::IntRect(0, 102, 194.5, 153/3));
    retour.setPosition(5, 250);

    quit.setTexture(buttonPopUp);
    quit.setTextureRect(sf::IntRect(0, 0, 390/2, 100/2));
    quit.setPosition(300, 250);

    Font fontQuit;
    if (!fontQuit.loadFromFile("./UIcomponents/font/Viking.ttf") ){ cout<<"Erreur chargement"<<endl;}

    Text title;
    title.setFont(fontQuit);
    title.setCharacterSize(38);
    title.setString("Attention !");
    title.setColor(Color::Black);
    title.setStyle(sf::Text::Bold);
    title.setPosition(150, 10);

    Text message;
    message.setFont(fontQuit);
    message.setCharacterSize(24);
    message.setString(L"Êtes-vous sûr de vouloir quitter la partie ?");
    message.setColor(Color::Black);
    message.setPosition(10, 80);

    // event's quitPopup
    while (quitWindow.isOpen()){
        Event eventQuit;
        while(quitWindow.pollEvent(eventQuit)){
            if(eventQuit.type == Event :: MouseButtonPressed){
                if(eventQuit.mouseButton.button == Mouse::Left){
                    // mouse coord recuperation
                    Vector2i mousePosition = Mouse::getPosition(quitWindow);
                    if(mousePosition.y >=250 && mousePosition.y <= 300){
                        if(mousePosition.x >=5 && mousePosition.x <= 200){
                            signal=1;
                            quitWindow.close();
                        }
                        if(mousePosition.x >=300 && mousePosition.x <= 495){
                            signal=2;
                            quitWindow.close();
                        }
                    }
                }
            }
        }
        quitWindow.clear();
        quitWindow.draw(quitPopup);
        quitWindow.draw(title);
        quitWindow.draw(message);
        quitWindow.draw(quit);
        quitWindow.draw(retour);
        quitWindow.display();
    }
}

void UIGame::DrawMessage(int &signal){
    ContextSettings drawSettings;
    drawSettings.antialiasingLevel = 8;
    RenderWindow drawWindow(VideoMode(400, 600, 32), "Egalite !", Style::None, drawSettings);
    
    drawWindow.setFramerateLimit(30);
    drawWindow.setPosition(Vector2i( (VideoMode::getDesktopMode().width/2)-200, (VideoMode::getDesktopMode().height/2)-300) );// center the window on screen
                
    Texture textureDrawPopup;
    if(!textureDrawPopup.loadFromFile("./UIcomponents/img/draw.jpeg")){cout<<"Erreur chargement"<<endl;}

    SoundBuffer nullbuffer;
    if (!nullbuffer.loadFromFile("./UIcomponents/music/nul.ogg")){cout<<"Erreur chargement"<<endl;}
    sf::Sound null_sound;
    null_sound.setBuffer(nullbuffer);          
   
 
    null_sound.play();

    Font font2;
    if (!font2.loadFromFile("./UIcomponents/font/Viking.ttf")){}

    Text text;
    text.setFont(font2); // font est un sf::Font
    text.setCharacterSize(30); // exprimée en pixels, pas en points !
    text.setString(L"Egalité");
    text.setPosition(20,20);

     Texture button;

    Sprite rejouer;
    Sprite quit;

    if (!button.loadFromFile("./UIcomponents/img/Message_buttons.gif")){cout<<"Erreur chargement"<<endl;}// erreur.

    rejouer.setTexture(button); 
    quit.setTexture(button);

    quit.setTextureRect(sf::IntRect(0, 0, 390/2, 100/2));
   
    quit.setPosition(200, 545);

    rejouer.setTextureRect(sf::IntRect(0, 50, 390/2, 100/2));

    rejouer.setPosition(5, 545);

    RectangleShape drawPopup(Vector2f(400,600));
    drawPopup.setTexture(&textureDrawPopup);
    
    while(drawWindow.isOpen()){
        Event eventDraw;
        while(drawWindow.pollEvent(eventDraw)){
             if (eventDraw.type == sf::Event::MouseMoved or eventDraw.type == sf::Event::MouseButtonPressed){
                Vector2i mouseDrawPosition = Mouse::getPosition(drawWindow);
                if(mouseDrawPosition.y >=545 && mouseDrawPosition.y <= 600){
                    if(mouseDrawPosition.x >=5 && mouseDrawPosition.x <= 199){
                        quit.setTextureRect(sf::IntRect(0, 0, 390/2, 100/2));
                        rejouer.setTextureRect(sf::IntRect(390/2, 50, 390/2, 100/2));
                        if(eventDraw.mouseButton.button == Mouse::Left){
                            drawWindow.close();
                            signal=1;
                        }
                    }
                    if (mouseDrawPosition.x >= 200 && mouseDrawPosition.x <= 400){
                        quit.setTextureRect(sf::IntRect(390/2, 0, 390/2, 100/2));
                        rejouer.setTextureRect(sf::IntRect(0, 50, 390/2, 100/2));
                        if(eventDraw.mouseButton.button == Mouse::Left){
                            drawWindow.close();
                            signal=2;
                        }
                    }
                }
            }
        } 
        drawWindow.clear();
        drawWindow.draw(drawPopup);
        drawWindow.draw(text);
        drawWindow.draw(quit);
        drawWindow.draw(rejouer);
        drawWindow.display();
    } 
}

void UIGame::WinMessage(int &signal){
    ContextSettings winSettings;
    winSettings.antialiasingLevel = 8;
    RenderWindow winWindow(VideoMode(400, 400, 32), "victoire !!", Style::None, winSettings);
    
    winWindow.setFramerateLimit(30);
    winWindow.setPosition(Vector2i( (VideoMode::getDesktopMode().width/2)-200, (VideoMode::getDesktopMode().height/2)-200) );// center the window on screen
    //set the background wallpaper
    
    SoundBuffer winbuffer;
    if (!winbuffer.loadFromFile("./UIcomponents/music/victory.ogg")){cout<<"Erreur chargement"<<endl;}
    sf::Sound win_sound;
    win_sound.setBuffer(winbuffer);          
   
 
    win_sound.play();
   
    Font font2;
    if (!font2.loadFromFile("./UIcomponents/font/Viking.ttf")){}

    Text text;
    text.setFont(font2); // font est un sf::Font
    text.setCharacterSize(30); // exprimée en pixels, pas en points !
    text.setString("Victoire");
    text.setPosition(20,20);


    Texture textureWinPopup;
    
    if(!textureWinPopup.loadFromFile("./UIcomponents/img/victory.jpeg")){cout<<"Erreur chargement"<<endl;}
    
    RectangleShape winPopup(Vector2f(400,400));
    winPopup.setTexture(&textureWinPopup);
    

    Texture button;

    Sprite rejouer;
    Sprite quit;

    if (!button.loadFromFile("./UIcomponents/img/Message_buttons.gif")){cout<<"Erreur chargement"<<endl;}// erreur.

    rejouer.setTexture(button); 
    quit.setTexture(button);

    quit.setTextureRect(sf::IntRect(0, 0, 390/2, 100/2));
   
    quit.setPosition(200, 345);

    rejouer.setTextureRect(sf::IntRect(0, 50, 390/2, 100/2));

    rejouer.setPosition(5, 345);
                
    while(winWindow.isOpen()){
        Event eventWin;
        while(winWindow.pollEvent(eventWin)){
           if (eventWin.type == sf::Event::MouseMoved or eventWin.type == sf::Event::MouseButtonPressed){
                // mouse coord recuperation
                Vector2i mouseWinPosition = Mouse::getPosition(winWindow);
                if(mouseWinPosition.y >= 345 && mouseWinPosition.y <= 400){
                    if(mouseWinPosition.x >=5 && mouseWinPosition.x <= 199){
                        quit.setTextureRect(sf::IntRect(0, 0, 390/2, 100/2));
                        rejouer.setTextureRect(sf::IntRect(390/2, 50, 390/2, 100/2));
                        if(eventWin.mouseButton.button == Mouse::Left){
                            winWindow.close();
                            signal=1;
                        }
                    }
                    if (mouseWinPosition.x >= 200 && mouseWinPosition.x <= 400){
                        quit.setTextureRect(sf::IntRect(390/2, 0, 390/2, 100/2));
                        rejouer.setTextureRect(sf::IntRect(0, 50, 390/2, 100/2));
                        if(eventWin.mouseButton.button == Mouse::Left){
                            winWindow.close();
                            signal=2;
                        }
                    }
                }
           }
        }
        winWindow.clear();
        winWindow.draw(winPopup);
        winWindow.draw(text);
        winWindow.draw(quit);
        winWindow.draw(rejouer);
        winWindow.display();
    }
} 
        
void UIGame::LoseMessage(int &signal){
    ContextSettings loseSettings;
    loseSettings.antialiasingLevel = 8;
    RenderWindow loseWindow(VideoMode(800, 400, 32), "defaite !!", Style::None, loseSettings);
    
    loseWindow.setFramerateLimit(30);
    loseWindow.setPosition(Vector2i( (VideoMode::getDesktopMode().width/2)-400, (VideoMode::getDesktopMode().height/2)-200) );// center the window on screen
    //set the background wallpaper
    
    SoundBuffer losebuffer;
    if (!losebuffer.loadFromFile("./UIcomponents/music/defeat.ogg")){cout<<"Erreur chargement"<<endl;}
    sf::Sound lose_sound;
    lose_sound.setBuffer(losebuffer);          
    lose_sound.play();
                
    Font font2;
    if (!font2.loadFromFile("./UIcomponents/font/Viking.ttf")){}

    Text text;
    text.setFont(font2); // font est un sf::Font
    text.setCharacterSize(50); // exprimée en pixels, pas en points !
    text.setString(L"Défaite");
    text.setPosition(200,50);

    Texture texturelosePopup;
    
    if(!texturelosePopup.loadFromFile("./UIcomponents/img/defeat.jpeg")){cout<<"Erreur chargement"<<endl;}
    
    RectangleShape losePopup(Vector2f(800,400));
    losePopup.setTexture(&texturelosePopup);
    
    Texture button;

    Sprite rejouer;
    Sprite quit;

    if (!button.loadFromFile("./UIcomponents/img/Message_buttons.gif")){cout<<"Erreur chargement"<<endl;}// erreur.

    rejouer.setTexture(button); 
    quit.setTexture(button);

    quit.setTextureRect(sf::IntRect(0, 0, 390/2, 100/2));
   
    quit.setPosition(600, 345);

    rejouer.setTextureRect(sf::IntRect(0, 50, 390/2, 100/2));

    rejouer.setPosition(5, 345);

    while(loseWindow.isOpen()){
        Event eventlose;
        while(loseWindow.pollEvent(eventlose)){
            if (eventlose.type == sf::Event::MouseMoved or eventlose.type == sf::Event::MouseButtonPressed){
                // mouse coord recuperation
                Vector2i mouselosePosition = Mouse::getPosition(loseWindow);
                if(mouselosePosition.y >= 345 && mouselosePosition.y <= 390){
                    if(mouselosePosition.x >=5 && mouselosePosition.x <= 205){
                        quit.setTextureRect(sf::IntRect(0, 0, 390/2, 100/2));
                        rejouer.setTextureRect(sf::IntRect(390/2, 50, 390/2, 100/2));
                        if(eventlose.mouseButton.button == Mouse::Left){
                            loseWindow.close();
                            signal=1;
                        }
                    }
                    if (mouselosePosition.x >= 600 && mouselosePosition.x <= 800){ 
                        quit.setTextureRect(sf::IntRect(390/2, 0, 390/2, 100/2));
                        rejouer.setTextureRect(sf::IntRect(0, 50, 390/2, 100/2));
                        if(eventlose.mouseButton.button == Mouse::Left){
                            loseWindow.close();

                            signal=2;
                        }
                    }
                }
            }
        }
        loseWindow.clear();
        loseWindow.draw(losePopup);
        loseWindow.draw(text);
        loseWindow.draw(quit);
        loseWindow.draw(rejouer);
        loseWindow.display();   
    }
}