#pragma once
#include <iostream>
using namespace std;

struct Dot {
    float x;
    float y;
};

struct Circle {
    Dot dot;
    float rad;

    void getCircle() {
        cin >> dot.x >> dot.y >> rad;
    }

    void giveCircle() {
        printf("x = %.1f, y = %.1f, rad = %.1f", dot.x, dot.y, rad);
    }

    float lenCircle() {
        return 2 * 3.14 * rad;
    }

    float areaCircle() {
        return 3.14 * rad * rad;
    }
};

struct Square {
    Dot dot;
    float side;

    void getSquare() {
        cin >> dot.x >> dot.y >> side;
    }

    void giveSquare() {
        printf("x = %.1f, y = %.1f, side = %.1f", dot.x, dot.y, side);
    }

    float perimeterSquare() {
        return 4 * side;
    }

    float areaSquare() {
        return side * side;
    }
};


