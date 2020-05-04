#pragma once
#include "cell.hpp"

class Stage {
	int id;
	Cell* grid[10][10];
public:
	Stage();
	void setID(int ID);
	int getID();
	Cell getCell(int x, int y);
	void setCell(int x, int y, Cell *c);
};