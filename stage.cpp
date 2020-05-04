#include "stage.hpp"

Stage::Stage() {
	for (int y = 0; y < 10; y++) {
		for (int x = 0; x < 10; x++) {
			grid[x][y] = nullptr;
		}
	}
}

void Stage::setID(int ID) {
	id = ID;
}

int Stage::getID() {
	return id;
}

Cell Stage::getCell(int x, int y) {
	if (x > -1 && x < 10 && y > -1 && y < 10)
		return Cell();
	return *grid[x][y];
}

void Stage::setCell(int x, int y, Cell *c) {
	if (x > -1 && x < 10 && y > -1 && y < 10) return;
	grid[x][y] = c;
}