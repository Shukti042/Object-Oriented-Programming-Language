#include<iostream>
using namespace std;

class Point2D
{
    double x,y;
public:
	Point2D(){ x = 0; y = 0; }
	Point2D(double argx, double argy);
	void setX(double argx);
	void setY(double argy);
	double getX();
	double getY();
	void print();
	~Point2D(){ x = 0; y = 0; }
	Point2D operator + (Point2D a);
	Point2D operator * (double a);
	bool operator == (Point2D a);
	bool operator != (Point2D a);
	void operator = (Point2D a);
};
Point2D::Point2D(double argx,double argy)
{
	x = argx;
	y = argy;
}
void Point2D::setX(double argx)
{
	x=argx;
}

void Point2D::setY(double argy)
{
	y = argy;
}

double Point2D::getX()
{
	return x;
}

double Point2D::getY()
{
	return y;
}

void Point2D::print()
{
	cout << "(" << x << "," << y << ")";
}
Point2D Point2D:: operator + (Point2D a)
{
    Point2D b;
    b.setX(x+a.getX());
    b.setY(y+a.getY());
    return b;
}
void Point2D:: operator = (Point2D a)
{
    x=a.getX();
    y=a.getY();
}
Point2D Point2D:: operator * (double a)
{
    Point2D b;
    b.setX(x*a);
    b.setY(y*a);
    return b;
}
bool Point2D:: operator == (Point2D a)
{
    return (x==a.getX()&&y==a.getY());
}
bool Point2D:: operator != (Point2D a)
{
    return !(x==a.getX()&&y==a.getY());
}

class Circle
{
	Point2D center;
	double radius;
public:
	Circle()
	{
	    center.setX(0);
	    center.setY(0);
	    radius=0.0;
	}
	Circle(Point2D c, double r);
	Point2D getCenter();
	void setCenter(Point2D c);
	double getRadius();
	void setRadius(double r);
	void print();
	Circle operator + (Point2D);
	Circle operator * (double a);
	void operator = (Circle a);
	Circle operator + (Circle a);
	Circle operator - (Circle a);
	double area();
	bool operator == (Circle a);
	bool operator >= (Circle a);
	bool operator <= (Circle a);
	bool operator > (Circle a);
	bool operator < (Circle a);
	Circle operator ++(int a);
	Circle operator ++();
	~Circle()
	{
	    center.setX(0);
	    center.setY(0);
	    radius=0.0;
	}
};
Circle::Circle(Point2D c, double r)
{
	center.setX(c.getX());
	center.setY(c.getY());
	radius=r;
}
void Circle::setCenter(Point2D c)
{
    center.setX(c.getX());
    center.setY(c.getY());
}

Point2D Circle::getCenter()
{
    return center;
}

double Circle::getRadius()
{
    return radius;
}

void Circle::setRadius(double r)
{
    radius=r;
}

void Circle::print()
{
	cout << "Center: ";
	center.print();
	cout << ",Radius: " << radius;
}
Circle Circle:: operator + (Point2D a)
{
    Circle b;
    Point2D p;
    p=center+a;
    b.setCenter(p);
    b.setRadius(radius);
    return b;

}
Circle Circle:: operator * (double a)
{
    Circle b;
    Point2D p;
    p.setX(center.getX()*a);
    p.setY(center.getY()*a);
    b.setCenter(p);
    b.setRadius(a*radius);
    return b;

}
void Circle:: operator = (Circle a)
{
    center=a.getCenter();
    radius=a.getRadius();
}
Circle Circle:: operator + (Circle a)
{
    Circle p;
    double o;
    o=radius/(radius+a.getRadius());
    p.setRadius(radius+a.getRadius());
    p.setCenter((center*o)+(a.getCenter()*(1-o)));
    return p;
}
Circle Circle:: operator - (Circle a)
{
    Circle p;
    double o;
    o=radius/(radius+a.getRadius());
    p.setRadius(radius-a.getRadius());
    p.setCenter((center*o)+(a.getCenter()*(1-o)));
    return p;
}
double Circle::area()
{
	return 3.1416*radius*radius;
}
bool Circle:: operator == (Circle a)
{
   double p,q;
   p=area();
   q=a.area();
   return p==q;
}
bool Circle:: operator >= (Circle a)
{
   double p,q;
   p=area();
   q=a.area();
   return p>=q;
}
bool Circle:: operator <= (Circle a)
{
   double p,q;
   p=area();
   q=a.area();
   return p<=q;
}
bool Circle:: operator > (Circle a)
{
   double p,q;
   p=area();
   q=a.area();
   return p>q;
}
bool Circle:: operator < (Circle a)
{
   double p,q;
   p=area();
   q=a.area();
   return p<q;
}
Circle Circle:: operator ++(int a)
{
    Circle b(*this);
    center.setX(center.getX()+1);
     center.setY(center.getY()+1);
     return b;
}
Circle Circle:: operator ++()
{
    center.setX(center.getX()+1);
     center.setY(center.getY()+1);
     return *this;
}



class Rectangle
{
	Point2D a,b;
public:
	Rectangle()
	{
	    a.setX(0);
	    a.setY(0);
	    b.setX(0);
	    b.setY(0);
	}
	Rectangle(Point2D m,Point2D n)
	{
	    a.setX(m.getX());
	    a.setY(m.getY());
	    b.setX(n.getX());
	    b.setY(n.getY());
	}
	void setPoint1(Point2D p);
	void setPoint2(Point2D p);
	Point2D getPoint1();
	Point2D getPoint2();
    Rectangle operator + (Point2D o);
    Rectangle operator * (double o);
	~Rectangle()
	{
	    a.setX(0);
	    a.setY(0);
	    b.setX(0);
	    b.setY(0);
	}
};
void Rectangle::setPoint1(Point2D p)
{
    a.setX(p.getX());
    a.setY(p.getY());
}

void Rectangle::setPoint2(Point2D p)
{
    b.setX(p.getX());
    b.setY(p.getY());
}

Point2D Rectangle::getPoint1()
{
    return a;
}
Point2D Rectangle::getPoint2()
{
    return b;
}
Rectangle Rectangle:: operator + (Point2D o)
{
    Rectangle p;
    p.setPoint1(a+o);
    p.setPoint2(b+o);
    return p;
}
Rectangle Rectangle::operator * (double o)
{
    Rectangle p;
    p.setPoint1(a*o);
    p.setPoint2(b*o);
    return p;
}

int main()
{
    Point2D a(2.0,3.0),b(3.0,4.0),c,d(3.0,4.0);
    cout<<"a";
    a.print();
    cout<<",b";
    b.print();
    cout<<",d";
    d.print();
    cout<<endl;

    c=a+b;
    cout<<"The Sum of 'a' and 'b':";
    c.print();
    cout<<endl<<"a*3=";
    c=a*3;
    c.print();
    cout<<endl;
    if(a!=b)
        cout<<"The two points 'a' and 'b' are not similar"<<endl;
    if(d==b)
        cout<<"The two points 'd' and 'b' are similar"<<endl;

    Circle cir1(a,5.0),cir2(b,4.0),cir3(b,5.0);
    cout<<endl<<endl<<"cir1-";
    cir1.print();
    cout<<endl<<"cir2-";
    cir2.print();
    cout<<endl<<"cir3-";
    cir3.print();
    cir3=cir1+b;
    cout<<endl<<"cir3=cir1+b --";
    cir3.print();
    cir3=cir2*2;
    cout<<endl<<"cir3=cir2*2 --";
    cir3.print();
    cir3=cir1+cir2;
    cout<<endl<<"cir3=cir1+cir2 --";
    cir3.print();
    cir3=cir1-cir2;
    cout<<endl<<"cir3=cir1-cir2 --";
    cir3.print();
    cir3.setRadius(5.0);
    cout<<endl<<"The radius of cir3 has set to 5";
    if(cir3==cir1)
    {
        cout<<endl<<"cir3=cir1";
    }
    if(cir1>cir2)
    {
        cout<<endl<<"cir1>cir2";
    }
    if(cir2<cir1)
    {
        cout<<endl<<"cir2<cir1";
    }
    if(cir3>=cir1)
    {
        cout<<endl<<"cir3>=cir1";
    }
    if(cir2<=cir1)
    {
        cout<<endl<<"cir2<=cir1";
    }
    cir3=cir1++;
     cout<<endl<<"cir3=cir1++ is typed:"<<endl<<"cir1--";
    cir1.print();
     cout<<endl<<"cir3--";
    cir3.print();
    a.setX(1);
    a.setY(1);
    b.setX(5);
    b.setY(4);
    Rectangle rec(a,b),rec2;
    cout<<endl<<endl<<"The Rectangle is: rec";
    rec.getPoint1().print();
    rec.getPoint2().print();
    a.setX(1);
    a.setY(2);
    cout<<endl<<"rec2=rec+(1,2) :rec2";
    rec2=rec+a;
    rec2.getPoint1().print();
    rec2.getPoint2().print();
    cout<<endl<<"rec2=rec*(2.5) :rec2";
    rec2=rec*2.5;
    rec2.getPoint1().print();
    rec2.getPoint2().print();
    cout<<endl<<endl;
    return 0;
}
