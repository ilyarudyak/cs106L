//
// Created by Ilya Rudyak on 2/21/16.
//

#include "Snake.h"
#include <fstream>
#include <sstream>

Snake::Snake(string filename) : numEaten(0) {
    loadWorld(filename);
}

void Snake::loadWorld(string filename) {

    ifstream in(filename);
    in >> numRows >> numCols >> dx >> dy;

    string line;
    getline(in, line);
    while(getline(in, line)) {
        world.push_back(line);

        int col = (int) line.find(kSnakeTile);
        if(col != string::npos) {
            PointT point((int)world.size() - 1, col);
            snake.push_back(point);
        }
    }

}

void Snake::runSimulation() {

}





























