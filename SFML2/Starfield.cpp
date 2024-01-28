#include "Starfield.h"

// Initializers

void Starfield::initWindow()
{
	this->window = new sf::RenderWindow(this->windowSize, "StarField Simulator", sf::Style::Close | sf::Style::Titlebar);
	this->window->setFramerateLimit(60);
	
	/*sf::View centered_view;
	centered_view.setCenter(this->window->getSize().x / 8.f, this->window->getSize().y / 8.f);
	centered_view.setSize(this->window->getSize().x, this->window->getSize().y);
	centered_view.setViewport(sf::FloatRect(0, 0, 1, 1));
	this->window->setView(centered_view);*/
}

void Starfield::initVariable()
{
	/*this->windowSize = { 1000, 800 };*/
	this->windowSize.width = 800;
	this->windowSize.height = 800;



}

void Starfield::initStar()
{
	int numberOfStar = 500;

	for (int i = 0; i < numberOfStar; i++)
	{
		star STAR(this->windowSize);
		this->Stars.push_back(STAR);
	}

}

std::random_device rd;
std::mt19937 gen(rd());






// Constructor and Destructor
Starfield::Starfield()
{
	this->initVariable();
	this->initWindow();
	this->initStar();


	this->test.setPosition(this->window->getSize() .x / 2 , this->window->getSize().y / 2);
	this->test.setFillColor(sf::Color::Cyan);
	this->test.setSize(sf::Vector2f(50.0f, 50.0f));
}

Starfield::~Starfield()
{
	delete this->window;
}


// Accessor

const bool Starfield::running() const
{
	return this->window->isOpen();
}

void Starfield::pollevent()
{

	while (this->window->pollEvent(this->ev))
	{
		switch (this->ev.type)
		{
		case sf::Event::Closed:
			this->window->close();

		case sf::Event::KeyPressed:
			if (ev.key.code == sf::Keyboard::Escape) {
				this->window->close();
				break;
			}

		default:
			break;
		}
	}

}


// Update Function

void Starfield::update()
{
	this->pollevent();

	this->updateStar();

}

void Starfield::updateStar()
{
	for (int i = 0; i < this->Stars.size(); i++)
	{
		float change = Stars[i].mapValue(sf::Mouse::getPosition(*this->window).x, 0, this->windowSize.width, 1, 15);
		this->Stars[i].changeZ(-change);
		this->Stars[i].updatePosition(this->windowSize);
		float r = this->Stars[i].mapValue(this->Stars[i].getZ(), 0, windowSize.width, 5.0, 0.5);
		this->Stars[i].setRadius(r);



		/*if(this->Stars[i].getPosition().x > window->getSize().x && this->Stars[i].getPosition().y > window->getSize().y)
		{
			this->Stars[i].setPosition(rand() % this->windowSize.width , rand() % this->windowSize.height );
		}*/
	}
}


// Render Function

void Starfield::render()
{
	this->window->clear();

	this->renderStars();
	this->bringStarBack();
	//this->window->draw(this->test);

	this->window->display();
}

void Starfield::renderStars()
{
	for (auto& st : this->Stars)
	{
		this->window->draw(st);
	}
}

void Starfield::bringStarBack()
{
	for (auto& st : Stars)
	{

		std::uniform_real_distribution<> disX(-static_cast<int>(this->windowSize.width) * 5, this->windowSize.width * 2);
		std::uniform_real_distribution<> disY(-static_cast<int>(this->windowSize.height) * 2, this->windowSize.height * 2);
		if (st.getPosition().x > this->windowSize.width && st.getPosition().y > this->windowSize.height)
		{
			st.setZ(this->windowSize.width);
			st.setPosition(sf::Vector2f(disX(gen), disY(gen)));
		}
	}
}
