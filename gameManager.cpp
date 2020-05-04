#include "gameManager.hpp"
#include <fstream>

using namespace std; 

void processLine(string &str) { // makes line prosessable if there is a CR
    string line = "";
    for (int i = 0; i < str.size(); i++) {
        if (str[i] != 13) {
            line.push_back(str[i]);
        }
    }
    str = line;
}

int GameManager::parceDungeon(std::string filename) {
    std::ifstream file;
    file.open(filename);
    if (!file.is_open()) {
        return -1;
    }
    std::string line;
    do {
        getline(file, line);
        if (line == "S") {
if (line == "S") { // After "S" next 10 lines are a stage
                Stage tempStage;
                for (int y = 0; y < 10; y++) {
                    getline(file, line); processLine(line);

                    if (y == 0) {
                        string tempID; // First number in first line of stage is that stage's ID
                        for (int i = 0; line[i] != ','; i++) {
                            tempID.push_back(line[i]);
                        }
                        try {
                            tempStage.setID(stoi(tempID));
                        } catch (...) {
                            cout << "---error---" << endl;
                            cout << "   [" << tempID << "] <- is unreadable as stage a ID." << endl; 
                            return false;
                        }
                    }
                    
                    char tempChar;
                    int x = 0;
                    for (int i = 0; i < line.size(); i++) {
                        if (line[i] >= '0' && line[i] <= '9' && (x != 0 || y != 0)) {
                            string num;
                            while (line[i] != ',') {
                                num.push_back(line[i]);
                                i++;
                            }
                            tempStage.addTP(stoi(num), x, y);
                            //cout << x << "," << y << endl;
                            tempStage.setCell(x, y, dungeon->cellTypes.getCell('^'));
                            x++;
                            //cout << "[" << line[i] << "]" << x << "," << y << ":" << stoi(num) << endl;
                        } else {
                            if (line[i] != ',') {
                                tempChar = line[i];
                            } else {
                                tempStage.setCell(x, y, dungeon->cellTypes.getCell(tempChar));
                                x++;
                            }
                        }
                    }
                }
                dungeon->stages.push_back(tempStage);
            }
        }
    } while (file && line != "END");
}