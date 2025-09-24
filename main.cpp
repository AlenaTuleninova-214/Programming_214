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

    // ���� ������
    cout << "������� ������ ������� ����� (x y ������): ";
    circle1.getCircle();

    cout << "������� ������ ������� ����� (x y ������): ";
    circle2.getCircle();

    cout << "������� ������ ������� �������� (x y �������): ";
    square1.getSquare();

    cout << "������� ������ ������� �������� (x y �������): ";
    square2.getSquare();

    cout << "������� ���������� ����� (x y): ";
    cin >> point.x >> point.y;

    // ����� ��������� ������
    cout << "���� 1: "; circle1.giveCircle(); cout << endl;
    cout << "����� ����������: " << circle1.lenCircle() << endl;
    cout << "������� �����: " << circle1.areaCircle() << endl << endl;

    cout << "���� 2: "; circle2.giveCircle(); cout << endl;
    cout << "����� ����������: " << circle2.lenCircle() << endl;
    cout << "������� �����: " << circle2.areaCircle() << endl << endl;

    cout << "������� 1: "; square1.giveSquare(); cout << endl;
    cout << "�������� ��������: " << square1.perimeterSquare() << endl;
    cout << "������� ��������: " << square1.areaSquare() << endl << endl;

    cout << "������� 2: "; square2.giveSquare(); cout << endl;
    cout << "�������� ��������: " << square2.perimeterSquare() << endl;
    cout << "������� ��������: " << square2.areaSquare() << endl << endl;

    cout << "�����: x = " << point.x << ", y = " << point.y << endl << endl;

    // �������
    cout << "�����." << endl;
    cout << "������ ����: " << check_on_circle(circle1, point) << endl;
    cout << "������ ����: " << check_in_circle(circle1, point) << endl;
    cout << "������ ����: " << check_inside_circle(circle1, point) << endl;
    cout << "������ ����: " << check_on_square(square1, point) << endl;
    cout << "������ ����: " << check_in_square(square1, point) << endl;
    cout << "������ ����: " << check_inside_square(square1, point) << endl;
    cout << "������ ���� � ������ �������: " << check_on_figure(circle1, point, square1) << endl;
    cout << "������ ���� � ������ �������: " << check_in_figure(circle2, point, square2) << endl;

    cout << endl << "�����������." << endl;
    cout << check_squares_intersection(square1, square2) << endl;
    cout << check_circles_intersection(circle1, circle2) << endl;
    cout << "������ ���� � ������ �������: " << check_circle_square_intersection(circle1, square1) << endl;
    cout << "������ ���� � ������ �������: " << check_circle_square_intersection(circle1, square2) << endl;
    cout << "������ ���� � ������ �������: " << check_circle_square_intersection(circle2, square1) << endl;
    cout << "������ ���� � ������ �������: " << check_circle_square_intersection(circle2, square2) << endl;

    cout << endl << "��������������" << endl;
    cout << check_square_inside_square(square1, square2) << endl;

    cout << check_circle_inside_circle(circle1, circle2) << endl;
    cout << "������ ���� � ������ �������: " << check_square_inside_circle(square1, circle1) << endl;
    cout << "������ ���� � ������ �������: " << check_square_inside_circle(square2, circle1) << endl;
    cout << "������ ���� � ������ �������: " << check_square_inside_circle(square1, circle2) << endl;
    cout << "������ ���� � ������ �������: " << check_square_inside_circle(square2, circle2) << endl;
    cout << "������ ���� � ������ �������: " << check_circle_inside_square(circle1, square1) << endl;
    cout << "������ ���� � ������ �������: " << check_circle_inside_square(circle2, square1) << endl;
    cout << "������ ���� � ������ �������: " << check_circle_inside_square(circle1, square2) << endl;
    cout << "������ ���� � ������ �������: " << check_circle_inside_square(circle2, square2) << endl;

    system("pause");

    return 0;
}