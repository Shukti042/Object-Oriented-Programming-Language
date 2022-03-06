public class Square implements Shape,Area {
    double length;
    int count;
    public Square(double l,int c)
    {
        length=l;
        count=c;
    }

    @Override
    public void area() {
        System.out.println("Area: "+length*length);

    }

    @Override
    public void print() {
        System.out.println("Name: Circle"+count);
        area();

    }
}
