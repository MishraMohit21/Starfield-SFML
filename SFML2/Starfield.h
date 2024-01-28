#pragma once
#include "star.h"

class Starfield
{
	sf::RenderWindow* window;
	sf::Event ev;
	sf::VideoMode windowSize;
	sf::View centered_view;

	// Array of Star
	std::vector<star> Stars;
	sf::RectangleShape test;

	//initialitzers

	void initWindow();
	void initVariable();
	void initStar();

	
	

public:

	Starfield();
	virtual ~Starfield();


	// Accessor

	const bool running() const;


	void pollevent();
	

	//Update Function
	void update();
	void updateStar();

	//Render Function
	void render();
	void renderStars();
	void bringStarBack();
};

