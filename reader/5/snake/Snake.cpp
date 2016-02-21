#include "Snake.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdlib>

Snake::Snake(string filename) : numEaten(0) {

    // seed the randomizer
    srand(static_cast<unsigned int>(time(NULL)));

    loadWorld(filename);
}
void Snake::runSimulation() {
    while(numEaten < kMaxFood) {
        printWorld();
        performAI();
        if(!moveSnake())
            break;
        pause();
    }
    displayResult();
}

// helper functions
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
void Snake::printWorld() {
    system(kClearCommand.c_str());
    for (string row : world) {
        cout << row << endl;
    }
    cout << "food eaten: " << numEaten << endl;
}
void Snake::performAI() {

    // figure out where we will be after we move this turn.
    PointT nextHead = Snake::getNextPosition(dx, dy);

    // if that hits a wall or we randomly decide to, turn the snake.
    if(Snake::crashed(nextHead) || Snake::randomChance(kTurnRate)) {

        int leftDx = -dy;
        int leftDy = dx;

        int rightDx = dy;
        int rightDy = -dx;

        // check if turning left or right will cause us to crash.
        bool canLeft = !crashed(getNextPosition(leftDx, leftDy));
        bool canRight = !crashed(getNextPosition(rightDx, rightDy));

        bool willTurnLeft = false;
        if (!canLeft && !canRight) {
            return;                             // if we can't turn, don't turn.
        }
        else if (canLeft && !canRight) {
            willTurnLeft = true;                // if we must turn left, do so.
        }
        else if (!canLeft && canRight) {
            willTurnLeft = false;               // if we must turn right, do so.
        }
        else {
            willTurnLeft = randomChance(0.5);   // else pick randomly
        }

        dx = willTurnLeft? leftDx : rightDx;
        dy = willTurnLeft? leftDy : rightDy;
    }

}
bool Snake::moveSnake() {
    PointT nextHead = getNextPosition(dx, dy);
    if(crashed(nextHead))
        return false;

    bool isFood = (world[nextHead.getRow()][nextHead.getCol()] == kFoodTile);

    world[nextHead.getRow()][nextHead.getCol()] = kSnakeTile;
    snake.push_front(nextHead);

    if(!isFood) {
        world[snake.back().getRow()][snake.back().getCol()] = kEmptyTile;
        snake.pop_back();
    } else {
        ++numEaten;
        placeFood();
    }
    return true;
}
void Snake::pause() {
    clock_t startTime = clock();
    while(static_cast<double>(clock() - startTime) / CLOCKS_PER_SEC <
          kWaitTime);
}
void Snake::displayResult() {
    printWorld();
    if(numEaten == kMaxFood)
        cout << "the snake ate enough food and wins!" << endl;
    else
        cout << "oh no!  the snake crashed!" << endl;
}
PointT &Snake::getNextPosition(int dx, int dy) {
    PointT result = snake.front();
    result.setRow(result.getRow() + dy);
    result.setCol(result.getCol() + dx);
    return result;
}
bool Snake::crashed(PointT &headPos) {
    return !inWorld(headPos) ||
           world[headPos.getRow()][headPos.getCol()] == kSnakeTile ||
           world[headPos.getRow()][headPos.getCol()] == kWallTile;
}
bool Snake::randomChance(double probability) {
    return (rand() / (RAND_MAX + 1.0)) < probability;
}
bool Snake::inWorld(PointT &pt) {
    return pt.getCol() >= 0 &&
           pt.getRow() >= 0 &&
           pt.getCol() < numCols &&
           pt.getRow() < numRows;
}
void Snake::placeFood() {
    while(true) {
        int row = rand() % numRows;
        int col = rand() % numCols;

        // if the specified position is empty, place the food there
        if(world[row][col] == kEmptyTile) {
            world[row][col] = kFoodTile;
            return;
        }
    }
}

















