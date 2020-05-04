#include "cell.hpp"

Cell::Cell() {
	identifier = 0;
	solid = false;
}

CellTypes::CellTypes() {
	Cell rockCell;
	rockCell.identifier = '_';
	rockCell.solid = true;
	types.push_back(rockCell);

	Cell floorCell;
	floorCell.identifier = 'f';
	types.push_back(floorCell);

	Cell grassCell;
	grassCell.identifier = 'g';
	types.push_back(grassCell);
}

Cell* CellTypes::getType(char id) {
	for (unsigned int i = 0; i < types.size(); i++) {
		if (types[i].identifier == id)
			return &types[i];
	}
	return nullptr;
}