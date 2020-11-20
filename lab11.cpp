#include <iostream>
#include <math.h>
using namespace std;

enum Color
{
    Red,
    Green,
    Blue,
    Yellow,
    Black,
    White,
    Pink,
    Purple,
    Brown
};

class Point
{
private:
    int x, y;
public:
    Point(int x, int y) : x{ x }, y { y } {}

    Point(Point& point) : Point(point.x, point.y) {}

    Point() 
    {
        x = 0;
        y = 0;
    }

    static double Distance(Point p1, Point p2)
    {
        return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
    }

    double Distance(Point other)
    {
        return sqrt(pow(other.x - x, 2) + pow(other.y - y, 2));
    }

    static Point Add(Point p1, Point p2)
    {
        Point p(p2.x + p1.x, p2.y + p1.y);
        return p;
    }

    Point Add(Point other)
    {
        Point p(other.x + x, other.y + y);
        return p;
    }

    void SetPoint(int x, int y)
    {
        this->x = x;
        this->y = y;
    }

    int X()
    {
        return x;
    }

    int Y()
    {
        return y;
    }

    ~Point() {}

    friend ostream& operator <<(ostream& os, Point p)
    {
        os << 'x: ' << p.x << ' ' << 'y: ' << p.y;
        return os;
    }

    friend istream& operator >>(istream& is, Point& p)
    {
        while (true)
        {
            is >> p.x >> p.y;

            if (is.fail())
            {
                cout << "Ошибка ввода данных, попробуйте еще раз\n";
                is.clear();
                is.ignore(INT16_MAX, '\n');
                continue;
            }
            break;
        }
        return is;
    }

    friend bool operator ==(Point& p1, Point& p2)
    {
        return p1.x == p2.x && p1.y == p2.y;
    }
};

class Pixel : public Point
{
private:
    Color color;
public:
    Pixel(Color& color) : Point()
    {
        this->color = color;
    }

    Pixel() : Point()
    {
        color = Red;
    }

    void SetColor(Color value)
    {
        color = value;
    }

    Color GetColor()
    {
        return color;
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");
    Point p1(1, 1);
    Point p2;
    p2.SetPoint(3, 8);
    Point p3(p2);
    Point p4(p1);
    Point p5(5, 3);
    Pixel pixel;

    cout << "При сравнении " << p1 << " и " << p4 << " получаем " << (p1 == p4) << '\n';
    cout << "При сравнении " << p1 << " и " << p2 << " получаем " << (p1 == p2) << '\n';
    cout << "При сложении " << p1 << " и " << p2 << " получаем " << &Point::Add(p1,p2) << '\n';
    cout << "Дистанция между" << p1 << " и " << p5 << " равна " << Point::Distance(p1, p5) << '\n';
    cout << "Дэфолтный цвет  " << pixel.GetColor() << " дэфолтное расположение " << &(Point)pixel << '\n';
    pixel.SetPoint(8, 5);
    pixel.SetColor(Brown);
    cout << "Измененный цвет  " << pixel.GetColor() << " измененное расположение " << &(Point)pixel << '\n';


}

