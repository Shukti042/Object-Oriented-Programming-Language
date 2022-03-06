public class Cylinder implements Shape,Area,Volume {
    double radius;
    double hight;
    int count;
    public Cylinder(double r,double h,int c)
    {
        radius=r;
        hight=h;
        count=c;
    }

    @Override
    public void area() {
        System.out.println("Area of the base: "+3.1416*radius*radius);
        double temp=2*3.1416*radius*(radius+hight);
        System.out.println("Area of surface: "+temp);

    }

    @Override
    public void print() {
        System.out.println("Name: Cylinder"+count);
        area();
        volume();

    }

    @Override
    public void volume() {
        System.out.println("Volume: "+3.1416*radius*radius*hight);

    }
}
