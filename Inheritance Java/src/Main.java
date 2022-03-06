import java.util.Scanner;
public class Main {
    public static int circ=1,cubc=1,sqc=1,cylc=1,spc=1;
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        Shape s;
        while (true)
        {
            System.out.println("Please select your choice:");
            System.out.println("1. Circle\n2. Cylinder\n3.Sphere \n4. Square\n5. Cube\n6. Exit System");
            int a=sc.nextInt();
            sc.nextLine();
            switch (a)
            {
                case 1:
                    System.out.println("Enter radius:");
                    double rcir=sc.nextDouble();
                    sc.nextLine();
                    if(rcir>=0)
                    {
                        s=new Circle(rcir,circ++);
                        s.print();
                    }
                    else
                    {
                        System.out.println("You can not enter a negative value.");
                    }

                    break;
                case 2:
                    System.out.println("Enter radius:");
                    double rcyl=sc.nextDouble();
                    sc.nextLine();
                    System.out.println("Enter radius:");
                    double hcyl=sc.nextDouble();
                    sc.nextLine();
                    if (rcyl>=0&&hcyl>=0)
                    {
                        s=new Cylinder(rcyl,hcyl,cylc++);
                        s.print();
                    }
                    else
                    {
                        System.out.println("You can not enter a negative value.");
                    }

                    break;
                case 3:
                    System.out.println("Enter radius:");
                    double rsp=sc.nextDouble();
                    sc.nextLine();
                    if(rsp>=0)
                    {
                        s=new Sphere(rsp,spc++);
                        s.print();
                    }
                    else
                    {
                        System.out.println("You can not enter a negative value.");
                    }

                    break;
                case 4:
                    System.out.println("Enter length:");
                    double lsq=sc.nextDouble();
                    sc.nextLine();
                    if(lsq>=0)
                    {
                        s=new Square(lsq,sqc++);
                        s.print();
                    }
                    else
                    {
                        System.out.println("You can not enter a negative value.");
                    }
                    break;
                case 5:
                    System.out.println("Enter length:");
                    double lcu=sc.nextDouble();
                    sc.nextLine();
                    if(lcu>=0)
                    {
                        s=new Cube(lcu,cubc++);
                        s.print();
                    }
                    else
                    {
                        System.out.println("You can not enter a negative value.");
                    }
                    break;
                case 6:
                    break;
                    default:
                        System.out.println("Error Serial Number");


            }
            if(a==6)
            {
                break;
            }


        }
    }
}
