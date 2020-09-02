#include "Pacman.h"
Pacman::Pacman()
{
	x = 32*13+16;
	y = 32*23;
	direction = UP;
	speed = 4;
}

double Pacman::getX()
{
	return x;
}

double Pacman::getY()
{
	return y;
}

double Pacman::getNextX()
{
	if (direction == LEFT)
		return x - speed;
	else if (direction == RIGHT)
		return x + speed;
	else
		return x;
}

double Pacman::getNextY()
{
	if (direction == DOWN)
		return y + speed;
	else if (direction == UP)
		return y - speed;
	else
		return y;
}
void Pacman::toggleMoveUp()
{
	direction = UP;
}

void Pacman::toggleMoveRight()
{
	direction = RIGHT;
}
void Pacman::toggleMoveDown()
{
	direction = DOWN;
}
void Pacman::move()
{
	switch (direction) {
	case UP:
		y -= speed;
		break;
	case RIGHT:
		x += speed;
		break;
	case LEFT:
		x -= speed;
		break;
	case DOWN:
		y += speed;
		break;
	}
}
void Pacman::toggleMoveLeft()
{
	direction = LEFT;
}

