#include "Controller.h"

Controller::Controller() {

}

Controller::Controller(int largeurIn, int hauteurIn) {
	largeur = largeurIn;
	hauteur = hauteurIn;
	makeGrid();
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
			vectorRow.insert(vectorRow.end(), Bloc());
		}
	}
}
