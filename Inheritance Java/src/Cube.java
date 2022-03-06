public class Cube implements Shape,Volume {
    double length;
    int count;
    public Cube(double l,int c)
    {
        length=l;
        count=c;
    }
    @Override
    public void print() {
        System.out.println("Name: Cube"+count);
        volume();

    }

    @Override
    public void volume() {
        System.out.println("Volume: "+length*length*length);

    }
}
