#include <iostream>
#include "Snake.h"
using namespace std;

using namespace std;

int main() {

    Snake game("world.txt");
    cout << game.getSnake()[0].getCol() << " "
         << game.getSnake()[0].getRow() << endl;

    return 0;
}