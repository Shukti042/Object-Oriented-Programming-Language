public class Circle implements Shape,Area {
    double radius;
    int count;
    public Circle(double r,int c)
    {
        radius=r;
        count=c;
    }
    @Override public void area() {

        System.out.println("Area: "+3.1416*radius*radius);
    }

    @Override
    public void print() {
        System.out.println("Name: Circle"+count);
        area();

    }
}
