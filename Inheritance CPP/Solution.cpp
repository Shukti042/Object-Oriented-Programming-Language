#include<iostream>
#include<bits/stdc++.h>
using namespace std;

typedef enum {UNDEFINED, POINT2D, POINT3D, CIRCLE, SPHERE, RECTANGLE} STYPE;

class Shape
{
	STYPE type;
public:
	Shape();
	Shape(STYPE type);
	virtual void print();
	virtual double volume();
	virtual double area();
	virtual bool contains(const Shape *s);
	//Intentionally made non-virtual
	bool operator==(const Shape &rhs);
	virtual ~Shape(){}
};

Shape::Shape()
{
	type = UNDEFINED;
}

Shape::Shape(STYPE argtype)
{
	type = argtype;
}

double Shape::area()
{
	cout << "\nI am a dummy Shape";
	return 0.0;
}
double Shape::volume()
{
	cout << "\nI am a dummy Shape";
	return 0.0;
}

bool Shape::contains(const Shape *rhs)
{
	cout << "You see this, because appropriate contains function is undefined";
	return false;
}

void Shape::print()
{
	cout << "Type: " << type;
}

bool Shape::operator==(const Shape &rhs)
{
	if(type==rhs.type) return true;
	else return false;
}

class Point2D : public Shape
{
public:
    double x,y;
	Point2D();
	Point2D(STYPE argtype, double argx, double argy);
	void print();
	double area();
	double volume()
	{
	    Shape::volume();
	}
	bool contains(const Shape * rhs);
	bool contains(const Point2D * rhs);
	bool operator==(const Point2D &rhs);

	double getX() const { return x; }
	double getY() const { return y; }
	void setx(double a)
	{
	    x=a;
	}
	void sety(double a)
	{
	    y=a;
	}
	~Point2D(){}
};

Point2D::Point2D() //calls Base's default constructor
{
	x = 0.0;
	y = 0.0;
}

Point2D::Point2D(STYPE argtype, double argx, double argy) : Shape(argtype)
{
	x = argx;
	y = argy;
}

void Point2D::print()
{
	Shape::print();
	cout << " (" << x << "," << y << ")\n";
}

double Point2D::area()
{
	Shape::area();
}

bool Point2D::contains(const Shape *s)
{
	const Point2D *pointType = dynamic_cast<const Point2D*>(s);
	if(pointType!=NULL)
	{
		//Supported
		return contains(pointType);
	}
	//By default, use base
	return Shape::contains(s);
}

bool Point2D::contains(const Point2D * rhs)
{
	if(x==rhs->x && y==rhs->y) return true;
	else return false;
}

bool Point2D::operator==(const Point2D & rhs)
{
	if( !Shape::operator==(rhs) ) return false;
	if( x==rhs.x && y==rhs.y ) return true;
	else return false;
}
class Rectangle : public Shape
{
public:
    Point2D topRight;
	Point2D bottomLeft;
	Rectangle();//implement this
	Rectangle(STYPE type, Point2D tr, Point2D bl);//implement this
	void print(); //implement this
	double area(); //implement this
	double volume()
	{
	    return 0;
	}
	bool contains(const Shape *rhs); //implement this to check containment for point2d only
	bool contains(const Point2D * p);
	bool operator==(const Rectangle &rhs); //implement this
	Point2D getTopRight()
	{
	    return topRight;
	}
	Point2D getBottomLeft()
	{
	    return bottomLeft;
	}
	~Rectangle(){}
};

class Circle : public Shape
{
	Point2D center;
	double radius;
public:
	Circle();
	Circle(STYPE type, Point2D c, double r); //implement this
	double area(); //implement this
	void print(); //implement this
	bool contains(const Shape * s); //implemented partially
	bool contains(const Point2D * p); //implement this
	bool contains(const Circle * rhs); //implement this
	bool contains(const Rectangle * p); //implement this
	bool operator==(const Circle &rhs); //implement this
	bool contains(const Point2D p);
	~Circle(){}
};
Circle::Circle():Shape()
{
    center.setx(0);
    center.sety(0);
}
Circle::Circle(STYPE type, Point2D c, double r):Shape(type)
{
    center.setx(c.getX());
    center.sety(c.getY());
    radius=r;
}
double Circle::area()
{
    return 3.1416*radius*radius;
}
void Circle::print()
{
    Shape::print();
    cout<<" Center("<<center.getX()<<","<<center.getY()<<"),Radius: "<<radius;
}

bool Circle::contains(const Shape * s)
{
	const Point2D * pointType = dynamic_cast<const Point2D*>(s);
	if(pointType!=NULL)
	{
		//Supported
		return contains(pointType);
	}
	const Circle * circleType = dynamic_cast<const Circle*>(s);
	if(circleType!=NULL)
	{
		//Supported
		return contains(circleType);
	}
	const Rectangle * rectangleType = dynamic_cast<const Rectangle*>(s);
	if(rectangleType!=NULL)
	{
		//Supported
		return contains(rectangleType);
	}
	//By default
	return Shape::contains(s);
}

bool Circle::contains(const Circle *rhs)
{
    double distance;
	distance=sqrt(((center.getX()-rhs->center.getX())*(center.getX()-rhs->center.getX()))+((center.getY()-rhs->center.getY())*(center.getY()-rhs->center.getY())));
	if(radius-rhs->radius>=distance)
        return true;
    else
        return false;
}
bool Circle::contains(const Point2D *p)
{
    double distance;
    distance=sqrt((center.getX()-p->getX())*(center.getX()-p->getX())+(center.getY()-p->getY())*(center.getY()-p->getY()));
    if(distance<=radius)
        return true;
    else
        return false;
}

bool Circle::contains(Point2D p)
{
    double distance;
    distance=sqrt((center.getX()-p.getX())*(center.getX()-p.getX())+(center.getY()-p.getY())*(center.getY()-p.getY()));
    if(distance<=radius)
        return true;
    else
        return false;
}
bool Circle::contains(const Rectangle * p)
{
    Point2D m,n;
    m.setx(p->topRight.getX());
    m.sety(p->bottomLeft.getY());
    n.sety(p->topRight.getY());
    n.setx(p->bottomLeft.getX());
    return (contains(p->topRight)&&contains(p->bottomLeft)&&contains(m)&&contains(n));
}
bool Circle::operator==(const Circle &rhs)
{
    if(Shape::operator==(rhs))
    return (center.getX()==rhs.center.getX())&&(center.getY()==rhs.center.getY())&&(radius==rhs.radius);
    return false;
}



bool Rectangle::contains(const Point2D *p)
{
    double x1,y1;
    x1=p->getX();
    y1=p->getY();
    if((x1>=bottomLeft.getX())&&(x1<=topRight.getX())&&(y1>=bottomLeft.getY())&&(y1<=topRight.getY()))
        return true;
    else
        return false;
}
bool Rectangle:: contains(const Shape *s)
{
    const Point2D * pointType = dynamic_cast<const Point2D*>(s);
	if(pointType!=NULL)
	{
		//Supported
		return contains(pointType);
	}
	return Shape::contains(s);
}
Rectangle::Rectangle():Shape()
{
    topRight.setx(0);
    topRight.sety(0);
    bottomLeft.setx(0);
    bottomLeft.sety(0);

}
Rectangle::Rectangle(STYPE type, Point2D tr, Point2D bl):Shape(type)
{
    topRight.setx(tr.getX());
    topRight.sety(tr.getY());
    bottomLeft.setx(bl.getX());
    bottomLeft.sety(bl.getY());
}
void Rectangle:: print()
{
    Shape::print();
    topRight.print();
    bottomLeft.print();

}
double Rectangle:: area()
{
     return abs((topRight.getX()- bottomLeft.getX())*(topRight.getY()-bottomLeft.getY()));
}
bool Rectangle::operator==(const Rectangle &rhs)
{
    if(Shape::operator==(rhs))
        return (rhs.bottomLeft.getX()==bottomLeft.getX()&&rhs.bottomLeft.getY()==bottomLeft.getY()&&rhs.topRight.getX()==topRight.getX()&&rhs.topRight.getY()==topRight.getY());
    return false;
}



class Point3D : public Point2D
{

public:
    double z;
    Point3D(); //already implemented
    Point3D(STYPE type, double argx, double argy, double argz); //implement this
    void print(); //already implemented
    //double area(); Not needed, base version is sufficient
	bool contains(const Shape *rhs); //implement this
	bool contains(const Point3D *rhs);  //implement this
	~Point3D(){}
};
 Point3D::Point3D(STYPE type, double argx, double argy, double argz):Point2D(type,argx,argy)
 {
     z=argz;
 }
 bool Point3D:: contains(const Shape *s)
 {
     const Point3D * pointType = dynamic_cast<const Point3D*>(s);
	if(pointType!=NULL)
	{
		//Supported
		return contains(pointType);
	}
	//By default, use base
	return Shape::contains(s);
 }
 bool Point3D:: contains(const Point3D *s)
 {
     return (z==s->z&&x==s->x&&y==s->y);
 }

Point3D::Point3D()
{
    z = 0;
}

void Point3D::print()
{
	Shape::print();
    cout << " (" << getX() << "," << getY() << "," << z << ")";
}

class Shape3D : public Shape
{
public:
	Shape3D();
	Shape3D(STYPE type);
	virtual double volume();
	~Shape3D(){}
};

Shape3D::Shape3D()
{

}

Shape3D::Shape3D(STYPE argtype) : Shape(argtype)
{

}

double Shape3D::volume()
{
	cout << "You see this, because appropriate function is missing in the derived class";
	return 0.0;
}



class Sphere : public Shape3D
{
	Point3D center;
	double radius;
public:
	Sphere();//implement this
	Sphere(STYPE type, Point3D c, double r);//implement this
	void print(); //implement this
	double area(); //implement this
	double volume(); //implement this
	bool contains(const Shape *rhs); //implement this for checking containgment of Point3D, rectangle inside sphere
	bool contains(const Point3D *rhs);
	bool contains(const Sphere *rhs); //implement this
	~Sphere(){}
};
Sphere::Sphere():Shape3D()
{
    center.setx(0);
    center.sety(0);
    center.z=0;
}
Sphere::Sphere(STYPE type, Point3D c, double r):Shape3D(type)
{
    center.setx(c.getX());
    center.sety(c.getY());
    center.z=c.z;
    radius=r;
}
void Sphere::print()
{
    cout<<"Center ("<<center.getX()<<","<<center.getY()<<","<<center.z<<"),Radius:"<<radius;

}
double Sphere:: volume()
{
    return (4.0/3)*3.1416*radius*radius*radius;
}
double Sphere:: area()
{
    return 4*3.1416*radius*radius;
}
bool Sphere:: contains(const Shape *s)
{
    const Point3D * pointType = dynamic_cast<const Point3D*>(s);
	if(pointType!=NULL)
	{
		//Supported
		return contains(pointType);
	}
	const Sphere * sphereType = dynamic_cast<const Sphere*>(s);
	if(sphereType!=NULL)
	{
		//Supported
		return contains(sphereType);
	}
	//By default
	return Shape::contains(s);
}
bool Sphere:: contains(const Sphere *rhs)
{
    return sqrt((center.getX()-rhs->center.getX())*(center.getX()-rhs->center.getX())+(center.getY()-rhs->center.getY())*(center.getY()-rhs->center.getY())+(center.z-rhs->center.z)*(center.z-rhs->center.z))<=radius-rhs->radius;
}
bool Sphere:: contains(const Point3D *rhs)
{
    return sqrt((center.getX()-rhs->getX())*(center.getX()-rhs->getX())+(center.getY()-rhs->getY())*(center.getY()-rhs->getY())+(center.z-rhs->z)*(center.z-rhs->z))<=radius;
}

int main(void)
{
	//Write main function to demonstrate your code
	//Create circles, rectanges, point2d,point3d,and sphere objects using base class pointers
	//then call the virtual methods to show that polymorphism works!
	while(1)
	{
	    int choice = 10;
	    cout << "\n1. Point2D 2. Rectangle 3. Circle\n";
        cout << "4. Point3D 5. Sphere. 0. Exit\n";
        cout << "Your choice:";
        cin >> choice;
		Shape * shape;
		Shape3D * shape3D;
		switch(choice)
		{
			case 1:
				shape = new Point2D(POINT2D, 5.0,10.0);
				shape->print();
				cout << "\nArea: " << shape->area();
				cout<<"\nVolume: "<<shape->volume();
				break;
			case 2:
			    {
                Point2D p1(POINT2D,5.0,5.0);
				Point2D p2(POINT2D,20.0,20.0);
				shape = new Rectangle(RECTANGLE, p1, p2);
				shape->print();
				cout << "\nArea: " << shape->area();
				break;
			    }

			case 3:
			    {
                    Point2D p1(POINT2D,0.0,0.0);
                    shape = new Circle(CIRCLE,p1,10.0);
                    break;
			    }

			case 4:
			    {
                shape = new Point3D(POINT3D,5.0,10.0,20.0);
				shape->print();
				cout << "\nArea: " << shape->area();
				cout << "\nVolume: " << shape->volume();
				break;
			    }

			case 5:
			    {
                Point3D p1(POINT3D,0.0,0.0,0.0);
				shape = new Sphere(SPHERE,p1,10.0);
				shape->print();
				cout << "\nArea: " << shape->area()<<endl;
				cout << "\nVolume: " << shape->volume();
				break;
			    }

		}
		if(choice==0)break;
	}
	while(1)
    {
        Shape *shape2,*shape3,*shape4,*shape5;
        //Shape3D *shape3D1,*shape3D2;
        int choice2;
        cout << "\n1. Rectangle 2. Circle ";
        cout << "3. Sphere. 0. Exit\n";
        cout << "Your choice to check contains: ";
        cin >> choice2;
        switch(choice2)
        {
            case 1:
                {
                    Point2D p3(POINT2D,5.0,5.0);
                    Point2D p4(POINT2D,20.0,20.0);
                    shape3=new Point2D(POINT2D,10.0,10.0);
                    shape2 = new Rectangle(RECTANGLE, p4, p3);
                    shape2->print();
                    cout<<"\n";
                    shape3->print();
                    cout<<"\n";
                    if(shape2->contains(shape3))
                        cout<<"The rectangle contains the point\n";
                    else
                        cout<<"The rectangle does not contain the point\n";
                    break;
                }
            case 2:
                {
                    Point2D p3(POINT2D,0.0,0.0),p4(POINT2D,1.0,1.0),p5(POINT2D,5.0,5.0);
                    shape3=new Point2D(POINT2D,1.0,1.0);
                    shape2 = new Circle(CIRCLE,p3,8.0);
                    shape4 = new Circle(CIRCLE,p4,2.0);
                    shape5 = new Rectangle(RECTANGLE, p5, p4);
                    shape2->print();
                    cout<<endl;
                    shape3->print();
                    cout<<endl;
                    if(shape2->contains(shape3))
                        cout<<"The Circle Contains The Point"<<endl;
                    else
                        cout<<"The Circle does not Contain The Point"<<endl;
                    shape4->print();
                    cout<<endl;
                    if(shape2->contains(shape4))
                        cout<<"The Circle Contains The Circle"<<endl;
                    else
                        cout<<"The Circle does not Contain The Circle"<<endl;
                    shape5->print();
                    cout<<endl;
                    if(shape2->contains(shape5))
                        cout<<"The Circle Contains The Rectangle"<<endl;
                    else
                        cout<<"The Circle does not Contain The Rectangle"<<endl;
                    break;
                }
            case 3:
                {
                    Point3D p3(POINT3D,0.0,0.0,0.0),p4(POINT3D,2.0,2.0,2.0);
                    shape2 = new Sphere(SPHERE,p3,10.0);
                    shape3= new Sphere(SPHERE,p4,2.0);
                    shape4= new Point3D(POINT3D,1.0,1.0,1.0);
                    shape2->print();
                    cout<<endl;
                    shape4->print();
                    cout<<endl;
                    if(shape2->contains(shape4))
                        cout<<"The Sphere Contains The Point"<<endl;
                    else
                        cout<<"The Sphere does not Contain The Point"<<endl;
                    shape3->print();
                    cout<<endl;
                    if(shape2->contains(shape3))
                        cout<<"The Sphere Contains The Sphere"<<endl;
                    else
                        cout<<"The Sphere does not Contain The Sphere"<<endl;
                    break;
                }
        }
        if(choice2==0)break;
    }

	//add other functions for demonstration
	return 0;
}
