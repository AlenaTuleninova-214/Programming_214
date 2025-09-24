#pragma once
#include "structs.h"
#include <string>

using namespace std;

// Функции проверки точек
string check_on_circle(Circle circle, Dot dot);
string check_in_circle(Circle circle, Dot dot);
string check_inside_circle(Circle circle, Dot dot);
string check_on_square(Square square, Dot dot);
string check_in_square(Square square, Dot dot);
string check_inside_square(Square square, Dot dot);

// Функции проверки пересечения
string check_circles_intersection(Circle c1, Circle c2);
string check_squares_intersection(Square sq1, Square sq2);
string check_circle_square_intersection(Circle circle, Square square);

// Функции проверки принадлежности фигур
string check_circle_inside_circle(Circle inner, Circle outer);
string check_square_inside_square(Square inner, Square outer);
string check_square_inside_circle(Square square, Circle circle);
string check_circle_inside_square(Circle circle, Square square);

// Комбинированные проверки
string check_on_figure(Circle circle, Dot dot, Square square);
string check_in_figure(Circle circle, Dot dot, Square square);
