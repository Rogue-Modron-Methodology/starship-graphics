//  Copyright 2015 Jamie Johnson.
//  This work is for educational purposes only.
//  No commercial use, duplication, or distribution is allowed.
//  All artwork belongs to Mayfair Games Inc.
//  www.mayfairgames.com
//  Used without permission for educational purposes only.
//
//  The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Universe.h"
#include "Object.h"
#include <string>
#include <fstream>
#include <sstream>
#include "SFML/Graphics.hpp"


const int CARDLISTSIZE = 71;					//  number of cards in the deck
const std::string CARDLIST = "starship.csv";
const std::string ADVENTURELIST = "starship2.csv";
const std::string SDIEFLE = "resources/board/flightdie.png";

enum Phases{ production, flight, trades, build };

class Game{
private:
	Player *P1, *P2, *cPlyr;
	Universe *universe;
	sf::RenderWindow gWindow;
	sf::Vector2u screenSize;
	ResourceManager<sf::Texture> txtMgr;
	sf::Font font;
	int cPhase;						//  Current Phase Num
	sf::Text phaseNameString;			//  Phase Name Text String
	sf::Text errorString;				//  Error Text String
	std::string statusUpdate;			//  Catches errors from called functions
	sf::Text infoString;				//  Info Text String
	int errorTimer;
	Icon flightDie;
	int combatDie[6];
	bool phaseSetupComplete;				//  Flag 
	bool gainProductionResource;			//  Flag for enabling free colony resource
	bool phaseComplete;					//  Flag

public:
	Game();
	~Game()
	{
		delete P1;
		delete P2;
		delete universe;
		delete flightDie.icon;
	}
	// getters and setters
	Player* getP1() const
	{	return P1;  }
	Player* getP2() const
	{	return P2;  }
	Universe* getUniverse() const
	{	return universe;	}


	int rollCombatDie()
	{	return combatDie[rand() % 6];	}
	void startGame()
	{	gameLoop();	};

private:	
	void gameLoop();
	void playerSetup();	
	void initCDie();
	void phaseSetup();
	void updateGameWindow(sf::RenderWindow &gWindow);
	void endPhase();
	void setError(std::string error);
	int rollSpeedDie();

};

#endif // BOARDGAME_H
