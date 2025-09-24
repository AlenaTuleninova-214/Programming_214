#include "structs.h"
#include "func.h"
#include <iostream>
#include <locale>

using namespace std;

int main() {

    setlocale(LC_ALL, "Russian");

    Circle circle1, circle2;
    Square square1, square2;
    Dot point;

    // Ввод данных
    cout << "Введите данные первого круга (x y радиус): ";
    circle1.getCircle();

    cout << "Введите данные второго круга (x y радиус): ";
    circle2.getCircle();

    cout << "Введите данные первого квадрата (x y сторона): ";
    square1.getSquare();

    cout << "Введите данные второго квадрата (x y сторона): ";
    square2.getSquare();

    cout << "Введите координаты точки (x y): ";
    cin >> point.x >> point.y;

    // Вывод введенных данных
    cout << "Круг 1: "; circle1.giveCircle(); cout << endl;
    cout << "Длина окружности: " << circle1.lenCircle() << endl;
    cout << "Площадь круга: " << circle1.areaCircle() << endl << endl;

    cout << "Круг 2: "; circle2.giveCircle(); cout << endl;
    cout << "Длина окружности: " << circle2.lenCircle() << endl;
    cout << "Площадь круга: " << circle2.areaCircle() << endl << endl;

    cout << "Квадрат 1: "; square1.giveSquare(); cout << endl;
    cout << "Периметр квадрата: " << square1.perimeterSquare() << endl;
    cout << "Площадь квадрата: " << square1.areaSquare() << endl << endl;

    cout << "Квадрат 2: "; square2.giveSquare(); cout << endl;
    cout << "Периметр квадрата: " << square2.perimeterSquare() << endl;
    cout << "Площадь квадрата: " << square2.areaSquare() << endl << endl;

    cout << "Точка: x = " << point.x << ", y = " << point.y << endl << endl;

    // Функции
    cout << "Точки." << endl;
    cout << "Первый круг: " << check_on_circle(circle1, point) << endl;
    cout << "Первый круг: " << check_in_circle(circle1, point) << endl;
    cout << "Первый круг: " << check_inside_circle(circle1, point) << endl;
    cout << "Второй круг: " << check_on_square(square1, point) << endl;
    cout << "Второй круг: " << check_in_square(square1, point) << endl;
    cout << "Второй круг: " << check_inside_square(square1, point) << endl;
    cout << "Первый круг и первый квадрат: " << check_on_figure(circle1, point, square1) << endl;
    cout << "Первый круг и первый квадрат: " << check_in_figure(circle2, point, square2) << endl;

    cout << endl << "Пересечения." << endl;
    cout << check_squares_intersection(square1, square2) << endl;
    cout << check_circles_intersection(circle1, circle2) << endl;
    cout << "Первый круг и первый квадрат: " << check_circle_square_intersection(circle1, square1) << endl;
    cout << "Первый круг и второй квадрат: " << check_circle_square_intersection(circle1, square2) << endl;
    cout << "Второй круг и первый квадрат: " << check_circle_square_intersection(circle2, square1) << endl;
    cout << "Второй круг и второй квадрат: " << check_circle_square_intersection(circle2, square2) << endl;

    cout << endl << "Принадлежность" << endl;
    cout << check_square_inside_square(square1, square2) << endl;

    cout << check_circle_inside_circle(circle1, circle2) << endl;
    cout << "Первый круг и первый квадрат: " << check_square_inside_circle(square1, circle1) << endl;
    cout << "Первый круг и второй квадрат: " << check_square_inside_circle(square2, circle1) << endl;
    cout << "Второй круг и первый квадрат: " << check_square_inside_circle(square1, circle2) << endl;
    cout << "Второй круг и второй квадрат: " << check_square_inside_circle(square2, circle2) << endl;
    cout << "Первый круг и первый квадрат: " << check_circle_inside_square(circle1, square1) << endl;
    cout << "Второй круг и первый квадрат: " << check_circle_inside_square(circle2, square1) << endl;
    cout << "Первый круг и второй квадрат: " << check_circle_inside_square(circle1, square2) << endl;
    cout << "Второй круг и второй квадрат: " << check_circle_inside_square(circle2, square2) << endl;

    system("pause");

    return 0;
}