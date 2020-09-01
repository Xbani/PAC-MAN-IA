#pragma once
#include <vector>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <fstream>
#include <sstream>
#include <Bloc.h>

using namespace std;
class Controller
{
protected:
    vector<vector<Bloc>> grille;

    int largeur;
    int hauteur;

    static const int cellWidth = 32;
    static const int cellHeight = 32;

    sf::RenderWindow* window;

public:
    Controller();
    ~Controller();

    Controller(int largeurIn, int hauteurIn);

private:
    void makeGrid();
    void makeGrid(int rowIn, int columnIn);
    void makeGridFromFile(string path);

    void setBlocAt(int x, int y, Bloc::BlocType typeIn);

    bool run();

};