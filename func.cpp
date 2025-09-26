
#include "func.h"
#include <cmath>
#include <algorithm>

using namespace std;

// 1. Ďđîâĺđęč ňî÷ĺę
string check_on_circle(Circle circle, Dot dot) {
    float distance = sqrt((dot.x - circle.dot.x) * (dot.x - circle.dot.x) +
        (dot.y - circle.dot.y) * (dot.y - circle.dot.y));
    if (fabs(distance - circle.rad) < 0.0001f)
        return "Ňî÷ęŕ ëĺćčň íŕ îęđóćíîńňč";
    else
        return "Ňî÷ęŕ íĺ ëĺćčň íŕ îęđóćíîńňč";
}

string check_in_circle(Circle circle, Dot dot) {
    float distance = sqrt((dot.x - circle.dot.x) * (dot.x - circle.dot.x) +
        (dot.y - circle.dot.y) * (dot.y - circle.dot.y));
    if (distance <= circle.rad + 0.0001f)
        return "Ňî÷ęŕ ďđčíŕäëĺćčň ęđóăó";
    else
        return "Ňî÷ęŕ íĺ ďđčíŕäëĺćčň ęđóăó";
}

string check_inside_circle(Circle circle, Dot dot) {
    float distance = sqrt((dot.x - circle.dot.x) * (dot.x - circle.dot.x) +
        (dot.y - circle.dot.y) * (dot.y - circle.dot.y));
    if (distance < circle.rad - 0.0001f)
        return "Ňî÷ęŕ ńňđîăî ďđčíŕäëĺćčň ęđóăó";
    else
        return "Ňî÷ęŕ íĺ ńňđîăî ďđčíŕäëĺćčň ęđóăó";
}

string check_on_square(Square square, Dot dot) {
    float left = square.dot.x;
    float right = square.dot.x + square.side;
    float top = square.dot.y;
    float bottom = square.dot.y - square.side;

    bool on_vertical = (fabs(dot.x - left) < 0.0001f || fabs(dot.x - right) < 0.0001f) &&
        (dot.y >= bottom - 0.0001f) && (dot.y <= top + 0.0001f);
    bool on_horizontal = (fabs(dot.y - top) < 0.0001f || fabs(dot.y - bottom) < 0.0001f) &&
        (dot.x >= left - 0.0001f) && (dot.x <= right + 0.0001f);

    if (on_vertical || on_horizontal)
        return "Ňî÷ęŕ ëĺćčň íŕ ăđŕíčöĺ ęâŕäđŕňŕ";
    else
        return "Ňî÷ęŕ ëĺćčň íĺ íŕ ăđŕíčöĺ ęâŕäđŕňŕ";
}

string check_in_square(Square square, Dot dot) {
    float left = square.dot.x;
    float right = square.dot.x + square.side;
    float top = square.dot.y;
    float bottom = square.dot.y - square.side;

    if (dot.x >= left - 0.0001f && dot.x <= right + 0.0001f &&
        dot.y >= bottom - 0.0001f && dot.y <= top + 0.0001f)
        return "Ňî÷ęŕ ďđčíŕäëĺćčň ęâŕäđŕňó";
    else
        return "Ňî÷ęŕ íĺ ďđčíŕäëĺćčň ęâŕäđŕňó";
}

string check_inside_square(Square square, Dot dot) {
    float left = square.dot.x;
    float right = square.dot.x + square.side;
    float top = square.dot.y;
    float bottom = square.dot.y - square.side;

    if (dot.x > left + 0.0001f && dot.x < right - 0.0001f &&
        dot.y > bottom + 0.0001f && dot.y < top - 0.0001f)
        return "Ňî÷ęŕ ńňđîăî ďđčíŕäëĺćčň ęâŕäđŕňó";
    else
        return "Ňî÷ęŕ íĺ ńňđîăî ďđčíŕäëĺćčň ęâŕäđŕňó";
}

// 2. Ďđîâĺđęč ďĺđĺńĺ÷ĺíčé
string check_squares_intersection(Square sq1, Square sq2) {
    float left1 = sq1.dot.x;
    float right1 = sq1.dot.x + sq1.side;
    float top1 = sq1.dot.y;
    float bottom1 = sq1.dot.y - sq1.side;

    float left2 = sq2.dot.x;
    float right2 = sq2.dot.x + sq2.side;
    float top2 = sq2.dot.y;
    float bottom2 = sq2.dot.y - sq2.side;

    bool x_overlap = (left1 <= right2 + 0.0001f) && (right1 >= left2 - 0.0001f);
    bool y_overlap = (bottom1 <= top2 + 0.0001f) && (top1 >= bottom2 - 0.0001f);

    if (x_overlap && y_overlap)
        return "Ęâŕäđŕňű ďĺđĺńĺęŕţňń˙";
    else
        return "Ęâŕäđŕňű íĺ ďĺđĺńĺęŕţňń˙";
}

string check_circles_intersection(Circle c1, Circle c2) {
    float dx = c2.dot.x - c1.dot.x;
    float dy = c2.dot.y - c1.dot.y;
    float distance = sqrt(dx * dx + dy * dy);

    if (distance <= c1.rad + c2.rad + 0.0001f) {
        return "Ęđóăč ďĺđĺńĺęŕţňń˙";
    }
    else {
        return "Ęđóăč íĺ ďĺđĺńĺęŕţňń˙";
    }
}

string check_circle_square_intersection(Circle circle, Square square) {
    float closest_x = max(square.dot.x, min(circle.dot.x, square.dot.x + square.side));
    float closest_y = max(square.dot.y - square.side, min(circle.dot.y, square.dot.y));

    float distance = sqrt((circle.dot.x - closest_x) * (circle.dot.x - closest_x) +
        (circle.dot.y - closest_y) * (circle.dot.y - closest_y));

    if (distance <= circle.rad + 0.0001f)
        return "Ęđóă č ęâŕäđŕň ďĺđĺńĺęŕţňń˙";
    else
        return "Ęđóă č ęâŕäđŕň íĺ ďĺđĺńĺęŕţňń˙";
}

// 3. Ďđîâĺđęč ďđčíŕäëĺćíîńňč ôčăóđ
string check_square_inside_square(Square inner, Square outer) {
    float inner_left = inner.dot.x;
    float inner_right = inner.dot.x + inner.side;
    float inner_top = inner.dot.y;
    float inner_bottom = inner.dot.y - inner.side;

    float outer_left = outer.dot.x;
    float outer_right = outer.dot.x + outer.side;
    float outer_top = outer.dot.y;
    float outer_bottom = outer.dot.y - outer.side;

    if (inner_left >= outer_left - 0.0001f && inner_right <= outer_right + 0.0001f &&
        inner_top <= outer_top + 0.0001f && inner_bottom >= outer_bottom - 0.0001f)
        return "Ďĺđâűé ęâŕäđŕň âíóňđč âňîđîăî";
    else
        return "Ďĺđâűé ęâŕäđŕň íĺ âíóňđč âňîđîăî";
}

string check_circle_inside_circle(Circle inner, Circle outer) {
    float distance = sqrt((outer.dot.x - inner.dot.x) * (outer.dot.x - inner.dot.x) +
        (outer.dot.y - inner.dot.y) * (outer.dot.y - inner.dot.y));

    if (distance + inner.rad <= outer.rad + 0.0001f)
        return "Ďĺđâűé ęđóă âíóňđč âňîđîăî";
    else
        return "Ďĺđâűé ęđóă íĺ âíóňđč âňîđîăî";
}

string check_square_inside_circle(Square square, Circle circle) {
    Dot corners[4] = {
        {square.dot.x, square.dot.y},
        {square.dot.x + square.side, square.dot.y},
        {square.dot.x, square.dot.y - square.side},
        {square.dot.x + square.side, square.dot.y - square.side}
    };

    for (int i = 0; i < 4; i++) {
        float distance = sqrt((corners[i].x - circle.dot.x) * (corners[i].x - circle.dot.x) +
            (corners[i].y - circle.dot.y) * (corners[i].y - circle.dot.y));
        if (distance > circle.rad + 0.0001f)
            return "Ęâŕäđŕň íĺ âíóňđč ęđóăŕ";
    }
    return "Ęâŕäđŕň âíóňđč ęđóăŕ";
}

string check_circle_inside_square(Circle circle, Square square) {
    float left = square.dot.x;
    float right = square.dot.x + square.side;
    float top = square.dot.y;
    float bottom = square.dot.y - square.side;

    if ((circle.dot.x - circle.rad >= left - 0.0001f) &&
        (circle.dot.x + circle.rad <= right + 0.0001f) &&
        (circle.dot.y + circle.rad <= top + 0.0001f) &&
        (circle.dot.y - circle.rad >= bottom - 0.0001f))
        return "Ęđóă âíóňđč ęâŕäđŕňŕ";
    else
        return "Ęđóă íĺ âíóňđč ęâŕäđŕňŕ";
}

// 4. Ęîěáčíčđîâŕííűĺ ďđîâĺđęč
string check_on_figure(Circle circle, Dot dot, Square square) {
    if (check_on_circle(circle, dot) == "Ňî÷ęŕ ëĺćčň íŕ îęđóćíîńňč" ||
        check_on_square(square, dot) == "Ňî÷ęŕ ëĺćčň íŕ ăđŕíčöĺ ęâŕäđŕňŕ")
        return "Ňî÷ęŕ ńňđîăî íŕ ăđŕíčöĺ ôčăóđű";
    else
        return "Ňî÷ęŕ íĺ íŕ ăđŕíčöĺ ôčăóđű";
}

string check_in_figure(Circle circle, Dot dot, Square square) {
    if (check_on_figure(circle, dot, square) == "Ňî÷ęŕ íĺ íŕ ăđŕíčöĺ ôčăóđű" &&
        (check_inside_square(square, dot) == "Ňî÷ęŕ ńňđîăî ďđčíŕäëĺćčň ęâŕäđŕňó" ||
            check_inside_circle(circle, dot) == "Ňî÷ęŕ ńňđîăî ďđčíŕäëĺćčň ęđóăó"))
        return "Ňî÷ęŕ ńňđîăî âíóňđč ôčăóđű";
    else
        return "Ňî÷ęŕ íĺ ńňđîăî âíóňđč ôčăóđű";

}
