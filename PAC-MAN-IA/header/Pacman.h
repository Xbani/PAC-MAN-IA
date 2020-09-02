#pragma once
#include <Entity.h>
class Pacman : public Entity
{
public:
    enum Direction {
        UP,
        RIGHT,
        DOWN,
        LEFT
    };

protected:
	double x;
	double y;

    double speed;

    Pacman::Direction direction;

public:
    Pacman();

    double getX();
    double getY();

    double getNextX();
    double getNextY();

    void toggleMoveUp();
    void toggleMoveRight();
    void toggleMoveLeft();
    void toggleMoveDown();

    void move();
};

