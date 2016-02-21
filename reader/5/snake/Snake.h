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

    // Pause 0.1 seconds between frames
    const double kWaitTime = 0.1;

    /* The string used to clear the display before printing the game board.
     * Windows systems should use "CLS"; Mac OS X or Linux users should use
     * "clear" instead.
     */
    const string kClearCommand = "clear";

    // 20% chance to turn each step.
    const double kTurnRate = 0.2;

    vector<string> world;
    int numRows, numCols;

    struct pointT {
        int row, col;
    };

    deque<PointT> snake;
    int dx, dy;

    int numEaten;

    // helper functions
    void loadWorld(string);
    void printWorld();
    void performAI();
    bool moveSnake();
    void pause();
    void displayResult();
    PointT& getNextPosition(int, int);
    bool crashed(PointT&);
    bool randomChance(double);
    bool inWorld(PointT&);
    void placeFood();

};


#endif //SNAKE_SNAKE_H






















