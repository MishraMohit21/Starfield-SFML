#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>

#include <iostream>
#include <random>
#include <algorithm>
#include <cmath>


class star :public sf::CircleShape
{
	float x;
	float y; 
	float z;
	float width;
	float height;
	float sx, sy;


public:
	double mapValue(double value, double inputMin, double inputMax, double outputMin, double outputMax);

	// Accessor
	const float getZ() const;

	// Getter
	void setZ(float val);

	star(sf::VideoMode vm);
	virtual	~star();

	void updatePosition(sf::VideoMode vm);

	void initProperties(sf::VideoMode vm);
	void changeZ(float change);
};

