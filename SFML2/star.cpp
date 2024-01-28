#include "star.h"




double star::mapValue(double value, double inputMin, double inputMax, double outputMin, double outputMax)
{
	return (value - inputMin) * (outputMax - outputMin) / (inputMax - inputMin) + outputMin;
}

const float star::getZ() const
{
	return this->z;
}

void star::setZ(float val)
{
	this->z = val;
}

star::star(sf::VideoMode vm)
{
	std::random_device rd;
	std::mt19937 gen(rd());


	std::uniform_real_distribution<> disX(-static_cast<int>(vm.width), vm.width);
	std::uniform_real_distribution<> disY(-static_cast<int>(vm.height), vm.height);

	x = disX(gen);
	y = disY(gen);
	z = vm.width;
	height = vm.height;
	width = vm.width;
	this->initProperties(vm);
	
}

star::~star()
{
}

void star::updatePosition(sf::VideoMode vm)
{
	sx = this->mapValue(x / z, 0.0, 1.0, 0.0, vm.width);
	sy = this->mapValue(y / z, 0.0, 1.0, 0.0, vm.height);
	this->setPosition(sx , sy );

}


void star::initProperties(sf::VideoMode vm)
{
	sx = this->mapValue(x / z, 0.0, 1.0, 0.0, vm.width);
	sy = this->mapValue(y / z, 0.0, 1.0, 0.0, vm.height);
	this->setFillColor(sf::Color::White);
	//this->setRadius(2.5f);
	this->setPosition(sx , sy );
}

void star::changeZ(float change)
{
	z += change;

	if (z < 1)
	{
		z = width;
	}
}


