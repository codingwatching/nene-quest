#include <iostream>
#include "../headers/randomCloud.hpp"

using namespace std;
using namespace sf;

RandomCloud::RandomCloud() {
	this->cloudBody = RectangleShape(Vector2f(this->MAX_WIDTH, this->MAX_HEIGHT));
	this->cloudBody.setFillColor(Color::White);
	this->cloudBody.setOrigin(this->cloudBody.getSize().x / 2, this->cloudBody.getSize().y / 2);
}

void RandomCloud::generateBorder() {
	srand(time(NULL));
	float currentRad = 0;
	float radStep = 7.28f / this->BORDER_NUMBER;
	for (int i = 0; i < this->BORDER_NUMBER; i++)
	{
		sf::CircleShape nc = CircleShape(this->BORDER_SIZE_MIN + rand() % (this->BORDER_SIZE_MAX - this->BORDER_SIZE_MIN));
		nc.setFillColor(Color::White);
		nc.setOrigin(nc.getRadius() + cos(currentRad) * (rand()% (this->BORDER_VARI*2) - this->BORDER_VARI + this->MAX_WIDTH/2),
			nc.getRadius() + sin(currentRad) * (rand() % (this->BORDER_VARI * 2) - this->BORDER_VARI + this->MAX_HEIGHT/2)
		);

		nc.setPosition(this->cloudBody.getPosition());
		this->cloudBorder.push_back(nc);
		currentRad += radStep;
	}

	this->clock.restart();
}

void RandomCloud::update() {
	if (this->clock.getElapsedTime().asSeconds() >= this->LIFETIME)
		this->alive = false;
}

bool RandomCloud::isAlive() {
	return this->alive;
}