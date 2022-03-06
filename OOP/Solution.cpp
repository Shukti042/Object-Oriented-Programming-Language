#include<iostream>
#include<bits/stdc++.h>
using namespace std;


class Point2D
{
	int x,y;
public:
	Point2D(){ x = 0; y = 0; } //default constructor initializes to (0,0)
	Point2D(int argx, int argy);
	//Complete setX funciton
	//Complete getX function
	void setX(int argx);
	void setY(int argy);
	int getX();
	int getY();
	void print();
	~Point2D(){ x = 0; y = 0; } //destructor that sets all values to 0
};

Point2D::Point2D(int argx,int argy)
{
	x = argx;
	y = argy;
}

void Point2D::setX(int argx)
{
	x=argx;
}

void Point2D::setY(int argy)
{
	y = argy;
}

int Point2D::getX()
{
	return x;
}

int Point2D::getY()
{
	return y;
}

void Point2D::print()
{
	cout << "(" << x << "," << y << ")";
}

class Circle
{
	Point2D center;
	double radius;
public:
    //write a default constructor that initializes all values to 0
	Circle()
	{
	    center.setX(0);
	    center.setY(0);
	    radius=0.0;
	}
	//Complete the all-argument constructor: Circle(Point2D c, double r)
	Circle(Point2D c, double r);
	//write getter and setter methods for this class
	Point2D getCenter();
	void setCenter(Point2D c);
	double getRadius();
	void setRadius(double r);
	double area(); //returns area of the circle
	void print(); //prints the rectangle in the stdout
	int intersect(Circle rhs); //determine if this circle intersects with rhs
	int contains(Circle rhs); //determine if this circle contains circle rhs
	int contains(Point2D p); //determine if this circle contains point p
	double perimeter(); //returns perimeter of the circle
	//write a destructor that sets all values to 0
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

double Circle::area()
{
	return 3.1416*radius*radius;
}

double Circle::perimeter()
{
    return 2*3.1416*radius;
}

int Circle::intersect(Circle rhs)
{
	double distance;
	distance=sqrt(((center.getX()-rhs.getCenter().getX()))*((center.getX()-rhs.getCenter().getX()))+((center.getY()-rhs.getCenter().getY()))*((center.getY()-rhs.getCenter().getY())));
	if(distance<=radius+rhs.getRadius())
        return 1;
    else
        return 0;
}

int Circle::contains(Circle rhs)
{
    double distance;
	distance=sqrt(((center.getX()-rhs.getCenter().getX()))*((center.getX()-rhs.getCenter().getX()))+((center.getY()-rhs.getCenter().getY()))*((center.getY()-rhs.getCenter().getY())));
	if(radius-rhs.getRadius()>=distance)
        return 1;
    else
        return 0;
}
int Circle::contains(Point2D p)
{
    double distance;
    distance=sqrt((center.getX()-p.getX())*(center.getX()-p.getX())+(center.getY()-p.getY())*(center.getY()-p.getY()));
    if(distance<=radius)
        return 1;
    else
        return 0;
}

void Circle::print()
{
	cout << "Center: ";
	center.print();
	cout << "Radius: " << radius;
}

class Rectangle
{
	Point2D a,b;
public:
    //write a default constructor that initializes all values to 0
	Rectangle()
	{
	    a.setX(0);
	    a.setY(0);
	    b.setX(0);
	    b.setY(0);
	}
	//write an all-argument constructor that accepts values of all member variables and set the members
    //variables accordingly
	Rectangle(Point2D m,Point2D n)
	{
	    a.setX(m.getX());
	    a.setY(m.getY());
	    b.setX(n.getX());
	    b.setY(n.getY());
	}
	//write an all-argument constructor that accepts values of all member variables and set the members
    //variables accordingly
	void setPoint1(Point2D p);
	void setPoint2(Point2D p);
	Point2D getPoint1();
	Point2D getPoint2();

	double area(); //returns area of the rectangle
	int intersect(Rectangle rhs); //determine if this rectangle intersects with rhs
	int contains(Rectangle rhs); //determine if this rectangle contains rhs
	int inside(Circle c); //determine if this rectangle is completely inside the circle c
	double perimeter(); //returns perimeter of the rectangle
	//write a destructor that sets all values to 0
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

double Rectangle::area()
{
    return abs((a.getX()-b.getX())*(a.getY()-b.getY()));
}

int Rectangle::intersect(Rectangle rhs)
{
    int maxi,mini,c=0,d=0;
    if(a.getX()>b.getX())
    {
        maxi=a.getX();
        mini=b.getX();
    }
    else
    {
        maxi=b.getX();
        mini=a.getX();
    }
    if(rhs.a.getX()>=mini&&rhs.a.getX()<=maxi)
        c++;
    if(rhs.b.getX()>=mini&&rhs.b.getX()<=maxi)
        c++;
    if(a.getY()>b.getY())
    {
        maxi=a.getY();
        mini=b.getY();
    }
    else
    {
        maxi=b.getY();
        mini=a.getY();
    }
    if(rhs.a.getY()>=mini&&rhs.a.getY()<=maxi)
        d++;
    if(rhs.b.getY()>=mini&&rhs.b.getY()<=maxi)
        d++;
    if(c==1||d==1)
        return 1;
    else
        return 0;


}

int Rectangle::contains(Rectangle rhs)
{
    int maxi,mini,c=0,d=0;
    if(a.getX()>b.getX())
    {
        maxi=a.getX();
        mini=b.getX();
    }
    else
    {
        maxi=b.getX();
        mini=a.getX();
    }
    if(rhs.a.getX()>=mini&&rhs.a.getX()<=maxi)
        c++;
    if(rhs.b.getX()>=mini&&rhs.b.getX()<=maxi)
        c++;
    if(a.getY()>b.getY())
    {
        maxi=a.getY();
        mini=b.getY();
    }
    else
    {
        maxi=b.getY();
        mini=a.getY();
    }
    if(rhs.a.getY()>=mini&&rhs.a.getY()<=maxi)
        d++;
    if(rhs.b.getY()>=mini&&rhs.b.getY()<=maxi)
        d++;

    if(c==2&&d==2)
        return 1;
    else
        return 0;
}

int Rectangle::inside(Circle c)
{
    Point2D m,n;
    m.setX(a.getX());
    m.setY(b.getY());
    n.setY(a.getY());
    n.setX(b.getX());
    if(c.contains(a)==1&&c.contains(b)==1&&c.contains(m)==1&&c.contains(n)==1)
        return 1;
    else
        return 0;
}

double Rectangle::perimeter()
{
    return abs(2*(a.getX()-b.getX()))+abs(2*(a.getY()-b.getY()));
}
//Practice: Extend your program to include other geometric objects such as square, ellipse, triangle, etc.


int main(void)
{
//Demonstrate your circle class
    Circle tcircle,acircle1,acircle2;
    Point2D cent1(2,3),cent2(1,1);
    double rad1=5.0,rad2=4.0;
    tcircle.setCenter(cent1);
    tcircle.setRadius(rad1);
    acircle1.setCenter(cent2);
    acircle1.setRadius(rad2);
    acircle2.setCenter(cent2);
    acircle2.setRadius(1);
    cout<<"Circle1:-";
    tcircle.print();
    cout<<endl;
    cout<<"Circle2:-";
    acircle1.print();
    cout<<endl;
    cout<<"Circle3:-";
    acircle2.print();
    cout<<endl;
	//Demonstrate your area funciton showing that it successfully prints area of a circle
	cout<<"Area of the Circle1: "<<tcircle.area()<<endl;
	//Demonstrate intersect(Circle) function by creating appropriate circles and showing that they intersect
    if(tcircle.intersect(acircle1))
    cout<<"Circle1 and Circle2 Intersect"<<endl;
	//Demonstrate contains(Circle) function by creating appropriate circles and showing that one circle
	//contains another circle
	if(tcircle.contains(acircle2))
    cout<<"Circle1 Contains Circle3"<<endl<<endl;

//Demonstrate your Rectangle class

	Rectangle trec,arec1,arec2;
	Point2D x1(1,1),x2(3,4),x3(2,2),x4(4,5),x5(2,2),x6(3,3);
	trec.setPoint1(x1);
	trec.setPoint2(x2);
	arec1.setPoint1(x3);
	arec1.setPoint2(x4);
	arec2.setPoint1(x5);
	arec2.setPoint2(x6);
	cout<<"Rectangle1:-";
	trec.getPoint1().print();
	trec.getPoint2().print();
	cout<<endl;
	cout<<"Rectangle2:-";
	arec1.getPoint1().print();
	arec1.getPoint2().print();
	cout<<endl;
	cout<<"Rectangle3:-";
	arec2.getPoint1().print();
	arec2.getPoint2().print();
	cout<<endl;

//Demonstrate your area function showing that it successfully prints area of a rectangle
    cout<<"The Area of the Rectangle1: "<<trec.area()<<endl;

	//Demonstrate intersect(Rectangle) function by creating appropriate rectangle and showing that
	//they intersect
	if(trec.intersect(arec1))
        cout<<"Rectangle1 and Rectangle2 Intersect"<<endl;
	//Demonstrate contains(Rectangle) function by creating appropriate rectangles and showing that
	//one rectangle contains another rectangle
	if(trec.contains(arec2))
        cout<<"Rectangle1 contains another Rectangle3"<<endl;
	//Demonstrate inside(Circle) function by creating appropriate rectangle and circle and showing that
	//a rectange is completely inside a circle
	if(trec.inside(tcircle))
	cout<<"Rectangle1 is inside Circle1"<<endl;

	return 0;
}
