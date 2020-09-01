#pragma once
#include <vector>

#include "Bloc.h"

class Controller
{
protected:
    std::vector<std::vector<Bloc>> grille;
    int largeur;
    int hauteur;

public:
    Controller();
    Controller(const Controller& controlelrIn);
    ~Controller();

    Controller(int largeurIn, int hauteurIn);

    Controller& operator=(const Controller& controllerIn);
};