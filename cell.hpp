#pragma once
#include <vector>

struct Cell {
	Cell();
	char identifier;
	bool solid;
};

class CellTypes {
	std::vector<Cell> types;
public:
	CellTypes();
	Cell* getType(char id);
};