#pragma once
#include <vector>
#include "stage.hpp"

class Dungeon {
	std::vector<Stage> stages;
	Stage* currentStage = nullptr;
	int id;
public:
	void setID(int id);
	void addStage(Stage stage);
	
};