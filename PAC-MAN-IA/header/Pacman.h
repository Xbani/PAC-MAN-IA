#pragma once
#include <Entity.h>
class Pacman : public Entity
{
public:
    enum Direction {
        UP,
        RIGHT,
        LEFT,
        DOWN
    };

protected:
	double x;
	double y;

    Pacman::Direction direction;

public:
    Pacman();

    double getX();
    double getY();
};

