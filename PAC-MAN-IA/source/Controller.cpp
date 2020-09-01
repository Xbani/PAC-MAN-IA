#include "Controller.h"

Controller::Controller() {
	makeGridFromFile("C:\\Users\\oscar\\source\\repos\\PAC-MAN-IA\\Debug\\lvl1.csv");
	while (run());
}

Controller::~Controller()
{
	delete window;
}

Controller::Controller(int largeurIn, int hauteurIn) {
	largeur = largeurIn;
	hauteur = hauteurIn;
	window = new sf::RenderWindow(sf::VideoMode(largeur*cellWidth, hauteur*cellHeight), "PAC-MAN");
	
	makeGrid(largeurIn,hauteurIn);
	while (run());
}

void Controller::makeGrid() {
	makeGrid(28, 28);
}

void Controller::makeGrid(int rowIn, int columnIn) {
	grille = std::vector<std::vector<Bloc>>();

	for (int x = 0; x < rowIn; ++x) {

		std::vector<Bloc> vectorRow;
		grille.insert(grille.end(), vectorRow);

		for (int y = 0; y < columnIn; ++y) {
			Bloc bloc = Bloc();
			grille.at(x).push_back(bloc);
		}
	}
}

void Controller::setBlocAt(int x, int y, Bloc::BlocType typeIn)
{
	grille.at(x).at(y).setType(typeIn);
}

void Controller::makeGridFromFile(string path)
{
	largeur = 28;
	hauteur = 31;
	makeGrid(28, 31);

	std::ifstream myFile(path);
	// Make sure the file is open
	if (!myFile.is_open()) throw std::runtime_error("Could not open file");
	// Helper vars
	std::string line, colname;
	int val;
	int rowIdx = 0;
	while (std::getline(myFile, line))
	{
		// Create a stringstream of the current line
		std::stringstream ss(line);

		// Keep track of the current column index
		int colIdx = 0;

		// Extract each integer
		while (ss >> val) {
			switch (val)
			{
			case 0:
				setBlocAt(colIdx, rowIdx, Bloc::EMPTY);
				break;
			case 1:
				setBlocAt(colIdx, rowIdx, Bloc::WALL);
				break;
			case 2:
				setBlocAt(colIdx, rowIdx, Bloc::POINT);
				break;
			case 3:
				setBlocAt(colIdx, rowIdx, Bloc::GUM);
				break;
			default:
				break;
			}
			// If the next token is a comma, ignore it and move on
			if (ss.peek() == ',') ss.ignore();
			// Increment the column index
			colIdx++;
		}
		rowIdx++;
	}
	window = new sf::RenderWindow(sf::VideoMode(largeur * cellWidth, hauteur * cellHeight), "PAC-MAN");
}

bool Controller::run()
{
	if (window->isOpen()==true)
	{
		sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window->close();
		}

		//Background
		sf::RectangleShape background(sf::Vector2f(window->getSize().x, window->getSize().y));
		background.setFillColor(sf::Color::White);
		window->draw(background);
		
		//Display Blocks
		for (int x = 0; x < largeur; ++x) {
			for (int y = 0; y < hauteur; ++y) {
				sf::RectangleShape cellShape(sf::Vector2f(cellWidth, cellHeight));
				sf::Texture* texture;
				cellShape.setPosition(x * cellWidth, y * cellHeight);

				switch (grille.at(x).at(y).getType()) {
				case Bloc::EMPTY:
					cellShape.setFillColor(sf::Color::Black);
					break;
				case Bloc::POINT:
					texture = new sf::Texture;
					texture->loadFromFile("resources/point.bmp");
					cellShape.setTexture(texture);
					break;
				case Bloc::WALL:
					cellShape.setFillColor(sf::Color::Blue);
					break;
				case Bloc::GUM:
					texture = new sf::Texture;
					texture->loadFromFile("resources/gum.bmp");
					cellShape.setTexture(texture);
					break;
				default:
					break;
				}
				window->draw(cellShape);
			}
		}
		//Display Pacman
		sf::RectangleShape pacmanShape(sf::Vector2f(cellWidth, cellHeight));
		sf::Texture * texturePacman = new sf::Texture;
		texturePacman->loadFromFile("resources/pacman.bmp");
		pacmanShape.setTexture(texturePacman);
		pacmanShape.setPosition(pacman.getX(), pacman.getY());
		window->draw(pacmanShape);

		//CALCULATIONS

		//PACMAN MOVEMENTS

		window->display();
		return true;
	}
	return false;
}
