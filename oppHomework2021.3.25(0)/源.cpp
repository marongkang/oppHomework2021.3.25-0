class  myPoint
{
public:
    myPoint(double  x, double  y);
    double  getX();
    double  getY();
private:
    double  mX, mY;
};

myPoint::myPoint(double x, double y) {
    mX = x;
    mY = y;
}

double myPoint::getX() {
    return mX;
}

double myPoint::getY() {
    return mY;
}

#include<iostream>
#include<math.h>
using namespace std;


class Line
{
public:
    Line();
    Line(const myPoint &p1,const myPoint &p2);
    double GetDistance();
    ~Line();

private:
    myPoint startPoint, endPoint;
};

Line::Line(const myPoint &p1,const myPoint &p2):startPoint(p1),endPoint(p2)
{
}

double Line::GetDistance() {
    double dx = startPoint.getX() - endPoint.getX();
    double dy = startPoint.getY() - endPoint.getY();
    return sqrt(dx * dx + dy * dy);
}

Line::~Line()
{
}

class Triangle
{
public:
    Triangle(const myPoint &p1,const myPoint &p2, const myPoint &p3);
    ~Triangle();
    double getGirth();
    double getArea();

private:
    Line l1, l2, l3;
};

Triangle::Triangle(const myPoint &p1, const myPoint &p2,const myPoint &p3) : l1(p1, p2), l2(p2, p3), l3(p3, p1) 
{
}

Triangle::~Triangle()
{
}

double Triangle::getGirth() {
    return l1.GetDistance() + l2.GetDistance() + l3.GetDistance();
}

double Triangle::getArea() {
    double p, a, b, c;
    a = l1.GetDistance();
    b = l2.GetDistance();
    c = l3.GetDistance();
    p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}








int  main()
{
    double  x1, x2, x3, y1, y2, y3;
    cout << "请输入点1的x的值：";
    cin >> x1;
    cout << "请输入点1的y的值：";
    cin >> y1;
    cout << "请输入点2的x的值：";
    cin >> x2;
    cout << "请输入点2的y的值：";
    cin >> y2;
    cout << "请输入点3的x的值：";
    cin >> x3;
    cout << "请输入点3的y的值：";
    cin >> y3;
    cout << "点1的坐标为：(" << x1 << "," << y1 << ")" << endl;
    cout << "点2的坐标为：(" << x2 << "," << y2 << ")" << endl;
    cout << "点3的坐标为：(" << x3 << "," << y3 << ")" << endl;
    myPoint  p1(x1, y1), p2(x2, y2), p3(x3, y3);
    Line    line1(p1, p2);
    cout << "线长度:" << line1.GetDistance() << endl;
    Triangle  t(p1, p2, p3);
    cout << "该三角形的周长为：" << t.getGirth() << endl;
    cout << "该三角形的面积为：" << t.getArea() << endl;
    return  0;
}