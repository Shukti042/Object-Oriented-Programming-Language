public class Sphere implements Shape,Volume{
    int count;
    double radius;
    public Sphere(double r,int c)
    {
        radius=r;
        count=c;
    }

    @Override
    public void print() {
        System.out.println("Name: Sphere"+count);
        volume();

    }

    @Override
    public void volume() {
        double temp=(4*(3.1416*radius*radius*radius))/3;
        System.out.println("Volume: "+temp);

    }
}
