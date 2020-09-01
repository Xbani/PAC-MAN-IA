#include "Pacman.h"
Pacman::Pacman()
{
	x = 450;
	y = 738;
	direction = UP;
}

double Pacman::getX()
{
	return x;
}

double Pacman::getY()
{
	return y;
}
