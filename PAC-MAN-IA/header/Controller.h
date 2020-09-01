#pragma once
#include <vector>
#include <SFML/Window.hpp>

#include "Bloc.h"

class Controller
{
protected:
    std::vector<std::vector<Bloc>> grille;

    int largeur;
    int hauteur;

    static const int cellWidth = 32;
    static const int cellHeight = 32;

    sf::Window window(sf::VideoMode(800, 600), "My window");

public:
    Controller();
    Controller(const Controller& controllerIn);
    ~Controller();

    Controller(int largeurIn, int hauteurIn);

    Controller& operator=(const Controller& controllerIn);

private:
    void makeGrid();
    void makeGrid(int rowIn, int columnIn);
};