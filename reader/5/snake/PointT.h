//
// Created by Ilya Rudyak on 2/21/16.
//

#ifndef SNAKE_POINTT_H
#define SNAKE_POINTT_H


class PointT {

public:

    PointT() : row(0), col(0) {}
    PointT(int row, int col);


    int getRow() const {
        return row;
    }

    int getCol() const {
        return col;
    }


    void setRow(int row) {
        PointT::row = row;
    }

    void setCol(int col) {
        PointT::col = col;
    }

private:
    int row;
    int col;

};


#endif //SNAKE_POINTT_H
