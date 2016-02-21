//
// Created by Ilya Rudyak on 2/21/16.
//

#ifndef SNAKE_SNAKE_H
#define SNAKE_SNAKE_H

#include <vector>
#include <string>
#include <deque>
#include "PointT.h"

using namespace std;


class Snake {

public:

    Snake() = default;
    Snake(string filename);

    void runSimulation();

    // getters
    int getNumRows() const {
        return numRows;
    }
    int getNumCols() const {
        return numCols;
    }
    int getDx() const {
        return dx;
    }
    int getDy() const {
        return dy;
    }
    const vector<string> &getWorld() const {
        return world;
    }
    const deque<PointT> &getSnake() const {
        return snake;
    }

private:

    // number of food pellets that must be eaten to win
    const int kMaxFood = 20;

    // constants for the different tile types
    const char kEmptyTile = ' ';
    const char kWallTile  = '#';
    const char kFoodTile  = '$';
    const char kSnakeTile = '*';

    vector<string> world;
    int numRows, numCols;

    struct pointT {
        int row, col;
    };

    deque<PointT> snake;
    int dx, dy;

    int numEaten;

    void loadWorld(string filename);
};


#endif //SNAKE_SNAKE_H






















